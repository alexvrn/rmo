#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "common.h"

#define TEST_HOST_PU	"localhost"
#define TEST_PORT_PU	"2777"

//extern unsigned char stream_data[CBOR_STREAM_DATA_SIZE];

int
pgas_http_put_create(char* url, char* data, size_t size) {
	CURLcode ret = 0;
	long status = 0;

	if(!curl_handler) {
		ret = -1;
		goto exit;
	}

	curl_easy_setopt(curl_handler, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
	curl_easy_setopt(curl_handler, CURLOPT_URL, url);
	curl_easy_setopt(curl_handler, CURLOPT_TIMEOUT, 1L);
	curl_easy_setopt(curl_handler, CURLOPT_VERBOSE, 1L);
	curl_easy_setopt(curl_handler, CURLOPT_POSTFIELDS, data);
	curl_easy_setopt(curl_handler, CURLOPT_POSTFIELDSIZE, (long)size);


	ret = curl_easy_perform(curl_handler);
	printf("REQ: %s %ld byte: ", url, size);
	switch(ret) {
		case CURLE_OK:
		case CURLE_GOT_NOTHING:
			if(CURLE_OK == curl_easy_getinfo(curl_handler,
				CURLINFO_RESPONSE_CODE, &status)) {
				printf("status %ld\n", status);
				break;
			}
			break;
		default:
			printf("failed: %s\n",
				curl_easy_strerror(ret));
			break;
	}

exit:
	return ret;
}

int
pgas_url_request_handler(void* arg, void* conn,
		const char* url, const char* method, const char* version,
		const char* request_data, size_t request_data_size) {
	int ret = -1;
	int i = 0;
	unsigned int status = 200;

	printf("### ### ### ### ###\n");

	printf("HTTPD: %6s %s %lu %s\n",
		method, version, request_data_size, url);

	if(url_response_handler) {
		// show default test page on "GET /" request 
		if(strcmp("/", url) == 0 && strcmp("GET", method) == 0) {
			ret = url_response_handler(
				conn, (char*)arg, strlen((char*)arg), status);
			goto exit;
		}
		for(i=0; i<PGAS_CMD_MAX; i++) {
			//printf("%d: %s %s\n", i, pgas_cmd[i].appointment, pgas_cmd[i].http_url);
			if(	strcmp(pgas_cmd[i].http_url, url) == 0 &&
				strcmp(pgas_cmd[i].http_method, method) == 0
				) {
				printf("CMD: %s\n", pgas_cmd[i].appointment);
				if(i == 0) {
					printf("PGAS SHUTDOWN...\n");
					exit(0);
				}
				//request stream
				cbor_stream_in.data = (unsigned char*)(request_data);
				cbor_stream_in.size = request_data_size;
				cbor_stream_in.pos = 0;
				//response stream
				cbor_stream_out.pos = 0;
				pgas_cmd[i].handler(url, &cbor_stream_in, &cbor_stream_out);
				printf("REQUEST DATA : %p %lu byte\n",
					cbor_stream_in.data, cbor_stream_in.size);
				printf("RESPONSE DATA: %p %lu byte\n",
					cbor_stream_out.data, cbor_stream_out.pos);
				print_hex_word(cbor_stream_out.data, cbor_stream_out.pos);
				ret = url_response_handler(conn,
					(char*)cbor_stream_out.data, cbor_stream_out.pos,
					status);
				break;
			}
		}
		if(i == PGAS_CMD_MAX) {
			printf("CMD: NOT FOUND\n");
			ret = url_response_handler(conn,
				(char*)cbor_stream_out.data, 0,
				404);
		}
	}

exit:
	return ret;
}

int
pgas_stream_proc(pgas_stream_t* stream) {
	int ret = 0;
	struct timeval tv;
	unsigned now = 0;
	pgas_stream_t* st = NULL;
	char* data = NULL;
	char url[1024] = "";

	gettimeofday(&tv, NULL);
	now = tv.tv_sec;

	printf("%s:%u:%u\n", __func__, __LINE__, now);
	for(int i=0; i<PGAS_STREAM_MAX; i++) {

		st = &stream[i];
		//printf("%d Process stream %d %s:\n",
		//	i, stream[i].id, stream[i].info);

		if(st->interval <= 0) {
			continue;
		}
		//printf("st %d interval %d\n", st->id, st->interval);

		if(st->last_timestamp + st->interval >= now) {
			continue;
		}
		//printf("st %d time left %d\n", st->id, now - st->last_timestamp);

		if(cbuf_is_empty(&st->cbuf[st->irq_cbuf_id]) != 0) {
			printf("st %d cbuf[%d]\n", st->id, st->irq_cbuf_id);

			st->irq_cbuf_id = !st->irq_cbuf_id;

			while(0==cbuf_get(&st->cbuf[!st->irq_cbuf_id], &data)) {

				st->http_pack(&cbor_stream_out, data);

				snprintf(url, 1024, "%s/%d-%d",
					"http://" TEST_HOST_PU ":" TEST_PORT_PU,
					now, st->id);
				pgas_http_put_create(
					url, //"http://" TEST_HOST_PU ":" TEST_PORT_PU,
					(char*)cbor_stream_out.data, cbor_stream_out.pos);

				//clenup cbor buffer
				cbor_stream_out.pos = 0;

				ret = cbuf_remove(&st->cbuf[!st->irq_cbuf_id]);
				if(ret != 0) {
					printf("%s:%d: error\n", __func__,__LINE__);
					goto fail;
				}
			}
		}

		st->last_timestamp = now;
	}

	sleep(1);
fail:
	return ret;
}


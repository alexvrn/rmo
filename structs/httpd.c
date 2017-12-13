#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "common.h"

#include <microhttpd.h>
#include <curl/curl.h>

/*
* HTTP SERVER - LIBMICROHTTPD
*/

static URL_REQUEST_HANDLER url_request_handler = NULL;

static int MHD_request_handler(
			void* arg,
			struct MHD_Connection * connection,
			const char * url,
			const char * method,
			const char * version,
			const char * upload_data,
			size_t * upload_data_size,
			void ** ptr) {
	static int dummy;
	int ret = 0;

	//check for header is received but massage is not yet
	if (&dummy != *ptr) {
		*ptr = &dummy;
		//printf("%s:%d: HEADER\n", __func__, __LINE__);
		ret = MHD_YES;
		goto exit;
	}

	*ptr = NULL;

	//url handler
	if(url_request_handler) {
		ret = url_request_handler(arg, (void*)connection,
			url, method, version,
			upload_data, *upload_data_size);
	}

	//printf("%s %s %s %s(%lu)\n", method, version, url, upload_data, *upload_data_size);
exit:
	return ret;
}

int
httpd_url_response_handler(	void* connection,
			char* resp,
			size_t resp_len,
			unsigned int status) {
	int ret = 0;
	struct MHD_Response* response = NULL;

	response = MHD_create_response_from_buffer(	resp_len,
							(void*)resp,
							MHD_RESPMEM_PERSISTENT);

//printf("%s:%d: %u resp=%s (%lu)\n", __func__, __LINE__, status, resp, resp_len);
	ret = MHD_queue_response((struct MHD_Connection*)connection,
							status,
							response);

	MHD_destroy_response(response);

	return ret;
}

httpd*
httpd_start(int port,
		URL_REQUEST_HANDLER request_handler,
		URL_RESPONSE_HANDLER* response_handler,
		void* arg) {
	//set handler for server to call on request
	url_request_handler = request_handler;
	//set handler for user to send responce
	if(response_handler)
		*response_handler = httpd_url_response_handler;
	//start daemon
	return MHD_start_daemon(
		MHD_USE_THREAD_PER_CONNECTION,	//flags
		port,				//port
		NULL,				//policy handler to filter out clients
		NULL,				//args
		&MHD_request_handler,		//URL handler
		arg,				//args
		MHD_OPTION_END);
}

int
httpd_stop(struct MHD_Daemon* daemon) {
	int ret = 0;

	if(!daemon) {
		ret = 1;
		goto exit;
	}
	MHD_stop_daemon(daemon);
exit:
	return ret;
}

/*
* HTTP CLIENT - LIBCURL
*/

CURL* curl_handler = NULL;


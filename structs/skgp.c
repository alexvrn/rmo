#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"

int
skgp_url_request_handler(void* arg, void* conn,
		const char* url, const char * method, const char * version,
		const char* request_data, size_t request_data_size) {
	int ret = 0;
	unsigned int status = 200;

	printf("%s:%d: %s %s %s %s(%lu)\n", __func__, __LINE__,
		method, version, url, request_data, request_data_size);

	if(url_response_handler) {
		ret = url_response_handler(conn, (char*)arg, strlen((char*)arg), status);
	}

	return ret;
}


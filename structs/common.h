#ifndef COMMON_H
#define COMMON_H

#include <sys/time.h>
#include <unistd.h>
#include "cbor.h"
#include "types.h"
#include "status.h"
#include "debug.h"
#include "log.h"
#include "httpd.h"
#include "sensor_emulator.h"
#include "emulators.h"

#include "html.h"
#include "signal.h"
#include "cmd.h"
#include "debug.h"
#include "cbuf.h"
#include "pgas_stream.h"

extern dev_type_t dev;
extern URL_RESPONSE_HANDLER url_response_handler;
extern int pu_url_request_handler(void* arg, void* conn,
	const char* url, const char* method, const char* version,
	const char* request_data, size_t request_data_size);
extern int pgas_url_request_handler(void* arg, void* conn,
	const char* url, const char* method, const char* version,
	const char* request_data, size_t request_data_size);
extern int skgp_url_request_handler(void* arg, void* conn,
	const char* url, const char* method, const char* version,
	const char* request_data, size_t request_data_size);

extern int pgas_stream_proc(pgas_stream_t* stream);

#endif

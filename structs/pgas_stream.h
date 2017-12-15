/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-15 16:04:08
 */

#ifndef PGAS_STREAM_H
#define PGAS_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#include "cbor.h"

#include "curl/curl.h"

#include "types.h"

#include "common.h"
#include "debug.h"
#include "cmd_data_debug.h"
#include "cmd_data_rnd.h"
#include "cmd_data_packer.h"
#include "cmd_handler.h"
#include "cmd_data.h"
#include "cbuf.h"

#include "pgas_stream.h"

#include "cmd.h"

#define UNDEFINED_SIZE 2
#define CBOR_STREAM_DATA_SIZE (1024*32)

#define PGAS_STREAM_MAX 23
#define STREAM_DATA_SIZE_MAX 10
#define STREAM_URL_SIZE_MAX 256

typedef int (*IRQ_STREAM_HANDLER)(
	void* data,
	size_t size);

typedef int (*HTTP_STREAM_PACK)(
	cbor_stream_t* stream_out,
	void* data);

typedef int (*HTTP_STREAM_UNPACK)(
	cbor_stream_t* stream_in,
	size_t* offset,
	void* data);

typedef struct pgas_stream_t {
	unsigned id;
	char* info;
	unsigned interval;
	unsigned last_timestamp;
	/* Data */
	cbuf_t cbuf[2];
	unsigned irq_cbuf_id;
	IRQ_STREAM_HANDLER irq_handler;
	/* Data pack function */
	HTTP_STREAM_PACK http_pack;
	char* url;
} pgas_stream_t;

extern CURL* curl_handler;
extern pgas_stream_t pgas_stream[PGAS_STREAM_MAX];
extern int pgas_stream_init(void);
extern int pgas_stream_cleanup(void);

#ifdef __cplusplus
}
#endif


#endif


#ifndef TYPES_H
#define TYPES_H

typedef struct MHD_Daemon httpd;

typedef enum dev_type_t {
	DEV_UNDEF	= 0,
	DEV_PU		= 1,
	DEV_PGAS	= 2,
	DEV_SKGP	= 3
} dev_type_t;

typedef struct cmd_t {
	char* appointment;
	char* http_url;
	char* http_method;
	int (*handler)(const char* param,
		cbor_stream_t *stream_in,
		cbor_stream_t *stream_out);
} cmd_t;

#endif

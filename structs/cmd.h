/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-15 16:04:08
 */

#ifndef CMD_H
#define CMD_H

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

#define PGAS_CMD_MAX 36
#define SKGP_CMD_MAX 13
#define PU_CMD_MAX 15
extern cmd_t pgas_cmd[];
extern cmd_t skgp_cmd[];
extern cmd_t pu_cmd[];

#ifdef __cplusplus
}
#endif


#endif


/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-13 16:19:47
 */

#ifndef CMD_HANDLER_H
#define CMD_HANDLER_H

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

extern int handler_post_control_reboot(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_post_control_resurface(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_post_control_self_test(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_post_firmware_burn(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_firmware_sha1(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_rtc(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_post_rtc(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_put_antenna_defective_columns(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_antenna_defective_columns(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_put_env_params(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_env_params(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_patch_active_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_put_active_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_active_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_patch_utcs_transmit_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_put_utcs_transmit_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_utcs_transmit_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_patch_satcom_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_patch_satcom_scheduleFIX(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_satcom_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_put_passive_processing_parameters(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_patch_passive_processing_parameters(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_passive_processing_parameters(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_post_att_1(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_att_1(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_delete_att_1(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_passive_marks(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_active_GET_ANGLE_ID_marks(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_utcs_inbox(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_passive_targets(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_active_targets(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_patch_streams(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_put_streams(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_streams(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_get_self_diagnosis(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_post_control_set_mode(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);
extern int handler_post_do_measurements(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out);

#ifdef __cplusplus
}
#endif


#endif


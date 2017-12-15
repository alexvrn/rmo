/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-15 16:04:08
 */

#ifndef CMD_DATA_DEBUG_H
#define CMD_DATA_DEBUG_H

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

extern int cmd_data0_print(cmd_data0_t* cmd_data);
extern int cmd_data2_print(cmd_data2_t* cmd_data);
extern int cmd_data5_print(cmd_data5_t* cmd_data);
extern int cmd_data8_print(cmd_data8_t* cmd_data);
extern int cmd_data10_print(cmd_data10_t* cmd_data);
extern int cmd_data12_print(cmd_data12_t* cmd_data);
extern int cmd_data16_print(cmd_data16_t* cmd_data);
extern int cmd_data19_print(cmd_data19_t* cmd_data);
extern int cmd_data21_print(cmd_data21_t* cmd_data);
extern int cmd_data24_print(cmd_data24_t* cmd_data);
extern int cmd_data28_print(cmd_data28_t* cmd_data);
extern int cmd_data30_print(cmd_data30_t* cmd_data);
extern int cmd_data31_print(cmd_data31_t* cmd_data);
extern int cmd_data32_print(cmd_data32_t* cmd_data);
extern int cmd_data36_print(cmd_data36_t* cmd_data);
extern int cmd_data38_print(cmd_data38_t* cmd_data);
extern int cmd_data39_print(cmd_data39_t* cmd_data);
extern int cmd_data40_print(cmd_data40_t* cmd_data);
extern int cmd_data43_print(cmd_data43_t* cmd_data);
extern int cmd_data47_print(cmd_data47_t* cmd_data);
extern int cmd_data49_print(cmd_data49_t* cmd_data);
extern int cmd_data50_print(cmd_data50_t* cmd_data);
extern int cmd_data54_print(cmd_data54_t* cmd_data);
extern int cmd_data58_print(cmd_data58_t* cmd_data);
extern int cmd_data60_print(cmd_data60_t* cmd_data);
extern int cmd_data61_print(cmd_data61_t* cmd_data);
extern int cmd_data65_print(cmd_data65_t* cmd_data);
extern int cmd_data69_print(cmd_data69_t* cmd_data);
extern int cmd_data71_print(cmd_data71_t* cmd_data);
extern int cmd_data78_print(cmd_data78_t* cmd_data);
extern int cmd_data82_print(cmd_data82_t* cmd_data);
extern int cmd_data86_print(cmd_data86_t* cmd_data);
extern int cmd_data89_print(cmd_data89_t* cmd_data);
extern int cmd_data92_print(cmd_data92_t* cmd_data);
extern int cmd_data95_print(cmd_data95_t* cmd_data);
extern int cmd_data96_print(cmd_data96_t* cmd_data);
extern int cmd_data99_print(cmd_data99_t* cmd_data);
extern int cmd_data101_print(cmd_data101_t* cmd_data);
extern int cmd_data102_print(cmd_data102_t* cmd_data);
extern int cmd_data104_print(cmd_data104_t* cmd_data);
extern int cmd_data107_print(cmd_data107_t* cmd_data);
extern int cmd_data110_print(cmd_data110_t* cmd_data);
extern int cmd_data111_print(cmd_data111_t* cmd_data);
extern int cmd_data114_print(cmd_data114_t* cmd_data);
extern int cmd_data117_print(cmd_data117_t* cmd_data);
extern int cmd_data118_print(cmd_data118_t* cmd_data);
extern int cmd_data121_print(cmd_data121_t* cmd_data);
extern int cmd_data124_print(cmd_data124_t* cmd_data);
extern int cmd_data125_print(cmd_data125_t* cmd_data);
extern int cmd_data129_print(cmd_data129_t* cmd_data);
extern int cmd_data130_print(cmd_data130_t* cmd_data);
extern int cmd_data132_print(cmd_data132_t* cmd_data);
extern int cmd_data135_print(cmd_data135_t* cmd_data);
extern int cmd_data136_print(cmd_data136_t* cmd_data);
extern int cmd_data140_print(cmd_data140_t* cmd_data);
extern int cmd_data142_print(cmd_data142_t* cmd_data);
extern int cmd_data143_print(cmd_data143_t* cmd_data);
extern int cmd_data145_print(cmd_data145_t* cmd_data);
extern int cmd_data146_print(cmd_data146_t* cmd_data);
extern int cmd_data147_print(cmd_data147_t* cmd_data);
extern int cmd_data151_print(cmd_data151_t* cmd_data);
extern int cmd_data152_print(cmd_data152_t* cmd_data);
extern int cmd_data154_print(cmd_data154_t* cmd_data);
extern int cmd_data155_print(cmd_data155_t* cmd_data);
extern int cmd_data156_print(cmd_data156_t* cmd_data);
extern int cmd_data160_print(cmd_data160_t* cmd_data);
extern int cmd_data161_print(cmd_data161_t* cmd_data);
extern int cmd_data163_print(cmd_data163_t* cmd_data);
extern int cmd_data165_print(cmd_data165_t* cmd_data);
extern int cmd_data168_print(cmd_data168_t* cmd_data);
extern int cmd_data172_print(cmd_data172_t* cmd_data);
extern int cmd_data174_print(cmd_data174_t* cmd_data);
extern int cmd_data175_print(cmd_data175_t* cmd_data);
extern int cmd_data176_print(cmd_data176_t* cmd_data);
extern int cmd_data177_print(cmd_data177_t* cmd_data);
extern int cmd_data178_print(cmd_data178_t* cmd_data);
extern int cmd_data179_print(cmd_data179_t* cmd_data);
extern int cmd_data180_print(cmd_data180_t* cmd_data);
extern int cmd_data181_print(cmd_data181_t* cmd_data);
extern int cmd_data182_print(cmd_data182_t* cmd_data);
extern int cmd_data183_print(cmd_data183_t* cmd_data);
extern int cmd_data187_print(cmd_data187_t* cmd_data);
extern int cmd_data189_print(cmd_data189_t* cmd_data);
extern int cmd_data191_print(cmd_data191_t* cmd_data);
extern int cmd_data192_print(cmd_data192_t* cmd_data);
extern int cmd_data194_print(cmd_data194_t* cmd_data);

#ifdef __cplusplus
}
#endif


#endif


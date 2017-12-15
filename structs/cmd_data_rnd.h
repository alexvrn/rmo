/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-15 16:04:08
 */

#ifndef CMD_DATA_RND_H
#define CMD_DATA_RND_H

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

#define RANDOM(BUF, SIZE) {for(int _i=0; _i<SIZE; _i++) ((char*)BUF)[_i]=rand()%256;}
extern int cmd_data0_rnd(cmd_data0_t* cmd_data);
extern int cmd_data2_rnd(cmd_data2_t* cmd_data);
extern int cmd_data5_rnd(cmd_data5_t* cmd_data);
extern int cmd_data8_rnd(cmd_data8_t* cmd_data);
extern int cmd_data10_rnd(cmd_data10_t* cmd_data);
extern int cmd_data12_rnd(cmd_data12_t* cmd_data);
extern int cmd_data16_rnd(cmd_data16_t* cmd_data);
extern int cmd_data19_rnd(cmd_data19_t* cmd_data);
extern int cmd_data21_rnd(cmd_data21_t* cmd_data);
extern int cmd_data24_rnd(cmd_data24_t* cmd_data);
extern int cmd_data28_rnd(cmd_data28_t* cmd_data);
extern int cmd_data30_rnd(cmd_data30_t* cmd_data);
extern int cmd_data31_rnd(cmd_data31_t* cmd_data);
extern int cmd_data32_rnd(cmd_data32_t* cmd_data);
extern int cmd_data36_rnd(cmd_data36_t* cmd_data);
extern int cmd_data38_rnd(cmd_data38_t* cmd_data);
extern int cmd_data39_rnd(cmd_data39_t* cmd_data);
extern int cmd_data40_rnd(cmd_data40_t* cmd_data);
extern int cmd_data43_rnd(cmd_data43_t* cmd_data);
extern int cmd_data47_rnd(cmd_data47_t* cmd_data);
extern int cmd_data49_rnd(cmd_data49_t* cmd_data);
extern int cmd_data50_rnd(cmd_data50_t* cmd_data);
extern int cmd_data54_rnd(cmd_data54_t* cmd_data);
extern int cmd_data58_rnd(cmd_data58_t* cmd_data);
extern int cmd_data60_rnd(cmd_data60_t* cmd_data);
extern int cmd_data61_rnd(cmd_data61_t* cmd_data);
extern int cmd_data65_rnd(cmd_data65_t* cmd_data);
extern int cmd_data69_rnd(cmd_data69_t* cmd_data);
extern int cmd_data71_rnd(cmd_data71_t* cmd_data);
extern int cmd_data78_rnd(cmd_data78_t* cmd_data);
extern int cmd_data82_rnd(cmd_data82_t* cmd_data);
extern int cmd_data86_rnd(cmd_data86_t* cmd_data);
extern int cmd_data89_rnd(cmd_data89_t* cmd_data);
extern int cmd_data92_rnd(cmd_data92_t* cmd_data);
extern int cmd_data95_rnd(cmd_data95_t* cmd_data);
extern int cmd_data96_rnd(cmd_data96_t* cmd_data);
extern int cmd_data99_rnd(cmd_data99_t* cmd_data);
extern int cmd_data101_rnd(cmd_data101_t* cmd_data);
extern int cmd_data102_rnd(cmd_data102_t* cmd_data);
extern int cmd_data104_rnd(cmd_data104_t* cmd_data);
extern int cmd_data107_rnd(cmd_data107_t* cmd_data);
extern int cmd_data110_rnd(cmd_data110_t* cmd_data);
extern int cmd_data111_rnd(cmd_data111_t* cmd_data);
extern int cmd_data114_rnd(cmd_data114_t* cmd_data);
extern int cmd_data117_rnd(cmd_data117_t* cmd_data);
extern int cmd_data118_rnd(cmd_data118_t* cmd_data);
extern int cmd_data121_rnd(cmd_data121_t* cmd_data);
extern int cmd_data124_rnd(cmd_data124_t* cmd_data);
extern int cmd_data125_rnd(cmd_data125_t* cmd_data);
extern int cmd_data129_rnd(cmd_data129_t* cmd_data);
extern int cmd_data130_rnd(cmd_data130_t* cmd_data);
extern int cmd_data132_rnd(cmd_data132_t* cmd_data);
extern int cmd_data135_rnd(cmd_data135_t* cmd_data);
extern int cmd_data136_rnd(cmd_data136_t* cmd_data);
extern int cmd_data140_rnd(cmd_data140_t* cmd_data);
extern int cmd_data142_rnd(cmd_data142_t* cmd_data);
extern int cmd_data143_rnd(cmd_data143_t* cmd_data);
extern int cmd_data145_rnd(cmd_data145_t* cmd_data);
extern int cmd_data146_rnd(cmd_data146_t* cmd_data);
extern int cmd_data147_rnd(cmd_data147_t* cmd_data);
extern int cmd_data151_rnd(cmd_data151_t* cmd_data);
extern int cmd_data152_rnd(cmd_data152_t* cmd_data);
extern int cmd_data154_rnd(cmd_data154_t* cmd_data);
extern int cmd_data155_rnd(cmd_data155_t* cmd_data);
extern int cmd_data156_rnd(cmd_data156_t* cmd_data);
extern int cmd_data160_rnd(cmd_data160_t* cmd_data);
extern int cmd_data161_rnd(cmd_data161_t* cmd_data);
extern int cmd_data163_rnd(cmd_data163_t* cmd_data);
extern int cmd_data165_rnd(cmd_data165_t* cmd_data);
extern int cmd_data168_rnd(cmd_data168_t* cmd_data);
extern int cmd_data172_rnd(cmd_data172_t* cmd_data);
extern int cmd_data174_rnd(cmd_data174_t* cmd_data);
extern int cmd_data175_rnd(cmd_data175_t* cmd_data);
extern int cmd_data176_rnd(cmd_data176_t* cmd_data);
extern int cmd_data177_rnd(cmd_data177_t* cmd_data);
extern int cmd_data178_rnd(cmd_data178_t* cmd_data);
extern int cmd_data179_rnd(cmd_data179_t* cmd_data);
extern int cmd_data180_rnd(cmd_data180_t* cmd_data);
extern int cmd_data181_rnd(cmd_data181_t* cmd_data);
extern int cmd_data182_rnd(cmd_data182_t* cmd_data);
extern int cmd_data183_rnd(cmd_data183_t* cmd_data);
extern int cmd_data187_rnd(cmd_data187_t* cmd_data);
extern int cmd_data189_rnd(cmd_data189_t* cmd_data);
extern int cmd_data191_rnd(cmd_data191_t* cmd_data);
extern int cmd_data192_rnd(cmd_data192_t* cmd_data);
extern int cmd_data194_rnd(cmd_data194_t* cmd_data);

#ifdef __cplusplus
}
#endif


#endif


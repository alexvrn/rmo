/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-15 16:04:08
 */

#ifndef CMD_DATA_PACKER_H
#define CMD_DATA_PACKER_H

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

extern cbor_stream_t cbor_stream_in;extern cbor_stream_t cbor_stream_out;

extern int cmd_data0_pack(cbor_stream_t* stream, void* data);
extern int cmd_data0_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data2_pack(cbor_stream_t* stream, void* data);
extern int cmd_data2_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data5_pack(cbor_stream_t* stream, void* data);
extern int cmd_data5_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data8_pack(cbor_stream_t* stream, void* data);
extern int cmd_data8_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data10_pack(cbor_stream_t* stream, void* data);
extern int cmd_data10_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data12_pack(cbor_stream_t* stream, void* data);
extern int cmd_data12_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data16_pack(cbor_stream_t* stream, void* data);
extern int cmd_data16_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data19_pack(cbor_stream_t* stream, void* data);
extern int cmd_data19_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data21_pack(cbor_stream_t* stream, void* data);
extern int cmd_data21_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data24_pack(cbor_stream_t* stream, void* data);
extern int cmd_data24_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data28_pack(cbor_stream_t* stream, void* data);
extern int cmd_data28_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data30_pack(cbor_stream_t* stream, void* data);
extern int cmd_data30_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data31_pack(cbor_stream_t* stream, void* data);
extern int cmd_data31_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data32_pack(cbor_stream_t* stream, void* data);
extern int cmd_data32_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data36_pack(cbor_stream_t* stream, void* data);
extern int cmd_data36_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data38_pack(cbor_stream_t* stream, void* data);
extern int cmd_data38_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data39_pack(cbor_stream_t* stream, void* data);
extern int cmd_data39_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data40_pack(cbor_stream_t* stream, void* data);
extern int cmd_data40_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data43_pack(cbor_stream_t* stream, void* data);
extern int cmd_data43_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data47_pack(cbor_stream_t* stream, void* data);
extern int cmd_data47_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data49_pack(cbor_stream_t* stream, void* data);
extern int cmd_data49_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data50_pack(cbor_stream_t* stream, void* data);
extern int cmd_data50_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data54_pack(cbor_stream_t* stream, void* data);
extern int cmd_data54_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data58_pack(cbor_stream_t* stream, void* data);
extern int cmd_data58_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data60_pack(cbor_stream_t* stream, void* data);
extern int cmd_data60_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data61_pack(cbor_stream_t* stream, void* data);
extern int cmd_data61_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data65_pack(cbor_stream_t* stream, void* data);
extern int cmd_data65_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data69_pack(cbor_stream_t* stream, void* data);
extern int cmd_data69_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data71_pack(cbor_stream_t* stream, void* data);
extern int cmd_data71_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data78_pack(cbor_stream_t* stream, void* data);
extern int cmd_data78_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data82_pack(cbor_stream_t* stream, void* data);
extern int cmd_data82_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data86_pack(cbor_stream_t* stream, void* data);
extern int cmd_data86_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data89_pack(cbor_stream_t* stream, void* data);
extern int cmd_data89_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data92_pack(cbor_stream_t* stream, void* data);
extern int cmd_data92_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data95_pack(cbor_stream_t* stream, void* data);
extern int cmd_data95_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data96_pack(cbor_stream_t* stream, void* data);
extern int cmd_data96_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data99_pack(cbor_stream_t* stream, void* data);
extern int cmd_data99_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data101_pack(cbor_stream_t* stream, void* data);
extern int cmd_data101_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data102_pack(cbor_stream_t* stream, void* data);
extern int cmd_data102_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data104_pack(cbor_stream_t* stream, void* data);
extern int cmd_data104_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data107_pack(cbor_stream_t* stream, void* data);
extern int cmd_data107_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data110_pack(cbor_stream_t* stream, void* data);
extern int cmd_data110_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data111_pack(cbor_stream_t* stream, void* data);
extern int cmd_data111_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data114_pack(cbor_stream_t* stream, void* data);
extern int cmd_data114_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data117_pack(cbor_stream_t* stream, void* data);
extern int cmd_data117_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data118_pack(cbor_stream_t* stream, void* data);
extern int cmd_data118_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data121_pack(cbor_stream_t* stream, void* data);
extern int cmd_data121_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data124_pack(cbor_stream_t* stream, void* data);
extern int cmd_data124_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data125_pack(cbor_stream_t* stream, void* data);
extern int cmd_data125_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data129_pack(cbor_stream_t* stream, void* data);
extern int cmd_data129_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data130_pack(cbor_stream_t* stream, void* data);
extern int cmd_data130_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data132_pack(cbor_stream_t* stream, void* data);
extern int cmd_data132_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data135_pack(cbor_stream_t* stream, void* data);
extern int cmd_data135_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data136_pack(cbor_stream_t* stream, void* data);
extern int cmd_data136_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data140_pack(cbor_stream_t* stream, void* data);
extern int cmd_data140_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data142_pack(cbor_stream_t* stream, void* data);
extern int cmd_data142_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data143_pack(cbor_stream_t* stream, void* data);
extern int cmd_data143_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data145_pack(cbor_stream_t* stream, void* data);
extern int cmd_data145_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data146_pack(cbor_stream_t* stream, void* data);
extern int cmd_data146_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data147_pack(cbor_stream_t* stream, void* data);
extern int cmd_data147_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data151_pack(cbor_stream_t* stream, void* data);
extern int cmd_data151_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data152_pack(cbor_stream_t* stream, void* data);
extern int cmd_data152_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data154_pack(cbor_stream_t* stream, void* data);
extern int cmd_data154_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data155_pack(cbor_stream_t* stream, void* data);
extern int cmd_data155_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data156_pack(cbor_stream_t* stream, void* data);
extern int cmd_data156_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data160_pack(cbor_stream_t* stream, void* data);
extern int cmd_data160_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data161_pack(cbor_stream_t* stream, void* data);
extern int cmd_data161_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data163_pack(cbor_stream_t* stream, void* data);
extern int cmd_data163_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data165_pack(cbor_stream_t* stream, void* data);
extern int cmd_data165_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data168_pack(cbor_stream_t* stream, void* data);
extern int cmd_data168_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data172_pack(cbor_stream_t* stream, void* data);
extern int cmd_data172_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data174_pack(cbor_stream_t* stream, void* data);
extern int cmd_data174_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data175_pack(cbor_stream_t* stream, void* data);
extern int cmd_data175_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data176_pack(cbor_stream_t* stream, void* data);
extern int cmd_data176_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data177_pack(cbor_stream_t* stream, void* data);
extern int cmd_data177_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data178_pack(cbor_stream_t* stream, void* data);
extern int cmd_data178_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data179_pack(cbor_stream_t* stream, void* data);
extern int cmd_data179_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data180_pack(cbor_stream_t* stream, void* data);
extern int cmd_data180_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data181_pack(cbor_stream_t* stream, void* data);
extern int cmd_data181_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data182_pack(cbor_stream_t* stream, void* data);
extern int cmd_data182_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data183_pack(cbor_stream_t* stream, void* data);
extern int cmd_data183_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data187_pack(cbor_stream_t* stream, void* data);
extern int cmd_data187_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data189_pack(cbor_stream_t* stream, void* data);
extern int cmd_data189_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data191_pack(cbor_stream_t* stream, void* data);
extern int cmd_data191_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data192_pack(cbor_stream_t* stream, void* data);
extern int cmd_data192_unpack(cbor_stream_t* stream, size_t* offset, void* data);
extern int cmd_data194_pack(cbor_stream_t* stream, void* data);
extern int cmd_data194_unpack(cbor_stream_t* stream, size_t* offset, void* data);

#ifdef __cplusplus
}
#endif


#endif


/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-15 16:04:08
 */


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

cbor_stream_t cbor_stream_in = {NULL, 0, 0};
unsigned char cbor_stream_out_data[CBOR_STREAM_DATA_SIZE];
cbor_stream_t cbor_stream_out = {cbor_stream_out_data, sizeof(cbor_stream_out_data), 0};
unsigned char* tmp_ptr;
size_t tmp_len;

int
cmd_data0_pack(cbor_stream_t* stream, void* data) {
	cmd_data0_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->data, 32);

#ifdef DEBUG
	cmd_data0_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data0_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data0_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 32) {
		return 0;
	}
	memcpy(cmd_data->data, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data0_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data2_pack(cbor_stream_t* stream, void* data) {
	cmd_data2_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->cookie, 64);
	cbor_serialize_byte_stringl(stream, cmd_data->cookieSHA1, 20);

#ifdef DEBUG
	cmd_data2_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data2_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data2_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 64) {
		return 0;
	}
	memcpy(cmd_data->cookie, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 20) {
		return 0;
	}
	memcpy(cmd_data->cookieSHA1, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data2_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data5_pack(cbor_stream_t* stream, void* data) {
	cmd_data5_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->cookie, 64);
	cbor_serialize_byte_stringl(stream, cmd_data->cookieSHA1, 20);

#ifdef DEBUG
	cmd_data5_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data5_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data5_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 64) {
		return 0;
	}
	memcpy(cmd_data->cookie, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 20) {
		return 0;
	}
	memcpy(cmd_data->cookieSHA1, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data5_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data8_pack(cbor_stream_t* stream, void* data) {
	cmd_data8_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->cookie, 64);
	cbor_serialize_byte_stringl(stream, cmd_data->cookieSHA1, 20);
	cbor_serialize_byte_stringl(stream, cmd_data->reportURL, 2048);

#ifdef DEBUG
	cmd_data8_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data8_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data8_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 64) {
		return 0;
	}
	memcpy(cmd_data->cookie, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 20) {
		return 0;
	}
	memcpy(cmd_data->cookieSHA1, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 2048) {
		return 0;
	}
	memcpy(cmd_data->reportURL, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data8_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data10_pack(cbor_stream_t* stream, void* data) {
	cmd_data10_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cmd_data175_pack(stream, (void*)&cmd_data->diagData);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data10_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data10_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data10_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	if(0 == cmd_data175_unpack(stream, offset, &cmd_data->diagData)) {
		 return 0;
	}
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data10_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data12_pack(cbor_stream_t* stream, void* data) {
	cmd_data12_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->cookie, 64);
	cbor_serialize_byte_stringl(stream, cmd_data->cookieSHA1, 20);
	cbor_serialize_byte_stringl(stream, &cmd_data->image, 1);

#ifdef DEBUG
	cmd_data12_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data12_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data12_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 64) {
		return 0;
	}
	memcpy(cmd_data->cookie, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 20) {
		return 0;
	}
	memcpy(cmd_data->cookieSHA1, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->image, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data12_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data16_pack(cbor_stream_t* stream, void* data) {
	cmd_data16_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->sha1, 20);

#ifdef DEBUG
	cmd_data16_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data16_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data16_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 20) {
		return 0;
	}
	memcpy(cmd_data->sha1, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data16_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data19_pack(cbor_stream_t* stream, void* data) {
	cmd_data19_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);

#ifdef DEBUG
	cmd_data19_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data19_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data19_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
#ifdef DEBUG
	cmd_data19_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data21_pack(cbor_stream_t* stream, void* data) {
	cmd_data21_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->datetime);

#ifdef DEBUG
	cmd_data21_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data21_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data21_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->datetime);
#ifdef DEBUG
	cmd_data21_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data24_pack(cbor_stream_t* stream, void* data) {
	cmd_data24_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<PGA_COUNT_MAX;++i)
		cbor_serialize_int(stream, (int)cmd_data->defectiveColumns[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data24_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data24_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data24_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= PGA_COUNT_MAX)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->defectiveColumns[i++]);
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data24_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data28_pack(cbor_stream_t* stream, void* data) {
	cmd_data28_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<PGA_COUNT_MAX;++i)
		cbor_serialize_int(stream, (int)cmd_data->defectiveColumns[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data28_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data28_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data28_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= PGA_COUNT_MAX)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->defectiveColumns[i++]);
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data28_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data30_pack(cbor_stream_t* stream, void* data) {
	cmd_data30_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cmd_data31_pack(stream, (void*)&cmd_data->beta);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<24;++i)
		cmd_data32_pack(stream, (void*)&cmd_data->soundVelocity[i]);
	cbor_write_break(stream);
	cbor_serialize_float(stream, cmd_data->multipathTimeCoef);

#ifdef DEBUG
	cmd_data30_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data30_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data30_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	if(0 == cmd_data31_unpack(stream, offset, &cmd_data->beta)) {
		 return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 24)
			return 0;
		if(0 == cmd_data32_unpack(stream, offset, &cmd_data->soundVelocity[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->multipathTimeCoef);
#ifdef DEBUG
	cmd_data30_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data31_pack(cbor_stream_t* stream, void* data) {
	cmd_data31_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->b0);
	cbor_serialize_float(stream, cmd_data->b1);
	cbor_serialize_float(stream, cmd_data->b2);

#ifdef DEBUG
	cmd_data31_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data31_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data31_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->b0);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->b1);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->b2);
#ifdef DEBUG
	cmd_data31_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data32_pack(cbor_stream_t* stream, void* data) {
	cmd_data32_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->toHour);
	cbor_serialize_float(stream, cmd_data->sv);

#ifdef DEBUG
	cmd_data32_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data32_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data32_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->toHour);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->sv);
#ifdef DEBUG
	cmd_data32_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data36_pack(cbor_stream_t* stream, void* data) {
	cmd_data36_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cmd_data31_pack(stream, (void*)&cmd_data->beta);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<24;++i)
		cmd_data32_pack(stream, (void*)&cmd_data->soundVelocity[i]);
	cbor_write_break(stream);
	cbor_serialize_float(stream, cmd_data->multipathTimeCoef);

#ifdef DEBUG
	cmd_data36_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data36_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data36_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	if(0 == cmd_data31_unpack(stream, offset, &cmd_data->beta)) {
		 return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 24)
			return 0;
		if(0 == cmd_data32_unpack(stream, offset, &cmd_data->soundVelocity[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->multipathTimeCoef);
#ifdef DEBUG
	cmd_data36_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data38_pack(cbor_stream_t* stream, void* data) {
	cmd_data38_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<200;++i)
		cmd_data39_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);
	cbor_serialize_float(stream, cmd_data->cutOff);

#ifdef DEBUG
	cmd_data38_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data38_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data38_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 200)
			return 0;
		if(0 == cmd_data39_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->cutOff);
#ifdef DEBUG
	cmd_data38_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data39_pack(cbor_stream_t* stream, void* data) {
	cmd_data39_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->sweepId, 32);
	cbor_serialize_float(stream, cmd_data->emissionTimestamp);
	cbor_serialize_int(stream, (int)cmd_data->code);
	cbor_serialize_float(stream, cmd_data->range);
	cbor_serialize_float(stream, cmd_data->emitterBearing);
	cbor_serialize_float(stream, cmd_data->emitterDistance);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cbor_serialize_int(stream, (int)cmd_data->emissionSectors[i]);
	cbor_write_break(stream);
	cbor_serialize_float(stream, cmd_data->emissionLevel);
	cmd_data40_pack(stream, (void*)&cmd_data->procParams);
	cbor_serialize_float(stream, cmd_data->detectionDelay);
	cbor_serialize_float(stream, cmd_data->emitterRelativeBearing);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cbor_serialize_int(stream, (int)cmd_data->emissionRelativeSectors[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data39_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data39_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data39_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 32) {
		return 0;
	}
	memcpy(cmd_data->sweepId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->emissionTimestamp);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->code);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->range);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->emitterBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->emitterDistance);
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->emissionSectors[i++]);
	}
	*offset += 1;
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->emissionLevel);
	if(0 == cmd_data40_unpack(stream, offset, &cmd_data->procParams)) {
		 return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->detectionDelay);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->emitterRelativeBearing);
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->emissionRelativeSectors[i++]);
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data39_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data40_pack(cbor_stream_t* stream, void* data) {
	cmd_data40_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->targetThreshold);
	cbor_serialize_float(stream, cmd_data->markThreshold);
	cbor_serialize_float(stream, cmd_data->reverbShift);
	cbor_serialize_float(stream, cmd_data->reverbWidening);

#ifdef DEBUG
	cmd_data40_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data40_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data40_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->targetThreshold);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->markThreshold);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->reverbShift);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->reverbWidening);
#ifdef DEBUG
	cmd_data40_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data43_pack(cbor_stream_t* stream, void* data) {
	cmd_data43_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<200;++i)
		cmd_data39_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data43_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data43_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data43_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 200)
			return 0;
		if(0 == cmd_data39_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data43_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data47_pack(cbor_stream_t* stream, void* data) {
	cmd_data47_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<200;++i)
		cmd_data39_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data47_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data47_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data47_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 200)
			return 0;
		if(0 == cmd_data39_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data47_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data49_pack(cbor_stream_t* stream, void* data) {
	cmd_data49_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<50;++i)
		cmd_data50_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);
	cbor_serialize_float(stream, cmd_data->cutOff);

#ifdef DEBUG
	cmd_data49_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data49_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data49_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 50)
			return 0;
		if(0 == cmd_data50_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->cutOff);
#ifdef DEBUG
	cmd_data49_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data50_pack(cbor_stream_t* stream, void* data) {
	cmd_data50_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->msgId, 32);
	cbor_serialize_float(stream, cmd_data->txTimestamp);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		cbor_serialize_int(stream, (int)cmd_data->txSectors[i]);
	cbor_write_break(stream);
	cbor_serialize_float(stream, cmd_data->txLevel);
	cbor_serialize_int(stream, cmd_data->txMode);
	cbor_serialize_byte_stringl(stream, &cmd_data->txData, 1);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		cbor_serialize_int(stream, (int)cmd_data->txRelativeSectors[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data50_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data50_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data50_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 32) {
		return 0;
	}
	memcpy(cmd_data->msgId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->txTimestamp);
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= IGA_COUNT_MAX)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->txSectors[i++]);
	}
	*offset += 1;
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->txLevel);
	*offset += cbor_deserialize_int(stream, *offset, &cmd_data->txMode);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->txData, tmp_ptr, tmp_len);
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= IGA_COUNT_MAX)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->txRelativeSectors[i++]);
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data50_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data54_pack(cbor_stream_t* stream, void* data) {
	cmd_data54_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<50;++i)
		cmd_data50_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data54_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data54_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data54_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 50)
			return 0;
		if(0 == cmd_data50_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data54_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data58_pack(cbor_stream_t* stream, void* data) {
	cmd_data58_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<50;++i)
		cmd_data50_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data58_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data58_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data58_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 50)
			return 0;
		if(0 == cmd_data50_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data58_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data60_pack(cbor_stream_t* stream, void* data) {
	cmd_data60_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<200;++i)
		cmd_data61_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);
	cbor_serialize_float(stream, cmd_data->cutOff);

#ifdef DEBUG
	cmd_data60_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data60_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data60_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 200)
			return 0;
		if(0 == cmd_data61_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->cutOff);
#ifdef DEBUG
	cmd_data60_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data61_pack(cbor_stream_t* stream, void* data) {
	cmd_data61_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->to);

#ifdef DEBUG
	cmd_data61_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data61_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data61_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->to);
#ifdef DEBUG
	cmd_data61_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data65_pack(cbor_stream_t* stream, void* data) {
	cmd_data65_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<200;++i)
		cmd_data61_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data65_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data65_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data65_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 200)
			return 0;
		if(0 == cmd_data61_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data65_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data69_pack(cbor_stream_t* stream, void* data) {
	cmd_data69_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<200;++i)
		cmd_data61_pack(stream, (void*)&cmd_data->schedule[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data69_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data69_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data69_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 200)
			return 0;
		if(0 == cmd_data61_unpack(stream, offset, &cmd_data->schedule[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data69_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data71_pack(cbor_stream_t* stream, void* data) {
	cmd_data71_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->targetThreshold);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<2;++i)
		cbor_serialize_int(stream, (int)cmd_data->detectionRule[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data71_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data71_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data71_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->targetThreshold);
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 2)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->detectionRule[i++]);
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data71_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data78_pack(cbor_stream_t* stream, void* data) {
	cmd_data78_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->bearing);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_int(stream, (int)cmd_data->autoTracking);
	cbor_serialize_byte_stringl(stream, &cmd_data->targetId, 1);

#ifdef DEBUG
	cmd_data78_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data78_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data78_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->bearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->autoTracking);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->targetId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data78_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data82_pack(cbor_stream_t* stream, void* data) {
	cmd_data82_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_int(stream, (int)cmd_data->autoTracking);
	cbor_serialize_float(stream, cmd_data->Heading);
	cbor_serialize_float(stream, cmd_data->headingStd);

#ifdef DEBUG
	cmd_data82_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data82_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data82_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->autoTracking);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->Heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
#ifdef DEBUG
	cmd_data82_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data86_pack(cbor_stream_t* stream, void* data) {
	cmd_data86_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_int(stream, (int)cmd_data->coefCount);
	cbor_serialize_int(stream, (int)cmd_data->elemCount);
	cbor_serialize_float(stream, cmd_data->lowFreq);
	cbor_serialize_float(stream, cmd_data->highFreq);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->data, 1);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data86_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data86_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data86_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->coefCount);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->elemCount);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->lowFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->highFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->data, tmp_ptr, tmp_len);
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data86_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data89_pack(cbor_stream_t* stream, void* data) {
	cmd_data89_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_int(stream, (int)cmd_data->coefCount);
	cbor_serialize_int(stream, (int)cmd_data->beamCount);
	cbor_serialize_float(stream, cmd_data->lowFreq);
	cbor_serialize_float(stream, cmd_data->highFreq);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->data, 1);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data89_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data89_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data89_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->coefCount);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->beamCount);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->lowFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->highFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->data, tmp_ptr, tmp_len);
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data89_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data92_pack(cbor_stream_t* stream, void* data) {
	cmd_data92_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_int(stream, (int)cmd_data->beamCount);
	cbor_serialize_float(stream, cmd_data->lowFreq);
	cbor_serialize_float(stream, cmd_data->highFreq);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_float(stream, cmd_data->data);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data92_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data92_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data92_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->beamCount);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->lowFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->highFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->data);
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data92_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data95_pack(cbor_stream_t* stream, void* data) {
	cmd_data95_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_float(stream, cmd_data->lowFreq);
	cbor_serialize_float(stream, cmd_data->highFreq);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data96_pack(stream, (void*)&cmd_data->data[i]);
	cbor_write_break(stream);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data95_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data95_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data95_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->lowFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->highFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data96_unpack(stream, offset, &cmd_data->data[i++])) {
			return 0;
		}
	}
	*offset += 1;
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data95_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data96_pack(cbor_stream_t* stream, void* data) {
	cmd_data96_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, &cmd_data->targetId, 1);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->width);
	cbor_serialize_float(stream, cmd_data->level);
	cbor_serialize_float(stream, cmd_data->noise);

#ifdef DEBUG
	cmd_data96_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data96_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data96_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->targetId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->width);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->level);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->noise);
#ifdef DEBUG
	cmd_data96_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data99_pack(cbor_stream_t* stream, void* data) {
	cmd_data99_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->from);
	cbor_serialize_float(stream, cmd_data->to);

#ifdef DEBUG
	cmd_data99_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data99_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data99_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->from);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->to);
#ifdef DEBUG
	cmd_data99_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data101_pack(cbor_stream_t* stream, void* data) {
	cmd_data101_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data102_pack(stream, (void*)&cmd_data->marks[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data101_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data101_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data101_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data102_unpack(stream, offset, &cmd_data->marks[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data101_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data102_pack(cbor_stream_t* stream, void* data) {
	cmd_data102_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data96_pack(stream, (void*)&cmd_data->data[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data102_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data102_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data102_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data96_unpack(stream, offset, &cmd_data->data[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data102_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data104_pack(cbor_stream_t* stream, void* data) {
	cmd_data104_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_int(stream, (int)cmd_data->sampleCount);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->data, 1);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data104_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data104_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data104_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->sampleCount);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->data, tmp_ptr, tmp_len);
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data104_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data107_pack(cbor_stream_t* stream, void* data) {
	cmd_data107_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_int(stream, (int)cmd_data->coefCount);
	cbor_serialize_float(stream, cmd_data->lowFreq);
	cbor_serialize_float(stream, cmd_data->highFreq);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->data, 1);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data107_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data107_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data107_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->coefCount);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->lowFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->highFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->data, tmp_ptr, tmp_len);
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data107_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data110_pack(cbor_stream_t* stream, void* data) {
	cmd_data110_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_pack(stream, (void*)&cmd_data->data[i]);
	cbor_write_break(stream);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data110_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data110_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data110_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data111_unpack(stream, offset, &cmd_data->data[i++])) {
			return 0;
		}
	}
	*offset += 1;
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data110_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data111_pack(cbor_stream_t* stream, void* data) {
	cmd_data111_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->frequency);
	cbor_serialize_float(stream, cmd_data->level);

#ifdef DEBUG
	cmd_data111_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data111_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data111_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->frequency);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->level);
#ifdef DEBUG
	cmd_data111_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data114_pack(cbor_stream_t* stream, void* data) {
	cmd_data114_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_int(stream, (int)cmd_data->sampleCount);
	cbor_serialize_float(stream, cmd_data->minShift);
	cbor_serialize_float(stream, cmd_data->maxShift);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->data, 1);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data114_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data114_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data114_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->sampleCount);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->minShift);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->maxShift);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->data, tmp_ptr, tmp_len);
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data114_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data117_pack(cbor_stream_t* stream, void* data) {
	cmd_data117_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data118_pack(stream, (void*)&cmd_data->data[i]);
	cbor_write_break(stream);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data117_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data117_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data117_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data118_unpack(stream, offset, &cmd_data->data[i++])) {
			return 0;
		}
	}
	*offset += 1;
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data117_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data118_pack(cbor_stream_t* stream, void* data) {
	cmd_data118_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->shift);
	cbor_serialize_float(stream, cmd_data->level);

#ifdef DEBUG
	cmd_data118_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data118_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data118_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->shift);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->level);
#ifdef DEBUG
	cmd_data118_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data121_pack(cbor_stream_t* stream, void* data) {
	cmd_data121_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_byte_stringl(stream, cmd_data->sweepId, 32);
	cbor_serialize_int(stream, (int)cmd_data->dopplerAltCount);
	cbor_serialize_int(stream, (int)cmd_data->beamCount);
	cbor_serialize_float(stream, cmd_data->dopplerRange);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);

#ifdef DEBUG
	cmd_data121_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data121_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data121_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 32) {
		return 0;
	}
	memcpy(cmd_data->sweepId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->dopplerAltCount);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->beamCount);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->dopplerRange);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
#ifdef DEBUG
	cmd_data121_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data124_pack(cbor_stream_t* stream, void* data) {
	cmd_data124_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_byte_stringl(stream, cmd_data->sweepId, 32);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data125_pack(stream, (void*)&cmd_data->data[i]);
	cbor_write_break(stream);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data124_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data124_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data124_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 32) {
		return 0;
	}
	memcpy(cmd_data->sweepId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data125_unpack(stream, offset, &cmd_data->data[i++])) {
			return 0;
		}
	}
	*offset += 1;
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data124_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data125_pack(cbor_stream_t* stream, void* data) {
	cmd_data125_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, &cmd_data->targetId, 1);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->dopplerSpeed);
	cbor_serialize_float(stream, cmd_data->level);
	cbor_serialize_float(stream, cmd_data->level0);
	cbor_serialize_float(stream, cmd_data->noise);

#ifdef DEBUG
	cmd_data125_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data125_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data125_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->targetId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->dopplerSpeed);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->level);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->level0);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->noise);
#ifdef DEBUG
	cmd_data125_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data129_pack(cbor_stream_t* stream, void* data) {
	cmd_data129_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data130_pack(stream, (void*)&cmd_data->marks[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data129_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data129_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data129_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data130_unpack(stream, offset, &cmd_data->marks[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data129_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data130_pack(cbor_stream_t* stream, void* data) {
	cmd_data130_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_byte_stringl(stream, cmd_data->sweepId, 32);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data125_pack(stream, (void*)&cmd_data->data[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data130_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data130_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data130_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 32) {
		return 0;
	}
	memcpy(cmd_data->sweepId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data125_unpack(stream, offset, &cmd_data->data[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data130_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data132_pack(cbor_stream_t* stream, void* data) {
	cmd_data132_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_int(stream, (int)cmd_data->beamCount);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cbor_serialize_byte_stringl(stream, &cmd_data->data, 1);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data132_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data132_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data132_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->beamCount);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->data, tmp_ptr, tmp_len);
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data132_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data135_pack(cbor_stream_t* stream, void* data) {
	cmd_data135_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cmd_data136_pack(stream, (void*)&cmd_data->data);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data135_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data135_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data135_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	if(0 == cmd_data136_unpack(stream, offset, &cmd_data->data)) {
		 return 0;
	}
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data135_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data136_pack(cbor_stream_t* stream, void* data) {
	cmd_data136_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, &cmd_data->rxMessage, 1);
	cbor_serialize_int(stream, cmd_data->rxMode);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_float(stream, cmd_data->dopplerSpeed);
	cbor_serialize_float(stream, cmd_data->dopplerSpeedStd);
	cbor_serialize_float(stream, cmd_data->distance);
	cbor_serialize_float(stream, cmd_data->distanceStd);
	cbor_serialize_float(stream, cmd_data->txTimestamp);

#ifdef DEBUG
	cmd_data136_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data136_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data136_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->rxMessage, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_int(stream, *offset, &cmd_data->rxMode);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->dopplerSpeed);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->dopplerSpeedStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->distance);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->distanceStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->txTimestamp);
#ifdef DEBUG
	cmd_data136_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data140_pack(cbor_stream_t* stream, void* data) {
	cmd_data140_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->from);
	cbor_serialize_float(stream, cmd_data->to);

#ifdef DEBUG
	cmd_data140_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data140_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data140_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->from);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->to);
#ifdef DEBUG
	cmd_data140_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data142_pack(cbor_stream_t* stream, void* data) {
	cmd_data142_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data143_pack(stream, (void*)&cmd_data->rxData[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data142_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data142_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data142_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data143_unpack(stream, offset, &cmd_data->rxData[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data142_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data143_pack(cbor_stream_t* stream, void* data) {
	cmd_data143_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cmd_data136_pack(stream, (void*)&cmd_data->data);

#ifdef DEBUG
	cmd_data143_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data143_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data143_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	if(0 == cmd_data136_unpack(stream, offset, &cmd_data->data)) {
		 return 0;
	}
#ifdef DEBUG
	cmd_data143_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data145_pack(cbor_stream_t* stream, void* data) {
	cmd_data145_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_byte_stringl(stream, &cmd_data->targetId, 1);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cmd_data146_pack(stream, (void*)&cmd_data->data);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data145_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data145_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data145_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->targetId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	if(0 == cmd_data146_unpack(stream, offset, &cmd_data->data)) {
		 return 0;
	}
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data145_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data146_pack(cbor_stream_t* stream, void* data) {
	cmd_data146_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_float(stream, cmd_data->bearingRate);
	cbor_serialize_float(stream, cmd_data->bearingRateStd);
	cbor_serialize_float(stream, cmd_data->course);
	cbor_serialize_float(stream, cmd_data->courseStd);
	cbor_serialize_float(stream, cmd_data->vRel);
	cbor_serialize_float(stream, cmd_data->vRelStd);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_pack(stream, (void*)&cmd_data->cLines[i]);
	cbor_write_break(stream);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_pack(stream, (void*)&cmd_data->pLines[i]);
	cbor_write_break(stream);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_pack(stream, (void*)&cmd_data->rpLines[i]);
	cbor_write_break(stream);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data118_pack(stream, (void*)&cmd_data->acfLines[i]);
	cbor_write_break(stream);
	cbor_serialize_float(stream, cmd_data->c1Prob);
	cbor_serialize_float(stream, cmd_data->c2Prob);
	cbor_serialize_int(stream, (int)cmd_data->class_);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data147_pack(stream, (void*)&cmd_data->frMarks[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data146_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data146_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data146_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->bearingRate);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->bearingRateStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->course);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->courseStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->vRel);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->vRelStd);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data111_unpack(stream, offset, &cmd_data->cLines[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data111_unpack(stream, offset, &cmd_data->pLines[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data111_unpack(stream, offset, &cmd_data->rpLines[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data118_unpack(stream, offset, &cmd_data->acfLines[i++])) {
			return 0;
		}
	}
	*offset += 1;
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->c1Prob);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->c2Prob);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->class_);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data147_unpack(stream, offset, &cmd_data->frMarks[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data146_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data147_pack(cbor_stream_t* stream, void* data) {
	cmd_data147_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->lowFreq);
	cbor_serialize_float(stream, cmd_data->highFreq);
	cbor_serialize_float(stream, cmd_data->snr);
	cbor_serialize_float(stream, cmd_data->width);
	cbor_serialize_float(stream, cmd_data->p0);
	cbor_serialize_float(stream, cmd_data->noise);
	cbor_serialize_float(stream, cmd_data->relativeBearing);

#ifdef DEBUG
	cmd_data147_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data147_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data147_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->lowFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->highFreq);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->snr);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->width);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->p0);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->noise);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
#ifdef DEBUG
	cmd_data147_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data151_pack(cbor_stream_t* stream, void* data) {
	cmd_data151_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<1;++i)
		cmd_data152_pack(stream, (void*)&cmd_data->targets[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data151_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data151_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data151_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 1)
			return 0;
		if(0 == cmd_data152_unpack(stream, offset, &cmd_data->targets[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data151_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data152_pack(cbor_stream_t* stream, void* data) {
	cmd_data152_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_byte_stringl(stream, &cmd_data->targetId, 1);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cmd_data146_pack(stream, (void*)&cmd_data->data);

#ifdef DEBUG
	cmd_data152_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data152_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data152_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->targetId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	if(0 == cmd_data146_unpack(stream, offset, &cmd_data->data)) {
		 return 0;
	}
#ifdef DEBUG
	cmd_data152_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data154_pack(cbor_stream_t* stream, void* data) {
	cmd_data154_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_byte_stringl(stream, &cmd_data->targetId, 1);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cmd_data155_pack(stream, (void*)&cmd_data->data);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data154_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data154_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data154_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->targetId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	if(0 == cmd_data155_unpack(stream, offset, &cmd_data->data)) {
		 return 0;
	}
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data154_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data155_pack(cbor_stream_t* stream, void* data) {
	cmd_data155_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_float(stream, cmd_data->distance);
	cbor_serialize_float(stream, cmd_data->distanceStd);
	cbor_serialize_float(stream, cmd_data->course);
	cbor_serialize_float(stream, cmd_data->courseStd);
	cbor_serialize_float(stream, cmd_data->velocity);
	cbor_serialize_float(stream, cmd_data->velocityStd);
	cbor_serialize_float(stream, cmd_data->c1Prob);
	cbor_serialize_float(stream, cmd_data->c2Prob);
	cbor_serialize_int(stream, (int)cmd_data->class_);
	cmd_data156_pack(stream, (void*)&cmd_data->mark);

#ifdef DEBUG
	cmd_data155_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data155_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data155_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->distance);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->distanceStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->course);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->courseStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->velocity);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->velocityStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->c1Prob);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->c2Prob);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->class_);
	if(0 == cmd_data156_unpack(stream, offset, &cmd_data->mark)) {
		 return 0;
	}
#ifdef DEBUG
	cmd_data155_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data156_pack(cbor_stream_t* stream, void* data) {
	cmd_data156_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->sweepId, 32);
	cbor_serialize_float(stream, cmd_data->relativeBearing);
	cbor_serialize_float(stream, cmd_data->relativeBearingStd);
	cbor_serialize_float(stream, cmd_data->distance);
	cbor_serialize_float(stream, cmd_data->distanceStd);
	cbor_serialize_float(stream, cmd_data->dopplerSpeed);
	cbor_serialize_float(stream, cmd_data->dopplerSpeedStd);
	cbor_serialize_float(stream, cmd_data->snr);
	cbor_serialize_float(stream, cmd_data->snr0);
	cbor_serialize_float(stream, cmd_data->noise);

#ifdef DEBUG
	cmd_data156_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data156_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data156_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 32) {
		return 0;
	}
	memcpy(cmd_data->sweepId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearing);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->relativeBearingStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->distance);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->distanceStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->dopplerSpeed);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->dopplerSpeedStd);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->snr);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->snr0);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->noise);
#ifdef DEBUG
	cmd_data156_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data160_pack(cbor_stream_t* stream, void* data) {
	cmd_data160_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<1;++i)
		cmd_data161_pack(stream, (void*)&cmd_data->targets[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data160_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data160_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data160_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 1)
			return 0;
		if(0 == cmd_data161_unpack(stream, offset, &cmd_data->targets[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data160_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data161_pack(cbor_stream_t* stream, void* data) {
	cmd_data161_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_byte_stringl(stream, &cmd_data->targetId, 1);
	cbor_serialize_float(stream, cmd_data->heading);
	cbor_serialize_float(stream, cmd_data->headingStd);
	cmd_data155_pack(stream, (void*)&cmd_data->data);

#ifdef DEBUG
	cmd_data161_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data161_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data161_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->targetId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->heading);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->headingStd);
	if(0 == cmd_data155_unpack(stream, offset, &cmd_data->data)) {
		 return 0;
	}
#ifdef DEBUG
	cmd_data161_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data163_pack(cbor_stream_t* stream, void* data) {
	cmd_data163_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<1;++i)
		cmd_data165_pack(stream, (void*)&cmd_data->stream_id[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data163_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data163_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data163_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 1)
			return 0;
		if(0 == cmd_data165_unpack(stream, offset, &cmd_data->stream_id[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data163_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data165_pack(cbor_stream_t* stream, void* data) {
	cmd_data165_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->baseURL, 2048);
	cbor_serialize_int(stream, (int)cmd_data->interval);
	cbor_serialize_byte_stringl(stream, &cmd_data->targetId, 1);
	cbor_serialize_int(stream, (int)cmd_data->attChannelId);

#ifdef DEBUG
	cmd_data165_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data165_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data165_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 2048) {
		return 0;
	}
	memcpy(cmd_data->baseURL, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->interval);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->targetId, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->attChannelId);
#ifdef DEBUG
	cmd_data165_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data168_pack(cbor_stream_t* stream, void* data) {
	cmd_data168_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<1;++i)
		cmd_data165_pack(stream, (void*)&cmd_data->stream_id[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data168_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data168_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data168_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 1)
			return 0;
		if(0 == cmd_data165_unpack(stream, offset, &cmd_data->stream_id[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data168_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data172_pack(cbor_stream_t* stream, void* data) {
	cmd_data172_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<1;++i)
		cmd_data165_pack(stream, (void*)&cmd_data->stream_id[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data172_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data172_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data172_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= 1)
			return 0;
		if(0 == cmd_data165_unpack(stream, offset, &cmd_data->stream_id[i++])) {
			return 0;
		}
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data172_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data174_pack(cbor_stream_t* stream, void* data) {
	cmd_data174_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->streamId);
	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cmd_data175_pack(stream, (void*)&cmd_data->data);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data174_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data174_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data174_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->streamId);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	if(0 == cmd_data175_unpack(stream, offset, &cmd_data->data)) {
		 return 0;
	}
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data174_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data175_pack(cbor_stream_t* stream, void* data) {
	cmd_data175_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cmd_data176_pack(stream, (void*)&cmd_data->hsmDiag);
	cmd_data177_pack(stream, (void*)&cmd_data->rxAntennaDiag);
	cmd_data178_pack(stream, (void*)&cmd_data->txAntennaDiag);
	cmd_data179_pack(stream, (void*)&cmd_data->utcsDiag);
	cmd_data180_pack(stream, (void*)&cmd_data->satcomDiag);
	cmd_data181_pack(stream, (void*)&cmd_data->batteryDiag);
	cmd_data182_pack(stream, (void*)&cmd_data->foclDiag);
	cmd_data183_pack(stream, (void*)&cmd_data->hpsDiag);
	cbor_serialize_int(stream, (int)cmd_data->generalFault);
	cbor_serialize_int(stream, (int)cmd_data->offlineMode);
	cbor_serialize_int(stream, (int)cmd_data->uptime);

#ifdef DEBUG
	cmd_data175_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data175_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data175_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	if(0 == cmd_data176_unpack(stream, offset, &cmd_data->hsmDiag)) {
		 return 0;
	}
	if(0 == cmd_data177_unpack(stream, offset, &cmd_data->rxAntennaDiag)) {
		 return 0;
	}
	if(0 == cmd_data178_unpack(stream, offset, &cmd_data->txAntennaDiag)) {
		 return 0;
	}
	if(0 == cmd_data179_unpack(stream, offset, &cmd_data->utcsDiag)) {
		 return 0;
	}
	if(0 == cmd_data180_unpack(stream, offset, &cmd_data->satcomDiag)) {
		 return 0;
	}
	if(0 == cmd_data181_unpack(stream, offset, &cmd_data->batteryDiag)) {
		 return 0;
	}
	if(0 == cmd_data182_unpack(stream, offset, &cmd_data->foclDiag)) {
		 return 0;
	}
	if(0 == cmd_data183_unpack(stream, offset, &cmd_data->hpsDiag)) {
		 return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->generalFault);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->offlineMode);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->uptime);
#ifdef DEBUG
	cmd_data175_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data176_pack(cbor_stream_t* stream, void* data) {
	cmd_data176_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->fwFault);
	cbor_serialize_float(stream, cmd_data->compassFault);
	cbor_serialize_int(stream, (int)cmd_data->waterAlarm);
	cbor_serialize_float(stream, cmd_data->tsErrorStd);

#ifdef DEBUG
	cmd_data176_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data176_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data176_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->fwFault);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->compassFault);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->waterAlarm);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->tsErrorStd);
#ifdef DEBUG
	cmd_data176_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data177_pack(cbor_stream_t* stream, void* data) {
	cmd_data177_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->generalFault);
	cbor_serialize_float(stream, cmd_data->radius);
	cbor_serialize_int(stream, (int)cmd_data->waterAlarm);

#ifdef DEBUG
	cmd_data177_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data177_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data177_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->generalFault);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->radius);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->waterAlarm);
#ifdef DEBUG
	cmd_data177_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data178_pack(cbor_stream_t* stream, void* data) {
	cmd_data178_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->generalFault);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		cbor_serialize_int(stream, (int)cmd_data->faultySectors[i]);
	cbor_write_break(stream);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		cbor_serialize_int(stream, (int)cmd_data->drainedSectors[i]);
	cbor_write_break(stream);
	cbor_serialize_int(stream, (int)cmd_data->waterAlarm);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		cbor_serialize_int(stream, (int)cmd_data->sectorWaterAlarms[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data178_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data178_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data178_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->generalFault);
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= IGA_COUNT_MAX)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->faultySectors[i++]);
	}
	*offset += 1;
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= IGA_COUNT_MAX)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->drainedSectors[i++]);
	}
	*offset += 1;
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->waterAlarm);
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= IGA_COUNT_MAX)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->sectorWaterAlarms[i++]);
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data178_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data179_pack(cbor_stream_t* stream, void* data) {
	cmd_data179_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->txFault);
	cbor_serialize_int(stream, (int)cmd_data->rxFault);

#ifdef DEBUG
	cmd_data179_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data179_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data179_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->txFault);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->rxFault);
#ifdef DEBUG
	cmd_data179_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data180_pack(cbor_stream_t* stream, void* data) {
	cmd_data180_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->generalFault);
	cbor_serialize_int(stream, (int)cmd_data->waterAlarm);

#ifdef DEBUG
	cmd_data180_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data180_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data180_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->generalFault);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->waterAlarm);
#ifdef DEBUG
	cmd_data180_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data181_pack(cbor_stream_t* stream, void* data) {
	cmd_data181_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->generalFault);

#ifdef DEBUG
	cmd_data181_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data181_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data181_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->generalFault);
#ifdef DEBUG
	cmd_data181_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data182_pack(cbor_stream_t* stream, void* data) {
	cmd_data182_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->powerFault);
	cbor_serialize_int(stream, (int)cmd_data->connFault);

#ifdef DEBUG
	cmd_data182_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data182_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data182_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->powerFault);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->connFault);
#ifdef DEBUG
	cmd_data182_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data183_pack(cbor_stream_t* stream, void* data) {
	cmd_data183_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cbor_serialize_int(stream, (int)cmd_data->faultyTempSensors[i]);
	cbor_write_break(stream);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cbor_serialize_int(stream, (int)cmd_data->faultyPressureSensors[i]);
	cbor_write_break(stream);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cbor_serialize_int(stream, (int)cmd_data->faultySVSensors[i]);
	cbor_write_break(stream);

#ifdef DEBUG
	cmd_data183_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data183_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data183_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->faultyTempSensors[i++]);
	}
	*offset += 1;
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->faultyPressureSensors[i++]);
	}
	*offset += 1;
	i = 0;
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->faultySVSensors[i++]);
	}
	*offset += 1;
#ifdef DEBUG
	cmd_data183_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data187_pack(cbor_stream_t* stream, void* data) {
	cmd_data187_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cmd_data175_pack(stream, (void*)&cmd_data->data);

#ifdef DEBUG
	cmd_data187_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data187_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data187_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	if(0 == cmd_data175_unpack(stream, offset, &cmd_data->data)) {
		 return 0;
	}
#ifdef DEBUG
	cmd_data187_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data189_pack(cbor_stream_t* stream, void* data) {
	cmd_data189_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_float(stream, cmd_data->minDepth);
	cbor_serialize_byte_stringl(stream, cmd_data->reportURL, 2048);

#ifdef DEBUG
	cmd_data189_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data189_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data189_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->minDepth);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 2048) {
		return 0;
	}
	memcpy(cmd_data->reportURL, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data189_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data191_pack(cbor_stream_t* stream, void* data) {
	cmd_data191_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->timestamp);
	cbor_serialize_array_indefinite(stream);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data192_pack(stream, (void*)&cmd_data->data[i]);
	cbor_write_break(stream);
	cmd_data0_pack(stream, (void*)&cmd_data->serviceData);
	cbor_serialize_byte_stringl(stream, &cmd_data->stationId, 1);

#ifdef DEBUG
	cmd_data191_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data191_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data191_t* cmd_data = data;
	size_t i=0;

	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->timestamp);
	*offset += cbor_deserialize_array_indefinite(stream, *offset);
	i = 0;
	while (!cbor_at_break(stream, *offset)) {
		if(i >= UNDEFINED_SIZE)
			return 0;
		if(0 == cmd_data192_unpack(stream, offset, &cmd_data->data[i++])) {
			return 0;
		}
	}
	*offset += 1;
	if(0 == cmd_data0_unpack(stream, offset, &cmd_data->serviceData)) {
		 return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 1) {
		return 0;
	}
	memcpy(&cmd_data->stationId, tmp_ptr, tmp_len);
#ifdef DEBUG
	cmd_data191_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data192_pack(cbor_stream_t* stream, void* data) {
	cmd_data192_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_int(stream, (int)cmd_data->sensorsId);
	cbor_serialize_float(stream, cmd_data->pressure);
	cbor_serialize_float(stream, cmd_data->temperature);
	cbor_serialize_float(stream, cmd_data->soundVelocity);

#ifdef DEBUG
	cmd_data192_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data192_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data192_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->sensorsId);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->pressure);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->temperature);
	*offset += cbor_deserialize_float(stream, *offset, &cmd_data->soundVelocity);
#ifdef DEBUG
	cmd_data192_print(cmd_data);
#endif

	return *offset;
}

int
cmd_data194_pack(cbor_stream_t* stream, void* data) {
	cmd_data194_t* cmd_data = data;
	if(!stream) {
		return 0;
	}

	cbor_serialize_byte_stringl(stream, cmd_data->cookie, 64);
	cbor_serialize_byte_stringl(stream, cmd_data->cookieSHA1, 20);
	cbor_serialize_int(stream, (int)cmd_data->offlineMode);

#ifdef DEBUG
	cmd_data194_print(cmd_data);
#endif

	return stream->pos;
}

int
cmd_data194_unpack(cbor_stream_t* stream, size_t* offset, void* data) {
	cmd_data194_t* cmd_data = data;
	if(!stream) {
		return 0;
	}
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 64) {
		return 0;
	}
	memcpy(cmd_data->cookie, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_byte_string_no_copy(stream, *offset, &tmp_ptr, &tmp_len);
	if(tmp_len > 20) {
		return 0;
	}
	memcpy(cmd_data->cookieSHA1, tmp_ptr, tmp_len);
	*offset += cbor_deserialize_int(stream, *offset, (int*)&cmd_data->offlineMode);
#ifdef DEBUG
	cmd_data194_print(cmd_data);
#endif

	return *offset;
}


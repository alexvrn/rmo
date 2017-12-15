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

int
cmd_data0_rnd(cmd_data0_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<32;++i)
		RANDOM(&cmd_data->data[i], sizeof(char));

	return 0;

}

int
cmd_data2_rnd(cmd_data2_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<64;++i)
		RANDOM(&cmd_data->cookie[i], sizeof(char));
	for(int i=0; i<20;++i)
		RANDOM(&cmd_data->cookieSHA1[i], sizeof(char));

	return 0;

}

int
cmd_data5_rnd(cmd_data5_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<64;++i)
		RANDOM(&cmd_data->cookie[i], sizeof(char));
	for(int i=0; i<20;++i)
		RANDOM(&cmd_data->cookieSHA1[i], sizeof(char));

	return 0;

}

int
cmd_data8_rnd(cmd_data8_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<64;++i)
		RANDOM(&cmd_data->cookie[i], sizeof(char));
	for(int i=0; i<20;++i)
		RANDOM(&cmd_data->cookieSHA1[i], sizeof(char));
	for(int i=0; i<2048;++i)
		RANDOM(&cmd_data->reportURL[i], sizeof(char));

	return 0;

}

int
cmd_data10_rnd(cmd_data10_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	cmd_data175_rnd(&cmd_data->diagData);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data12_rnd(cmd_data12_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<64;++i)
		RANDOM(&cmd_data->cookie[i], sizeof(char));
	for(int i=0; i<20;++i)
		RANDOM(&cmd_data->cookieSHA1[i], sizeof(char));
	RANDOM(&cmd_data->image, sizeof(char));

	return 0;

}

int
cmd_data16_rnd(cmd_data16_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<20;++i)
		RANDOM(&cmd_data->sha1[i], sizeof(char));

	return 0;

}

int
cmd_data19_rnd(cmd_data19_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));

	return 0;

}

int
cmd_data21_rnd(cmd_data21_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->datetime, sizeof(float));

	return 0;

}

int
cmd_data24_rnd(cmd_data24_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<PGA_COUNT_MAX;++i)
		RANDOM(&cmd_data->defectiveColumns[i], sizeof(unsigned));

	return 0;

}

int
cmd_data28_rnd(cmd_data28_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<PGA_COUNT_MAX;++i)
		RANDOM(&cmd_data->defectiveColumns[i], sizeof(unsigned));

	return 0;

}

int
cmd_data30_rnd(cmd_data30_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	cmd_data31_rnd(&cmd_data->beta);
	for(int i=0; i<24;++i)
		cmd_data32_rnd(&cmd_data->soundVelocity[i]);
	RANDOM(&cmd_data->multipathTimeCoef, sizeof(float));

	return 0;

}

int
cmd_data31_rnd(cmd_data31_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->b0, sizeof(float));
	RANDOM(&cmd_data->b1, sizeof(float));
	RANDOM(&cmd_data->b2, sizeof(float));

	return 0;

}

int
cmd_data32_rnd(cmd_data32_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->toHour, sizeof(unsigned));
	RANDOM(&cmd_data->sv, sizeof(float));

	return 0;

}

int
cmd_data36_rnd(cmd_data36_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	cmd_data31_rnd(&cmd_data->beta);
	for(int i=0; i<24;++i)
		cmd_data32_rnd(&cmd_data->soundVelocity[i]);
	RANDOM(&cmd_data->multipathTimeCoef, sizeof(float));

	return 0;

}

int
cmd_data38_rnd(cmd_data38_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<200;++i)
		cmd_data39_rnd(&cmd_data->schedule[i]);
	RANDOM(&cmd_data->cutOff, sizeof(float));

	return 0;

}

int
cmd_data39_rnd(cmd_data39_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<32;++i)
		RANDOM(&cmd_data->sweepId[i], sizeof(char));
	RANDOM(&cmd_data->emissionTimestamp, sizeof(float));
	RANDOM(&cmd_data->code, sizeof(unsigned));
	RANDOM(&cmd_data->range, sizeof(float));
	RANDOM(&cmd_data->emitterBearing, sizeof(float));
	RANDOM(&cmd_data->emitterDistance, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		RANDOM(&cmd_data->emissionSectors[i], sizeof(unsigned));
	RANDOM(&cmd_data->emissionLevel, sizeof(float));
	cmd_data40_rnd(&cmd_data->procParams);
	RANDOM(&cmd_data->detectionDelay, sizeof(float));
	RANDOM(&cmd_data->emitterRelativeBearing, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		RANDOM(&cmd_data->emissionRelativeSectors[i], sizeof(unsigned));

	return 0;

}

int
cmd_data40_rnd(cmd_data40_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->targetThreshold, sizeof(float));
	RANDOM(&cmd_data->markThreshold, sizeof(float));
	RANDOM(&cmd_data->reverbShift, sizeof(float));
	RANDOM(&cmd_data->reverbWidening, sizeof(float));

	return 0;

}

int
cmd_data43_rnd(cmd_data43_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<200;++i)
		cmd_data39_rnd(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data47_rnd(cmd_data47_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<200;++i)
		cmd_data39_rnd(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data49_rnd(cmd_data49_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<50;++i)
		cmd_data50_rnd(&cmd_data->schedule[i]);
	RANDOM(&cmd_data->cutOff, sizeof(float));

	return 0;

}

int
cmd_data50_rnd(cmd_data50_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<32;++i)
		RANDOM(&cmd_data->msgId[i], sizeof(char));
	RANDOM(&cmd_data->txTimestamp, sizeof(float));
	for(int i=0; i<IGA_COUNT_MAX;++i)
		RANDOM(&cmd_data->txSectors[i], sizeof(unsigned));
	RANDOM(&cmd_data->txLevel, sizeof(float));
	RANDOM(&cmd_data->txMode, sizeof(int));
	RANDOM(&cmd_data->txData, sizeof(char));
	for(int i=0; i<IGA_COUNT_MAX;++i)
		RANDOM(&cmd_data->txRelativeSectors[i], sizeof(unsigned));

	return 0;

}

int
cmd_data54_rnd(cmd_data54_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<50;++i)
		cmd_data50_rnd(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data58_rnd(cmd_data58_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<50;++i)
		cmd_data50_rnd(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data60_rnd(cmd_data60_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<200;++i)
		cmd_data61_rnd(&cmd_data->schedule[i]);
	RANDOM(&cmd_data->cutOff, sizeof(float));

	return 0;

}

int
cmd_data61_rnd(cmd_data61_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->to, sizeof(float));

	return 0;

}

int
cmd_data65_rnd(cmd_data65_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<200;++i)
		cmd_data61_rnd(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data69_rnd(cmd_data69_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<200;++i)
		cmd_data61_rnd(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data71_rnd(cmd_data71_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->targetThreshold, sizeof(float));
	for(int i=0; i<2;++i)
		RANDOM(&cmd_data->detectionRule[i], sizeof(unsigned));

	return 0;

}

int
cmd_data78_rnd(cmd_data78_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->bearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->autoTracking, sizeof(unsigned));
	RANDOM(&cmd_data->targetId, sizeof(char));

	return 0;

}

int
cmd_data82_rnd(cmd_data82_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->autoTracking, sizeof(unsigned));
	RANDOM(&cmd_data->Heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));

	return 0;

}

int
cmd_data86_rnd(cmd_data86_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->coefCount, sizeof(unsigned));
	RANDOM(&cmd_data->elemCount, sizeof(unsigned));
	RANDOM(&cmd_data->lowFreq, sizeof(float));
	RANDOM(&cmd_data->highFreq, sizeof(float));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	RANDOM(&cmd_data->data, sizeof(char));
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data89_rnd(cmd_data89_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->coefCount, sizeof(unsigned));
	RANDOM(&cmd_data->beamCount, sizeof(unsigned));
	RANDOM(&cmd_data->lowFreq, sizeof(float));
	RANDOM(&cmd_data->highFreq, sizeof(float));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	RANDOM(&cmd_data->data, sizeof(char));
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data92_rnd(cmd_data92_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->beamCount, sizeof(unsigned));
	RANDOM(&cmd_data->lowFreq, sizeof(float));
	RANDOM(&cmd_data->highFreq, sizeof(float));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	RANDOM(&cmd_data->data, sizeof(float));
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data95_rnd(cmd_data95_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->lowFreq, sizeof(float));
	RANDOM(&cmd_data->highFreq, sizeof(float));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data96_rnd(&cmd_data->data[i]);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data96_rnd(cmd_data96_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->targetId, sizeof(char));
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->width, sizeof(float));
	RANDOM(&cmd_data->level, sizeof(float));
	RANDOM(&cmd_data->noise, sizeof(float));

	return 0;

}

int
cmd_data99_rnd(cmd_data99_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->from, sizeof(float));
	RANDOM(&cmd_data->to, sizeof(float));

	return 0;

}

int
cmd_data101_rnd(cmd_data101_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data102_rnd(&cmd_data->marks[i]);

	return 0;

}

int
cmd_data102_rnd(cmd_data102_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data96_rnd(&cmd_data->data[i]);

	return 0;

}

int
cmd_data104_rnd(cmd_data104_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->sampleCount, sizeof(unsigned));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	RANDOM(&cmd_data->data, sizeof(char));
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data107_rnd(cmd_data107_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->coefCount, sizeof(unsigned));
	RANDOM(&cmd_data->lowFreq, sizeof(float));
	RANDOM(&cmd_data->highFreq, sizeof(float));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	RANDOM(&cmd_data->data, sizeof(char));
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data110_rnd(cmd_data110_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_rnd(&cmd_data->data[i]);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data111_rnd(cmd_data111_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->frequency, sizeof(float));
	RANDOM(&cmd_data->level, sizeof(float));

	return 0;

}

int
cmd_data114_rnd(cmd_data114_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->sampleCount, sizeof(unsigned));
	RANDOM(&cmd_data->minShift, sizeof(float));
	RANDOM(&cmd_data->maxShift, sizeof(float));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	RANDOM(&cmd_data->data, sizeof(char));
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data117_rnd(cmd_data117_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data118_rnd(&cmd_data->data[i]);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data118_rnd(cmd_data118_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->shift, sizeof(float));
	RANDOM(&cmd_data->level, sizeof(float));

	return 0;

}

int
cmd_data121_rnd(cmd_data121_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	for(int i=0; i<32;++i)
		RANDOM(&cmd_data->sweepId[i], sizeof(char));
	RANDOM(&cmd_data->dopplerAltCount, sizeof(unsigned));
	RANDOM(&cmd_data->beamCount, sizeof(unsigned));
	RANDOM(&cmd_data->dopplerRange, sizeof(float));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));

	return 0;

}

int
cmd_data124_rnd(cmd_data124_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	for(int i=0; i<32;++i)
		RANDOM(&cmd_data->sweepId[i], sizeof(char));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data125_rnd(&cmd_data->data[i]);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data125_rnd(cmd_data125_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->targetId, sizeof(char));
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->dopplerSpeed, sizeof(float));
	RANDOM(&cmd_data->level, sizeof(float));
	RANDOM(&cmd_data->level0, sizeof(float));
	RANDOM(&cmd_data->noise, sizeof(float));

	return 0;

}

int
cmd_data129_rnd(cmd_data129_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data130_rnd(&cmd_data->marks[i]);

	return 0;

}

int
cmd_data130_rnd(cmd_data130_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	for(int i=0; i<32;++i)
		RANDOM(&cmd_data->sweepId[i], sizeof(char));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data125_rnd(&cmd_data->data[i]);

	return 0;

}

int
cmd_data132_rnd(cmd_data132_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->beamCount, sizeof(unsigned));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	RANDOM(&cmd_data->data, sizeof(char));
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data135_rnd(cmd_data135_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	cmd_data136_rnd(&cmd_data->data);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data136_rnd(cmd_data136_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->rxMessage, sizeof(char));
	RANDOM(&cmd_data->rxMode, sizeof(int));
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->dopplerSpeed, sizeof(float));
	RANDOM(&cmd_data->dopplerSpeedStd, sizeof(float));
	RANDOM(&cmd_data->distance, sizeof(float));
	RANDOM(&cmd_data->distanceStd, sizeof(float));
	RANDOM(&cmd_data->txTimestamp, sizeof(float));

	return 0;

}

int
cmd_data140_rnd(cmd_data140_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->from, sizeof(float));
	RANDOM(&cmd_data->to, sizeof(float));

	return 0;

}

int
cmd_data142_rnd(cmd_data142_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data143_rnd(&cmd_data->rxData[i]);

	return 0;

}

int
cmd_data143_rnd(cmd_data143_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	cmd_data136_rnd(&cmd_data->data);

	return 0;

}

int
cmd_data145_rnd(cmd_data145_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->targetId, sizeof(char));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	cmd_data146_rnd(&cmd_data->data);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data146_rnd(cmd_data146_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->bearingRate, sizeof(float));
	RANDOM(&cmd_data->bearingRateStd, sizeof(float));
	RANDOM(&cmd_data->course, sizeof(float));
	RANDOM(&cmd_data->courseStd, sizeof(float));
	RANDOM(&cmd_data->vRel, sizeof(float));
	RANDOM(&cmd_data->vRelStd, sizeof(float));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_rnd(&cmd_data->cLines[i]);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_rnd(&cmd_data->pLines[i]);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_rnd(&cmd_data->rpLines[i]);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data118_rnd(&cmd_data->acfLines[i]);
	RANDOM(&cmd_data->c1Prob, sizeof(float));
	RANDOM(&cmd_data->c2Prob, sizeof(float));
	RANDOM(&cmd_data->class_, sizeof(unsigned));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data147_rnd(&cmd_data->frMarks[i]);

	return 0;

}

int
cmd_data147_rnd(cmd_data147_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->lowFreq, sizeof(float));
	RANDOM(&cmd_data->highFreq, sizeof(float));
	RANDOM(&cmd_data->snr, sizeof(float));
	RANDOM(&cmd_data->width, sizeof(float));
	RANDOM(&cmd_data->p0, sizeof(float));
	RANDOM(&cmd_data->noise, sizeof(float));
	RANDOM(&cmd_data->relativeBearing, sizeof(float));

	return 0;

}

int
cmd_data151_rnd(cmd_data151_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<1;++i)
		cmd_data152_rnd(&cmd_data->targets[i]);

	return 0;

}

int
cmd_data152_rnd(cmd_data152_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->targetId, sizeof(char));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	cmd_data146_rnd(&cmd_data->data);

	return 0;

}

int
cmd_data154_rnd(cmd_data154_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->targetId, sizeof(char));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	cmd_data155_rnd(&cmd_data->data);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data155_rnd(cmd_data155_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->distance, sizeof(float));
	RANDOM(&cmd_data->distanceStd, sizeof(float));
	RANDOM(&cmd_data->course, sizeof(float));
	RANDOM(&cmd_data->courseStd, sizeof(float));
	RANDOM(&cmd_data->velocity, sizeof(float));
	RANDOM(&cmd_data->velocityStd, sizeof(float));
	RANDOM(&cmd_data->c1Prob, sizeof(float));
	RANDOM(&cmd_data->c2Prob, sizeof(float));
	RANDOM(&cmd_data->class_, sizeof(unsigned));
	cmd_data156_rnd(&cmd_data->mark);

	return 0;

}

int
cmd_data156_rnd(cmd_data156_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<32;++i)
		RANDOM(&cmd_data->sweepId[i], sizeof(char));
	RANDOM(&cmd_data->relativeBearing, sizeof(float));
	RANDOM(&cmd_data->relativeBearingStd, sizeof(float));
	RANDOM(&cmd_data->distance, sizeof(float));
	RANDOM(&cmd_data->distanceStd, sizeof(float));
	RANDOM(&cmd_data->dopplerSpeed, sizeof(float));
	RANDOM(&cmd_data->dopplerSpeedStd, sizeof(float));
	RANDOM(&cmd_data->snr, sizeof(float));
	RANDOM(&cmd_data->snr0, sizeof(float));
	RANDOM(&cmd_data->noise, sizeof(float));

	return 0;

}

int
cmd_data160_rnd(cmd_data160_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<1;++i)
		cmd_data161_rnd(&cmd_data->targets[i]);

	return 0;

}

int
cmd_data161_rnd(cmd_data161_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	RANDOM(&cmd_data->targetId, sizeof(char));
	RANDOM(&cmd_data->heading, sizeof(float));
	RANDOM(&cmd_data->headingStd, sizeof(float));
	cmd_data155_rnd(&cmd_data->data);

	return 0;

}

int
cmd_data163_rnd(cmd_data163_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<1;++i)
		cmd_data165_rnd(&cmd_data->stream_id[i]);

	return 0;

}

int
cmd_data165_rnd(cmd_data165_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<2048;++i)
		RANDOM(&cmd_data->baseURL[i], sizeof(char));
	RANDOM(&cmd_data->interval, sizeof(unsigned));
	RANDOM(&cmd_data->targetId, sizeof(char));
	RANDOM(&cmd_data->attChannelId, sizeof(unsigned));

	return 0;

}

int
cmd_data168_rnd(cmd_data168_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<1;++i)
		cmd_data165_rnd(&cmd_data->stream_id[i]);

	return 0;

}

int
cmd_data172_rnd(cmd_data172_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<1;++i)
		cmd_data165_rnd(&cmd_data->stream_id[i]);

	return 0;

}

int
cmd_data174_rnd(cmd_data174_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->streamId, sizeof(unsigned));
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	cmd_data175_rnd(&cmd_data->data);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data175_rnd(cmd_data175_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	cmd_data176_rnd(&cmd_data->hsmDiag);
	cmd_data177_rnd(&cmd_data->rxAntennaDiag);
	cmd_data178_rnd(&cmd_data->txAntennaDiag);
	cmd_data179_rnd(&cmd_data->utcsDiag);
	cmd_data180_rnd(&cmd_data->satcomDiag);
	cmd_data181_rnd(&cmd_data->batteryDiag);
	cmd_data182_rnd(&cmd_data->foclDiag);
	cmd_data183_rnd(&cmd_data->hpsDiag);
	RANDOM(&cmd_data->generalFault, sizeof(unsigned));
	RANDOM(&cmd_data->offlineMode, sizeof(unsigned));
	RANDOM(&cmd_data->uptime, sizeof(unsigned));

	return 0;

}

int
cmd_data176_rnd(cmd_data176_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->fwFault, sizeof(unsigned));
	RANDOM(&cmd_data->compassFault, sizeof(float));
	RANDOM(&cmd_data->waterAlarm, sizeof(unsigned));
	RANDOM(&cmd_data->tsErrorStd, sizeof(float));

	return 0;

}

int
cmd_data177_rnd(cmd_data177_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->generalFault, sizeof(unsigned));
	RANDOM(&cmd_data->radius, sizeof(float));
	RANDOM(&cmd_data->waterAlarm, sizeof(unsigned));

	return 0;

}

int
cmd_data178_rnd(cmd_data178_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->generalFault, sizeof(unsigned));
	for(int i=0; i<IGA_COUNT_MAX;++i)
		RANDOM(&cmd_data->faultySectors[i], sizeof(unsigned));
	for(int i=0; i<IGA_COUNT_MAX;++i)
		RANDOM(&cmd_data->drainedSectors[i], sizeof(unsigned));
	RANDOM(&cmd_data->waterAlarm, sizeof(unsigned));
	for(int i=0; i<IGA_COUNT_MAX;++i)
		RANDOM(&cmd_data->sectorWaterAlarms[i], sizeof(unsigned));

	return 0;

}

int
cmd_data179_rnd(cmd_data179_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->txFault, sizeof(unsigned));
	RANDOM(&cmd_data->rxFault, sizeof(unsigned));

	return 0;

}

int
cmd_data180_rnd(cmd_data180_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->generalFault, sizeof(unsigned));
	RANDOM(&cmd_data->waterAlarm, sizeof(unsigned));

	return 0;

}

int
cmd_data181_rnd(cmd_data181_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->generalFault, sizeof(unsigned));

	return 0;

}

int
cmd_data182_rnd(cmd_data182_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->powerFault, sizeof(unsigned));
	RANDOM(&cmd_data->connFault, sizeof(unsigned));

	return 0;

}

int
cmd_data183_rnd(cmd_data183_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<UNDEFINED_SIZE;++i)
		RANDOM(&cmd_data->faultyTempSensors[i], sizeof(unsigned));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		RANDOM(&cmd_data->faultyPressureSensors[i], sizeof(unsigned));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		RANDOM(&cmd_data->faultySVSensors[i], sizeof(unsigned));

	return 0;

}

int
cmd_data187_rnd(cmd_data187_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	cmd_data175_rnd(&cmd_data->data);

	return 0;

}

int
cmd_data189_rnd(cmd_data189_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->minDepth, sizeof(float));
	for(int i=0; i<2048;++i)
		RANDOM(&cmd_data->reportURL[i], sizeof(char));

	return 0;

}

int
cmd_data191_rnd(cmd_data191_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->timestamp, sizeof(unsigned));
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data192_rnd(&cmd_data->data[i]);
	cmd_data0_rnd(&cmd_data->serviceData);
	RANDOM(&cmd_data->stationId, sizeof(char));

	return 0;

}

int
cmd_data192_rnd(cmd_data192_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	RANDOM(&cmd_data->sensorsId, sizeof(unsigned));
	RANDOM(&cmd_data->pressure, sizeof(float));
	RANDOM(&cmd_data->temperature, sizeof(float));
	RANDOM(&cmd_data->soundVelocity, sizeof(float));

	return 0;

}

int
cmd_data194_rnd(cmd_data194_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	for(int i=0; i<64;++i)
		RANDOM(&cmd_data->cookie[i], sizeof(char));
	for(int i=0; i<20;++i)
		RANDOM(&cmd_data->cookieSHA1[i], sizeof(char));
	RANDOM(&cmd_data->offlineMode, sizeof(unsigned));

	return 0;

}


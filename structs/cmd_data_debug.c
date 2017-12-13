/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-13 16:19:47
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
cmd_data0_print(cmd_data0_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data0:\n");
	for(int i=0; i<1024;++i)
		printf("data: %d\n", cmd_data->data[i]);

	return 0;

}

int
cmd_data2_print(cmd_data2_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data2:\n");
	for(int i=0; i<64;++i)
		printf("cookie: %d\n", cmd_data->cookie[i]);
	for(int i=0; i<20;++i)
		printf("cookieSHA1: %d\n", cmd_data->cookieSHA1[i]);

	return 0;

}

int
cmd_data5_print(cmd_data5_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data5:\n");
	for(int i=0; i<64;++i)
		printf("cookie: %d\n", cmd_data->cookie[i]);
	for(int i=0; i<20;++i)
		printf("cookieSHA1: %d\n", cmd_data->cookieSHA1[i]);

	return 0;

}

int
cmd_data8_print(cmd_data8_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data8:\n");
	for(int i=0; i<64;++i)
		printf("cookie: %d\n", cmd_data->cookie[i]);
	for(int i=0; i<20;++i)
		printf("cookieSHA1: %d\n", cmd_data->cookieSHA1[i]);
	for(int i=0; i<2048;++i)
		printf("reportURL: %d\n", cmd_data->reportURL[i]);

	return 0;

}

int
cmd_data10_print(cmd_data10_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data10:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	cmd_data175_print(&cmd_data->diagData);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data12_print(cmd_data12_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data12:\n");
	for(int i=0; i<64;++i)
		printf("cookie: %d\n", cmd_data->cookie[i]);
	for(int i=0; i<20;++i)
		printf("cookieSHA1: %d\n", cmd_data->cookieSHA1[i]);
	printf("image: %d\n", cmd_data->image);

	return 0;

}

int
cmd_data16_print(cmd_data16_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data16:\n");
	for(int i=0; i<20;++i)
		printf("sha1: %d\n", cmd_data->sha1[i]);

	return 0;

}

int
cmd_data19_print(cmd_data19_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data19:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);

	return 0;

}

int
cmd_data21_print(cmd_data21_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data21:\n");
	printf("datetime: %f\n", cmd_data->datetime);

	return 0;

}

int
cmd_data24_print(cmd_data24_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data24:\n");
	for(int i=0; i<PGA_COUNT_MAX;++i)
		printf("defectiveColumns: %u\n", cmd_data->defectiveColumns[i]);

	return 0;

}

int
cmd_data28_print(cmd_data28_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data28:\n");
	for(int i=0; i<PGA_COUNT_MAX;++i)
		printf("defectiveColumns: %u\n", cmd_data->defectiveColumns[i]);

	return 0;

}

int
cmd_data30_print(cmd_data30_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data30:\n");
	cmd_data31_print(&cmd_data->beta);
	for(int i=0; i<24;++i)
		cmd_data32_print(&cmd_data->soundVelocity[i]);
	printf("multipathTimeCoef: %f\n", cmd_data->multipathTimeCoef);

	return 0;

}

int
cmd_data31_print(cmd_data31_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data31:\n");
	printf("b0: %f\n", cmd_data->b0);
	printf("b1: %f\n", cmd_data->b1);
	printf("b2: %f\n", cmd_data->b2);

	return 0;

}

int
cmd_data32_print(cmd_data32_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data32:\n");
	printf("toHour: %u\n", cmd_data->toHour);
	printf("sv: %f\n", cmd_data->sv);

	return 0;

}

int
cmd_data36_print(cmd_data36_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data36:\n");
	cmd_data31_print(&cmd_data->beta);
	for(int i=0; i<24;++i)
		cmd_data32_print(&cmd_data->soundVelocity[i]);
	printf("multipathTimeCoef: %f\n", cmd_data->multipathTimeCoef);

	return 0;

}

int
cmd_data38_print(cmd_data38_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data38:\n");
	for(int i=0; i<200;++i)
		cmd_data39_print(&cmd_data->schedule[i]);
	printf("cutOff: %f\n", cmd_data->cutOff);

	return 0;

}

int
cmd_data39_print(cmd_data39_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data39:\n");
	for(int i=0; i<32;++i)
		printf("sweepId: %d\n", cmd_data->sweepId[i]);
	printf("emissionTimestamp: %f\n", cmd_data->emissionTimestamp);
	printf("code: %u\n", cmd_data->code);
	printf("range: %f\n", cmd_data->range);
	printf("emitterBearing: %f\n", cmd_data->emitterBearing);
	printf("emitterDistance: %f\n", cmd_data->emitterDistance);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		printf("emissionSectors: %u\n", cmd_data->emissionSectors[i]);
	printf("emissionLevel: %f\n", cmd_data->emissionLevel);
	cmd_data40_print(&cmd_data->procParams);
	printf("detectionDelay: %f\n", cmd_data->detectionDelay);
	printf("emitterRelativeBearing: %f\n", cmd_data->emitterRelativeBearing);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		printf("emissionRelativeSectors: %u\n", cmd_data->emissionRelativeSectors[i]);

	return 0;

}

int
cmd_data40_print(cmd_data40_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data40:\n");
	printf("targetThreshold: %f\n", cmd_data->targetThreshold);
	printf("markThreshold: %f\n", cmd_data->markThreshold);
	printf("reverbShift: %f\n", cmd_data->reverbShift);
	printf("reverbWidening: %f\n", cmd_data->reverbWidening);

	return 0;

}

int
cmd_data43_print(cmd_data43_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data43:\n");
	for(int i=0; i<200;++i)
		cmd_data39_print(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data47_print(cmd_data47_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data47:\n");
	for(int i=0; i<200;++i)
		cmd_data39_print(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data49_print(cmd_data49_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data49:\n");
	for(int i=0; i<50;++i)
		cmd_data50_print(&cmd_data->schedule[i]);
	printf("cutOff: %f\n", cmd_data->cutOff);

	return 0;

}

int
cmd_data50_print(cmd_data50_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data50:\n");
	for(int i=0; i<32;++i)
		printf("msgId: %d\n", cmd_data->msgId[i]);
	printf("txTimestamp: %f\n", cmd_data->txTimestamp);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		printf("txSectors: %u\n", cmd_data->txSectors[i]);
	printf("txLevel: %f\n", cmd_data->txLevel);
	printf("txMode: %d\n", cmd_data->txMode);
	printf("txData: %d\n", cmd_data->txData);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		printf("txRelativeSectors: %u\n", cmd_data->txRelativeSectors[i]);

	return 0;

}

int
cmd_data54_print(cmd_data54_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data54:\n");
	for(int i=0; i<50;++i)
		cmd_data50_print(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data58_print(cmd_data58_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data58:\n");
	for(int i=0; i<50;++i)
		cmd_data50_print(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data60_print(cmd_data60_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data60:\n");
	for(int i=0; i<200;++i)
		cmd_data61_print(&cmd_data->schedule[i]);
	printf("cutOff: %f\n", cmd_data->cutOff);

	return 0;

}

int
cmd_data61_print(cmd_data61_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data61:\n");
	printf("to: %f\n", cmd_data->to);

	return 0;

}

int
cmd_data65_print(cmd_data65_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data65:\n");
	for(int i=0; i<200;++i)
		cmd_data61_print(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data69_print(cmd_data69_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data69:\n");
	for(int i=0; i<200;++i)
		cmd_data61_print(&cmd_data->schedule[i]);

	return 0;

}

int
cmd_data71_print(cmd_data71_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data71:\n");
	printf("targetThreshold: %f\n", cmd_data->targetThreshold);
	for(int i=0; i<2;++i)
		printf("detectionRule: %u\n", cmd_data->detectionRule[i]);

	return 0;

}

int
cmd_data78_print(cmd_data78_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data78:\n");
	printf("bearing: %f\n", cmd_data->bearing);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("autoTracking: %u\n", cmd_data->autoTracking);
	printf("targetId: %d\n", cmd_data->targetId);

	return 0;

}

int
cmd_data82_print(cmd_data82_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data82:\n");
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("autoTracking: %u\n", cmd_data->autoTracking);
	printf("Heading: %f\n", cmd_data->Heading);
	printf("headingStd: %f\n", cmd_data->headingStd);

	return 0;

}

int
cmd_data86_print(cmd_data86_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data86:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("coefCount: %u\n", cmd_data->coefCount);
	printf("elemCount: %u\n", cmd_data->elemCount);
	printf("lowFreq: %f\n", cmd_data->lowFreq);
	printf("highFreq: %f\n", cmd_data->highFreq);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	printf("data: %d\n", cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data89_print(cmd_data89_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data89:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("coefCount: %u\n", cmd_data->coefCount);
	printf("beamCount: %u\n", cmd_data->beamCount);
	printf("lowFreq: %f\n", cmd_data->lowFreq);
	printf("highFreq: %f\n", cmd_data->highFreq);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	printf("data: %d\n", cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data92_print(cmd_data92_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data92:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("beamCount: %u\n", cmd_data->beamCount);
	printf("lowFreq: %f\n", cmd_data->lowFreq);
	printf("highFreq: %f\n", cmd_data->highFreq);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	printf("data: %d\n", cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data95_print(cmd_data95_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data95:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("lowFreq: %f\n", cmd_data->lowFreq);
	printf("highFreq: %f\n", cmd_data->highFreq);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data96_print(&cmd_data->data[i]);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data96_print(cmd_data96_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data96:\n");
	printf("targetId: %d\n", cmd_data->targetId);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("width: %f\n", cmd_data->width);
	printf("level: %f\n", cmd_data->level);
	printf("noise: %f\n", cmd_data->noise);

	return 0;

}

int
cmd_data99_print(cmd_data99_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data99:\n");
	printf("from: %f\n", cmd_data->from);
	printf("to: %f\n", cmd_data->to);

	return 0;

}

int
cmd_data101_print(cmd_data101_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data101:\n");
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data102_print(&cmd_data->marks[i]);

	return 0;

}

int
cmd_data102_print(cmd_data102_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data102:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data96_print(&cmd_data->data[i]);

	return 0;

}

int
cmd_data104_print(cmd_data104_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data104:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("sampleCount: %u\n", cmd_data->sampleCount);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	printf("data: %d\n", cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data107_print(cmd_data107_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data107:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("coefCount: %u\n", cmd_data->coefCount);
	printf("lowFreq: %f\n", cmd_data->lowFreq);
	printf("highFreq: %f\n", cmd_data->highFreq);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	printf("data: %d\n", cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data110_print(cmd_data110_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data110:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_print(&cmd_data->data[i]);
	cmd_data0_print(&cmd_data->serviceData);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data111_print(cmd_data111_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data111:\n");
	printf("frequency: %f\n", cmd_data->frequency);
	printf("level: %f\n", cmd_data->level);

	return 0;

}

int
cmd_data114_print(cmd_data114_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data114:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("sampleCount: %u\n", cmd_data->sampleCount);
	printf("minShift: %f\n", cmd_data->minShift);
	printf("maxShift: %f\n", cmd_data->maxShift);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	printf("data: %d\n", cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data117_print(cmd_data117_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data117:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data118_print(&cmd_data->data[i]);
	cmd_data0_print(&cmd_data->serviceData);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data118_print(cmd_data118_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data118:\n");
	printf("shift: %f\n", cmd_data->shift);
	printf("level: %f\n", cmd_data->level);

	return 0;

}

int
cmd_data121_print(cmd_data121_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data121:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	for(int i=0; i<32;++i)
		printf("sweepId: %d\n", cmd_data->sweepId[i]);
	printf("dopplerAltCount: %u\n", cmd_data->dopplerAltCount);
	printf("beamCount: %u\n", cmd_data->beamCount);
	printf("dopplerRange: %f\n", cmd_data->dopplerRange);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);

	return 0;

}

int
cmd_data124_print(cmd_data124_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data124:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	for(int i=0; i<32;++i)
		printf("sweepId: %d\n", cmd_data->sweepId[i]);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data125_print(&cmd_data->data[i]);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data125_print(cmd_data125_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data125:\n");
	printf("targetId: %d\n", cmd_data->targetId);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("dopplerSpeed: %f\n", cmd_data->dopplerSpeed);
	printf("level: %f\n", cmd_data->level);
	printf("level0: %f\n", cmd_data->level0);
	printf("noise: %f\n", cmd_data->noise);

	return 0;

}

int
cmd_data129_print(cmd_data129_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data129:\n");
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data130_print(&cmd_data->marks[i]);

	return 0;

}

int
cmd_data130_print(cmd_data130_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data130:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	for(int i=0; i<32;++i)
		printf("sweepId: %d\n", cmd_data->sweepId[i]);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data125_print(&cmd_data->data[i]);

	return 0;

}

int
cmd_data132_print(cmd_data132_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data132:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("beamCount: %u\n", cmd_data->beamCount);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	printf("data: %d\n", cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data135_print(cmd_data135_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data135:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	cmd_data136_print(&cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data136_print(cmd_data136_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data136:\n");
	printf("rxMessage: %d\n", cmd_data->rxMessage);
	printf("rxMode: %d\n", cmd_data->rxMode);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("dopplerSpeed: %f\n", cmd_data->dopplerSpeed);
	printf("dopplerSpeedStd: %f\n", cmd_data->dopplerSpeedStd);
	printf("distance: %f\n", cmd_data->distance);
	printf("distanceStd: %f\n", cmd_data->distanceStd);
	printf("txTimestamp: %f\n", cmd_data->txTimestamp);

	return 0;

}

int
cmd_data140_print(cmd_data140_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data140:\n");
	printf("from: %f\n", cmd_data->from);
	printf("to: %f\n", cmd_data->to);

	return 0;

}

int
cmd_data142_print(cmd_data142_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data142:\n");
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data143_print(&cmd_data->rxData[i]);

	return 0;

}

int
cmd_data143_print(cmd_data143_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data143:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	cmd_data136_print(&cmd_data->data);

	return 0;

}

int
cmd_data145_print(cmd_data145_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data145:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("targetId: %d\n", cmd_data->targetId);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	cmd_data146_print(&cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data146_print(cmd_data146_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data146:\n");
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("bearingRate: %f\n", cmd_data->bearingRate);
	printf("bearingRateStd: %f\n", cmd_data->bearingRateStd);
	printf("course: %f\n", cmd_data->course);
	printf("courseStd: %f\n", cmd_data->courseStd);
	printf("vRel: %f\n", cmd_data->vRel);
	printf("vRelStd: %f\n", cmd_data->vRelStd);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_print(&cmd_data->cLines[i]);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_print(&cmd_data->pLines[i]);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data111_print(&cmd_data->rpLines[i]);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data118_print(&cmd_data->acfLines[i]);
	printf("c1Prob: %f\n", cmd_data->c1Prob);
	printf("c2Prob: %f\n", cmd_data->c2Prob);
	printf("class_: %u\n", cmd_data->class_);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data147_print(&cmd_data->frMarks[i]);

	return 0;

}

int
cmd_data147_print(cmd_data147_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data147:\n");
	printf("lowFreq: %f\n", cmd_data->lowFreq);
	printf("highFreq: %f\n", cmd_data->highFreq);
	printf("snr: %f\n", cmd_data->snr);
	printf("width: %f\n", cmd_data->width);
	printf("p0: %f\n", cmd_data->p0);
	printf("noise: %f\n", cmd_data->noise);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);

	return 0;

}

int
cmd_data151_print(cmd_data151_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data151:\n");
	for(int i=0; i<1;++i)
		cmd_data152_print(&cmd_data->targets[i]);

	return 0;

}

int
cmd_data152_print(cmd_data152_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data152:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("targetId: %d\n", cmd_data->targetId);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	cmd_data146_print(&cmd_data->data);

	return 0;

}

int
cmd_data154_print(cmd_data154_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data154:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("targetId: %d\n", cmd_data->targetId);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	cmd_data155_print(&cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data155_print(cmd_data155_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data155:\n");
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("distance: %f\n", cmd_data->distance);
	printf("distanceStd: %f\n", cmd_data->distanceStd);
	printf("course: %f\n", cmd_data->course);
	printf("courseStd: %f\n", cmd_data->courseStd);
	printf("velocity: %f\n", cmd_data->velocity);
	printf("velocityStd: %f\n", cmd_data->velocityStd);
	printf("c1Prob: %f\n", cmd_data->c1Prob);
	printf("c2Prob: %f\n", cmd_data->c2Prob);
	printf("class_: %u\n", cmd_data->class_);
	cmd_data156_print(&cmd_data->mark);

	return 0;

}

int
cmd_data156_print(cmd_data156_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data156:\n");
	for(int i=0; i<32;++i)
		printf("sweepId: %d\n", cmd_data->sweepId[i]);
	printf("relativeBearing: %f\n", cmd_data->relativeBearing);
	printf("relativeBearingStd: %f\n", cmd_data->relativeBearingStd);
	printf("distance: %f\n", cmd_data->distance);
	printf("distanceStd: %f\n", cmd_data->distanceStd);
	printf("dopplerSpeed: %f\n", cmd_data->dopplerSpeed);
	printf("dopplerSpeedStd: %f\n", cmd_data->dopplerSpeedStd);
	printf("snr: %f\n", cmd_data->snr);
	printf("snr0: %f\n", cmd_data->snr0);
	printf("noise: %f\n", cmd_data->noise);

	return 0;

}

int
cmd_data160_print(cmd_data160_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data160:\n");
	for(int i=0; i<1;++i)
		cmd_data161_print(&cmd_data->targets[i]);

	return 0;

}

int
cmd_data161_print(cmd_data161_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data161:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	printf("targetId: %d\n", cmd_data->targetId);
	printf("heading: %f\n", cmd_data->heading);
	printf("headingStd: %f\n", cmd_data->headingStd);
	cmd_data155_print(&cmd_data->data);

	return 0;

}

int
cmd_data163_print(cmd_data163_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data163:\n");
	for(int i=0; i<1;++i)
		cmd_data165_print(&cmd_data->stream_id[i]);

	return 0;

}

int
cmd_data165_print(cmd_data165_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data165:\n");
	for(int i=0; i<2048;++i)
		printf("baseURL: %d\n", cmd_data->baseURL[i]);
	printf("interval: %u\n", cmd_data->interval);
	printf("targetId: %d\n", cmd_data->targetId);
	printf("attChannelId: %u\n", cmd_data->attChannelId);

	return 0;

}

int
cmd_data168_print(cmd_data168_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data168:\n");
	for(int i=0; i<1;++i)
		cmd_data165_print(&cmd_data->stream_id[i]);

	return 0;

}

int
cmd_data172_print(cmd_data172_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data172:\n");
	for(int i=0; i<1;++i)
		cmd_data165_print(&cmd_data->stream_id[i]);

	return 0;

}

int
cmd_data174_print(cmd_data174_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data174:\n");
	printf("streamId: %u\n", cmd_data->streamId);
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	cmd_data175_print(&cmd_data->data);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data175_print(cmd_data175_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data175:\n");
	cmd_data176_print(&cmd_data->hsmDiag);
	cmd_data177_print(&cmd_data->rxAntennaDiag);
	cmd_data178_print(&cmd_data->txAntennaDiag);
	cmd_data179_print(&cmd_data->utcsDiag);
	cmd_data180_print(&cmd_data->satcomDiag);
	cmd_data181_print(&cmd_data->batteryDiag);
	cmd_data182_print(&cmd_data->foclDiag);
	cmd_data183_print(&cmd_data->hpsDiag);
	printf("generalFault: %u\n", cmd_data->generalFault);
	printf("offlineMode: %u\n", cmd_data->offlineMode);
	printf("uptime: %u\n", cmd_data->uptime);

	return 0;

}

int
cmd_data176_print(cmd_data176_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data176:\n");
	printf("fwFault: %u\n", cmd_data->fwFault);
	printf("compassFault: %f\n", cmd_data->compassFault);
	printf("waterAlarm: %u\n", cmd_data->waterAlarm);
	printf("tsErrorStd: %f\n", cmd_data->tsErrorStd);

	return 0;

}

int
cmd_data177_print(cmd_data177_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data177:\n");
	printf("generalFault: %u\n", cmd_data->generalFault);
	printf("radius: %f\n", cmd_data->radius);
	printf("waterAlarm: %u\n", cmd_data->waterAlarm);

	return 0;

}

int
cmd_data178_print(cmd_data178_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data178:\n");
	printf("generalFault: %u\n", cmd_data->generalFault);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		printf("faultySectors: %u\n", cmd_data->faultySectors[i]);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		printf("drainedSectors: %u\n", cmd_data->drainedSectors[i]);
	printf("waterAlarm: %u\n", cmd_data->waterAlarm);
	for(int i=0; i<IGA_COUNT_MAX;++i)
		printf("sectorWaterAlarms: %u\n", cmd_data->sectorWaterAlarms[i]);

	return 0;

}

int
cmd_data179_print(cmd_data179_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data179:\n");
	printf("txFault: %u\n", cmd_data->txFault);
	printf("rxFault: %u\n", cmd_data->rxFault);

	return 0;

}

int
cmd_data180_print(cmd_data180_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data180:\n");
	printf("generalFault: %u\n", cmd_data->generalFault);
	printf("waterAlarm: %u\n", cmd_data->waterAlarm);

	return 0;

}

int
cmd_data181_print(cmd_data181_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data181:\n");
	printf("generalFault: %u\n", cmd_data->generalFault);

	return 0;

}

int
cmd_data182_print(cmd_data182_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data182:\n");
	printf("powerFault: %u\n", cmd_data->powerFault);
	printf("connFault: %u\n", cmd_data->connFault);

	return 0;

}

int
cmd_data183_print(cmd_data183_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data183:\n");
	for(int i=0; i<UNDEFINED_SIZE;++i)
		printf("faultyTempSensors: %u\n", cmd_data->faultyTempSensors[i]);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		printf("faultyPressureSensors: %u\n", cmd_data->faultyPressureSensors[i]);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		printf("faultySVSensors: %u\n", cmd_data->faultySVSensors[i]);

	return 0;

}

int
cmd_data187_print(cmd_data187_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data187:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	cmd_data175_print(&cmd_data->data);

	return 0;

}

int
cmd_data189_print(cmd_data189_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data189:\n");
	printf("minDepth: %f\n", cmd_data->minDepth);
	for(int i=0; i<2048;++i)
		printf("reportURL: %d\n", cmd_data->reportURL[i]);

	return 0;

}

int
cmd_data191_print(cmd_data191_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data191:\n");
	printf("timestamp: %ld\n", (long int)cmd_data->timestamp);
	for(int i=0; i<UNDEFINED_SIZE;++i)
		cmd_data192_print(&cmd_data->data[i]);
	cmd_data0_print(&cmd_data->serviceData);
	printf("stationId: %d\n", cmd_data->stationId);

	return 0;

}

int
cmd_data192_print(cmd_data192_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data192:\n");
	printf("sensorsId: %u\n", cmd_data->sensorsId);
	printf("pressure: %f\n", cmd_data->pressure);
	printf("temperature: %f\n", cmd_data->temperature);
	printf("soundVelocity: %f\n", cmd_data->soundVelocity);

	return 0;

}

int
cmd_data194_print(cmd_data194_t* cmd_data) {
	if(!cmd_data) {
		printf("%s:%d: ERROR: NULL data in use.\n", __func__, __LINE__);
		return -1;
	}
	printf("cmd_data194:\n");
	for(int i=0; i<64;++i)
		printf("cookie: %d\n", cmd_data->cookie[i]);
	for(int i=0; i<20;++i)
		printf("cookieSHA1: %d\n", cmd_data->cookieSHA1[i]);
	printf("offlineMode: %u\n", cmd_data->offlineMode);

	return 0;

}


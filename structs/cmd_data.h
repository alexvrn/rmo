/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-15 16:04:08
 */

#ifndef CMD_DATA_H
#define CMD_DATA_H

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

#define PGA_COUNT_MAX	2
#define IGA_COUNT_MAX	2
typedef struct cmd_data0_t {
	char	data[32];
} cmd_data0_t;

typedef struct cmd_data2_t {
	char	cookie[64];
	char	cookieSHA1[20];
} cmd_data2_t;

typedef struct cmd_data5_t {
	char	cookie[64];
	char	cookieSHA1[20];
} cmd_data5_t;

typedef struct cmd_data8_t {
	char	cookie[64];
	char	cookieSHA1[20];
	char	reportURL[2048];
} cmd_data8_t;

typedef struct cmd_data176_t {
	unsigned	fwFault;
	float	compassFault;
	unsigned	waterAlarm;
	float	tsErrorStd;
} cmd_data176_t;

typedef struct cmd_data177_t {
	unsigned	generalFault;
	float	radius;
	unsigned	waterAlarm;
} cmd_data177_t;

typedef struct cmd_data178_t {
	unsigned	generalFault;
	unsigned	faultySectors[IGA_COUNT_MAX];
	unsigned	drainedSectors[IGA_COUNT_MAX];
	unsigned	waterAlarm;
	unsigned	sectorWaterAlarms[IGA_COUNT_MAX];
} cmd_data178_t;

typedef struct cmd_data179_t {
	unsigned	txFault;
	unsigned	rxFault;
} cmd_data179_t;

typedef struct cmd_data180_t {
	unsigned	generalFault;
	unsigned	waterAlarm;
} cmd_data180_t;

typedef struct cmd_data181_t {
	unsigned	generalFault;
} cmd_data181_t;

typedef struct cmd_data182_t {
	unsigned	powerFault;
	unsigned	connFault;
} cmd_data182_t;

typedef struct cmd_data183_t {
	unsigned	faultyTempSensors[UNDEFINED_SIZE];
	unsigned	faultyPressureSensors[UNDEFINED_SIZE];
	unsigned	faultySVSensors[UNDEFINED_SIZE];
} cmd_data183_t;

typedef struct cmd_data175_t {
	cmd_data176_t	hsmDiag;
	cmd_data177_t	rxAntennaDiag;
	cmd_data178_t	txAntennaDiag;
	cmd_data179_t	utcsDiag;
	cmd_data180_t	satcomDiag;
	cmd_data181_t	batteryDiag;
	cmd_data182_t	foclDiag;
	cmd_data183_t	hpsDiag;
	unsigned	generalFault;
	unsigned	offlineMode;
	unsigned	uptime;
} cmd_data175_t;

typedef struct cmd_data10_t {
	unsigned	timestamp;
	cmd_data175_t	diagData;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data10_t;

typedef struct cmd_data12_t {
	char	cookie[64];
	char	cookieSHA1[20];
	char	image;
} cmd_data12_t;

typedef struct cmd_data16_t {
	char	sha1[20];
} cmd_data16_t;

typedef struct cmd_data19_t {
	unsigned	timestamp;
} cmd_data19_t;

typedef struct cmd_data21_t {
	float	datetime;
} cmd_data21_t;

typedef struct cmd_data24_t {
	unsigned	defectiveColumns[PGA_COUNT_MAX];
} cmd_data24_t;

typedef struct cmd_data28_t {
	unsigned	defectiveColumns[PGA_COUNT_MAX];
} cmd_data28_t;

typedef struct cmd_data31_t {
	float	b0;
	float	b1;
	float	b2;
} cmd_data31_t;

typedef struct cmd_data32_t {
	unsigned	toHour;
	float	sv;
} cmd_data32_t;

typedef struct cmd_data30_t {
	cmd_data31_t	beta;
	cmd_data32_t	soundVelocity[24];
	float	multipathTimeCoef;
} cmd_data30_t;

typedef struct cmd_data36_t {
	cmd_data31_t	beta;
	cmd_data32_t	soundVelocity[24];
	float	multipathTimeCoef;
} cmd_data36_t;

typedef struct cmd_data40_t {
	float	targetThreshold;
	float	markThreshold;
	float	reverbShift;
	float	reverbWidening;
} cmd_data40_t;

typedef struct cmd_data39_t {
	char	sweepId[32];
	float	emissionTimestamp;
	unsigned	code;
	float	range;
	float	emitterBearing;
	float	emitterDistance;
	unsigned	emissionSectors[UNDEFINED_SIZE];
	float	emissionLevel;
	cmd_data40_t	procParams;
	float	detectionDelay;
	float	emitterRelativeBearing;
	unsigned	emissionRelativeSectors[UNDEFINED_SIZE];
} cmd_data39_t;

typedef struct cmd_data38_t {
	cmd_data39_t	schedule[200];
	float	cutOff;
} cmd_data38_t;

typedef struct cmd_data43_t {
	cmd_data39_t	schedule[200];
} cmd_data43_t;

typedef struct cmd_data47_t {
	cmd_data39_t	schedule[200];
} cmd_data47_t;

typedef struct cmd_data50_t {
	char	msgId[32];
	float	txTimestamp;
	unsigned	txSectors[IGA_COUNT_MAX];
	float	txLevel;
	int	txMode;
	char	txData;
	unsigned	txRelativeSectors[IGA_COUNT_MAX];
} cmd_data50_t;

typedef struct cmd_data49_t {
	cmd_data50_t	schedule[50];
	float	cutOff;
} cmd_data49_t;

typedef struct cmd_data54_t {
	cmd_data50_t	schedule[50];
} cmd_data54_t;

typedef struct cmd_data58_t {
	cmd_data50_t	schedule[50];
} cmd_data58_t;

typedef struct cmd_data61_t {
	float	to;
} cmd_data61_t;

typedef struct cmd_data60_t {
	cmd_data61_t	schedule[200];
	float	cutOff;
} cmd_data60_t;

typedef struct cmd_data65_t {
	cmd_data61_t	schedule[200];
} cmd_data65_t;

typedef struct cmd_data69_t {
	cmd_data61_t	schedule[200];
} cmd_data69_t;

typedef struct cmd_data71_t {
	float	targetThreshold;
	unsigned	detectionRule[2];
} cmd_data71_t;

typedef struct cmd_data78_t {
	float	bearing;
	float	relativeBearing;
	unsigned	autoTracking;
	char	targetId;
} cmd_data78_t;

typedef struct cmd_data82_t {
	float	relativeBearing;
	float	relativeBearingStd;
	unsigned	autoTracking;
	float	Heading;
	float	headingStd;
} cmd_data82_t;

typedef struct cmd_data86_t {
	unsigned	streamId;
	unsigned	timestamp;
	unsigned	coefCount;
	unsigned	elemCount;
	float	lowFreq;
	float	highFreq;
	float	heading;
	float	headingStd;
	char	data;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data86_t;

typedef struct cmd_data89_t {
	unsigned	streamId;
	unsigned	timestamp;
	unsigned	coefCount;
	unsigned	beamCount;
	float	lowFreq;
	float	highFreq;
	float	heading;
	float	headingStd;
	char	data;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data89_t;

typedef struct cmd_data92_t {
	unsigned	streamId;
	unsigned	timestamp;
	unsigned	beamCount;
	float	lowFreq;
	float	highFreq;
	float	heading;
	float	headingStd;
	float	data;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data92_t;

typedef struct cmd_data96_t {
	char	targetId;
	float	relativeBearing;
	float	width;
	float	level;
	float	noise;
} cmd_data96_t;

typedef struct cmd_data95_t {
	unsigned	streamId;
	unsigned	timestamp;
	float	lowFreq;
	float	highFreq;
	float	heading;
	float	headingStd;
	cmd_data96_t	data[UNDEFINED_SIZE];
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data95_t;

typedef struct cmd_data99_t {
	float	from;
	float	to;
} cmd_data99_t;

typedef struct cmd_data102_t {
	unsigned	timestamp;
	float	heading;
	float	headingStd;
	cmd_data96_t	data[UNDEFINED_SIZE];
} cmd_data102_t;

typedef struct cmd_data101_t {
	cmd_data102_t	marks[UNDEFINED_SIZE];
} cmd_data101_t;

typedef struct cmd_data104_t {
	unsigned	streamId;
	unsigned	timestamp;
	unsigned	sampleCount;
	float	heading;
	float	headingStd;
	char	data;
	cmd_data0_t	serviceData;
	float	relativeBearing;
	float	relativeBearingStd;
	char	stationId;
} cmd_data104_t;

typedef struct cmd_data107_t {
	unsigned	streamId;
	unsigned	timestamp;
	unsigned	coefCount;
	float	lowFreq;
	float	highFreq;
	float	heading;
	float	headingStd;
	char	data;
	cmd_data0_t	serviceData;
	float	relativeBearing;
	float	relativeBearingStd;
	char	stationId;
} cmd_data107_t;

typedef struct cmd_data111_t {
	float	frequency;
	float	level;
} cmd_data111_t;

typedef struct cmd_data110_t {
	unsigned	streamId;
	unsigned	timestamp;
	float	heading;
	float	headingStd;
	cmd_data111_t	data[UNDEFINED_SIZE];
	cmd_data0_t	serviceData;
	float	relativeBearing;
	float	relativeBearingStd;
	char	stationId;
} cmd_data110_t;

typedef struct cmd_data114_t {
	unsigned	streamId;
	unsigned	timestamp;
	unsigned	sampleCount;
	float	minShift;
	float	maxShift;
	float	heading;
	float	headingStd;
	char	data;
	cmd_data0_t	serviceData;
	float	relativeBearing;
	float	relativeBearingStd;
	char	stationId;
} cmd_data114_t;

typedef struct cmd_data118_t {
	float	shift;
	float	level;
} cmd_data118_t;

typedef struct cmd_data117_t {
	unsigned	streamId;
	unsigned	timestamp;
	float	heading;
	float	headingStd;
	cmd_data118_t	data[UNDEFINED_SIZE];
	cmd_data0_t	serviceData;
	float	relativeBearing;
	float	relativeBearingStd;
	char	stationId;
} cmd_data117_t;

typedef struct cmd_data121_t {
	unsigned	streamId;
	unsigned	timestamp;
	char	sweepId[32];
	unsigned	dopplerAltCount;
	unsigned	beamCount;
	float	dopplerRange;
	float	heading;
	float	headingStd;
} cmd_data121_t;

typedef struct cmd_data125_t {
	char	targetId;
	float	relativeBearing;
	float	dopplerSpeed;
	float	level;
	float	level0;
	float	noise;
} cmd_data125_t;

typedef struct cmd_data124_t {
	unsigned	streamId;
	unsigned	timestamp;
	char	sweepId[32];
	float	heading;
	float	headingStd;
	cmd_data125_t	data[UNDEFINED_SIZE];
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data124_t;

typedef struct cmd_data130_t {
	unsigned	timestamp;
	char	sweepId[32];
	float	heading;
	float	headingStd;
	cmd_data125_t	data[UNDEFINED_SIZE];
} cmd_data130_t;

typedef struct cmd_data129_t {
	cmd_data130_t	marks[UNDEFINED_SIZE];
} cmd_data129_t;

typedef struct cmd_data132_t {
	unsigned	streamId;
	unsigned	timestamp;
	unsigned	beamCount;
	float	heading;
	float	headingStd;
	char	data;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data132_t;

typedef struct cmd_data136_t {
	char	rxMessage;
	int	rxMode;
	float	relativeBearing;
	float	relativeBearingStd;
	float	dopplerSpeed;
	float	dopplerSpeedStd;
	float	distance;
	float	distanceStd;
	float	txTimestamp;
} cmd_data136_t;

typedef struct cmd_data135_t {
	unsigned	streamId;
	unsigned	timestamp;
	float	heading;
	float	headingStd;
	cmd_data136_t	data;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data135_t;

typedef struct cmd_data140_t {
	float	from;
	float	to;
} cmd_data140_t;

typedef struct cmd_data143_t {
	unsigned	timestamp;
	float	heading;
	float	headingStd;
	cmd_data136_t	data;
} cmd_data143_t;

typedef struct cmd_data142_t {
	cmd_data143_t	rxData[UNDEFINED_SIZE];
} cmd_data142_t;

typedef struct cmd_data147_t {
	float	lowFreq;
	float	highFreq;
	float	snr;
	float	width;
	float	p0;
	float	noise;
	float	relativeBearing;
} cmd_data147_t;

typedef struct cmd_data146_t {
	float	relativeBearing;
	float	relativeBearingStd;
	float	bearingRate;
	float	bearingRateStd;
	float	course;
	float	courseStd;
	float	vRel;
	float	vRelStd;
	cmd_data111_t	cLines[UNDEFINED_SIZE];
	cmd_data111_t	pLines[UNDEFINED_SIZE];
	cmd_data111_t	rpLines[UNDEFINED_SIZE];
	cmd_data118_t	acfLines[UNDEFINED_SIZE];
	float	c1Prob;
	float	c2Prob;
	unsigned	class_;
	cmd_data147_t	frMarks[UNDEFINED_SIZE];
} cmd_data146_t;

typedef struct cmd_data145_t {
	unsigned	streamId;
	unsigned	timestamp;
	char	targetId;
	float	heading;
	float	headingStd;
	cmd_data146_t	data;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data145_t;

typedef struct cmd_data152_t {
	unsigned	timestamp;
	char	targetId;
	float	heading;
	float	headingStd;
	cmd_data146_t	data;
} cmd_data152_t;

typedef struct cmd_data151_t {
	cmd_data152_t	targets[1];
} cmd_data151_t;

typedef struct cmd_data156_t {
	char	sweepId[32];
	float	relativeBearing;
	float	relativeBearingStd;
	float	distance;
	float	distanceStd;
	float	dopplerSpeed;
	float	dopplerSpeedStd;
	float	snr;
	float	snr0;
	float	noise;
} cmd_data156_t;

typedef struct cmd_data155_t {
	float	relativeBearing;
	float	relativeBearingStd;
	float	distance;
	float	distanceStd;
	float	course;
	float	courseStd;
	float	velocity;
	float	velocityStd;
	float	c1Prob;
	float	c2Prob;
	unsigned	class_;
	cmd_data156_t	mark;
} cmd_data155_t;

typedef struct cmd_data154_t {
	unsigned	streamId;
	unsigned	timestamp;
	char	targetId;
	float	heading;
	float	headingStd;
	cmd_data155_t	data;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data154_t;

typedef struct cmd_data161_t {
	unsigned	timestamp;
	char	targetId;
	float	heading;
	float	headingStd;
	cmd_data155_t	data;
} cmd_data161_t;

typedef struct cmd_data160_t {
	cmd_data161_t	targets[1];
} cmd_data160_t;

typedef struct cmd_data165_t {
	char	baseURL[2048];
	unsigned	interval;
	char	targetId;
	unsigned	attChannelId;
} cmd_data165_t;

typedef struct cmd_data163_t {
	cmd_data165_t	stream_id[1];
} cmd_data163_t;

typedef struct cmd_data168_t {
	cmd_data165_t	stream_id[1];
} cmd_data168_t;

typedef struct cmd_data172_t {
	cmd_data165_t	stream_id[1];
} cmd_data172_t;

typedef struct cmd_data174_t {
	unsigned	streamId;
	unsigned	timestamp;
	cmd_data175_t	data;
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data174_t;

typedef struct cmd_data187_t {
	unsigned	timestamp;
	cmd_data175_t	data;
} cmd_data187_t;

typedef struct cmd_data189_t {
	float	minDepth;
	char	reportURL[2048];
} cmd_data189_t;

typedef struct cmd_data192_t {
	unsigned	sensorsId;
	float	pressure;
	float	temperature;
	float	soundVelocity;
} cmd_data192_t;

typedef struct cmd_data191_t {
	unsigned	timestamp;
	cmd_data192_t	data[UNDEFINED_SIZE];
	cmd_data0_t	serviceData;
	char	stationId;
} cmd_data191_t;

typedef struct cmd_data194_t {
	char	cookie[64];
	char	cookieSHA1[20];
	unsigned	offlineMode;
} cmd_data194_t;

extern cmd_data0_t cmd_data0;
extern cmd_data2_t cmd_data2;
extern cmd_data5_t cmd_data5;
extern cmd_data8_t cmd_data8;
extern cmd_data10_t cmd_data10;
extern cmd_data12_t cmd_data12;
extern cmd_data16_t cmd_data16;
extern cmd_data19_t cmd_data19;
extern cmd_data21_t cmd_data21;
extern cmd_data24_t cmd_data24;
extern cmd_data28_t cmd_data28;
extern cmd_data30_t cmd_data30;
extern cmd_data31_t cmd_data31;
extern cmd_data32_t cmd_data32;
extern cmd_data36_t cmd_data36;
extern cmd_data38_t cmd_data38;
extern cmd_data39_t cmd_data39;
extern cmd_data40_t cmd_data40;
extern cmd_data43_t cmd_data43;
extern cmd_data47_t cmd_data47;
extern cmd_data49_t cmd_data49;
extern cmd_data50_t cmd_data50;
extern cmd_data54_t cmd_data54;
extern cmd_data58_t cmd_data58;
extern cmd_data60_t cmd_data60;
extern cmd_data61_t cmd_data61;
extern cmd_data65_t cmd_data65;
extern cmd_data69_t cmd_data69;
extern cmd_data71_t cmd_data71;
extern cmd_data78_t cmd_data78;
extern cmd_data82_t cmd_data82;
extern cmd_data86_t cmd_data86;
extern cmd_data89_t cmd_data89;
extern cmd_data92_t cmd_data92;
extern cmd_data95_t cmd_data95;
extern cmd_data96_t cmd_data96;
extern cmd_data99_t cmd_data99;
extern cmd_data101_t cmd_data101;
extern cmd_data102_t cmd_data102;
extern cmd_data104_t cmd_data104;
extern cmd_data107_t cmd_data107;
extern cmd_data110_t cmd_data110;
extern cmd_data111_t cmd_data111;
extern cmd_data114_t cmd_data114;
extern cmd_data117_t cmd_data117;
extern cmd_data118_t cmd_data118;
extern cmd_data121_t cmd_data121;
extern cmd_data124_t cmd_data124;
extern cmd_data125_t cmd_data125;
extern cmd_data129_t cmd_data129;
extern cmd_data130_t cmd_data130;
extern cmd_data132_t cmd_data132;
extern cmd_data135_t cmd_data135;
extern cmd_data136_t cmd_data136;
extern cmd_data140_t cmd_data140;
extern cmd_data142_t cmd_data142;
extern cmd_data143_t cmd_data143;
extern cmd_data145_t cmd_data145;
extern cmd_data146_t cmd_data146;
extern cmd_data147_t cmd_data147;
extern cmd_data151_t cmd_data151;
extern cmd_data152_t cmd_data152;
extern cmd_data154_t cmd_data154;
extern cmd_data155_t cmd_data155;
extern cmd_data156_t cmd_data156;
extern cmd_data160_t cmd_data160;
extern cmd_data161_t cmd_data161;
extern cmd_data163_t cmd_data163;
extern cmd_data165_t cmd_data165;
extern cmd_data168_t cmd_data168;
extern cmd_data172_t cmd_data172;
extern cmd_data174_t cmd_data174;
extern cmd_data175_t cmd_data175;
extern cmd_data176_t cmd_data176;
extern cmd_data177_t cmd_data177;
extern cmd_data178_t cmd_data178;
extern cmd_data179_t cmd_data179;
extern cmd_data180_t cmd_data180;
extern cmd_data181_t cmd_data181;
extern cmd_data182_t cmd_data182;
extern cmd_data183_t cmd_data183;
extern cmd_data187_t cmd_data187;
extern cmd_data189_t cmd_data189;
extern cmd_data191_t cmd_data191;
extern cmd_data192_t cmd_data192;
extern cmd_data194_t cmd_data194;

#ifdef __cplusplus
}
#endif


#endif


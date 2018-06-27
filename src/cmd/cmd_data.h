/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2018-06-18 11:45:23
 */

#ifndef CMD_DATA_H
#define CMD_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#ifdef _MSC_VER
	#define PACKED_STRUCT(name) \
		__pragma(pack(push, 1)) struct name __pragma(pack(pop))
#elif defined(__GNUC__)
	#define PACKED_STRUCT(name) \
		struct __attribute__((packed)) name
#endif

#define PGA_COUNT_MAX	10
#define IGA_COUNT_MAX	10
#define UNDEFINED_SIZE	10

typedef PACKED_STRUCT(cmd_data156_t) {
	char sweepId[32];
	float relativeBearing;
	float relativeBearingStd;
	float distance;
	float distanceStd;
	float dopplerSpeed;
	float dopplerSpeedStd;
	float snr;
	float snr0;
	float noise;
} cmd_data156_t;

typedef PACKED_STRUCT(cmd_data155_t) {
	float relativeBearing;
	float relativeBearingStd;
	float distance;
	float distanceStd;
	float course;
	float courseStd;
	float velocity;
	float velocityStd;
	float c1Prob;
	float c2Prob;
	unsigned class_;
	cmd_data156_t mark;
} cmd_data155_t;

typedef PACKED_STRUCT(cmd_data111_t) {
	float frequency;
	float level;
} cmd_data111_t;

typedef PACKED_STRUCT(cmd_data118_t) {
	float shift;
	float level;
} cmd_data118_t;

typedef PACKED_STRUCT(cmd_data147_t) {
	float lowFreq;
	float highFreq;
	float snr;
	float width;
	float p0;
	float noise;
	float relativeBearing;
} cmd_data147_t;

typedef PACKED_STRUCT(cmd_data146_t) {
	float relativeBearing;
	float relativeBearingStd;
	float bearingRate;
	float bearingRateStd;
	float course;
	float courseStd;
	float vRel;
	float vRelStd;
	cmd_data111_t cLines[UNDEFINED_SIZE];
	cmd_data111_t pLines[UNDEFINED_SIZE];
	cmd_data111_t rpLines[UNDEFINED_SIZE];
	cmd_data118_t acfLines[UNDEFINED_SIZE];
	float c1Prob;
	float c2Prob;
	unsigned class_;
	cmd_data147_t frMarks[UNDEFINED_SIZE];
} cmd_data146_t;

typedef PACKED_STRUCT(cmd_data0_t) {
	char data[32];
} cmd_data0_t;

typedef PACKED_STRUCT(cmd_data132_t) {
	unsigned streamId;
	unsigned timestamp;
	unsigned beamCount;
	float heading;
	float headingStd;
	char data;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data132_t;

typedef PACKED_STRUCT(cmd_data125_t) {
	char targetId;
	float relativeBearing;
	float dopplerSpeed;
	float level;
	float level0;
	float noise;
} cmd_data125_t;

typedef PACKED_STRUCT(cmd_data130_t) {
	unsigned timestamp;
	char sweepId[32];
	float heading;
	float headingStd;
	cmd_data125_t data[UNDEFINED_SIZE];
} cmd_data130_t;

typedef PACKED_STRUCT(cmd_data136_t) {
	char rxMessage;
	int rxMode;
	float relativeBearing;
	float relativeBearingStd;
	float dopplerSpeed;
	float dopplerSpeedStd;
	float distance;
	float distanceStd;
	float txTimestamp;
} cmd_data136_t;

typedef PACKED_STRUCT(cmd_data135_t) {
	unsigned streamId;
	unsigned timestamp;
	float heading;
	float headingStd;
	cmd_data136_t data;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data135_t;

typedef PACKED_STRUCT(cmd_data24_t) {
	unsigned defectiveColumns[PGA_COUNT_MAX];
} cmd_data24_t;

typedef PACKED_STRUCT(cmd_data21_t) {
	float datetime;
} cmd_data21_t;

typedef PACKED_STRUCT(cmd_data96_t) {
	char targetId;
	float relativeBearing;
	float width;
	float level;
	float noise;
} cmd_data96_t;

typedef PACKED_STRUCT(cmd_data95_t) {
	unsigned streamId;
	unsigned timestamp;
	float lowFreq;
	float highFreq;
	float heading;
	float headingStd;
	cmd_data96_t data[UNDEFINED_SIZE];
	cmd_data0_t serviceData;
	char stationId;
} cmd_data95_t;

typedef PACKED_STRUCT(cmd_data28_t) {
	unsigned defectiveColumns[PGA_COUNT_MAX];
} cmd_data28_t;

typedef PACKED_STRUCT(cmd_data8_t) {
	char cookie[64];
	char cookieSHA1[20];
	char reportURL[2048];
} cmd_data8_t;

typedef PACKED_STRUCT(cmd_data165_t) {
	unsigned streamId;
	char baseURL[2048];
	unsigned interval;
	char targetId;
	unsigned attChannelId;
} cmd_data165_t;

typedef PACKED_STRUCT(cmd_data163_t) {
	cmd_data165_t parameters[22];
} cmd_data163_t;

typedef PACKED_STRUCT(cmd_data121_t) {
	unsigned streamId;
	unsigned timestamp;
	char sweepId[32];
	unsigned dopplerAltCount;
	unsigned beamCount;
	float dopplerRange;
	float heading;
	float headingStd;
} cmd_data121_t;

typedef PACKED_STRUCT(cmd_data124_t) {
	unsigned streamId;
	unsigned timestamp;
	char sweepId[32];
	float heading;
	float headingStd;
	cmd_data125_t data[UNDEFINED_SIZE];
	cmd_data0_t serviceData;
	char stationId;
} cmd_data124_t;

typedef PACKED_STRUCT(cmd_data129_t) {
	cmd_data130_t marks[UNDEFINED_SIZE];
} cmd_data129_t;

typedef PACKED_STRUCT(cmd_data50_t) {
	char msgId[32];
	float txTimestamp;
	unsigned txSectors[IGA_COUNT_MAX];
	float txLevel;
	int txMode;
	char txData;
	unsigned txRelativeSectors[IGA_COUNT_MAX];
} cmd_data50_t;

typedef PACKED_STRUCT(cmd_data58_t) {
	cmd_data50_t schedule[50];
} cmd_data58_t;

typedef PACKED_STRUCT(cmd_data54_t) {
	cmd_data50_t schedule[50];
} cmd_data54_t;

typedef PACKED_STRUCT(cmd_data194_t) {
	char cookie[64];
	char cookieSHA1[20];
	unsigned offlineMode;
} cmd_data194_t;
typedef PACKED_STRUCT(cmd_data192_t) {
	unsigned sensorsId;
	float pressure;
	float temperature;
	float soundVelocity;
} cmd_data192_t;

typedef PACKED_STRUCT(cmd_data191_t) {
	unsigned timestamp;
	cmd_data192_t data[UNDEFINED_SIZE];
	cmd_data0_t serviceData;
	char stationId;
} cmd_data191_t;

typedef PACKED_STRUCT(cmd_data114_t) {
	unsigned streamId;
	unsigned timestamp;
	unsigned sampleCount;
	float minShift;
	float maxShift;
	float heading;
	float headingStd;
	char data;
	cmd_data0_t serviceData;
	float relativeBearing;
	float relativeBearingStd;
	char stationId;
} cmd_data114_t;

typedef PACKED_STRUCT(cmd_data117_t) {
	unsigned streamId;
	unsigned timestamp;
	float heading;
	float headingStd;
	cmd_data118_t data[UNDEFINED_SIZE];
	cmd_data0_t serviceData;
	float relativeBearing;
	float relativeBearingStd;
	char stationId;
} cmd_data117_t;

typedef PACKED_STRUCT(cmd_data89_t) {
	unsigned streamId;
	unsigned timestamp;
	unsigned coefCount;
	unsigned beamCount;
	float lowFreq;
	float highFreq;
	float heading;
	float headingStd;
	char data;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data89_t;

typedef PACKED_STRUCT(cmd_data110_t) {
	unsigned streamId;
	unsigned timestamp;
	float heading;
	float headingStd;
	cmd_data111_t data[UNDEFINED_SIZE];
	cmd_data0_t serviceData;
	float relativeBearing;
	float relativeBearingStd;
	char stationId;
} cmd_data110_t;

typedef PACKED_STRUCT(cmd_data61_t) {
	float to;
} cmd_data61_t;

typedef PACKED_STRUCT(cmd_data69_t) {
	cmd_data61_t schedule[200];
} cmd_data69_t;

typedef PACKED_STRUCT(cmd_data82_t) {
	float relativeBearing;
	float relativeBearingStd;
	unsigned autoTracking;
	float Heading;
	float headingStd;
} cmd_data82_t;

typedef PACKED_STRUCT(cmd_data181_t) {
	unsigned generalFault;
} cmd_data181_t;

typedef PACKED_STRUCT(cmd_data86_t) {
	unsigned streamId;
	unsigned timestamp;
	unsigned coefCount;
	unsigned elemCount;
	float lowFreq;
	float highFreq;
	float heading;
	float headingStd;
	char data;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data86_t;

typedef PACKED_STRUCT(cmd_data102_t) {
	unsigned timestamp;
	float heading;
	float headingStd;
	cmd_data96_t data[UNDEFINED_SIZE];
} cmd_data102_t;

typedef PACKED_STRUCT(cmd_data101_t) {
	cmd_data102_t marks[UNDEFINED_SIZE];
} cmd_data101_t;

typedef PACKED_STRUCT(cmd_data107_t) {
	unsigned streamId;
	unsigned timestamp;
	unsigned coefCount;
	float lowFreq;
	float highFreq;
	float heading;
	float headingStd;
	char data;
	cmd_data0_t serviceData;
	float relativeBearing;
	float relativeBearingStd;
	char stationId;
} cmd_data107_t;

typedef PACKED_STRUCT(cmd_data104_t) {
	unsigned streamId;
	unsigned timestamp;
	unsigned sampleCount;
	float heading;
	float headingStd;
	char data;
	cmd_data0_t serviceData;
	float relativeBearing;
	float relativeBearingStd;
	char stationId;
} cmd_data104_t;

typedef PACKED_STRUCT(cmd_data40_t) {
	float targetThreshold;
	float markThreshold;
	float reverbShift;
	float reverbWidening;
} cmd_data40_t;

typedef PACKED_STRUCT(cmd_data39_t) {
	char sweepId[32];
	float emissionTimestamp;
	unsigned code;
	float range;
	float emitterBearing;
	float emitterDistance;
	unsigned emissionSectors[UNDEFINED_SIZE];
	float emissionLevel;
	cmd_data40_t procParams;
	float detectionDelay;
	float emitterRelativeBearing;
	unsigned emissionRelativeSectors[UNDEFINED_SIZE];
} cmd_data39_t;

typedef PACKED_STRUCT(cmd_data38_t) {
	cmd_data39_t schedule[200];
	unsigned cutOff;
} cmd_data38_t;

typedef PACKED_STRUCT(cmd_data32_t) {
	unsigned toHour;
	float sv;
} cmd_data32_t;

typedef PACKED_STRUCT(cmd_data31_t) {
	float b0;
	float b1;
	float b2;
} cmd_data31_t;

typedef PACKED_STRUCT(cmd_data30_t) {
	cmd_data31_t beta;
	cmd_data32_t soundVelocity[24];
	float multipathTimeCoef;
} cmd_data30_t;

typedef PACKED_STRUCT(cmd_data36_t) {
	cmd_data31_t beta;
	cmd_data32_t soundVelocity[24];
	float multipathTimeCoef;
} cmd_data36_t;

typedef PACKED_STRUCT(cmd_data60_t) {
	cmd_data61_t schedule[200];
	unsigned cutOff;
} cmd_data60_t;

typedef PACKED_STRUCT(cmd_data65_t) {
	cmd_data61_t schedule[200];
} cmd_data65_t;

typedef PACKED_STRUCT(cmd_data179_t) {
	unsigned txFault;
	unsigned rxFault;
} cmd_data179_t;

typedef PACKED_STRUCT(cmd_data178_t) {
	unsigned generalFault;
	unsigned faultySectors[IGA_COUNT_MAX];
	unsigned drainedSectors[IGA_COUNT_MAX];
	unsigned waterAlarm;
	unsigned sectorWaterAlarms[IGA_COUNT_MAX];
} cmd_data178_t;

typedef PACKED_STRUCT(cmd_data177_t) {
	unsigned generalFault;
	float radius;
	unsigned waterAlarm;
} cmd_data177_t;

typedef PACKED_STRUCT(cmd_data176_t) {
	unsigned fwFault;
	float compassFault;
	unsigned waterAlarm;
	float tsErrorStd;
} cmd_data176_t;

typedef PACKED_STRUCT(cmd_data180_t) {
	unsigned generalFault;
	unsigned waterAlarm;
} cmd_data180_t;

typedef PACKED_STRUCT(cmd_data182_t) {
	unsigned powerFault;
	unsigned connFault;
} cmd_data182_t;

typedef PACKED_STRUCT(cmd_data183_t) {
	unsigned faultyTempSensors[UNDEFINED_SIZE];
	unsigned faultyPressureSensors[UNDEFINED_SIZE];
	unsigned faultySVSensors[UNDEFINED_SIZE];
} cmd_data183_t;

typedef PACKED_STRUCT(cmd_data175_t) {
	cmd_data176_t hsmDiag;
	cmd_data177_t rxAntennaDiag;
	cmd_data178_t txAntennaDiag;
	cmd_data179_t utcsDiag;
	cmd_data180_t satcomDiag;
	cmd_data181_t batteryDiag;
	cmd_data182_t foclDiag;
	cmd_data183_t hpsDiag;
	unsigned generalFault;
	unsigned offlineMode;
	unsigned uptime;
} cmd_data175_t;

typedef PACKED_STRUCT(cmd_data174_t) {
	unsigned streamId;
	unsigned timestamp;
	cmd_data175_t data;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data174_t;

typedef PACKED_STRUCT(cmd_data172_t) {
	cmd_data165_t parameters[22];
} cmd_data172_t;

typedef PACKED_STRUCT(cmd_data2_t) {
	char cookie[64];
	char cookieSHA1[20];
} cmd_data2_t;

typedef PACKED_STRUCT(cmd_data187_t) {
	unsigned timestamp;
	cmd_data175_t data;
} cmd_data187_t;

typedef PACKED_STRUCT(cmd_data189_t) {
	float minDepth;
	char reportURL[2048];
} cmd_data189_t;

typedef PACKED_STRUCT(cmd_data99_t) {
	float from;
	float to;
} cmd_data99_t;

typedef PACKED_STRUCT(cmd_data168_t) {
	cmd_data165_t parameters[22];
} cmd_data168_t;

typedef PACKED_STRUCT(cmd_data92_t) {
	unsigned streamId;
	unsigned timestamp;
	unsigned beamCount;
	float lowFreq;
	float highFreq;
	float heading;
	float headingStd;
	float data;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data92_t;

typedef PACKED_STRUCT(cmd_data161_t) {
	unsigned timestamp;
	char targetId;
	float heading;
	float headingStd;
	cmd_data155_t data;
} cmd_data161_t;

typedef PACKED_STRUCT(cmd_data160_t) {
	cmd_data161_t targets[1];
} cmd_data160_t;

typedef PACKED_STRUCT(cmd_data10_t) {
	unsigned timestamp;
	cmd_data175_t diagData;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data10_t;

typedef PACKED_STRUCT(cmd_data12_t) {
	char cookie[64];
	char cookieSHA1[20];
	char image;
} cmd_data12_t;

typedef PACKED_STRUCT(cmd_data16_t) {
	char sha1[20];
} cmd_data16_t;

typedef PACKED_STRUCT(cmd_data19_t) {
	unsigned timestamp;
} cmd_data19_t;

typedef PACKED_STRUCT(cmd_data152_t) {
	unsigned timestamp;
	char targetId;
	float heading;
	float headingStd;
	cmd_data146_t data;
} cmd_data152_t;

typedef PACKED_STRUCT(cmd_data151_t) {
	cmd_data152_t targets[1];
} cmd_data151_t;

typedef PACKED_STRUCT(cmd_data154_t) {
	unsigned streamId;
	unsigned timestamp;
	char targetId;
	float heading;
	float headingStd;
	cmd_data155_t data;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data154_t;

typedef PACKED_STRUCT(cmd_data49_t) {
	cmd_data50_t schedule[50];
	unsigned cutOff;
} cmd_data49_t;

typedef PACKED_STRUCT(cmd_data47_t) {
	cmd_data39_t schedule[200];
} cmd_data47_t;

typedef PACKED_STRUCT(cmd_data43_t) {
	cmd_data39_t schedule[200];
} cmd_data43_t;

typedef PACKED_STRUCT(cmd_data5_t) {
	char cookie[64];
	char cookieSHA1[20];
} cmd_data5_t;

typedef PACKED_STRUCT(cmd_data145_t) {
	unsigned streamId;
	unsigned timestamp;
	char targetId;
	float heading;
	float headingStd;
	cmd_data146_t data;
	cmd_data0_t serviceData;
	char stationId;
} cmd_data145_t;

typedef PACKED_STRUCT(cmd_data143_t) {
	unsigned timestamp;
	float heading;
	float headingStd;
	cmd_data136_t data;
} cmd_data143_t;

typedef PACKED_STRUCT(cmd_data142_t) {
	cmd_data143_t rxData[UNDEFINED_SIZE];
} cmd_data142_t;

typedef PACKED_STRUCT(cmd_data140_t) {
	float from;
	float to;
} cmd_data140_t;

typedef PACKED_STRUCT(cmd_data71_t) {
	float targetThreshold;
	unsigned detectionRule[2];
} cmd_data71_t;

typedef PACKED_STRUCT(cmd_data78_t) {
	float bearing;
	float relativeBearing;
	unsigned autoTracking;
	char targetId;
} cmd_data78_t;

typedef union dev2host_t {
	cmd_data16_t cmd_data16;
	cmd_data19_t cmd_data19;
	cmd_data28_t cmd_data28;
	cmd_data36_t cmd_data36;
	cmd_data47_t cmd_data47;
	cmd_data58_t cmd_data58;
	cmd_data69_t cmd_data69;
	cmd_data71_t cmd_data71;
	cmd_data82_t cmd_data82;
	cmd_data101_t cmd_data101;
	cmd_data129_t cmd_data129;
	cmd_data142_t cmd_data142;
	cmd_data151_t cmd_data151;
	cmd_data160_t cmd_data160;
	cmd_data172_t cmd_data172;
	cmd_data187_t cmd_data187;
	cmd_data0_t cmd_data0;
	cmd_data86_t cmd_data86;
	cmd_data89_t cmd_data89;
	cmd_data92_t cmd_data92;
	cmd_data95_t cmd_data95;
	cmd_data104_t cmd_data104;
	cmd_data107_t cmd_data107;
	cmd_data110_t cmd_data110;
	cmd_data114_t cmd_data114;
	cmd_data117_t cmd_data117;
	cmd_data121_t cmd_data121;
	cmd_data124_t cmd_data124;
	cmd_data132_t cmd_data132;
	cmd_data135_t cmd_data135;
	cmd_data145_t cmd_data145;
	cmd_data154_t cmd_data154;
	cmd_data174_t cmd_data174;
} dev2host_t;

typedef union host2dev_t {
	cmd_data2_t cmd_data2;
	cmd_data5_t cmd_data5;
	cmd_data8_t cmd_data8;
	cmd_data12_t cmd_data12;
	cmd_data19_t cmd_data19;
	cmd_data24_t cmd_data24;
	cmd_data30_t cmd_data30;
	cmd_data38_t cmd_data38;
	cmd_data43_t cmd_data43;
	cmd_data49_t cmd_data49;
	cmd_data54_t cmd_data54;
	cmd_data60_t cmd_data60;
	cmd_data65_t cmd_data65;
	cmd_data71_t cmd_data71;
	cmd_data78_t cmd_data78;
	cmd_data163_t cmd_data163;
	cmd_data168_t cmd_data168;
	cmd_data189_t cmd_data189;
	cmd_data194_t cmd_data194;
	cmd_data0_t cmd_data0;
} host2dev_t;

typedef PACKED_STRUCT(dev2host_pkt_t) {
	uint16_t cmd_id;
	dev2host_t data;
} dev2host_pkt_t;

typedef PACKED_STRUCT(host2dev_pkt_t) {
	uint16_t cmd_id;
	host2dev_t data;
} host2dev_pkt_t;


#ifdef __cplusplus
}
#endif


#endif


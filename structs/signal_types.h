#ifndef SIGNAL_TYPES_H
#define SIGNAL_TYPES_H

#include <stdint.h>

typedef struct signal96_t {
	char	targetId[2];
	float	relativeBearing;
	float	width;
	float	level;
	float	noise;
} signal96_t;

typedef struct signal102_t {
	unsigned	timestamp;
	float	heading;
	float	headingStd;
	signal96_t	data;
} signal102_t;

typedef struct service_data_t {
	char	data;
} service_data_t;

typedef struct signal95_t {
	unsigned int	streamId;
	unsigned long		timestamp;
	float		lowfreq;
	float		highfreq;
	float		heading;
	float		headingStd;
	signal96_t		data[1];
	service_data_t	serviceData;
	char		stationId;
} signal95_t;

typedef signal95_t signal_test_t;

#endif

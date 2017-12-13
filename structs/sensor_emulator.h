#ifndef SENSOR_EMULATOR_H
#define SENSOR_EMULATOR_H

#include <pthread.h>

/* abstract type for data from sensor */
typedef struct sensor_data_t {
	void*		data;
	unsigned int	len;
} sensor_data_t;

typedef int (*SENSOR_EMULATOR)(
	void* emulator_data,
	sensor_data_t** sensor_data);

typedef int (*SENSOR_HANDLER)(
	void* handler_data,
	sensor_data_t* sensor_data);

typedef struct sensor_emulator_t {
	pthread_t thread;
	float freq;
	SENSOR_EMULATOR emulator;
	void* emulator_data;
	SENSOR_HANDLER handler;
	void* handler_data;
} sensor_emulator_t;

sensor_emulator_t*
sensor_emulator_start(  float freq,
                        SENSOR_EMULATOR emulator,
                        void* emulator_data,
                        SENSOR_HANDLER handler,
                        void* handler_data);
int sensor_emulator_stop(sensor_emulator_t* emu);

#endif

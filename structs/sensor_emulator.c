#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sensor_emulator.h"

void*
sensor_emulator(void* ptr) {
	sensor_data_t* sensor_data;

	if(!ptr) {
		printf("%s:%d: bad emulator pointer\n", __func__, __LINE__);
		goto exit;
	}

	sensor_emulator_t* emu = (sensor_emulator_t*)ptr;

	while(0 == emu->emulator(emu->emulator_data, &sensor_data)) {
		emu->handler(emu->handler_data, sensor_data);
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
		sleep(1/emu->freq);
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	}
	//printf("%s: %d: EMULATE freq=%d ...\n", __func__, __LINE__, emu->freq);

exit:
	return NULL;
}

sensor_emulator_t*
sensor_emulator_start(	float freq,
			SENSOR_EMULATOR emulator,
			void* emulator_data,
			SENSOR_HANDLER handler,
			void* handler_data) {
	sensor_emulator_t* emu = NULL;

	//check parameters
	if(freq == 0.0 || !emulator || !handler) {
		printf("%s:%d: bad parameters:"
			" freq = %f, emulator = %p, handler = %p",
			__func__, __LINE__, freq, emulator, handler);

		goto fail;
	}

	emu = malloc(sizeof(sensor_emulator_t));
	emu->freq = freq;
	emu->emulator = emulator;
	emu->emulator_data = emulator_data;
	emu->handler = handler;
	emu->handler_data = handler_data;

	if(pthread_create(&emu->thread, NULL, sensor_emulator, emu)) {
		printf("ERROR: pthread create fail\n");
		goto fail;
	}

	return emu;
	
fail:
	if(emu)
		free(emu);
	return emu;
}

int
sensor_emulator_stop(sensor_emulator_t* emu) {
	int ret = 0;
	void* res = NULL;

	if(!emu) {
		printf("%s:%d: bad sensor_emulator_t pointer\n",
			__func__, __LINE__);
		ret = -1;
		goto exit;	
	}

	if(pthread_cancel(emu->thread)) {
		printf("ERROR: pthread cancel fail\n");
		ret = -1;
		goto exit;
	}

	if(pthread_join(emu->thread, &res)) {
		printf("ERROR: pthread join fail\n");
		ret = -1;
		goto exit;
	}

	//stop thread TBD
	free(emu);

exit:
	return ret;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sensor_emulator.h"
#include "signal_types.h"
#include "common.h"

/* SHP emulator */
int
shp_emulator(void* emulator_data, sensor_data_t** data) {
	int ret = 0;
	char* fname = (char*)emulator_data;

	static unsigned int iter = 0;
	static sensor_data_t shp_data; 
	static FILE* file = NULL;

	if( iter == 0) {
		if(file != NULL) {
			printf("%s:%d: ERROR: emulator file already opened %s\n",
				__func__, __LINE__, fname);
			ret = -1;
			goto exit;
		}
		file = fopen(fname, "rb");
		shp_data.len = sizeof(signal_test_t);
		shp_data.data = malloc(shp_data.len);
		printf("%s:%d: emulate SHP data from file %s...\n",
			__func__, __LINE__, fname);
#if 0
	} else {
		printf("%s:%d: ...\n",
			__func__, __LINE__);
#endif
	}

	fseek(file, sizeof(signal_test_t)*iter, SEEK_SET);
	if(1 != fread(shp_data.data, sizeof(signal_test_t), 1, file)) {
		fclose(file);
		if(shp_data.data) {
			free(shp_data.data);
			shp_data.len = 0;
		}
		file = NULL;
		iter = 0;
		ret = 1;
		goto exit;
	} else {
		printf("%d %u\n", iter,
			//((signal_test_t*)shp_data.data)->streamId,
			(unsigned)((signal_test_t*)shp_data.data)->timestamp
		);
	}

	*data = &shp_data;
	//printf("setup %p\n", shp_data.data);
	iter++;

exit:
	return ret;
}

int
shp_handler(void* handler_data, sensor_data_t* sensor_data) {
	int ret = 0;

//	signal_test_t* sig = (signal_test_t*)sensor_data->data;
//
//	printf("%s:%d: %u...\n", __func__, __LINE__,
//		//sig->streamId,
//		sig->timestamp);

	return ret;
}

/* Stream emulator */
int
emu_stream_emulator(void* emulator_data, sensor_data_t** data) {
	return 0;
}

int
emu_stream_handler(void* handler_data, sensor_data_t* data) {
	int ret = 0;
	unsigned s_id;

	if(!handler_data) {
		ERROR
		goto exit;
	}
	s_id = *((unsigned*)handler_data);

	if(s_id >= PGAS_STREAM_MAX) {
		ERROR
		goto exit;
	}

	//printf("irq %d start\n", s_id);
	pgas_stream[s_id].irq_handler(NULL, 0);
	//printf("irq %d stop\n", s_id);
exit:
	return ret;
}


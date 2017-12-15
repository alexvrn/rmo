#ifndef EMULATORS_H
#define EMULATORS_H

typedef struct shp_emu_data_t {
	char** fname;
	unsigned int iter;
	//TBD!!! do not compiled cmd_data92_t* cmd_data;
	void* cmd_data;
	unsigned fname_id;
	FILE* file;
} shp_emu_data_t;

int shp_emulator(void* emulator_data, sensor_data_t* sensor_data);
int shp_handler(void* handler_data, sensor_data_t* sensor_data);

int emu_stream_emulator(void* emulator_data, sensor_data_t* sensor_data);
int emu_stream_handler(void* handler_data, sensor_data_t* sensor_data);

#endif


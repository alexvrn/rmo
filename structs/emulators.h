#ifndef EMULATORS_H
#define EMULATORS_H

int shp_emulator(void* emulator_data, sensor_data_t** sensor_data);
int shp_handler(void* handler_data, sensor_data_t* sensor_data);

int emu_stream_emulator(void* emulator_data, sensor_data_t** sensor_data);
int emu_stream_handler(void* handler_data, sensor_data_t* sensor_data);

#endif


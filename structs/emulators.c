#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sensor_emulator.h"
#include "common.h"
#include "cmd_data.h"

int
shp_emulator(void* emulator_data, sensor_data_t* sensor_data) {
	int ret = 0;

	shp_emu_data_t* emu_data	= (shp_emu_data_t*)emulator_data;
        struct timeval tv;
        unsigned now = 0;

        gettimeofday(&tv, NULL);
        now = tv.tv_sec;

open_file:
	if(emu_data->file == NULL) {
		emu_data->file = fopen(emu_data->fname[emu_data->fname_id], "rb");
		if(emu_data->file == NULL) {
			printf("%s:%d: error open %s\n",
				__func__, __LINE__, emu_data->fname[emu_data->fname_id]);
			goto exit;
		}
		emu_data->cmd_data = malloc(sizeof(cmd_data92_t));
		memset(emu_data->cmd_data, 0x00, sizeof(cmd_data92_t));
		printf("%s:%d: emulate SHP data from file %s...\n",
			__func__, __LINE__, emu_data->fname[emu_data->fname_id]);
		emu_data->fname_id = !emu_data->fname_id;
	}

	ret = fseek(emu_data->file, sizeof(float)*emu_data->iter, SEEK_SET);
	if(ret != 0) {
		printf("%s:%d: error seek %lu\n",
			__func__, __LINE__, sizeof(float)*emu_data->iter);
		goto exit;
	}
	//printf(">>> %d\n", sizeof(float)*iter);
	if(1 !=  fread(&((cmd_data92_t*)emu_data->cmd_data)->data, sizeof(float), 1, emu_data->file)) {
		if(emu_data->cmd_data) {
			free(emu_data->cmd_data);
		}
		emu_data->iter = 0;
		if(feof(emu_data->file)) {
			printf("%s:%d: end of file\n",
				__func__, __LINE__);
			fclose(emu_data->file);
			emu_data->file = NULL;
			goto open_file;
		}
		fclose(emu_data->file);
		emu_data->file = NULL;
		ret = 1;
		printf("%s:%d: error\n", __func__, __LINE__);
		goto exit;
	} else {
		((cmd_data92_t*)emu_data->cmd_data)->beamCount = emu_data->iter%128;
		((cmd_data92_t*)emu_data->cmd_data)->timestamp = now;
		emu_data->iter++;
	}
#if 0
	printf("%s:%d: timestamp %d beamCount=%d data=%x\n",
		__func__, __LINE__,
		now, emu_data->iter%128, *((uint32_t*)&(((cmd_data92_t*)emu_data->cmd_data)->data)) );
#endif
	sensor_data->data = emu_data->cmd_data;

exit:
	return ret;
}

int
shp_handler(void* handler_data, sensor_data_t* sensor_data) {
	int ret = 0;
	char* serviceMessage = "Zdraste, kakie dela kollega:)";

	unsigned stream = *((unsigned*)handler_data);
	cmd_data92_t* cmd_data = sensor_data->data;

	cmd_data->streamId = stream;
	cmd_data->stationId = 7;
	memcpy(cmd_data->serviceData.data, serviceMessage, strlen(serviceMessage));

	cbuf_add(&pgas_stream[stream].cbuf[pgas_stream[stream].irq_cbuf_id],
		(char*)cmd_data,
		sizeof(cmd_data92_t));

#if 0
	printf("%s:%d: timestamp=%d beamCount=%d data=%x\n",
		__func__, __LINE__,
		*((uint32_t*)&(cmd_data->timestamp)),
		cmd_data->beamCount,
		*((uint32_t*)&(cmd_data->data)) );
#endif

	return ret;
}

/* Stream emulator */
int
emu_stream_emulator(void* emulator_data, sensor_data_t* data) {
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


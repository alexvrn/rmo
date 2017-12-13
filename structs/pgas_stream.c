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

CURL* curl_handler;

int irq_stream0_handler(void* data, size_t size) {return 0;};
int
irq_stream1_handler(void* data, size_t size) {
	cmd_data86_t cmd_data;
	cmd_data86_rnd(&cmd_data);
	cbuf_add(&pgas_stream[1].cbuf[pgas_stream[1].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data86_t));
	return 0;
};
int
irq_stream2_handler(void* data, size_t size) {
	cmd_data89_t cmd_data;
	cmd_data89_rnd(&cmd_data);
	cbuf_add(&pgas_stream[2].cbuf[pgas_stream[2].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data89_t));
	return 0;
};
int
irq_stream3_handler(void* data, size_t size) {
	cmd_data92_t cmd_data;
	cmd_data92_rnd(&cmd_data);
	cbuf_add(&pgas_stream[3].cbuf[pgas_stream[3].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data92_t));
	return 0;
};
int
irq_stream4_handler(void* data, size_t size) {
	cmd_data92_t cmd_data;
	cmd_data92_rnd(&cmd_data);
	cbuf_add(&pgas_stream[4].cbuf[pgas_stream[4].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data92_t));
	return 0;
};
int
irq_stream5_handler(void* data, size_t size) {
	cmd_data95_t cmd_data;
	cmd_data95_rnd(&cmd_data);
	cbuf_add(&pgas_stream[5].cbuf[pgas_stream[5].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data95_t));
	return 0;
};
int
irq_stream6_handler(void* data, size_t size) {
	cmd_data95_t cmd_data;
	cmd_data95_rnd(&cmd_data);
	cbuf_add(&pgas_stream[6].cbuf[pgas_stream[6].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data95_t));
	return 0;
};
int
irq_stream7_handler(void* data, size_t size) {
	cmd_data104_t cmd_data;
	cmd_data104_rnd(&cmd_data);
	cbuf_add(&pgas_stream[7].cbuf[pgas_stream[7].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data104_t));
	return 0;
};
int
irq_stream8_handler(void* data, size_t size) {
	cmd_data107_t cmd_data;
	cmd_data107_rnd(&cmd_data);
	cbuf_add(&pgas_stream[8].cbuf[pgas_stream[8].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data107_t));
	return 0;
};
int
irq_stream9_handler(void* data, size_t size) {
	cmd_data110_t cmd_data;
	cmd_data110_rnd(&cmd_data);
	cbuf_add(&pgas_stream[9].cbuf[pgas_stream[9].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data110_t));
	return 0;
};
int
irq_stream10_handler(void* data, size_t size) {
	cmd_data107_t cmd_data;
	cmd_data107_rnd(&cmd_data);
	cbuf_add(&pgas_stream[10].cbuf[pgas_stream[10].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data107_t));
	return 0;
};
int
irq_stream11_handler(void* data, size_t size) {
	cmd_data110_t cmd_data;
	cmd_data110_rnd(&cmd_data);
	cbuf_add(&pgas_stream[11].cbuf[pgas_stream[11].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data110_t));
	return 0;
};
int
irq_stream12_handler(void* data, size_t size) {
	cmd_data107_t cmd_data;
	cmd_data107_rnd(&cmd_data);
	cbuf_add(&pgas_stream[12].cbuf[pgas_stream[12].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data107_t));
	return 0;
};
int
irq_stream13_handler(void* data, size_t size) {
	cmd_data110_t cmd_data;
	cmd_data110_rnd(&cmd_data);
	cbuf_add(&pgas_stream[13].cbuf[pgas_stream[13].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data110_t));
	return 0;
};
int
irq_stream14_handler(void* data, size_t size) {
	cmd_data114_t cmd_data;
	cmd_data114_rnd(&cmd_data);
	cbuf_add(&pgas_stream[14].cbuf[pgas_stream[14].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data114_t));
	return 0;
};
int
irq_stream15_handler(void* data, size_t size) {
	cmd_data117_t cmd_data;
	cmd_data117_rnd(&cmd_data);
	cbuf_add(&pgas_stream[15].cbuf[pgas_stream[15].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data117_t));
	return 0;
};
int
irq_stream16_handler(void* data, size_t size) {
	cmd_data121_t cmd_data;
	cmd_data121_rnd(&cmd_data);
	cbuf_add(&pgas_stream[16].cbuf[pgas_stream[16].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data121_t));
	return 0;
};
int
irq_stream17_handler(void* data, size_t size) {
	cmd_data124_t cmd_data;
	cmd_data124_rnd(&cmd_data);
	cbuf_add(&pgas_stream[17].cbuf[pgas_stream[17].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data124_t));
	return 0;
};
int
irq_stream18_handler(void* data, size_t size) {
	cmd_data132_t cmd_data;
	cmd_data132_rnd(&cmd_data);
	cbuf_add(&pgas_stream[18].cbuf[pgas_stream[18].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data132_t));
	return 0;
};
int
irq_stream19_handler(void* data, size_t size) {
	cmd_data135_t cmd_data;
	cmd_data135_rnd(&cmd_data);
	cbuf_add(&pgas_stream[19].cbuf[pgas_stream[19].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data135_t));
	return 0;
};
int
irq_stream20_handler(void* data, size_t size) {
	cmd_data145_t cmd_data;
	cmd_data145_rnd(&cmd_data);
	cbuf_add(&pgas_stream[20].cbuf[pgas_stream[20].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data145_t));
	return 0;
};
int
irq_stream21_handler(void* data, size_t size) {
	cmd_data154_t cmd_data;
	cmd_data154_rnd(&cmd_data);
	cbuf_add(&pgas_stream[21].cbuf[pgas_stream[21].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data154_t));
	return 0;
};
int
irq_stream22_handler(void* data, size_t size) {
	cmd_data174_t cmd_data;
	cmd_data174_rnd(&cmd_data);
	cbuf_add(&pgas_stream[22].cbuf[pgas_stream[22].irq_cbuf_id], (char*)&cmd_data, sizeof(cmd_data174_t));
	return 0;
};

pgas_stream_t pgas_stream[PGAS_STREAM_MAX] = {
	{0, "service", 
	2, 0,{{0,0,0,sizeof(cmd_data0_t),NULL}, {0,0,0,sizeof(cmd_data0_t),NULL}}, 0, 
	irq_stream0_handler, cmd_data0_pack, NULL},
	{1, "Энергетические спектры сигналов в линейках ПГА", 
	1, 0, {{0,0,0,sizeof(cmd_data86_t)}, {0,0,0,sizeof(cmd_data86_t)}}, 0, 
	irq_stream1_handler, cmd_data86_pack, NULL},
	{2, "Нормированные энергетические спектры сигналов в ПК в рабочей полосе станции", 
	1, 0, {{0,0,0,sizeof(cmd_data89_t)}, {0,0,0,sizeof(cmd_data89_t)}}, 0, 
	irq_stream2_handler, cmd_data89_pack, NULL},
	{3, "Строки индикаторного процесса режима ШП в ЧД-1", 
	1, 0, {{0,0,0,sizeof(cmd_data92_t)}, {0,0,0,sizeof(cmd_data92_t)}}, 0, 
	irq_stream3_handler, cmd_data92_pack, NULL},
	{4, "Строки индикаторного процесса режима ШП в ЧД-2", 
	1, 0, {{0,0,0,sizeof(cmd_data92_t)}, {0,0,0,sizeof(cmd_data92_t)}}, 0, 
	irq_stream4_handler, cmd_data92_pack, NULL},
	{5, "Первичные отметки режима ШП в ЧД‑1", 
	1, 0, {{0,0,0,sizeof(cmd_data95_t)}, {0,0,0,sizeof(cmd_data95_t)}}, 0, 
	irq_stream5_handler, cmd_data95_pack, NULL},
	{6, "Первичные отметки режима ШП в ЧД‑2", 
	1, 0, {{0,0,0,sizeof(cmd_data95_t)}, {0,0,0,sizeof(cmd_data95_t)}}, 0, 
	irq_stream6_handler, cmd_data95_pack, NULL},
	{7, "Сегменты отсчетов сигнала в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data104_t)}, {0,0,0,sizeof(cmd_data104_t)}}, 0, 
	irq_stream7_handler, cmd_data104_pack, NULL},
	{8, "Энергетические спектры несущей сигнала в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data107_t)}, {0,0,0,sizeof(cmd_data107_t)}}, 0, 
	irq_stream8_handler, cmd_data107_pack, NULL},
	{9, "Отметки ДС в спектре несущей сигнала в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data110_t)}, {0,0,0,sizeof(cmd_data110_t)}}, 0, 
	irq_stream9_handler, cmd_data110_pack, NULL},
	{10, "Энергетические спектры в диапазоне ВЛМ сигнала огибающей в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data107_t)}, {0,0,0,sizeof(cmd_data107_t)}}, 0, 
	irq_stream10_handler, cmd_data107_pack, NULL},
	{11, "Отметки ДС спектра в диапазоне ВЛМ сигнала огибающей в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data110_t)}, {0,0,0,sizeof(cmd_data110_t)}}, 0, 
	irq_stream11_handler, cmd_data110_pack, NULL},
	{12, "Энергетические спектры в диапазоне МК сигнала огибающей в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data107_t)}, {0,0,0,sizeof(cmd_data107_t)}}, 0, 
	irq_stream12_handler, cmd_data107_pack, NULL},
	{13, "Отметки ДС спектра в диапазоне МК сигнала огибающей в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data110_t)}, {0,0,0,sizeof(cmd_data110_t)}}, 0, 
	irq_stream13_handler, cmd_data110_pack, NULL},
	{14, "Отсчеты АКФ сигнала в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data114_t)}, {0,0,0,sizeof(cmd_data114_t)}}, 0, 
	irq_stream14_handler, cmd_data114_pack, NULL},
	{15, "Отметки АКФ сигнала в КИС или в канале АСЦ", 
	1, 0, {{0,0,0,sizeof(cmd_data117_t)}, {0,0,0,sizeof(cmd_data117_t)}}, 0, 
	irq_stream15_handler, cmd_data117_pack, NULL},
	{16, "Строки индикаторного процесса режима ГЛ", 
	1, 0, {{0,0,0,sizeof(cmd_data121_t)}, {0,0,0,sizeof(cmd_data121_t)}}, 0, 
	irq_stream16_handler, cmd_data121_pack, NULL},
	{17, "Первичные отметки режима ГЛ", 
	1, 0, {{0,0,0,sizeof(cmd_data124_t)}, {0,0,0,sizeof(cmd_data124_t)}}, 0, 
	irq_stream17_handler, cmd_data124_pack, NULL},
	{18, "Строки индикаторного процесса тракта обнаружения сигнала связи режима ЗПС", 
	1, 0, {{0,0,0,sizeof(cmd_data132_t)}, {0,0,0,sizeof(cmd_data132_t)}}, 0, 
	irq_stream18_handler, cmd_data132_pack, NULL},
	{19, "Формуляры режима ЗПС", 
	1, 0, {{0,0,0,sizeof(cmd_data135_t)}, {0,0,0,sizeof(cmd_data135_t)}}, 0, 
	irq_stream19_handler, cmd_data135_pack, NULL},
	{20, "Формуляры режима ШП", 
	1, 0, {{0,0,0,sizeof(cmd_data145_t)}, {0,0,0,sizeof(cmd_data145_t)}}, 0, 
	irq_stream20_handler, cmd_data145_pack, NULL},
	{21, "Формуляры режима ГЛ", 
	1, 0, {{0,0,0,sizeof(cmd_data154_t)}, {0,0,0,sizeof(cmd_data154_t)}}, 0, 
	irq_stream21_handler, cmd_data154_pack, NULL},
	{22, "Формуляры АСТД", 
	1, 0, {{0,0,0,sizeof(cmd_data174_t)}, {0,0,0,sizeof(cmd_data174_t)}}, 0, 
	irq_stream22_handler, cmd_data174_pack, NULL},
};

/* We allocate buf memory in heap, cause it's  too big for stack */
int
pgas_stream_init(void) {
	curl_handler = curl_easy_init();

	for(int i=0; i<PGAS_STREAM_MAX; i++) {
		pgas_stream[i].url = malloc(STREAM_URL_SIZE_MAX);
		pgas_stream[i].cbuf[0].buf = malloc(pgas_stream[i].cbuf[0].data_size*STREAM_DATA_SIZE_MAX);
		if(!pgas_stream[i].cbuf[0].buf)
			return -1;
		pgas_stream[i].cbuf[0].cbuf_size = STREAM_DATA_SIZE_MAX;
		pgas_stream[i].cbuf[1].buf = malloc(pgas_stream[i].cbuf[1].data_size*STREAM_DATA_SIZE_MAX);
		if(!pgas_stream[i].cbuf[1].buf)
			return -1;
		pgas_stream[i].cbuf[1].cbuf_size = STREAM_DATA_SIZE_MAX;
	}
	return 0;
}

int
pgas_stream_cleanup(void) {
	curl_easy_cleanup(curl_handler);

	for(int i=0; i<PGAS_STREAM_MAX; i++) {
		if(pgas_stream[i].url)
			free(pgas_stream[i].url);
		if(pgas_stream[i].cbuf[0].buf)
			free(pgas_stream[i].cbuf[0].buf);
		pgas_stream[i].cbuf[0].cbuf_size = 0;
		if(pgas_stream[i].cbuf[1].buf)
			free(pgas_stream[i].cbuf[1].buf);
		pgas_stream[i].cbuf[1].cbuf_size = 0;
	}
	return 0;
}


/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-14 11:48:51
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

/* PGAS/SKGP worker */
/* 1 Перезагрузка программного обеспечения ПГАС/СКГП */
int
worker_post_control_reboot(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data2_t* data_in = (cmd_data2_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Перезагрузка программного обеспечения ПГАС/СКГП\n", __func__, __LINE__);

	return ret;
}

/* 2 Отделение якорного устройства ПГАС/СКГП */
int
worker_post_control_resurface(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data5_t* data_in = (cmd_data5_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Отделение якорного устройства ПГАС/СКГП\n", __func__, __LINE__);

	return ret;
}

/* 3 Проведение функционального контроля ПГАС и перезагрузка ПГАС/СКГП */
int
worker_post_control_self_test(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data8_t* data_in = (cmd_data8_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Проведение функционального контроля ПГАС и перезагрузка ПГАС/СКГП\n", __func__, __LINE__);

	return ret;
}

/* 4 Запись образа, содержащего ПО ПГАС/СКГП, системные таблицы адресов и др., в программируемое ПЗУ ПГАС/СКГП */
int
worker_post_firmware_burn(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data12_t* data_in = (cmd_data12_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Запись образа, содержащего ПО ПГАС/СКГП, системные таблицы адресов и др., в программируемое ПЗУ ПГАС/СКГП\n", __func__, __LINE__);

	return ret;
}

/* 5 Запрос контрольной суммы образа программируемого ПЗУ ПГАС/СКГП */
int
worker_get_firmware_sha1(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data16_t* data_out = (cmd_data16_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос контрольной суммы образа программируемого ПЗУ ПГАС/СКГП\n", __func__, __LINE__);

	return ret;
}

/* 6 Запрос системного времени ПГАС/СКГП */
int
worker_get_rtc(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data19_t* data_out = (cmd_data19_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос системного времени ПГАС/СКГП\n", __func__, __LINE__);

	return ret;
}

/* 7 Установка системного времени ПГАС/СКГП (грубо) */
int
worker_post_rtc(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data19_t* data_in = (cmd_data19_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Установка системного времени ПГАС/СКГП (грубо)\n", __func__, __LINE__);

	return ret;
}

/* 8 Отключение неисправных линеек гидрофонов ПГА */
int
worker_put_antenna_defective_columns(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data24_t* data_in = (cmd_data24_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Отключение неисправных линеек гидрофонов ПГА\n", __func__, __LINE__);

	return ret;
}

/* 9 Запрос списка отключенных линеек гидрофонов ПГА */
int
worker_get_antenna_defective_columns(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data28_t* data_out = (cmd_data28_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос списка отключенных линеек гидрофонов ПГА\n", __func__, __LINE__);

	return ret;
}

/* 10 Установка гидрофизических параметров среды */
int
worker_put_env_params(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data30_t* data_in = (cmd_data30_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Установка гидрофизических параметров среды\n", __func__, __LINE__);

	return ret;
}

/* 11 Запрос гидрофизических параметров среды */
int
worker_get_env_params(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data36_t* data_out = (cmd_data36_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос гидрофизических параметров среды\n", __func__, __LINE__);

	return ret;
}

/* 12 Изменение расписания работы ПГАС в режиме ГЛ */
int
worker_patch_active_schedule(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data38_t* data_in = (cmd_data38_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Изменение расписания работы ПГАС в режиме ГЛ\n", __func__, __LINE__);

	return ret;
}

/* 13 Установка расписания работы ПГАС в режиме ГЛ */
int
worker_put_active_schedule(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data43_t* data_in = (cmd_data43_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Установка расписания работы ПГАС в режиме ГЛ\n", __func__, __LINE__);

	return ret;
}

/* 14 Запрос действующего расписания работы ПГАС в режиме ГЛ */
int
worker_get_active_schedule(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data47_t* data_out = (cmd_data47_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос действующего расписания работы ПГАС в режиме ГЛ\n", __func__, __LINE__);

	return ret;
}

/* 15 Изменение расписания работы ПГАС в режиме передачи по каналу ЗПС */
int
worker_patch_utcs_transmit_schedule(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data49_t* data_in = (cmd_data49_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Изменение расписания работы ПГАС в режиме передачи по каналу ЗПС\n", __func__, __LINE__);

	return ret;
}

/* 16 Установка расписания работы ПГАС в режиме передачи по каналу ЗПС */
int
worker_put_utcs_transmit_schedule(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data54_t* data_in = (cmd_data54_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Установка расписания работы ПГАС в режиме передачи по каналу ЗПС\n", __func__, __LINE__);

	return ret;
}

/* 17 Запрос действующего расписания работы ПГАС в режиме передачи по каналу ЗПС */
int
worker_get_utcs_transmit_schedule(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data58_t* data_out = (cmd_data58_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос действующего расписания работы ПГАС в режиме передачи по каналу ЗПС\n", __func__, __LINE__);

	return ret;
}

/* 18 Изменение расписания работы ВРМ */
int
worker_patch_satcom_schedule(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data60_t* data_in = (cmd_data60_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Изменение расписания работы ВРМ\n", __func__, __LINE__);

	return ret;
}

/* 19 Установка расписания работы ВРМ */
int
worker_patch_satcom_scheduleFIX(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data65_t* data_in = (cmd_data65_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Установка расписания работы ВРМ\n", __func__, __LINE__);

	return ret;
}

/* 20 Запрос действующего расписания работы ВРМ */
int
worker_get_satcom_schedule(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data69_t* data_out = (cmd_data69_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос действующего расписания работы ВРМ\n", __func__, __LINE__);

	return ret;
}

/* 21 Установка параметров обработки в режиме ШП */
int
worker_put_passive_processing_parameters(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data71_t* data_in = (cmd_data71_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Установка параметров обработки в режиме ШП\n", __func__, __LINE__);

	return ret;
}

/* 22 Изменение параметров обработки в режиме ШП */
int
worker_patch_passive_processing_parameters(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data71_t* data_in = (cmd_data71_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Изменение параметров обработки в режиме ШП\n", __func__, __LINE__);

	return ret;
}

/* 23 Запрос действующих параметров обработки в режиме ШП */
int
worker_get_passive_processing_parameters(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data71_t* data_out = (cmd_data71_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос действующих параметров обработки в режиме ШП\n", __func__, __LINE__);

	return ret;
}

/* 24 Наведение и установка параметров обработки в канале АСЦ */
int
worker_post_att_1(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data78_t* data_in = (cmd_data78_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Наведение и установка параметров обработки в канале АСЦ\n", __func__, __LINE__);

	return ret;
}

/* 25 Запрос действующих параметров канала АСЦ */
int
worker_get_att_1(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data82_t* data_out = (cmd_data82_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос действующих параметров канала АСЦ\n", __func__, __LINE__);

	return ret;
}

/* 26 Отмена АСЦ */
int
worker_delete_att_1(const char* param, void* in, void* out) {
	int ret = 0;
	printf("%s:%d: TDB!!! Отмена АСЦ\n", __func__, __LINE__);

	return ret;
}

/* 31 Запрос первичных отметок режима ШП */
int
worker_get_passive_marks(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data101_t* data_out = (cmd_data101_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос первичных отметок режима ШП\n", __func__, __LINE__);

	return ret;
}

/* 39 Запрос первичных отметок режима ГЛ */
int
worker_get_active_GET_ANGLE_ID_marks(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data129_t* data_out = (cmd_data129_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос первичных отметок режима ГЛ\n", __func__, __LINE__);

	return ret;
}

/* 42 Запрос формуляров режима ЗПС */
int
worker_get_utcs_inbox(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data142_t* data_out = (cmd_data142_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос формуляров режима ЗПС\n", __func__, __LINE__);

	return ret;
}

/* 44 Выдача формуляра режима ШП */
int
worker_get_passive_targets(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data151_t* data_out = (cmd_data151_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Выдача формуляра режима ШП\n", __func__, __LINE__);

	return ret;
}

/* 46 Запрос формуляров режима ГЛ */
int
worker_get_active_targets(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data160_t* data_out = (cmd_data160_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос формуляров режима ГЛ\n", __func__, __LINE__);

	return ret;
}

/* 47 Изменение параметров выдачи данных из ПГАС */
int
worker_patch_streams(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data163_t* data_in = (cmd_data163_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Изменение параметров выдачи данных из ПГАС\n", __func__, __LINE__);

	return ret;
}

/* 48 Установка параметров выдачи данных из ПГАС */
int
worker_put_streams(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data168_t* data_in = (cmd_data168_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Установка параметров выдачи данных из ПГАС\n", __func__, __LINE__);

	return ret;
}

/* 49 Запрос параметров выдачи данных из ПГАС */
int
worker_get_streams(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data172_t* data_out = (cmd_data172_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос параметров выдачи данных из ПГАС\n", __func__, __LINE__);

	return ret;
}

/* 51 Запрос формуляра режима АСТД */
int
worker_get_self_diagnosis(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data187_t* data_out = (cmd_data187_t*)out;
	if(!out) {
		printf("%s:%d: bad output data pointer %p.\n", __func__, __LINE__, data_out);
		return -1;
	}
	printf("%s:%d: TDB!!! Запрос формуляра режима АСТД\n", __func__, __LINE__);

	return ret;
}

/* 53 Изменение режима работы ПГАС/СКГП */
int
worker_post_control_set_mode(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data194_t* data_in = (cmd_data194_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Изменение режима работы ПГАС/СКГП\n", __func__, __LINE__);

	return ret;
}

/* SKGP worker */
/* 52 Команда на выполнение измерений ГФП */
int
worker_post_do_measurements(const char* param, void* in, void* out) {
	int ret = 0;
	cmd_data189_t* data_in = (cmd_data189_t*)in;
	if(!in) {
		printf("%s:%d: bad input data pointer %p.\n", __func__, __LINE__, data_in);
		return -1;
	}
	printf("%s:%d: TDB!!! Команда на выполнение измерений ГФП\n", __func__, __LINE__);

	return ret;
}


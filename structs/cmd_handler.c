/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-15 16:04:08
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

/* PGAS/SKGP handler */
/* 1 Перезагрузка программного обеспечения ПГАС/СКГП */
int
handler_post_control_reboot(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data2_unpack(stream_in, &offset, &cmd_data2);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_post_control_reboot(param, (void*)&cmd_data2, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 2 Отделение якорного устройства ПГАС/СКГП */
int
handler_post_control_resurface(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data5_unpack(stream_in, &offset, &cmd_data5);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_post_control_resurface(param, (void*)&cmd_data5, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 3 Проведение функционального контроля ПГАС и перезагрузка ПГАС/СКГП */
int
handler_post_control_self_test(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data8_unpack(stream_in, &offset, &cmd_data8);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_post_control_self_test(param, (void*)&cmd_data8, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 4 Запись образа, содержащего ПО ПГАС/СКГП, системные таблицы адресов и др., в программируемое ПЗУ ПГАС/СКГП */
int
handler_post_firmware_burn(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data12_unpack(stream_in, &offset, &cmd_data12);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_post_firmware_burn(param, (void*)&cmd_data12, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 5 Запрос контрольной суммы образа программируемого ПЗУ ПГАС/СКГП */
int
handler_get_firmware_sha1(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_firmware_sha1(param, NULL, (void*)&cmd_data16);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data16_pack(stream_out, (void*)&cmd_data16);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 6 Запрос системного времени ПГАС/СКГП */
int
handler_get_rtc(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_rtc(param, NULL, (void*)&cmd_data19);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data19_pack(stream_out, (void*)&cmd_data19);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 7 Установка системного времени ПГАС/СКГП (грубо) */
int
handler_post_rtc(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data19_unpack(stream_in, &offset, &cmd_data19);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_post_rtc(param, (void*)&cmd_data19, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 8 Отключение неисправных линеек гидрофонов ПГА */
int
handler_put_antenna_defective_columns(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data24_unpack(stream_in, &offset, &cmd_data24);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_put_antenna_defective_columns(param, (void*)&cmd_data24, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 9 Запрос списка отключенных линеек гидрофонов ПГА */
int
handler_get_antenna_defective_columns(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_antenna_defective_columns(param, NULL, (void*)&cmd_data28);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data28_pack(stream_out, (void*)&cmd_data28);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 10 Установка гидрофизических параметров среды */
int
handler_put_env_params(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data30_unpack(stream_in, &offset, &cmd_data30);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_put_env_params(param, (void*)&cmd_data30, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 11 Запрос гидрофизических параметров среды */
int
handler_get_env_params(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_env_params(param, NULL, (void*)&cmd_data36);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data36_pack(stream_out, (void*)&cmd_data36);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 12 Изменение расписания работы ПГАС в режиме ГЛ */
int
handler_patch_active_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data38_unpack(stream_in, &offset, &cmd_data38);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_patch_active_schedule(param, (void*)&cmd_data38, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 13 Установка расписания работы ПГАС в режиме ГЛ */
int
handler_put_active_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data43_unpack(stream_in, &offset, &cmd_data43);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_put_active_schedule(param, (void*)&cmd_data43, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 14 Запрос действующего расписания работы ПГАС в режиме ГЛ */
int
handler_get_active_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_active_schedule(param, NULL, (void*)&cmd_data47);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data47_pack(stream_out, (void*)&cmd_data47);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 15 Изменение расписания работы ПГАС в режиме передачи по каналу ЗПС */
int
handler_patch_utcs_transmit_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data49_unpack(stream_in, &offset, &cmd_data49);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_patch_utcs_transmit_schedule(param, (void*)&cmd_data49, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 16 Установка расписания работы ПГАС в режиме передачи по каналу ЗПС */
int
handler_put_utcs_transmit_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data54_unpack(stream_in, &offset, &cmd_data54);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_put_utcs_transmit_schedule(param, (void*)&cmd_data54, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 17 Запрос действующего расписания работы ПГАС в режиме передачи по каналу ЗПС */
int
handler_get_utcs_transmit_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_utcs_transmit_schedule(param, NULL, (void*)&cmd_data58);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data58_pack(stream_out, (void*)&cmd_data58);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 18 Изменение расписания работы ВРМ */
int
handler_patch_satcom_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data60_unpack(stream_in, &offset, &cmd_data60);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_patch_satcom_schedule(param, (void*)&cmd_data60, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 19 Установка расписания работы ВРМ */
int
handler_patch_satcom_scheduleFIX(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data65_unpack(stream_in, &offset, &cmd_data65);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_patch_satcom_scheduleFIX(param, (void*)&cmd_data65, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 20 Запрос действующего расписания работы ВРМ */
int
handler_get_satcom_schedule(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_satcom_schedule(param, NULL, (void*)&cmd_data69);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data69_pack(stream_out, (void*)&cmd_data69);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 21 Установка параметров обработки в режиме ШП */
int
handler_put_passive_processing_parameters(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data71_unpack(stream_in, &offset, &cmd_data71);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_put_passive_processing_parameters(param, (void*)&cmd_data71, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 22 Изменение параметров обработки в режиме ШП */
int
handler_patch_passive_processing_parameters(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data71_unpack(stream_in, &offset, &cmd_data71);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_patch_passive_processing_parameters(param, (void*)&cmd_data71, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 23 Запрос действующих параметров обработки в режиме ШП */
int
handler_get_passive_processing_parameters(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_passive_processing_parameters(param, NULL, (void*)&cmd_data71);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data71_pack(stream_out, (void*)&cmd_data71);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 24 Наведение и установка параметров обработки в канале АСЦ */
int
handler_post_att_1(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data78_unpack(stream_in, &offset, &cmd_data78);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_post_att_1(param, (void*)&cmd_data78, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 25 Запрос действующих параметров канала АСЦ */
int
handler_get_att_1(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_att_1(param, NULL, (void*)&cmd_data82);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data82_pack(stream_out, (void*)&cmd_data82);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 26 Отмена АСЦ */
int
handler_delete_att_1(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_delete_att_1(param, NULL, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 31 Запрос первичных отметок режима ШП */
int
handler_get_passive_marks(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_passive_marks(param, NULL, (void*)&cmd_data101);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data101_pack(stream_out, (void*)&cmd_data101);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 39 Запрос первичных отметок режима ГЛ */
int
handler_get_active_GET_ANGLE_ID_marks(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_active_GET_ANGLE_ID_marks(param, NULL, (void*)&cmd_data129);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data129_pack(stream_out, (void*)&cmd_data129);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 42 Запрос формуляров режима ЗПС */
int
handler_get_utcs_inbox(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_utcs_inbox(param, NULL, (void*)&cmd_data142);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data142_pack(stream_out, (void*)&cmd_data142);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 44 Выдача формуляра режима ШП */
int
handler_get_passive_targets(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_passive_targets(param, NULL, (void*)&cmd_data151);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data151_pack(stream_out, (void*)&cmd_data151);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 46 Запрос формуляров режима ГЛ */
int
handler_get_active_targets(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_active_targets(param, NULL, (void*)&cmd_data160);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data160_pack(stream_out, (void*)&cmd_data160);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 47 Изменение параметров выдачи данных из ПГАС */
int
handler_patch_streams(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data163_unpack(stream_in, &offset, &cmd_data163);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_patch_streams(param, (void*)&cmd_data163, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 48 Установка параметров выдачи данных из ПГАС */
int
handler_put_streams(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data168_unpack(stream_in, &offset, &cmd_data168);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_put_streams(param, (void*)&cmd_data168, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 49 Запрос параметров выдачи данных из ПГАС */
int
handler_get_streams(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_streams(param, NULL, (void*)&cmd_data172);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data172_pack(stream_out, (void*)&cmd_data172);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 51 Запрос формуляра режима АСТД */
int
handler_get_self_diagnosis(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;

	if(param)
		printf("param: %s\n", param);

	/* command worker */
	ret = worker_get_self_diagnosis(param, NULL, (void*)&cmd_data187);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	ret = cmd_data187_pack(stream_out, (void*)&cmd_data187);
	if(ret == 0) {
		goto fail;
	}
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* 53 Изменение режима работы ПГАС/СКГП */
int
handler_post_control_set_mode(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data194_unpack(stream_in, &offset, &cmd_data194);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_post_control_set_mode(param, (void*)&cmd_data194, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}

/* SKGP handler */
/* 52 Команда на выполнение измерений ГФП */
int
handler_post_do_measurements(const char* param, cbor_stream_t *stream_in, cbor_stream_t *stream_out) {
	int ret = 0;
	size_t offset = 0;

	if(param)
		printf("param: %s\n", param);
	/* Input data */
	printf("REQUEST DATA : %lu byte\n", stream_in->size);
	if(stream_in->size <= 0) {
		goto fail;
	}
	ret = cmd_data189_unpack(stream_in, &offset, &cmd_data189);
	if(ret == 0) {
		goto fail;
	}

	/* command worker */
	ret = worker_post_do_measurements(param, (void*)&cmd_data189, NULL);
	if(ret != 0) {
		goto fail;
	}

	/* Output data */
	printf("RESPONSE DATA : %lu byte\n", stream_out->pos);

	return 200;
fail:
	return 400;
}


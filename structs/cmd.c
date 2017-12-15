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

cmd_t pgas_cmd[] = {
	{"Перезагрузка программного обеспечения ПГАС/СКГП",
	"/control/reboot", "POST",
	&handler_post_control_reboot},
	{"Отделение якорного устройства ПГАС/СКГП",
	"/control/resurface", "POST",
	&handler_post_control_resurface},
	{"Проведение функционального контроля ПГАС и перезагрузка ПГАС/СКГП",
	"/control/self-test", "POST",
	&handler_post_control_self_test},
	{"Запись образа, содержащего ПО ПГАС/СКГП, системные таблицы адресов и др., в программируемое ПЗУ ПГАС/СКГП",
	"/firmware/burn", "POST",
	&handler_post_firmware_burn},
	{"Запрос контрольной суммы образа программируемого ПЗУ ПГАС/СКГП",
	"/firmware/sha1", "GET",
	&handler_get_firmware_sha1},
	{"Запрос системного времени ПГАС/СКГП",
	"/rtc", "GET",
	&handler_get_rtc},
	{"Установка системного времени ПГАС/СКГП (грубо)",
	"/rtc", "POST",
	&handler_post_rtc},
	{"Отключение неисправных линеек гидрофонов ПГА",
	"/antenna/defective-columns", "PUT",
	&handler_put_antenna_defective_columns},
	{"Запрос списка отключенных линеек гидрофонов ПГА",
	"/antenna/defective-columns", "GET",
	&handler_get_antenna_defective_columns},
	{"Установка гидрофизических параметров среды",
	"/env-params", "PUT",
	&handler_put_env_params},
	{"Запрос гидрофизических параметров среды",
	"/env-params", "GET",
	&handler_get_env_params},
	{"Изменение расписания работы ПГАС в режиме ГЛ",
	"/active/schedule", "PATCH",
	&handler_patch_active_schedule},
	{"Установка расписания работы ПГАС в режиме ГЛ",
	"/active/schedule", "PUT",
	&handler_put_active_schedule},
	{"Запрос действующего расписания работы ПГАС в режиме ГЛ",
	"/active/schedule", "GET",
	&handler_get_active_schedule},
	{"Изменение расписания работы ПГАС в режиме передачи по каналу ЗПС",
	"/utcs/transmit-schedule", "PATCH",
	&handler_patch_utcs_transmit_schedule},
	{"Установка расписания работы ПГАС в режиме передачи по каналу ЗПС",
	"/utcs/transmit-schedule", "PUT",
	&handler_put_utcs_transmit_schedule},
	{"Запрос действующего расписания работы ПГАС в режиме передачи по каналу ЗПС",
	"/utcs/transmit-schedule", "GET",
	&handler_get_utcs_transmit_schedule},
	{"Изменение расписания работы ВРМ",
	"/satcom/schedule", "PATCH",
	&handler_patch_satcom_schedule},
	{"Установка расписания работы ВРМ",
	"/satcom/scheduleFIX", "PATCH",
	&handler_patch_satcom_scheduleFIX},
	{"Запрос действующего расписания работы ВРМ",
	"/satcom/schedule", "GET",
	&handler_get_satcom_schedule},
	{"Установка параметров обработки в режиме ШП",
	"/passive/processing-parameters", "PUT",
	&handler_put_passive_processing_parameters},
	{"Изменение параметров обработки в режиме ШП",
	"/passive/processing-parameters", "PATCH",
	&handler_patch_passive_processing_parameters},
	{"Запрос действующих параметров обработки в режиме ШП",
	"/passive/processing-parameters", "GET",
	&handler_get_passive_processing_parameters},
	{"Наведение и установка параметров обработки в канале АСЦ",
	"/att/1", "POST",
	&handler_post_att_1},
	{"Запрос действующих параметров канала АСЦ",
	"/att/1", "GET",
	&handler_get_att_1},
	{"Отмена АСЦ",
	"/att/1", "DELETE",
	&handler_delete_att_1},
	{"Запрос первичных отметок режима ШП",
	"/passive/marks", "GET",
	&handler_get_passive_marks},
	{"Запрос первичных отметок режима ГЛ",
	"/active/GET_ANGLE_ID/marks", "GET",
	&handler_get_active_GET_ANGLE_ID_marks},
	{"Запрос формуляров режима ЗПС",
	"/utcs/inbox", "GET",
	&handler_get_utcs_inbox},
	{"Выдача формуляра режима ШП",
	"/passive/targets", "GET",
	&handler_get_passive_targets},
	{"Запрос формуляров режима ГЛ",
	"/active/targets", "GET",
	&handler_get_active_targets},
	{"Изменение параметров выдачи данных из ПГАС",
	"/streams", "PATCH",
	&handler_patch_streams},
	{"Установка параметров выдачи данных из ПГАС",
	"/streams", "PUT",
	&handler_put_streams},
	{"Запрос параметров выдачи данных из ПГАС",
	"/streams", "GET",
	&handler_get_streams},
	{"Запрос формуляра режима АСТД",
	"/self-diagnosis", "GET",
	&handler_get_self_diagnosis},
	{"Изменение режима работы ПГАС/СКГП",
	"/control/set-mode", "POST",
	&handler_post_control_set_mode},
};

cmd_t skgp_cmd[] = {
	{"Перезагрузка программного обеспечения ПГАС/СКГП",
	"/control/reboot", "POST",
	&handler_post_control_reboot},
	{"Отделение якорного устройства ПГАС/СКГП",
	"/control/resurface", "POST",
	&handler_post_control_resurface},
	{"Проведение функционального контроля ПГАС и перезагрузка ПГАС/СКГП",
	"/control/self-test", "POST",
	&handler_post_control_self_test},
	{"Запись образа, содержащего ПО ПГАС/СКГП, системные таблицы адресов и др., в программируемое ПЗУ ПГАС/СКГП",
	"/firmware/burn", "POST",
	&handler_post_firmware_burn},
	{"Запрос контрольной суммы образа программируемого ПЗУ ПГАС/СКГП",
	"/firmware/sha1", "GET",
	&handler_get_firmware_sha1},
	{"Запрос системного времени ПГАС/СКГП",
	"/rtc", "GET",
	&handler_get_rtc},
	{"Установка системного времени ПГАС/СКГП (грубо)",
	"/rtc", "POST",
	&handler_post_rtc},
	{"Изменение расписания работы ВРМ",
	"/satcom/schedule", "PATCH",
	&handler_patch_satcom_schedule},
	{"Установка расписания работы ВРМ",
	"/satcom/scheduleFIX", "PATCH",
	&handler_patch_satcom_scheduleFIX},
	{"Запрос действующего расписания работы ВРМ",
	"/satcom/schedule", "GET",
	&handler_get_satcom_schedule},
	{"Запрос формуляра режима АСТД",
	"/self-diagnosis", "GET",
	&handler_get_self_diagnosis},
	{"Изменение режима работы ПГАС/СКГП",
	"/control/set-mode", "POST",
	&handler_post_control_set_mode},
	{"Команда на выполнение измерений ГФП",
	"/do-measurements", "POST",
	&handler_post_do_measurements},
};


/*
 * GENERATED AUTOMATICALLY DO NOT FIX
 * 2017-12-13 16:19:47
 */

#ifndef HTML_H
#define HTML_H

#ifdef __cplusplus
extern "C" {
#endif


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


#define PAGE_PGAS "<html><head><meta charset='utf-8'><title>PGAS</title></head><body>\n"\
	"<table border='0' cellpadding='0' cellspacing='0' style='font-size:16px' margin='0' padding='0'>"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/control/reboot' method='POST'><button>request</button><label>1 - Перезагрузка программного обеспечения ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/control/resurface' method='POST'><button>request</button><label>2 - Отделение якорного устройства ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/control/self-test' method='POST'><button>request</button><label>3 - Проведение функционального контроля ПГАС и перезагрузка ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/firmware/burn' method='POST'><button>request</button><label>4 - Запись образа, содержащего ПО ПГАС/СКГП, системные таблицы адресов и др., в программируемое ПЗУ ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/firmware/sha1' method='GET'><button>request</button><label>5 - Запрос контрольной суммы образа программируемого ПЗУ ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/rtc' method='GET'><button>request</button><label>6 - Запрос системного времени ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/rtc' method='POST'><button>request</button><label>7 - Установка системного времени ПГАС/СКГП (грубо)</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/antenna/defective-columns' method='PUT'><button>request</button><label>8 - Отключение неисправных линеек гидрофонов ПГА</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/antenna/defective-columns' method='GET'><button>request</button><label>9 - Запрос списка отключенных линеек гидрофонов ПГА</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/env-params' method='PUT'><button>request</button><label>10 - Установка гидрофизических параметров среды</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/env-params' method='GET'><button>request</button><label>11 - Запрос гидрофизических параметров среды</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/active/schedule' method='PATCH'><button>request</button><label>12 - Изменение расписания работы ПГАС в режиме ГЛ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/active/schedule' method='PUT'><button>request</button><label>13 - Установка расписания работы ПГАС в режиме ГЛ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/active/schedule' method='GET'><button>request</button><label>14 - Запрос действующего расписания работы ПГАС в режиме ГЛ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/utcs/transmit-schedule' method='PATCH'><button>request</button><label>15 - Изменение расписания работы ПГАС в режиме передачи по каналу ЗПС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/utcs/transmit-schedule' method='PUT'><button>request</button><label>16 - Установка расписания работы ПГАС в режиме передачи по каналу ЗПС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/utcs/transmit-schedule' method='GET'><button>request</button><label>17 - Запрос действующего расписания работы ПГАС в режиме передачи по каналу ЗПС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/satcom/schedule' method='PATCH'><button>request</button><label>18 - Изменение расписания работы ВРМ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/satcom/scheduleFIX' method='PATCH'><button>request</button><label>19 - Установка расписания работы ВРМ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/satcom/schedule' method='GET'><button>request</button><label>20 - Запрос действующего расписания работы ВРМ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/passive/processing-parameters' method='PUT'><button>request</button><label>21 - Установка параметров обработки в режиме ШП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/passive/processing-parameters' method='PATCH'><button>request</button><label>22 - Изменение параметров обработки в режиме ШП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/passive/processing-parameters' method='GET'><button>request</button><label>23 - Запрос действующих параметров обработки в режиме ШП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/att/1' method='POST'><button>request</button><label>24 - Наведение и установка параметров обработки в канале АСЦ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/att/1' method='GET'><button>request</button><label>25 - Запрос действующих параметров канала АСЦ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/att/1' method='DELETE'><button>request</button><label>26 - Отмена АСЦ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/passive/marks' method='GET'><button>request</button><labe>from</label><input type='text' name='from'/><labe>to</label><input type='text' name='to'/><label>31 - Запрос первичных отметок режима ШП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/active/<Уникальный идентификатор цикла развертки>/marks' method='GET'><button>request</button><label>39 - Запрос первичных отметок режима ГЛ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/utcs/inbox' method='GET'><button>request</button><labe>from</label><input type='text' name='from'/><labe>to</label><input type='text' name='to'/><label>42 - Запрос формуляров режима ЗПС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/passive/targets' method='GET'><button>request</button><label>44 - Выдача формуляра режима ШП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/active/targets' method='GET'><button>request</button><label>46 - Запрос формуляров режима ГЛ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/streams' method='PATCH'><button>request</button><label>47 - Изменение параметров выдачи данных из ПГАС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/streams' method='PUT'><button>request</button><label>48 - Установка параметров выдачи данных из ПГАС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/streams' method='GET'><button>request</button><label>49 - Запрос параметров выдачи данных из ПГАС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/self-diagnosis' method='GET'><button>request</button><label>51 - Запрос формуляра режима АСТД</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/control/set-mode' method='POST'><button>request</button><label>53 - Изменение режима работы ПГАС/СКГП</label></form>\n"\
	"</table>"\
	"</body></html>"
#define PAGE_SKGP "<html><head><meta charset='utf-8'><title>SKGP</title></head><body>\n"\
	"<table border='0' cellpadding='0' cellspacing='0' style='font-size:16px' margin='0' padding='0'>"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/control/reboot' method='POST'><button>request</button><label>1 - Перезагрузка программного обеспечения ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/control/resurface' method='POST'><button>request</button><label>2 - Отделение якорного устройства ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/control/self-test' method='POST'><button>request</button><label>3 - Проведение функционального контроля ПГАС и перезагрузка ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/firmware/burn' method='POST'><button>request</button><label>4 - Запись образа, содержащего ПО ПГАС/СКГП, системные таблицы адресов и др., в программируемое ПЗУ ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/firmware/sha1' method='GET'><button>request</button><label>5 - Запрос контрольной суммы образа программируемого ПЗУ ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/rtc' method='GET'><button>request</button><label>6 - Запрос системного времени ПГАС/СКГП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/rtc' method='POST'><button>request</button><label>7 - Установка системного времени ПГАС/СКГП (грубо)</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/satcom/schedule' method='PATCH'><button>request</button><label>18 - Изменение расписания работы ВРМ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/satcom/scheduleFIX' method='PATCH'><button>request</button><label>19 - Установка расписания работы ВРМ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/satcom/schedule' method='GET'><button>request</button><label>20 - Запрос действующего расписания работы ВРМ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/self-diagnosis' method='GET'><button>request</button><label>51 - Запрос формуляра режима АСТД</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/control/set-mode' method='POST'><button>request</button><label>53 - Изменение режима работы ПГАС/СКГП</label></form>\n"\
	"</table>"\
	"<table border='0' cellpadding='0' cellspacing='0' style='font-size:16px' margin='0' padding='0'>"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='/do-measurements' method='POST'><button>request</button><label>52 - Команда на выполнение измерений ГФП</label></form>\n"\
	"</table>"\
	"</body></html>"
#define PAGE_PU "<html><head><meta charset='utf-8'><title>PU</title></head><body>\n"\
	"<table border='0' cellpadding='0' cellspacing='0' style='font-size:16px' margin='0' padding='0'>"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>‑<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>27 - Выдача энергетических спектров сигналов в линейках ПГА</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>‑<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>28 - Выдача нормированных энергетических спектров сигналов в ПК</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>‑<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>29 - Выдача строки индикаторного процесса режима ШП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>-<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>30 - Выдача первичных отметок режима ШП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>‑<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>32 - Выдача сегмента отсчетов сигнала в КИС или в канале АСЦ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>‑<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>33 - Выдача энергетических спектров сигналов несущей, огибающей (в диапазоне ВЛМ) или огибающей (в диапазоне МК) в КИС/канале АСЦ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>-<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>34 - Выдача отметок ДС энергетических спектров сигналов несущей, огибающей (в диапазоне ВЛМ) или огибающей (в диапазоне МК) в КИС/канале АСЦ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>‑<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>35 - Выдача отсчетов АКФ в КИС/канале АСЦ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>-<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>36 - Выдача отметок АКФ сигнала в КИС/канале АСЦ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>‑<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>37 - Выдача строки индикаторного процесса режима ГЛ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>-<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>38 - Выдача строки индикаторного процесса режима ГЛ</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>‑<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>40 - Выдача строки индикаторного процесса тракта обнаружения связи режима ЗПС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Штамп времени>-<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>41 - Выдача формуляра режима ЗПС</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Идентификатор цели>/<Штамп времени>-<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>43 - Выдача формуляра режима ШП</label></form>\n"\
	"<tr><td margin='0' padding='0'><form target='_blank'action='<base-url>/<Идентификатор цели>/<Штамп времени>-<Код потока>' method='PUT'><button>request</button><labe>base-url-query</label><input type='text' name='base-url-query'/><label>45 - Выдача формуляра режима ГЛ</label></form>\n"\
	"</table>"\
	"</body></html>"
#ifdef __cplusplus
}
#endif


#endif


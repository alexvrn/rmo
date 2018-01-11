#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H

#include <QMap>
#include <QVariantMap>

namespace CommandType
{
  enum Command
  {
    // Номера потоков
    Stream_1  = 1, // Энергетические спектры сигналов в линейках ПГА
    Stream_2  = 2, // Нормированные энергетические спектры сигналов в ПК в рабочей полосе станции
    Stream_3  = 3, // Строки индикаторного процесса режима ШП в ЧД-1
    Stream_4  = 4, // Строки индикаторного процесса режима ШП в ЧД-2
    Stream_5  = 5, // Первичные отметки режима ШП в ЧД‑1
    Stream_6  = 6, // Первичные отметки режима ШП в ЧД‑2
    Stream_7  = 7, // Сегменты отсчетов сигнала в КИС или в канале АСЦ
    Stream_8  = 8, // Энергетические спектры несущей сигнала в КИС или в канале АСЦ
    Stream_9  = 9, // Отметки ДС в спектре несущей сигнала в КИС или в канале АСЦ
    Stream_10 = 10, // Энергетические спектры в диапазоне ВЛМ сигнала огибающей в КИС или в канале АСЦ
    Stream_11 = 11, // Отметки ДС спектра в диапазоне ВЛМ сигнала огибающей в КИС или в канале АСЦ
    Stream_12 = 12, // Энергетические спектры в диапазоне МК сигнала огибающей в КИС или в канале АСЦ
    Stream_13 = 13, // Отметки ДС спектра в диапазоне МК сигнала огибающей в КИС или в канале АСЦ
    Stream_14 = 14, // Отсчеты АКФ сигнала в КИС или в канале АСЦ
    Stream_15 = 15, // Отметки АКФ сигнала в КИС или в канале АСЦ
    Stream_16 = 16, // Строки индикаторного процесса режима ГЛ
    Stream_17 = 17, // Первичные отметки режима ГЛ
    Stream_18 = 18, // Строки индикаторного процесса тракта обнаружения сигнала связи режима ЗПС
    Stream_19 = 19, // Формуляры режима ЗПС
    Stream_20 = 20, // Формуляры режима ШП
    Stream_21 = 21, // Формуляры режима ГЛ
    Stream_22 = 22, // Формуляры АСТД

    // Команды
    CMD_RequestData_DateTime = 50,
    CMD_PGAS_Data = 51
  };
}

typedef QHash<int, QHash<CommandType::Command, QList<QVariantMap> > > PgasData;

#endif // COMMANDTYPE_H

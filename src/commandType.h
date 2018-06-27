#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H

// Qt
#include <QMap>
#include <QVariantMap>

// cmd
#include <cmd.h>

// <Номер ПГАС, данные>
typedef QHash<int, QHash<cmd_e, QList<QVariantMap> > > PgasData;

#endif // COMMANDTYPE_H

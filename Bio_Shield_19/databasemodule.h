#ifndef DATABASEMODULE_H
#define DATABASEMODULE_H

#include <QtSql>
#include <QFileInfo>
#include "globlevariables.h"

class DataBaseModule
{
public:
    DataBaseModule();

    void DataBase(void);
    void DataBaseInit(void);
    void DataInject(const QString s);

private:
    QSqlDatabase mydb;
};

#endif // DATABASEMODULE_H

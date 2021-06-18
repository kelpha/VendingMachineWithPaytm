#include "databasemodule.h"

DataBaseModule::DataBaseModule()
{
   DataBaseInit();
}


void DataBaseModule::DataBase(void)
{
    if(!mydb.open())
    {
        qDebug()<<"DataBase Canot open";
    }
    QSqlQuery qry;
    qry.exec("select Unit_price,stock_1,stock_2,stock_3,stock_4,Paytm_link_1,Paytm_link_2,Serial_no from General_setting");
    while(qry.next())
    {
       Unit_price=qry.value(0).toInt();
       stock_1=qry.value(1).toInt();
       stock_2=qry.value(2).toInt();
       stock_3=qry.value(3).toInt();
       stock_4=qry.value(4).toInt();
       Paytm_link_1=qry.value(5).toString();
       Paytm_link_2=qry.value(6).toString();
       Serial_no = qry.value(7).toString();
    }

}
void DataBaseModule::DataBaseInit(void)
{
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/pi/Bio_shield");

}
void DataBaseModule::DataInject(const QString s)
{
    if(!mydb.open())
    {
        qDebug()<<"DataBase Canot open";
    }

    QSqlQuery qry;
    qry.prepare(s);
    if(!qry.exec())
    {
        qDebug()<<qry.lastError();
    }
    else
    {
        qDebug()<<"updates sucessfully..!";
    }


}

#include "homescreen.h"
#include "ui_homescreen.h"


Homescreen::Homescreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Homescreen)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    QWidget::showMaximized();


    GlobleVariables variable;
    variable.InitVariable();

    DataBaseModule db;
    db.DataBase();

    setting_count=0;
    t_reset = new QTimer;
    connect(t_reset,SIGNAL(timeout()),this,SLOT(setting_count_reset()));

}

Homescreen::~Homescreen()
{
    delete ui;
}

void Homescreen::on_btnClose_clicked()
{
    close();
}

void Homescreen::on_btnContinue_clicked()
{
    int total_stock = stock_1+stock_2+stock_3+stock_4;
    if(total_stock<=0)
    {
        OutOfStock w;
        w.setModal(true);
        w.exec();
    }
    else {
        QROnline w;
        w.setModal(true);
        w.exec();
    }


}

void Homescreen::on_btnSetting_clicked()
{
    setting_count++;
    t_reset->start(1000);
    if(setting_count>=5)
    {
        setting_count=0;
        PasswordScreen w;
        w.setModal(true);
        w.exec();
    }
}

void Homescreen::setting_count_reset()
{
    t_reset->stop();
    setting_count=0;
}

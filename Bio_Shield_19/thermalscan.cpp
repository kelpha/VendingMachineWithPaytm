#include "thermalscan.h"
#include "ui_thermalscan.h"

ThermalScan::ThermalScan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThermalScan)
{
    ui->setupUi(this);

    if(TestApp==true)
    {
        setWindowFlag(Qt::FramelessWindowHint);
        QWidget::showMaximized();
    }

    t = new QTimer;
    connect(t,SIGNAL(timeout()),this,SLOT(close()));
    t->start(2000);
}

ThermalScan::~ThermalScan()
{
    delete ui;
}

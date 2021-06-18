#include "thermalscanproxymity.h"
#include "ui_thermalscanproxymity.h"

ThermalScanProxymity::ThermalScanProxymity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThermalScanProxymity)
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

ThermalScanProxymity::~ThermalScanProxymity()
{
    delete ui;
}

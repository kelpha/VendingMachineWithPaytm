#include "outofstock.h"
#include "ui_outofstock.h"

OutOfStock::OutOfStock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutOfStock)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    QWidget::showMaximized();

    t = new QTimer;
    connect(t,SIGNAL(timeout()),this,SLOT(timeout_routine()));
    t->start(2000);
}

OutOfStock::~OutOfStock()
{
    delete ui;
}

void OutOfStock::timeout_routine(void)
{
    t->stop();
    close();
}

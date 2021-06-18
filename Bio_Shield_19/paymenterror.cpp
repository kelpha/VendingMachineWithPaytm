#include "paymenterror.h"
#include "ui_paymenterror.h"

PaymentError::PaymentError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentError)
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

PaymentError::~PaymentError()
{
    delete ui;
}

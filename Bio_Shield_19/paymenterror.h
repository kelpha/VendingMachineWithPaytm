#ifndef PAYMENTERROR_H
#define PAYMENTERROR_H

#include <QDialog>
#include <QTimer>
#include "globlevariables.h"

namespace Ui {
class PaymentError;
}

class PaymentError : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentError(QWidget *parent = nullptr);
    ~PaymentError();

private:
    Ui::PaymentError *ui;
    QTimer *t;

};

#endif // PAYMENTERROR_H

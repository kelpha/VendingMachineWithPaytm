#ifndef PAYMENTCONFIRMATION_H
#define PAYMENTCONFIRMATION_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <wiringPi.h>
#include "globlevariables.h"
#include "exitpage.h"
#include "databasemodule.h"


#define MOTOR_1_PIN     29
#define MOTOR_2_PIN     28
#define MOTOR_3_PIN     25
#define MOTOR_4_PIN     27
#define LED_RED_PIN     21
#define LED_GREEN_PIN   0
#define SWITCH_1_PIN      24
#define SWITCH_2_PIN      23
#define SWITCH_3_PIN      26
#define SWITCH_4_PIN      22



namespace Ui {
class PaymentConfirmation;
}

class PaymentConfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentConfirmation(QWidget *parent = nullptr);
    ~PaymentConfirmation();

private slots:
    void DispanceKit();
    void toggleRedGreenLed();


    void on_btnClose_clicked();

private:
    Ui::PaymentConfirmation *ui;
    QTimer *t;
    QTimer *t_blink;
    int toggle_status=0;
    uint8_t toggle_exit_counter=0;
    bool motor_rotate=false;
    DataBaseModule db;

};

#endif // PAYMENTCONFIRMATION_H

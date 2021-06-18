#include "paymentconfirmation.h"
#include "ui_paymentconfirmation.h"

PaymentConfirmation::PaymentConfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentConfirmation)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    QWidget::showMaximized();
    motor_rotate=false;
    wiringPiSetup();
    pinMode(MOTOR_1_PIN,OUTPUT);
    pinMode(MOTOR_2_PIN,OUTPUT);
    pinMode(MOTOR_3_PIN,OUTPUT);
    pinMode(MOTOR_4_PIN,OUTPUT);
    pinMode(LED_RED_PIN,OUTPUT);
    pinMode(LED_GREEN_PIN,OUTPUT);

    pinMode(SWITCH_1_PIN,INPUT);
    pullUpDnControl(SWITCH_1_PIN,PUD_UP);

    pinMode(SWITCH_2_PIN,INPUT);
    pullUpDnControl(SWITCH_2_PIN,PUD_UP);

    if(TestApp==true)
    {
        setWindowFlag(Qt::FramelessWindowHint);
        QWidget::showMaximized();
    }

    t_blink = new QTimer;
    connect(t_blink,SIGNAL(timeout()),this,SLOT(toggleRedGreenLed()));



    t = new QTimer;
    connect(t,SIGNAL(timeout()),this,SLOT(DispanceKit()));
    t->start(2000);
}

PaymentConfirmation::~PaymentConfirmation()
{
    delete ui;
}

void PaymentConfirmation::DispanceKit(void)
{
    t->stop();
    qDebug()<<"Kit is dispancing here";
    if((dis_count==1||dis_count>2)&&motor_rotate==false)
    {
        dis_count=1;
        if(stock_1>0)
        {
             digitalWrite(MOTOR_1_PIN,HIGH);
             QThread::msleep(500);
             here1:
             while(digitalRead(SWITCH_1_PIN)==0);
             QThread::msleep(1);
             if(digitalRead(SWITCH_1_PIN)==1)
             {
                 digitalWrite(MOTOR_1_PIN,LOW);
                 stock_1--;
                 motor_rotate=true;
             }
             else {
                 goto here1;
             }
        }
        dis_count++;
    }
    if(dis_count==2&&motor_rotate==false)
    {
        if(stock_2>0)
        {
             digitalWrite(MOTOR_2_PIN,HIGH);
             QThread::msleep(500);
             here2:
             while(digitalRead(SWITCH_2_PIN)==0);
             QThread::msleep(1);
             if(digitalRead(SWITCH_2_PIN)==1)
             {
                 digitalWrite(MOTOR_2_PIN,LOW);
                 stock_2--;
                 motor_rotate=true;
             }
             else {
                 goto here2;
             }
        }
        dis_count++;
    }
//    dispence_Count=10;
//    while(dispence_Count==10)
//    {
//        if(dis_count==1)
//        {
//            digitalWrite(MOTOR_1_PIN,HIGH);
//            qDebug()<<"inside dispence_count";

//            QThread::msleep(500);
//            here:
//            while(digitalRead(SWITCH_1_PIN)==0);
//            QThread::msleep(1);
//            if(digitalRead(SWITCH_1_PIN)==1)
//            {

//                digitalWrite(MOTOR_1_PIN,LOW);
//                dispence_Count--;
//                dis_count=2;
//            }
//            else {
//                goto here;
//            }
//        }
//        else {
//            digitalWrite(MOTOR_2_PIN,HIGH);
//            qDebug()<<"inside dispence_count";

//            QThread::msleep(500);
//            here1:
//            while(digitalRead(SWITCH_2_PIN)==0);
//            QThread::msleep(1);
//            if(digitalRead(SWITCH_2_PIN)==1)
//            {

//                digitalWrite(MOTOR_2_PIN,LOW);
//                dispence_Count--;
//                dis_count=1;
//            }
//            else {
//                goto here1;
//            }
//        }

//    }
    QString myUpdate="UPDATE General_setting SET stock_1='"+QString::number(stock_1)+"',stock_2='"+QString::number(stock_2)+
            "',stock_3='"+QString::number(stock_3)+"',stock_4='"+QString::number(stock_4)+
            "'Where Sr='1'";
    db.DataInject(myUpdate);
    t_blink->start(250);
    //close();

}

void PaymentConfirmation::toggleRedGreenLed()
{
    toggle_status++;
    toggle_exit_counter++;
    if(toggle_status==1)
    {
        digitalWrite(LED_RED_PIN,LOW);
        digitalWrite(LED_GREEN_PIN,HIGH);
    }
    else if(toggle_status==2||toggle_status>3){
        digitalWrite(LED_RED_PIN,LOW);
        digitalWrite(LED_GREEN_PIN,LOW);
        if(toggle_status>3)
        {
            toggle_status=0;
        }
    }
    else if(toggle_status==3) {
        digitalWrite(LED_RED_PIN,HIGH);
        digitalWrite(LED_GREEN_PIN,LOW);
    }
    if(toggle_exit_counter>12)
    {
        t_blink->stop();
        digitalWrite(LED_RED_PIN,LOW);
        digitalWrite(LED_GREEN_PIN,LOW);
        QThread::msleep(500);
        ExitPage window;
        window.setModal(true);
        window.exec();
        close();
    }
}



void PaymentConfirmation::on_btnClose_clicked()
{
    t->stop();
    t_blink->stop();
    close();
}

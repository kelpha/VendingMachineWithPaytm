#include "landingscreen.h"
#include "ui_landingscreen.h"

int count=0;
LandingScreen::LandingScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LandingScreen)
{
    ui->setupUi(this);

    wiringPiSetup();
    pinMode(MOTOR_1_PIN,OUTPUT);
    pinMode(MOTOR_2_PIN,OUTPUT);
    pinMode(MOTOR_3_PIN,OUTPUT);
    pinMode(MOTOR_4_PIN,OUTPUT);
    pinMode(LED_RED_PIN,OUTPUT);
    pinMode(LED_GREEN_PIN,OUTPUT);
    
    pinMode(SWITCH_1_PIN,INPUT);
    pullUpDnControl(SWITCH_1_PIN,PUD_UP);

    if(wiringPiISR (SWITCH_1_PIN, INT_EDGE_RISING,&LandingScreen::ISR_Switch_1)<0)
    {
        qDebug()<<"Error in setting Interrupt for switch ";
    }
    
    pinMode(SWITCH_2_PIN,INPUT);
    pullUpDnControl(SWITCH_2_PIN,PUD_UP);

    if(wiringPiISR (SWITCH_2_PIN, INT_EDGE_FALLING,&LandingScreen::ISR_Switch_2)<0)
    {
        qDebug()<<"Error in setting Interrupt for switch 2";
    }
    
    pinMode(SWITCH_3_PIN,INPUT);
    pullUpDnControl(SWITCH_3_PIN,PUD_UP);

    if(wiringPiISR (SWITCH_3_PIN, INT_EDGE_FALLING,&LandingScreen::ISR_Switch_3)<0)
    {
        qDebug()<<"Error in setting Interrupt for switch 3";
    }
    
    pinMode(SWITCH_4_PIN,INPUT);
    pullUpDnControl(SWITCH_4_PIN,PUD_UP);

    if(wiringPiISR (SWITCH_4_PIN, INT_EDGE_FALLING,&LandingScreen::ISR_Switch_4)<0)
    {
        qDebug()<<"Error in setting Interrupt for switch 4";
    }
    
    
    GlobleVariables variable;
    variable.InitVariable();

    if(TestApp==true)
    {
        setWindowFlag(Qt::FramelessWindowHint);
        QWidget::showMaximized();
    }


    t=new QTimer;
    connect(t,SIGNAL(timeout()),this,SLOT(TheramlScanProxyPage()));

    t_toggle = new QTimer;
    connect(t_toggle,SIGNAL(timeout()),this,SLOT(toggleRedGreenLed()));
   // t->start(2000);

}

LandingScreen::~LandingScreen()
{
    delete ui;
}

void LandingScreen::TheramlScanProxyPage(void)
{

    t->stop();
    ThermalScanProxymity window;
    window.setModal(true);
    window.exec();

    ThermalScan thermalscanWindow;
    thermalscanWindow.setModal(true);
    thermalscanWindow.exec();

    QRCodeDisplay qrcodeDisplayWindow;
    qrcodeDisplayWindow.setModal(true);
    qrcodeDisplayWindow.exec();

    QEventLoop eventLoop;
    QNetworkAccessManager networkManager;
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest req(QUrl(QString("http://192.168.137.180:8080/api/pytm")));
    QNetworkReply *rply=networkManager.get(req);
    eventLoop.exec();
    if(rply->error()==QNetworkReply::NoError)
    {
        QString strReply = (QString)rply->readAll();


        QJsonDocument jsonResponse= QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObj = jsonResponse.object();
        qDebug()<<strReply;

        qDebug()<<"hellow bhushan"<<jsonObj["response"].toString();
        if(jsonObj["response"].toString()=="Success")
        {
            dispence_Count=jsonObj["value"].toString().toInt();
            paymentSuccessfulRoutine();

        }
        else {
            paymentFailRoutine();
        }



    }
    else
    {
       paymentFailRoutine();
    }


    rply->deleteLater();


    ExitPage ExitPageWindow;
    ExitPageWindow.setModal(true);
    ExitPageWindow.exec();



}

void LandingScreen::on_btnClose_clicked()
{
    close();
}



void LandingScreen::on_btnRestart_clicked()
{
    t->start();
}

void LandingScreen::paymentSuccessfulRoutine()
{
    PaymentConfirmation pyamentConfirmationWindow;
    pyamentConfirmationWindow.setModal(true);
    pyamentConfirmationWindow.exec();
}

void LandingScreen::paymentFailRoutine()
{
    PaymentError pyamentErrorWindow;
    pyamentErrorWindow.setModal(true);
    pyamentErrorWindow.exec();
}


void LandingScreen::on_btnToggle_clicked()
{

    digitalWrite(LED_RED_PIN,HIGH);
    digitalWrite(LED_GREEN_PIN,LOW);



}

void LandingScreen::on_btnToggle_2_clicked()
{
    digitalWrite(LED_RED_PIN,LOW);
    digitalWrite(LED_GREEN_PIN,LOW);
}

void LandingScreen::on_btnLED1_on_clicked()
{

    digitalWrite(MOTOR_1_PIN,HIGH);
    QThread::msleep(1000);
    while(digitalRead(SWITCH_1_PIN)==0);
     digitalWrite(MOTOR_1_PIN,LOW);
//    count=0;
//    int wait_time=waitForInterrupt(SWITCH_1_PIN,5000);
//    if(wait_time==1)
//    {
//        digitalWrite(MOTOR_1_PIN,LOW);
//    }
//    digitalWrite(MOTOR_1_PIN,LOW);
}

void LandingScreen::on_btnLED1_off_clicked()
{
    digitalWrite(MOTOR_1_PIN,LOW);
}

void LandingScreen::on_btnLED2_on_clicked()
{
     digitalWrite(MOTOR_2_PIN,HIGH);
//     int wait_time=waitForInterrupt(SWITCH_2_PIN,-1);
//     if(wait_time==1)
//     {
//         digitalWrite(MOTOR_2_PIN,LOW);
//     }
}

void LandingScreen::on_btnLED2_off_clicked()
{
     digitalWrite(MOTOR_2_PIN,LOW);
}

void LandingScreen::on_btnLED3_on_clicked()
{
    digitalWrite(MOTOR_3_PIN,HIGH);
    int wait_time=waitForInterrupt(SWITCH_3_PIN,-1);
    if(wait_time==1)
    {
        digitalWrite(MOTOR_3_PIN,LOW);
    }
}

void LandingScreen::on_btnLED3_off_clicked()
{
    digitalWrite(MOTOR_3_PIN,LOW);
}

void LandingScreen::on_btnLED4_on_clicked()
{
    digitalWrite(MOTOR_4_PIN,HIGH);
    int wait_time=waitForInterrupt(SWITCH_4_PIN,-1);
    if(wait_time==1)
    {
        digitalWrite(MOTOR_4_PIN,LOW);
    }
}

void LandingScreen::on_btnLED4_off_clicked()
{
    digitalWrite(MOTOR_4_PIN,LOW);
}

void LandingScreen::on_btnToggle_3_clicked()
{
    digitalWrite(LED_RED_PIN,LOW);
    digitalWrite(LED_GREEN_PIN,HIGH);
}

void LandingScreen::toggleRedGreenLed()
{
    toggle_status++;
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
}

void LandingScreen::on_btnToggle_4_clicked()
{
    toggle_status=0;
    t_toggle->start(250);
}

void LandingScreen::on_btnToggle_5_clicked()
{
    t_toggle->stop();
    digitalWrite(LED_RED_PIN,LOW);
    digitalWrite(LED_GREEN_PIN,LOW);
}

void LandingScreen::ISR_Switch_1()
{
    count++;
    qDebug()<<"Interrupt on Switch 1"<<QString::number(count);
}

void LandingScreen::ISR_Switch_2()
{
    qDebug()<<"Interrupt on Switch 2";
}

void LandingScreen::ISR_Switch_3()
{
    qDebug()<<"Interrupt on Switch 3";
}

void LandingScreen::ISR_Switch_4()
{
    qDebug()<<"Interrupt on Switch 4";
}


void LandingScreen::on_btnQRI1_clicked()
{
   // QRImage1 window;
    QRCodeDisplay window;
    window.setModal(true);
    window.exec();
}

void LandingScreen::on_btnQRI2_clicked()
{
    QRImage2 window;
    window.setModal(true);
    window.exec();
}

void LandingScreen::on_btnQROnline_clicked()
{
    QROnline window;
    window.setModal(true);
    window.exec();
}

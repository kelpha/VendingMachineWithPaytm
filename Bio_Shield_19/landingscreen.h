#ifndef LANDINGSCREEN_H
#define LANDINGSCREEN_H

#include <QDialog>
#include <QTimer>
#include "thermalscanproxymity.h"
#include "thermalscan.h"
#include "qrcodedisplay.h"
#include "paymentconfirmation.h"
#include "paymenterror.h"
#include "exitpage.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "globlevariables.h"
#include <wiringPi.h>
#include <QThread>
#include "qrimage1.h"
#include "qrimage2.h"
#include "qronline.h"

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
class LandingScreen;
}

class LandingScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LandingScreen(QWidget *parent = nullptr);
    //static void myInterrupt(void);
    ~LandingScreen();

private slots:
    void TheramlScanProxyPage(void);

    void on_btnClose_clicked();



    void on_btnRestart_clicked();

    void paymentSuccessfulRoutine();

    void paymentFailRoutine();

    void on_btnToggle_clicked();

    void on_btnToggle_2_clicked();



    void on_btnLED1_on_clicked();

    void on_btnLED1_off_clicked();

    void on_btnLED2_on_clicked();

    void on_btnLED2_off_clicked();

    void on_btnLED3_on_clicked();

    void on_btnLED3_off_clicked();

    void on_btnLED4_on_clicked();

    void on_btnLED4_off_clicked();

    void on_btnToggle_3_clicked();

    void toggleRedGreenLed();

    void on_btnToggle_4_clicked();

    void on_btnToggle_5_clicked();

    void on_btnQRI1_clicked();

    void on_btnQRI2_clicked();

    void on_btnQROnline_clicked();

private:
    Ui::LandingScreen *ui;
    QTimer *t;
    QTimer *t_toggle;
    int toggle_status=0;
    void static ISR_Switch_1(void);
    void static ISR_Switch_2(void);
    void static ISR_Switch_3(void);
    void static ISR_Switch_4(void);


};

#endif // LANDINGSCREEN_H

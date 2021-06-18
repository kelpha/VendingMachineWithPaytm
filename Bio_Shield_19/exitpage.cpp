#include "exitpage.h"
#include "ui_exitpage.h"

ExitPage::ExitPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitPage)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    QWidget::showMaximized();

    if(TestApp==true)
    {
        setWindowFlag(Qt::FramelessWindowHint);
        QWidget::showMaximized();
    }

    t = new QTimer;
    //connect(t,SIGNAL(timeout()),this,SLOT(close()));
    connect(t,SIGNAL(timeout()),this,SLOT(SendDataToServer()));
    t->start(2000);
}

ExitPage::~ExitPage()
{
    delete ui;
}

void ExitPage::SendDataToServer(void)
{
    t->stop();

//    QByteArray postData;
//    QNetworkRequest request(QUrl(QString("http://192.168.137.180:8080/api/pytm")));
//    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant(QString("application/json")));


//    QJsonObject body;
//    QDate date=QDate::currentDate();
//    QTime time=QTime::currentTime();
//    body.insert("Date",date.toString("dd-MM-yyyy"));
//    body.insert("Time",time.toString("HH:mm"));


//    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
//    QNetworkReply *reply=nam->post(request,QJsonDocument(body).toJson());


//    while(!reply->isFinished())
//    {
//        qApp->processEvents();
//    }
//    QByteArray response_data=reply->readAll();
//    QJsonDocument json=QJsonDocument::fromJson(response_data);

//    reply->deleteLater();
    close();
}

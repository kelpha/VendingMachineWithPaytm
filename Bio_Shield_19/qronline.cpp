#include "qronline.h"
#include "ui_qronline.h"

#include <QDomDocument>
#include <QDomNodeList>
#include <QRandomGenerator>

QROnline::QROnline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QROnline)
{
    ui->setupUi(this);

    ui->lbPrice->setText(QString::number(Unit_price)+" ");
    setWindowFlags(Qt::FramelessWindowHint);
    QWidget::showMaximized();

    t_timeout = new QTimer;
    response_counter=0;
    connect(t_timeout,SIGNAL(timeout()),this,SLOT(timeout_routine()));
    t_timeout->start(5000);

    t_response = new QTimer;
    connect(t_response,SIGNAL(timeout()),this,SLOT(response_from_ptm()));



    QEventLoop eventLoop;
    QNetworkAccessManager networkManager;
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QString urlString = Paytm_link_1+QString::number(Unit_price)+"$";
    RandNumber1 = QRandomGenerator::global()->bounded(999);
    RandNumber2 = QRandomGenerator::global()->bounded(999999999);
    //qDebug()<<QString::number(RandNumber).rightJustified(5,'0');
    QString urlString1 = urlString+QString::number(RandNumber1).rightJustified(3,'0')+QString::number(RandNumber2).rightJustified(9,'0')+"$BS"+Serial_no ;
    //urlString1="http://115.243.128.104/PaytmAPI/api/qrcode/100$ORDERID01610$BS0001";
    qDebug()<<urlString1;
    QUrl url = QUrl(urlString1);
    QNetworkRequest req(url);
    QNetworkReply *rply=networkManager.get(req);
    eventLoop.exec();
    if(rply->error()==QNetworkReply::NoError)
    {
        QByteArray strReply = rply->readAll();
        qDebug()<<strReply;
        QByteArray strReply3;
        for(int i=0;i<(strReply.length()-2);i++)
        {
            strReply3[i]=strReply[i+1];
        }
        strReply3.replace("\\\"","\"");
        QString strReply2 = "{\"head\":{\"responseTimestamp\":\"1622622667184\",\"version\":\"v1\",\"clientId\":\"C11\"},\"body\":{\"resultInfo\":{\"resultStatus\":\"FAILURE\",\"resultCode\":\"QR_1033\",\"resultMsg\":\"A QR Code with same order id already exists.\"}}}";
        QJsonParseError jsonError;
        QJsonDocument jsonResponse= QJsonDocument::fromJson(strReply3,&jsonError);
        if (jsonError.error != QJsonParseError::NoError){
            qDebug() << jsonError.errorString();
        }

        QJsonObject jsonObj = jsonResponse.object();
        //qDebug()<<strReply3;
         //qDebug()<<strReply;

        QJsonObject headobj = jsonObj["head"].toObject();

        QString timeStapm = headobj["responseTimestamp"].toString();
        QString Version = headobj["version"].toString();
        QString clientId = headobj["clientId"].toString();
        QString signature = headobj["signature"].toString();
        QJsonObject bodyobj = jsonObj["body"].toObject();

        QJsonObject resultInfoobj = bodyobj["resultInfo"].toObject();

        QString resultStatus = resultInfoobj["resultStatus"].toString();
        QString resultCode = resultInfoobj["resultCode"].toString();
        QString resultMsg = resultInfoobj["resultMsg"].toString();

        QString qrCodeId = bodyobj["qrCodeId"].toString();
        QString qrData = bodyobj["qrData"].toString();
        QString QRImage = bodyobj["image"].toString();

        qDebug()<<"responseTimestamp = "+timeStapm;
        qDebug()<<"version = "+Version;
        qDebug()<<"ClientID = "+clientId;
        qDebug()<<"ResultStatus = "+resultStatus;
        qDebug()<<"ResultCode = "+resultCode;
        qDebug()<<"ResultMsg = "+resultMsg;
        qDebug()<<"signature = "+signature;
        qDebug()<<"qrCodeId = "+qrCodeId;
        qDebug()<<"qrData = "+qrData;
        qDebug()<<"QRImage = "+QRImage;



        QPixmap image;
        image.loadFromData(QByteArray::fromBase64(QRImage.toLocal8Bit()));
        ui->label->setPixmap(image.scaled(161,161));

        t_response->start(2000);



    }
    else
    {
       qDebug()<<"Faild to read";
    }


    rply->deleteLater();
    
    

}

QROnline::~QROnline()
{
    delete ui;
}

void QROnline::on_btnClose_clicked()
{
    close();
}

void QROnline::response_from_ptm(void)
{
    t_response->stop();

        QEventLoop eventLoop;
        QNetworkAccessManager networkManager;
        connect(&networkManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        QString urlString = Paytm_link_2;
        QString urlString1 = urlString+QString::number(RandNumber1).rightJustified(3,'0')+QString::number(RandNumber2).rightJustified(9,'0');
        //urlString1="http://115.243.128.104/PaytmAPI/api/Transaction/100$ORDERID01610";
        qDebug()<<urlString1;
        QUrl url = QUrl(urlString1);
        QNetworkRequest req(url);
        QNetworkReply *rply=networkManager.get(req);
        eventLoop.exec();
        if(rply->error()==QNetworkReply::NoError)
        {
            QByteArray strReply = rply->readAll();
            qDebug()<<strReply;
            QByteArray strReply3;
            for(int i=0;i<(strReply.length()-2);i++)
            {
                strReply3[i]=strReply[i+1];
            }
            strReply3.replace("\\\"","\"");

            QJsonParseError jsonError;
            QJsonDocument jsonResponse= QJsonDocument::fromJson(strReply3,&jsonError);
            if (jsonError.error != QJsonParseError::NoError){
                qDebug() << jsonError.errorString();
            }

            QJsonObject jsonObj = jsonResponse.object();
            qDebug()<<strReply3;

            QJsonObject headobj = jsonObj["head"].toObject();
            QString timeStapm = headobj["responseTimestamp"].toString();
            QString version = headobj["version"].toString();
            QString signature = headobj["signature"].toString();

            qDebug()<<"TimeStapm = "+timeStapm;
            qDebug()<<"version = "+version;
            qDebug()<<"signature = "+signature;

            QJsonObject bodyobj = jsonObj["body"].toObject();

            QJsonObject resultInfo = bodyobj["resultInfo"].toObject();
            QString resultStatus = resultInfo["resultStatus"].toString();
            QString resultCode = resultInfo["resultCode"].toString();
            QString resultMsg = resultInfo["resultMsg"].toString();

            qDebug()<<"resultStatus = "+resultStatus;
            qDebug()<<"resultCode = "+resultCode;
            qDebug()<<"resultMsg = "+resultMsg;

            QString txnId =bodyobj["txnId"].toString();
            QString orderId = bodyobj["orderId"].toString();
            QString txnAmount = bodyobj["txnAmount"].toString();
            QString txnType = bodyobj["txnType"].toString();
            QString midString = bodyobj["mid"].toString();
            QString refundAmt =  bodyobj["refundAmt"].toString();
            QString txnDate = bodyobj["txnDate"].toString();
            QString posId = bodyobj["posId"].toString();
            QString udf1 = bodyobj["udf1"].toString();

            qDebug()<<"txnId = "+txnId;
            qDebug()<<"orderId = "+orderId;
            qDebug()<<"txnAmount = "+txnAmount;
            qDebug()<<"txnType = "+txnType;
            qDebug()<<"mid = "+midString;
            qDebug()<<"refundAmt = "+refundAmt;
            qDebug()<<"txnDate = "+txnDate;
            qDebug()<<"posId = "+posId;
            qDebug()<<"udf1 = "+udf1;


            if(resultStatus == "PENDING")
            {
                t_response->start(2000);
            }
            else if(resultStatus == "TXN_SUCCESS")
            {
                PaymentConfirmation window;
                window.setModal(true);
                window.exec();
                close();
            }
            else if(resultStatus == "TXN_FAILURE")
            {
                PaymentError w;
                w.setModal(true);
                w.exec();
                close();
            }
            else
            {
                close();
            }



        }
        else
        {
           qDebug()<<"Not Found";
         }


        rply->deleteLater();



}

void QROnline::on_btnPass_clicked()
{
    PaymentConfirmation window;
    window.setModal(true);
    window.exec();
    close();
}

void QROnline::timeout_routine()
{
    response_counter++;
    if(response_counter>=60)
    {
        response_counter=0;
        t_timeout->stop();
        t_response->stop();
        close();
    }

}

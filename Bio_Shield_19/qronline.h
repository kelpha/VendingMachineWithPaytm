#ifndef QRONLINE_H
#define QRONLINE_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include "paymentconfirmation.h"
#include "paymenterror.h"
#include "globlevariables.h"

namespace Ui {
class QROnline;
}

class QROnline : public QDialog
{
    Q_OBJECT

public:
    explicit QROnline(QWidget *parent = nullptr);
    ~QROnline();

private slots:
    void on_btnClose_clicked();
    void response_from_ptm(void);

    void on_btnPass_clicked();

    void timeout_routine();

private:
    Ui::QROnline *ui;
    QTimer *t_response;
    uint32_t RandNumber1;
    uint32_t RandNumber2;
    uint16_t response_counter;
    QTimer *t_timeout;
};

#endif // QRONLINE_H

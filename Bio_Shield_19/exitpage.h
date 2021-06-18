#ifndef EXITPAGE_H
#define EXITPAGE_H

#include <QDialog>
#include <QTimer>
#include "globlevariables.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class ExitPage;
}

class ExitPage : public QDialog
{
    Q_OBJECT

public:
    explicit ExitPage(QWidget *parent = nullptr);
    ~ExitPage();

private slots:
    void SendDataToServer();

private:
    Ui::ExitPage *ui;
    QTimer *t;
};

#endif // EXITPAGE_H

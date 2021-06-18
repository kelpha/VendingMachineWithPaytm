#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QDialog>
#include "qronline.h"
#include "globlevariables.h"
#include "QTimer"
#include "passwordscreen.h"
#include "databasemodule.h"
#include "outofstock.h"

namespace Ui {
class Homescreen;
}

class Homescreen : public QDialog
{
    Q_OBJECT

public:
    explicit Homescreen(QWidget *parent = nullptr);
    ~Homescreen();

private slots:
    void on_btnClose_clicked();

    void on_btnContinue_clicked();

    void on_btnSetting_clicked();

    void setting_count_reset();

private:
    Ui::Homescreen *ui;
    int setting_count;
    QTimer *t_reset;

};

#endif // HOMESCREEN_H

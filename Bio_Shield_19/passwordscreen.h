#ifndef PASSWORDSCREEN_H
#define PASSWORDSCREEN_H

#include <QDialog>
#include "settings.h"

namespace Ui {
class PasswordScreen;
}

class PasswordScreen : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordScreen(QWidget *parent = nullptr);
    ~PasswordScreen();

private slots:
    void on_btnExit_clicked();

    void on_btnBack_clicked();

    void on_btnEnter_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btnDot_clicked();

    void on_btn0_clicked();

    void on_btnDel_clicked();

private:
    Ui::PasswordScreen *ui;
    QString s_password;
};

#endif // PASSWORDSCREEN_H

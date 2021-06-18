#include "passwordscreen.h"
#include "ui_passwordscreen.h"

PasswordScreen::PasswordScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordScreen)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    QWidget::showMaximized();

    s_password="";

}

PasswordScreen::~PasswordScreen()
{
    delete ui;
}

void PasswordScreen::on_btnExit_clicked()
{
    close();
}

void PasswordScreen::on_btnBack_clicked()
{
    close();
}

void PasswordScreen::on_btnEnter_clicked()
{
    if(ui->lineEdit->text()=="1234")
    {
        Settings w;
        w.setModal(true);
        w.exec();
        close();
    }
    else
    {
        ui->lineEdit->setText("");
        s_password="";

    }

}

void PasswordScreen::on_btn1_clicked()
{
    s_password += "1";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn2_clicked()
{
    s_password += "2";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn3_clicked()
{
    s_password += "3";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn4_clicked()
{
    s_password += "4";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn5_clicked()
{
    s_password += "5";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn6_clicked()
{
    s_password += "6";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn7_clicked()
{
    s_password += "7";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn8_clicked()
{
    s_password += "8";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn9_clicked()
{
    s_password += "9";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btnDot_clicked()
{
    s_password += ".";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btn0_clicked()
{
    s_password += "0";
    ui->lineEdit->setText(s_password);
}

void PasswordScreen::on_btnDel_clicked()
{
    s_password = s_password.left(s_password.length()-1);
    ui->lineEdit->setText(s_password);
}

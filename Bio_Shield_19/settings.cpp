#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    QWidget::showMaximized();

     ui->leStock_1->setStyleSheet(HighLight);
     edit_location = v_stock_1;

    ui->leUnit_price->setText(QString::number(Unit_price));
    ui->leStock_1->setText(QString::number(stock_1));
    ui->leStock_2->setText(QString::number(stock_2));
    ui->leStock_3->setText(QString::number(stock_3));
    ui->leStock_4->setText(QString::number(stock_4));
    ui->lePaytm_link_1->setText(Paytm_link_1);
    ui->lePaytm_link_2->setText(Paytm_link_2);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_btnBack_clicked()
{
    close();
}

void Settings::on_btnBack_2_clicked()
{
    Unit_price=ui->leUnit_price->text().toInt();
    stock_1=ui->leStock_1->text().toInt();
    stock_2=ui->leStock_2->text().toInt();
    stock_3=ui->leStock_3->text().toInt();
    stock_4=ui->leStock_4->text().toInt();
    Paytm_link_1=ui->lePaytm_link_1->text();
    Paytm_link_2=ui->lePaytm_link_2->text();
    QString myUpdate="UPDATE General_setting SET Unit_price='"+QString::number(Unit_price)+
            "',stock_1='"+QString::number(stock_1)+"',stock_2='"+QString::number(stock_2)+
            "',stock_3='"+QString::number(stock_3)+"',stock_4='"+QString::number(stock_4)+
            "',Paytm_link_1='"+Paytm_link_1+"',Paytm_link_2='"+Paytm_link_2+"'Where Sr='1'";
    db.DataInject(myUpdate);
    on_btnBack_clicked();
}

void Settings::on_btnTerminate_clicked()
{
    QMessageBox msgBox;

    msgBox.setWindowTitle(" ");
    msgBox.setInformativeText("Do you want to Terminate ComboPUC?");
    msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    switch(ret)
    {
        case QMessageBox::Yes:

          QApplication::quit();

        break;
    }
}

void Settings::on_btnShutdown_clicked()
{
    QProcess process;
    process.startDetached("shutdown -P now");
}

void Settings::on_leUnit_price_textEdited(const QString &arg1)
{
    Unit_price_string = ui->leUnit_price->text();
}




void Settings::reset_StyleSheet()
{
     ui->lePaytm_link_1->setStyleSheet("");
     ui->lePaytm_link_2->setStyleSheet("");
     ui->leUnit_price->setStyleSheet("");
     ui->leStock_1->setStyleSheet("");
     ui->leStock_2->setStyleSheet("");
     ui->leStock_3->setStyleSheet("");
     ui->leStock_4->setStyleSheet("");
}

void Settings::on_lePaytm_link_1_selectionChanged()
{
    reset_StyleSheet();
    ui->lePaytm_link_1->setStyleSheet(HighLight);
    edit_location = v_paytm_link_1;
}

void Settings::on_lePaytm_link_2_selectionChanged()
{
    reset_StyleSheet();
     ui->lePaytm_link_2->setStyleSheet(HighLight);
     edit_location = v_paytm_link_2;
}

void Settings::on_leUnit_price_selectionChanged()
{
    reset_StyleSheet();
    ui->leUnit_price->setStyleSheet(HighLight);
    ui->leUnit_price->setText("");
    s_unitPrice="";
    edit_location = v_unit_price;
}

void Settings::on_leStock_1_selectionChanged()
{
    reset_StyleSheet();
    ui->leStock_1->setStyleSheet(HighLight);
    ui->leStock_1->setText("");
    s_Stock1="";
    edit_location = v_stock_1;
}


void Settings::on_leStock_2_selectionChanged()
{
    reset_StyleSheet();
    ui->leStock_2->setStyleSheet(HighLight);
    ui->leStock_2->setText("");
    s_Stock2="";
    edit_location = v_stock_2;
}

void Settings::on_leStock_3_selectionChanged()
{
    reset_StyleSheet();
    ui->leStock_3->setStyleSheet(HighLight);
    ui->leStock_3->setText("");
    s_Stock3="";
    edit_location = v_stock_3;
}

void Settings::on_leStock_4_selectionChanged()
{
    reset_StyleSheet();
    ui->leStock_4->setStyleSheet(HighLight);
    ui->leStock_4->setText("");
    s_Stock4="";
    edit_location = v_stock_4;
}

void Settings::on_btn1_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "1";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "1";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "1";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "1";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "1";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn2_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "2";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "2";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "2";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "2";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "2";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn3_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "3";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "3";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "3";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "3";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "3";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn4_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "4";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "4";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "4";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "4";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "4";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn5_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "5";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "5";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "5";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "5";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "5";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn6_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "6";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "6";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "6";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "6";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "6";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn7_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "7";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "7";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "7";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "7";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "7";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn8_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "8";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "8";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "8";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "8";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "8";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn9_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "9";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "9";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "9";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "9";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "9";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btnDot_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += ".";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += ".";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += ".";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += ".";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += ".";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btn0_clicked()
{
    if(edit_location==v_unit_price)
    {
        s_unitPrice += "0";
        ui->leUnit_price->setText(s_unitPrice);
    }
    else if(edit_location==v_stock_1)
    {
        s_Stock1 += "0";
        ui->leStock_1->setText(s_Stock1);
    }
    else if(edit_location==v_stock_2)
    {
        s_Stock2 += "0";
        ui->leStock_2->setText(s_Stock2);
    }
    else if(edit_location==v_stock_3)
    {
        s_Stock3 += "0";
        ui->leStock_3->setText(s_Stock3);
    }
    else if(edit_location==v_stock_4)
    {
        s_Stock4 += "0";
        ui->leStock_4->setText(s_Stock4);
    }
}

void Settings::on_btnDel_clicked()
{

     if(edit_location==v_unit_price)
     {
         s_unitPrice = s_unitPrice.left(s_unitPrice.length()-1);
         ui->leUnit_price->setText(s_unitPrice);
     }
     else if(edit_location==v_stock_1)
     {
         s_Stock1 = s_Stock1.left(s_Stock1.length()-1);
         ui->leStock_1->setText(s_Stock1);
     }
     else if(edit_location==v_stock_2)
     {
         s_Stock2 = s_Stock2.left(s_Stock2.length()-1);
         ui->leStock_2->setText(s_Stock2);
     }
     else if(edit_location==v_stock_3)
     {
         s_Stock3 = s_Stock3.left(s_Stock3.length()-1);
         ui->leStock_3->setText(s_Stock3);
     }
     else if(edit_location==v_stock_4)
     {
          s_Stock4 = s_Stock4.left(s_Stock4.length()-1);
         ui->leStock_4->setText(s_Stock4);
     }

}

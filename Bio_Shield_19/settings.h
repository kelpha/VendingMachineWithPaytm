#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QMessageBox>
#include <QProcess>
#include "globlevariables.h"
#include "databasemodule.h"

#define HighLight "background-color:rgb(255,255,0);"
#define v_paytm_link_1  1
#define v_paytm_link_2  2
#define v_unit_price    3
#define v_stock_1       4
#define v_stock_2       5
#define v_stock_3       6
#define v_stock_4       7

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_btnBack_clicked();

    void on_btnBack_2_clicked();

    void on_btnTerminate_clicked();

    void on_btnShutdown_clicked();

    void on_leUnit_price_textEdited(const QString &arg1);

    void on_btn1_clicked();

    void on_leUnit_price_selectionChanged();

    void on_leStock_1_selectionChanged();

    void reset_StyleSheet();

    void on_lePaytm_link_1_selectionChanged();

    void on_lePaytm_link_2_selectionChanged();

    void on_leStock_2_selectionChanged();

    void on_leStock_3_selectionChanged();

    void on_leStock_4_selectionChanged();

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
    Ui::Settings *ui;
    DataBaseModule db;
    QString Unit_price_string;
    int edit_location;
    QString s_unitPrice;
    QString s_Stock1;
    QString s_Stock2;
    QString s_Stock3;
    QString s_Stock4;
};

#endif // SETTINGS_H

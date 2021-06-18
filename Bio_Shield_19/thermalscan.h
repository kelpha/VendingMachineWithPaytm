#ifndef THERMALSCAN_H
#define THERMALSCAN_H

#include <QDialog>
#include <QTimer>
#include "globlevariables.h"
namespace Ui {
class ThermalScan;
}

class ThermalScan : public QDialog
{
    Q_OBJECT

public:
    explicit ThermalScan(QWidget *parent = nullptr);
    ~ThermalScan();

private:
    Ui::ThermalScan *ui;
    QTimer *t;
};

#endif // THERMALSCAN_H

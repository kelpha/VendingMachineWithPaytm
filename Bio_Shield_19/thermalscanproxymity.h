#ifndef THERMALSCANPROXYMITY_H
#define THERMALSCANPROXYMITY_H

#include <QDialog>
#include <QTimer>
#include "globlevariables.h"
namespace Ui {
class ThermalScanProxymity;
}

class ThermalScanProxymity : public QDialog
{
    Q_OBJECT

public:
    explicit ThermalScanProxymity(QWidget *parent = nullptr);
    ~ThermalScanProxymity();

private:
    Ui::ThermalScanProxymity *ui;
    QTimer *t;
};

#endif // THERMALSCANPROXYMITY_H

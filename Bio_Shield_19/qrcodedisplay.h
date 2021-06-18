#ifndef QRCODEDISPLAY_H
#define QRCODEDISPLAY_H

#include <QDialog>
#include <QTimer>
#include "globlevariables.h"
namespace Ui {
class QRCodeDisplay;
}

class QRCodeDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit QRCodeDisplay(QWidget *parent = nullptr);
    ~QRCodeDisplay();

private:
    Ui::QRCodeDisplay *ui;
    QTimer *t;
};

#endif // QRCODEDISPLAY_H

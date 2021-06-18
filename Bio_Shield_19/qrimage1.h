#ifndef QRIMAGE1_H
#define QRIMAGE1_H

#include <QDialog>

namespace Ui {
class QRImage1;
}

class QRImage1 : public QDialog
{
    Q_OBJECT

public:
    explicit QRImage1(QWidget *parent = nullptr);
    ~QRImage1();

private slots:
    void on_btnClose_clicked();

private:
    Ui::QRImage1 *ui;
};

#endif // QRIMAGE1_H

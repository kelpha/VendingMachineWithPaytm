#ifndef QRIMAGE2_H
#define QRIMAGE2_H

#include <QDialog>

namespace Ui {
class QRImage2;
}

class QRImage2 : public QDialog
{
    Q_OBJECT

public:
    explicit QRImage2(QWidget *parent = nullptr);
    ~QRImage2();

private slots:
    void on_btnClose_clicked();

    void on_btnGetQR_clicked();

private:
    Ui::QRImage2 *ui;
};

#endif // QRIMAGE2_H

#ifndef OUTOFSTOCK_H
#define OUTOFSTOCK_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class OutOfStock;
}

class OutOfStock : public QDialog
{
    Q_OBJECT

public:
    explicit OutOfStock(QWidget *parent = nullptr);
    ~OutOfStock();

private slots:
    void timeout_routine(void);

private:
    Ui::OutOfStock *ui;
    QTimer *t;
};

#endif // OUTOFSTOCK_H

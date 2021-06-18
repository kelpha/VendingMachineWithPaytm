#include "qrcodedisplay.h"
#include "ui_qrcodedisplay.h"

QRCodeDisplay::QRCodeDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRCodeDisplay)
{
    ui->setupUi(this);

    if(TestApp==true)
    {
        setWindowFlag(Qt::FramelessWindowHint);
        QWidget::showMaximized();
    }

    t = new QTimer;
    connect(t,SIGNAL(timeout()),this,SLOT(close()));
    //t->start(2000);

    QString imageData="iVBORw0KGgoAAAANSUhEUgAAAeAAAAHgAQAAAABVr4M4AAADlElEQVR42u3dTZKcMAwFYLHiGBwVjsoxeoUyYOvpmf6x08kmqdeLrszARzYuy0iyx/wPPiYsLPzX8WH1M58/P8xW//ndutt0/nxdnXxb6EL9rMLCY3i9xtr+gze7yCOetc/n3deF8uip3Hc9VVh4FJ8jbj1vtMXrE37GI3/5bvjXeZ/NwsJf4fNujMx6z2MqEbXMgsLC3+MSRMvXwxB7I86aCQt/g2uIPeoTrpi60GOmGl0Ril/EZ2HhtzhH4boPfL1+xxAWfoPzU18/60sn3jzvg/J1nkRY+A3GiIvLJaYuEWIj9nqE2LxZWHgIW75v5mfPZ+Fzhd3bIk5YuIO9ZjSs5Mxi1Xala5H+4KfaxLOnsHAfY8ZbkZDdFsezPNO1FhEXizhh4Q4+IvlvsXQrI7MtOZUJsCTTUDgQFh7AcJ6LuAixeyFTJEKulwjcIiw8grEuM6N0bR2UmABLFDaOvauw8CjOYZezYIzRDYVO50ebsPAYRk/G7FS7NMTU+oXFXhmjNHsKC3/EOcU9VzEXlJxQEKj5DqwAhYU7ONZqbbo2y0t1KrRa2aztQH5gAhQW7uAt5zkztPlg6cYNZ9ZUoISFB3C7LiuZWqOSE6Vr8TphxrOnsHAPR4k80hqZqa0x1Wjau6U6hIU/Y/RkRLUpq+PN7wJTGUpYeADHyt+bVwKzmX+3GbX+NHkSYeE+tplD7LVq8z37MeasmNtTiBUW7mBH/0VurIxZ0J+3WNb/iTNxwsKfMPJjWLrdd8ZFVcBzf0npRBMWHsCOJJnxNvEsllNLGXU4IhMnLNzDG+X4b639Fn2NtcMxe82EhccxnzeQHbFHm/440HqGN1Rh4QHcRNecCusWyzxvZeKe/4U2KgkLd3BNyCJxS0MRzRo8C7Yt2MLCPZw91xsd14NuRl7JGZ+LISw8gtsjx9CEsWPH5ZLnYhi6ZGd6xxAW7mFcppUcqphJch/AU71KWPg9ztRs7BB3OjHxdiCZ51ZMYeERzAu23IW0oQwVJU8uOa3CwsOYj1XJDv5meD4dF9W2/ggLf8J8zHDuVqITVXaa++y59UdYuIfzeLsSTpcMu55n9nD74nrbqCQs/BHvtxOg5nbfEvKzue2X4rOw8G/gNq0Wx0UlydcJYeEvcCbODMfy02H8uLAt7sLCw5j+3ENOcblWayubdEKGsPAQ5mOGkbPNM8ZQC/C9PfxOWHgE/6N/8EtY+P/EvwDERn+7Wnid3QAAAABJRU5ErkJggg==";
            QPixmap image;
    image.loadFromData(QByteArray::fromBase64(imageData.toLocal8Bit()));
    ui->label->setPixmap(image.scaled(171,151));
}

QRCodeDisplay::~QRCodeDisplay()
{
    delete ui;
}

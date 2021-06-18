#include "qrimage1.h"
#include "ui_qrimage1.h"

QRImage1::QRImage1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRImage1)
{
    ui->setupUi(this);

    QString imageData="iVBORw0KGgoAAAANSUhEUgAAAeAAAAHgAQAAAABVr4M4AAADjUlEQVR42u3dTXKkMAwFYPWKY3BUfFSOwSqawdbPM6QbVTJVs3ksutITPmbjsowkO6K/uISYmPif4y+xazm/HyKbHi/VXV7n9/7bl7a1/+Lv1233+zdi4hre+ljbT2xEtfVn7ct59+Jfx1P7T50RE9fwOeK280ZZuzuv9eiD0j468Z/OIbsQE/8A97mvyRiUdk9/zJgK+yxITPwbrPaEHmzHtWYUFmLin2ALsTYoR0xd1Z7VF3FwvYnPxMRvsb8mJP748f07BjHxG5yXh9jVJ0CbDy+D8vs8CTHxGxwjbrF7mi3dMKZu6u8PcDMxcQ2P5b/mxzQe4eph97KIIyZ+xJu9ErxiAHq6NtIfuIjLNR0xcQ3vWQvwTG0babVlDrE5eLMgQExcwJ7vGMk0mUtOEXEtmaZ2CzFxBduPLea5Fsu5PgozXdtnxjZya4sSE1exwvDMZZq8pglQpnG72yKOmPgRR+tFDDurD/h76aox40EKV4iJqziXbmMCxNp5fPiabtQH9syTEBN/xvFecMxlSx+y1msWpfTVgy0xcRFrZGBtAE7lpQ26zrIdSDM+ExM/4BFdYdjFjGc3YpEAMx/ExAWMlXDBVsWojkfJ02ZG8WYNYuIijr6yLAOI/9toLoNpD1MdxMSPGPvKIMGRLY2R5WhZ1FyVmLiIM3TG8Ixes2wHEmj9mfMkxMSPWDx0wtjLsBs5EPy3CLHExA9Yof/Ckx7eoqH3LZb2P80hlpj4E7bQmfmOy844rwp4D20UOomJSziTZBqVTYmNld4ba8k07NcmJi7g6R1ULy1lU7E8f9GmrXDExJ+xSOx92y+T3SXLcci0M5OYuIBvrT/2lnl4jUngNIyvaPd/01xGTHzHo6i0XjfFyTwpxvvDAi3YxMQFrHEWVIPXhKmbMVv7JZ9ATFzB9xCbx6pYX1nUB3JN9zY+ExNfcNTEoWweW8cVS045PWJ8JiZ+wpmaFZj7jkh6TAeSKRyvSExcwLFgu7cveusPvoNK7vglJq7g6eVgzw5+GJ7fHBe1KDFxDeMxwy0L6HpMhyrmYT7X1h9i4iecx9tZ47XOcx/s+I3qwUJMXMc7bE/CQ9OnM3v8+df4TExcx9ARG9tIsgyQ7w/XHQLExDUM+3dFMqYqlAEETsggJq7h2N3WLudVRwFd4s89YAAmJi5hPGYYToWK4y+mMoDAwVHExAX8//5mFzEx8e36A+x50RBYSrhbAAAAAElFTkSuQmCC";
            QPixmap image;
    image.loadFromData(QByteArray::fromBase64(imageData.toLocal8Bit()));
    ui->label->setPixmap(image);
}

QRImage1::~QRImage1()
{
    delete ui;
}

void QRImage1::on_btnClose_clicked()
{
    close();
}

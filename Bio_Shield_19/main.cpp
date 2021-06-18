#include "landingscreen.h"
#include "homescreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //LandingScreen w;
    Homescreen w;
    w.show();

    return a.exec();
}

#include <QApplication>
#include "login.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login w;

    w.setWindowFlags(w.windowFlags() &~ Qt::WindowMaximizeButtonHint);
    w.show();

    return a.exec();
}
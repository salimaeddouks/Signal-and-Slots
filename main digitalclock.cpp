#include "digitalclock.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *d=new  digitalclock;
    d->show();
    return a.exec();
}

#include "Coinflip.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Coinflip w;
    w.show();
    return a.exec();
}

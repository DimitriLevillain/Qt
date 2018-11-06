#include "calculatricesd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatriceSD w;
    w.show();

    return a.exec();
}

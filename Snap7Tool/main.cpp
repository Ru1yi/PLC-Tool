#include "Snap7Tool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Snap7Tool w;
    w.show();
    return a.exec();
}

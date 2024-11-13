#include "Snap7Tool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    try {
        Snap7Tool w;
        w.show();
        return a.exec();
    }
    catch (...) {
        QMessageBox::critical(nullptr, "PLC connection failed", "Please check plc settings!");
        a.quit();
    }     
}

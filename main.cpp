#include "QTreeWIDgetWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTreeWIDgetWindow w;
    w.show();
    return a.exec();
}

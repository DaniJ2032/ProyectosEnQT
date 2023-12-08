#include "mainwidget.h"
#include <QApplication>
//#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget widget;
    widget.show();  //Ejecuta el widget

    return a.exec();
}

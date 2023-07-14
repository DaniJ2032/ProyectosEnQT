#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Cargar el icono desde un archivo
   // QIcon icon("C:/Users/Dimas/Documents/SVN_CODE/Qt/TTGO_Serial_Reader_Threaded/img/utn.png"); // Cambia la ruta del icono según sea necesario
   // w.setWindowIcon(icon);

    w.show();
    return a.exec();
}

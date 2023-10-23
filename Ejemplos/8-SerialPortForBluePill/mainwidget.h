/*#########################################################################################*/
/*##                                    Head principal                                   ##*/
/*##-------------------------------------------------------------------------------------##*/
/*## Es la cabecera principal del pgrogama y representa a la clase padre del sistema.    ##*/
/*## Dentro de la clase mainWidget se tiene declarado los botones de Inicio, Fin y una   ##*/
/*## Lista en donde se imprimirá lo recibido por el puerto serie, a su vez se almacenará ##*/
/*## lo recibidio para su posterior comparacion.                                         ##*/
/*#########################################################################################*/


#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "serialthread.h"


/* La clase MainWindow es una ventana de la interfaz gráfica principal de la aplicación.
   También hereda de QWidget. Contiene varios elementos de la interfaz de usuario,
   incluyendo botones y una lista para mostrar datos.*/

QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }
QT_END_NAMESPACE


class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);  // Constructor
    ~mainWidget();                          // Destructor

    uint8_t codeCRC8(uint8_t *dataFrame, uint8_t longitud);

// slot privados, propio de los widget
private slots:

    void on_Iniciar_clicked();
    void on_Finalizar_clicked();
    void appendDataToListWidget(const charFrame_t& data);

    void appendDataToListWidgetTx(const charTxFrame_t& data);

private:
    Ui::mainWidget *ui = nullptr;             // Puntero tipo mainWidget

    serialThread *mSerialThread = nullptr;    // Puntero de la clase serialThread
    QSerialPort *serialPort = nullptr;

};

#endif // MAINWIDGET_H

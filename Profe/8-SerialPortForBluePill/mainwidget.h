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
#include <QDateTime>
#include <QStateMachine>
#include <QPushButton>
#include <QState>

#include <QTimer>

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


// slot privados, propio de los widget
private slots:

    void on_Iniciar_clicked();
    void on_Finalizar_clicked();
    void sistemInit();
    void appendDataToListWidget();


    void inicializarUI();
    void updateDisplayDigital();
    void updateAnalogDisplay();

    void updateDataButonsAndDials();
    uint8_t* getButtonStates();
    uint8_t setdailAnalog1();
    uint8_t setdailAnalog2();

private:

    Ui::mainWidget *ui = nullptr;             // Puntero tipo mainWidget
    serialThread *mSerialThread = nullptr;    // Puntero de la clase serialThread
    QSerialPort *serialPort = nullptr;

    QTimer *timer;
    QList<QPushButton*> buttons;
    QList<QStateMachine*> machines;
    bool readyToSendData;

};

#endif // MAINWIDGET_H

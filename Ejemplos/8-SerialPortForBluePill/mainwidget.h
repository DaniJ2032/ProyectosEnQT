
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "serialthread.h"
#include <QWidget>
#include <QDateTime>
#include <QStateMachine>
#include <QPushButton>
#include <QState>

QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }
QT_END_NAMESPACE


class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);  // Constructor
    ~mainWidget();                          // Destructor

private slots:

    void on_Iniciar_clicked();          // Boton de inicio
    void on_Finalizar_clicked();        // Boton de finalizar
    void sistemInit();                  // Inicio del sistema
    void appendDataToListWidget();      // Imrpimir las tramas
    void inicializarUI();               // Seteo de los botones y diales
    void updateDisplayDigital();        // Actauliza display Digitales
    void updateAnalogDisplay();         // Actualiza los display analogicos
    void updateDataButonsAndDials();    // Actualiza estado de los botones y diales
    uint8_t* getButtonStates();         // Obtener valores de botones
    uint8_t setdailAnalog1();           // Obtener valores de Dial1
    uint8_t setdailAnalog2();           // Obtener valores del Dial2

private:

    Ui::mainWidget *ui = nullptr;           // Puntero tipo mainWidget
    serialThread *mSerialThread = nullptr;  // Puntero de la clase serialThread
    QSerialPort *serialPort = nullptr;      // Puntero serial port
    QList<QPushButton*> buttons;            // Vector de botones
    QList<QStateMachine*> machines;         // Maquina de estados
    bool readyToSendData;                   // bandera para envio de datos
    QTimer *timer;                          // puntero para tiempo
};

#endif // MAINWIDGET_H

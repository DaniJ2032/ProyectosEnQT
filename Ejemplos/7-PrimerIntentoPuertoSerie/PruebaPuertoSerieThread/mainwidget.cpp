#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "serialthread.h"
#include <QtDebug>

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainWidget){

    ui->setupUi(this);

    // Configurar el puerto serie
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    if (!portList.isEmpty()) {
        const QString portName = portList.first().portName();
        serialPort.setPortName(portName);
        serialPort.setBaudRate(QSerialPort::Baud9600);
        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setParity(QSerialPort::NoParity);
        serialPort.setStopBits(QSerialPort::OneStop);
        serialPort.setFlowControl(QSerialPort::NoFlowControl);

        if (serialPort.open(QIODevice::ReadOnly)) {
            qDebug() << "Conectado al puerto serie" << portName;

            // Crear e iniciar el hilo del lector serie

            connect(mSerialThread, &serialThread::dataReceived, this, SLOT(on_listWidget_currentTextChanged));
//            mSerialThread->start();
        } else {
            qDebug() << "No se pudo abrir el puerto serie" << portName << ":" << serialPort.errorString();
        }
    } else {
        qDebug() << "No se encontraron puertos serie disponibles.";
    }


}

mainWidget::~mainWidget()
{
    delete ui;
}

//void mainWidget::recibirArreglos(const QByteArray& data){
//    ui->listWidget->addItem(QString(data));

//}

void mainWidget::on_Iniciar_clicked(){
    mSerialThread->start();
}

void mainWidget::on_Finalizar_clicked(){
    mSerialThread->terminate();
}


void mainWidget::on_listWidget_currentTextChanged(const QString &currentText){
   ui->listWidget->addItem(currentText);
}


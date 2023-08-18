#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QString>

mainWidget::mainWidget(QWidget *parent) : QWidget(parent) , ui(new Ui::mainWidget),
    mSerialThread(nullptr)
{

    ui->setupUi(this);


}

mainWidget::~mainWidget()
{

    if(mSerialThread){
        mSerialThread->requestInterruption();
        mSerialThread->wait();
        delete mSerialThread;
    }
    delete ui;
}


void mainWidget::on_Iniciar_clicked(){
    if (!mSerialThread) {
        // Configurar y crear el hilo del lector serie con el puerto serie seleccionado
        QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
        if (!portList.isEmpty()) {

            const QString portName = portList.first().portName();
            mSerialThread = new serialThread("COM3", this);

            connect(mSerialThread, &serialThread::dataReceived, this, &mainWidget::appendDataToListWidget);
            mSerialThread->start();

        } else {
            qDebug() << "No se encontraron puertos serie disponibles.";
        }
    }

}

void mainWidget::on_Finalizar_clicked(){

    if(mSerialThread){
        mSerialThread->requestInterruption();
        mSerialThread->wait();
        delete mSerialThread;
        mSerialThread = nullptr;
    }
    ui->plainTextEdit->clear();
}

void mainWidget::appendDataToListWidget(const QByteArray &currentText){
//   ui->listWidget->addItem(QString(currentText));
//   QString charString = QString::fromUtf8(currentText); // Convierte los bytes en una cadena de caracteres
//    QStringList lista = currentText.split('\x');
   ui->plainTextEdit->appendPlainText(QString::fromUtf8(currentText));

}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*Configuracion inicial del puerto serial*/
    serial = new QSerialPort();
    serial->setPortName("COM6");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setStopBits(QSerialPort::OneStop);
    serial->open(QIODevice::ReadWrite);
    connect(serial, SIGNAL(readyRead()),this,SLOT(RecibirArreglos()));
}

void MainWindow::RecibirArreglos(){
    QByteArray arreglo;
    arreglo = serial ->readAll();
//    QByteArray byteArray = QByteArray::fromHex(cadena);
//    ui->plainTextEdit->appendPlainText(QString::fromLatin1(byteArray)); //Muestro lo recibido por puerto serie
//    byteArray =""; //limpio cadena
    qDebug() << "\nTrama recibida: " << arreglo;
    qDebug() << "\nTamaño de cadena: " << arreglo.size();

    ui->plainTextEdit->appendPlainText(arreglo.toHex());
    arreglo.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}


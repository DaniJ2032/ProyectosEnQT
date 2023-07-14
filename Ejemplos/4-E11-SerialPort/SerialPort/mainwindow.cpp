#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hw_is_available = false;
    hw_port_name = "";
    hw = new QSerialPort;
    ui->lineEdit_3->setText("9600");
    ui->lineEdit->setText(QString::number(QSerialPortInfo::availablePorts().length()));
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            ui->lineEdit_2->setText(QString::number(serialPortInfo.vendorIdentifier()));
            ui->lineEdit_5->setText(QString::number(serialPortInfo.productIdentifier()));
        }
    }

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
        {
        ui->comboBox->addItem(serialPortInfo.portName());
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString bauds = ui->lineEdit_3->text();
    int vbauds = bauds.toInt();
    if(vbauds == 9600){
        hw ->setBaudRate(QSerialPort::Baud9600);
        ui->lineEdit_4->setText(bauds);
    }
    else{
    }
}

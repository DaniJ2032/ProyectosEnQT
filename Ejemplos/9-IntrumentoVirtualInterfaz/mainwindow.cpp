#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <iostream>
#include <QFileInfo>

#include<QDebug>
#include<cstddef>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_serial(new QSerialPort(this))
{   
    // Set the UI to the main program
    ui->setupUi(this);

    // Set serial port status as disconnected when program starts
    ui->connectionStatus->setText("Disconnected");

    // Set the serial port configurations
    m_serial->setPortName("COM3");
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
}

MainWindow::~MainWindow()
{
    closeSerialPort();
    delete ui;
}

void MainWindow::openSerialPort()
{
    if (m_serial->open(QIODevice::ReadWrite)) {
        ui->connectionStatus->setText("Connected");
        ui->connectButton->setText("Disconnect");
    } else {
        ui->connectionStatus->setText("Couldn't connect");
    }
}

void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen()) {
        m_serial->close();

        if (!m_serial->isOpen()) {
            ui->connectionStatus->setText("Disconnected");
            ui->connectButton->setText("Connect");
        }
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::readData()
{
    short analogValue = 0;

    receivedFrame += m_serial->readAll();

    foreach(unsigned char byte, receivedFrame){
        switch(positionToRead) {
            case 0:                             // Check for startByte
                if(byte == 0x1b)
                    positionToRead = 1;
                break;

            case 1:                             // Save received counter
                receivedCounter = byte;
                positionToRead++;
                break;

            case 2:                             // Digital Inputs
                updateDigitalInputs(receivedFrame[1]);
                positionToRead++;
                break;

            case 3:                             // Analog Input 1 (first LSB then MSB)
                analogValue = (byte & 0xFF);
                positionToRead++;
                break;
            case 4:
                analogValue += (byte & 0xFF) << 8;
                ui->analogIn1_label->setText(QString::number((double)analogValue*10/4095,'f',2));
                ui->analogIn1_slider->setValue(analogValue*100/4095);
                positionToRead++;
                break;

            case 5:                             // Analog Input 2 (first LSB then MSB)
                analogValue = (byte & 0xFF);
                positionToRead++;
                break;
            case 6:
                analogValue += (byte & 0xFF) << 8;
                ui->analogIn2_label->setText(QString::number((double)analogValue*10/4095,'f',2));
                ui->analogIn2_slider->setValue(analogValue*100/4095);
                positionToRead++;
                break;

            case 7:                             // Analog Input 3 (first LSB then MSB)
                analogValue = (byte & 0xFF);
                positionToRead++;
                break;
            case 8:
                analogValue += (byte & 0xFF) << 8;
                ui->analogIn3_label->setText(QString::number((double)analogValue*10/4095,'f',2));
                ui->analogIn3_slider->setValue(analogValue*100/4095);
                positionToRead++;
                break;

            case 9:                             // Analog Input 4 (first LSB then MSB)
                analogValue = (byte & 0xFF);
                positionToRead++;
                break;
            case 10:
                analogValue += (byte & 0xFF) << 8;
                ui->analogIn4_label->setText(QString::number((double)analogValue*10/4095,'f',2));
                ui->analogIn4_slider->setValue(analogValue*100/4095);
                positionToRead++;
                break;

            case 11:                            // Analog Input 5 (first LSB then MSB)
                analogValue = (byte & 0xFF);
                positionToRead++;
                break;
            case 12:
                analogValue += (byte & 0xFF) << 8;
                ui->analogIn5_label->setText(QString::number((double)analogValue*10/4095,'f',2));
                ui->analogIn5_slider->setValue(analogValue*100/4095);
                positionToRead++;
                break;

            case 13:                            // Analog Input 6 (first LSB then MSB)
                analogValue = (byte & 0xFF);
                positionToRead++;
                break;
            case 14:
                analogValue += (byte & 0xFF) << 8;
                ui->analogIn6_label->setText(QString::number((double)analogValue*10/4095,'f',2));
                ui->analogIn6_slider->setValue(analogValue*100/4095);
                positionToRead++;
                break;

            case 15:                            // Analog Input 7 (first LSB then MSB)
                analogValue = (byte & 0xFF);
                positionToRead++;
                break;
            case 16:
                analogValue += (byte & 0xFF) << 8;
                ui->analogIn7_label->setText(QString::number((double)analogValue*10/4095,'f',2));
                ui->analogIn7_slider->setValue(analogValue*100/4095);
                positionToRead++;
                break;

            case 17:                            // Analog Input 8 (first LSB then MSB)
                analogValue = (byte & 0xFF);
                positionToRead++;
                break;
            case 18:
                analogValue += (byte & 0xFF) << 8;
                ui->analogIn8_label->setText(QString::number(getVoltageFromBytes(analogValue, 4095, -5, 5),'f',2) );
                ui->analogIn8_slider->setValue(getVoltageFromBytes(analogValue, 4095, -5, 5)*10);
                positionToRead++;
                break;

            case 19:                            // Digital Outputs
                //updateDigitalOutputs(byte);
                positionToRead++;
                break;

            case 20:                            // Analog Output 1 (first LSB then MSB)
          //      analogValue = ((unsigned int)byte & 0xFF);
                positionToRead++;
                break;
            case 21:
         //       analogValue += ((unsigned int)byte & 0xFF) << 8;
         //       ui->analogOutput1_lcd->display(getVoltageFromBytes(analogValue, 65535, 0, 5));
         //       ui->analogOutput1_dial->setValue(getVoltageFromBytes(analogValue, 65535, 0, 5)*10);
                positionToRead++;
                break;

            case 22:                            // Analog Output 2 (first LSB then MSB)
                positionToRead++;
                break;
            case 23:
                positionToRead = 0;
                break;

            default:
                qDebug() << "Error on rx!!";
                break;
        }
    }

    receivedFrame.clear();
}

double MainWindow::getVoltageFromBytes(short bytes, int resolution, double minVoltage, double maxVoltage){
    return (((double)bytes/resolution) * (maxVoltage-minVoltage)) + minVoltage;
}

short MainWindow::getBytesFromVoltage(double voltage, int resolution, double minVoltage, double maxVoltage){
    return (short)(((voltage-minVoltage)/(maxVoltage-minVoltage)) * resolution);
}

void MainWindow::updateDigitalInputs(unsigned char inputs){
    ui->digitalInput1->setChecked(inputs & 1);
    ui->digitalInput2->setChecked((inputs >> 1) & 1);
    ui->digitalInput3->setChecked((inputs >> 2) & 1);
    ui->digitalInput4->setChecked((inputs >> 3) & 1);
    ui->digitalInput5->setChecked((inputs >> 4) & 1);
    ui->digitalInput6->setChecked((inputs >> 5) & 1);
    ui->digitalInput7->setChecked((inputs >> 6) & 1);
    ui->digitalInput8->setChecked((inputs >> 7) & 1);
}

void MainWindow::updateDigitalOutputs(unsigned char outputs){
    ui->digitalOutput1->setChecked(outputs & 1);
    ui->digitalOutput2->setChecked((outputs >> 1) & 1);
    ui->digitalOutput3->setChecked((outputs >> 2) & 1);
    ui->digitalOutput4->setChecked((outputs >> 3) & 1);
    ui->digitalOutput5->setChecked((outputs >> 4) & 1);
    ui->digitalOutput6->setChecked((outputs >> 5) & 1);
    ui->digitalOutput7->setChecked((outputs >> 6) & 1);
    ui->digitalOutput8->setChecked((outputs >> 7) & 1);
}

void MainWindow::sendChangesToBluepill(){   
    // Start Byte
    transmitedFrame[0] = 0x1b;
    // Counter
    transmitedFrame[1] = 0;
    // Digital Inputs
    ui->digitalInput1->isChecked() ? transmitedFrame[2] |= 0b00000001 : transmitedFrame[2] &= 0b11111110;
    ui->digitalInput2->isChecked() ? transmitedFrame[2] |= 0b00000010 : transmitedFrame[2] &= 0b11111101;
    ui->digitalInput3->isChecked() ? transmitedFrame[2] |= 0b00000100 : transmitedFrame[2] &= 0b11111011;
    ui->digitalInput4->isChecked() ? transmitedFrame[2] |= 0b00001000 : transmitedFrame[2] &= 0b11110111;
    ui->digitalInput5->isChecked() ? transmitedFrame[2] |= 0b00010000 : transmitedFrame[2] &= 0b11101111;
    ui->digitalInput6->isChecked() ? transmitedFrame[2] |= 0b00100000 : transmitedFrame[2] &= 0b11011111;
    ui->digitalInput7->isChecked() ? transmitedFrame[2] |= 0b01000000 : transmitedFrame[2] &= 0b10111111;
    ui->digitalInput8->isChecked() ? transmitedFrame[2] |= 0b10000000 : transmitedFrame[2] &= 0b01111111;

    // Analgog Input 1
    transmitedFrame[3] = getBytesFromVoltage(ui->analogIn1_slider->value(), 4095, 0, 100) & 0xFF;
    transmitedFrame[4] = (getBytesFromVoltage(ui->analogIn1_slider->value(), 4095, 0, 100) >> 8) & 0xFF;
    // Analgog Input 2
    transmitedFrame[5] = getBytesFromVoltage(ui->analogIn2_slider->value(), 4095, 0, 100) & 0xFF;
    transmitedFrame[6] = (getBytesFromVoltage(ui->analogIn2_slider->value(), 4095, 0, 100) >> 8) & 0xFF;
    // Analgog Input 3
    transmitedFrame[7] = getBytesFromVoltage(ui->analogIn3_slider->value(), 4095, 0, 100) & 0xFF;
    transmitedFrame[8] = (getBytesFromVoltage(ui->analogIn3_slider->value(), 4095, 0, 100) >> 8) & 0xFF;
    // Analgog Input 4
    transmitedFrame[9] = getBytesFromVoltage(ui->analogIn4_slider->value(), 4095, 0, 100) & 0xFF;
    transmitedFrame[10] = (getBytesFromVoltage(ui->analogIn4_slider->value(), 4095, 0, 100) >> 8) & 0xFF;
    // Analgog Input 5
    transmitedFrame[11] = getBytesFromVoltage(ui->analogIn5_slider->value(), 4095, 0, 100) & 0xFF;
    transmitedFrame[12] = (getBytesFromVoltage(ui->analogIn5_slider->value(), 4095, 0, 100) >> 8) & 0xFF;
    // Analgog Input 6
    transmitedFrame[13] = getBytesFromVoltage(ui->analogIn6_slider->value(), 4095, 0, 100) & 0xFF;
    transmitedFrame[14] = (getBytesFromVoltage(ui->analogIn6_slider->value(), 4095, 0, 100) >> 8) & 0xFF;
    // Analgog Input 7
    transmitedFrame[15] = getBytesFromVoltage(ui->analogIn7_slider->value(), 4095, 0, 100) & 0xFF;
    transmitedFrame[16] = (getBytesFromVoltage(ui->analogIn7_slider->value(), 4095, 0, 100) >> 8) & 0xFF;
    // Analgog Input 8
    transmitedFrame[17] = getBytesFromVoltage((double)ui->analogIn8_slider->value(), 4095, -50, 50) & 0xFF;
    transmitedFrame[18] = (getBytesFromVoltage((double)ui->analogIn8_slider->value(), 4095, -50, 50) >> 8) & 0xFF;
    // Digital Outputs
    ui->digitalOutput1->isChecked() ? transmitedFrame[19] |= 0b00000001 : transmitedFrame[19] &= 0b11111110;
    ui->digitalOutput2->isChecked() ? transmitedFrame[19] |= 0b00000010 : transmitedFrame[19] &= 0b11111101;
    ui->digitalOutput3->isChecked() ? transmitedFrame[19] |= 0b00000100 : transmitedFrame[19] &= 0b11111011;
    ui->digitalOutput4->isChecked() ? transmitedFrame[19] |= 0b00001000 : transmitedFrame[19] &= 0b11110111;
    ui->digitalOutput5->isChecked() ? transmitedFrame[19] |= 0b00010000 : transmitedFrame[19] &= 0b11101111;
    ui->digitalOutput6->isChecked() ? transmitedFrame[19] |= 0b00100000 : transmitedFrame[19] &= 0b11011111;
    ui->digitalOutput7->isChecked() ? transmitedFrame[19] |= 0b01000000 : transmitedFrame[19] &= 0b10111111;
    ui->digitalOutput8->isChecked() ? transmitedFrame[19] |= 0b10000000 : transmitedFrame[19] &= 0b01111111;
    // Analog Output 1
    transmitedFrame[20] = ((ui->analogOutput1_dial->value()*65535/50) & 0xFF);
    transmitedFrame[21] = ((ui->analogOutput1_dial->value()*65535/50) >> 8) & 0xFF;
    // Analog Output 2
    transmitedFrame[22] = (ui->analogOutput2_dial->value()*65535/50) & 0xFF;
    transmitedFrame[23] = ((ui->analogOutput2_dial->value()*65535/50) >> 8) & 0xFF;

    int bytesTransmitted = m_serial->write(transmitedFrame, 24);

    if(bytesTransmitted != 24)
        qDebug() << "ERROR TX";
    else
        qDebug() << "TX OK";
}

void MainWindow::on_connectButton_clicked()
{
    if(ui->connectButton->text() == "Connect") {
        openSerialPort();

    } else if (ui->connectButton->text() == "Disconnect") {
        closeSerialPort();
    }
}


void MainWindow::on_analogOutput1_dial_valueChanged(int value)
{
    ui->analogOutput1_lcd->display((double)ui->analogOutput1_dial->value()/10);
}

void MainWindow::on_analogOutput1_dial_sliderReleased()
{
    sendChangesToBluepill();
}

void MainWindow::on_analogOutput2_dial_valueChanged(int value)
{
    ui->analogOutput2_lcd->display((double)ui->analogOutput2_dial->value()/10);
}

void MainWindow::on_analogOutput2_dial_sliderReleased()
{
    sendChangesToBluepill();
}

void MainWindow::on_digitalOutput1_toggled(bool checked)
{
    sendChangesToBluepill();
}

void MainWindow::on_digitalOutput2_toggled(bool checked)
{
    sendChangesToBluepill();
}

void MainWindow::on_digitalOutput3_toggled(bool checked)
{
    sendChangesToBluepill();
}

void MainWindow::on_digitalOutput4_toggled(bool checked)
{
    sendChangesToBluepill();
}

void MainWindow::on_digitalOutput5_toggled(bool checked)
{
    sendChangesToBluepill();
}

void MainWindow::on_digitalOutput6_toggled(bool checked)
{
    sendChangesToBluepill();
}

void MainWindow::on_digitalOutput7_toggled(bool checked)
{
    sendChangesToBluepill();
}

void MainWindow::on_digitalOutput8_toggled(bool checked)
{
    sendChangesToBluepill();
}


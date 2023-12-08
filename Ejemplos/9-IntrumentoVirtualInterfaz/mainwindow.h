#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* Librerias */
#include <QMainWindow>
#include <QSaveFile>
#include <QSerialPort>
#include <QMessageBox>
#include <iostream>
#include <QFileInfo>
#include<QDebug>
#include<cstddef>
#include<QSerialPortInfo>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void writeData(const QByteArray &data);
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void on_connectButton_clicked();

    void on_digitalOutput7_toggled(bool checked);

    void on_digitalOutput1_toggled(bool checked);

    void on_digitalOutput2_toggled(bool checked);

    void on_digitalOutput4_toggled(bool checked);

    void on_digitalOutput5_toggled(bool checked);

    void on_digitalOutput6_toggled(bool checked);

    void on_digitalOutput8_toggled(bool checked);

    void on_digitalOutput3_toggled(bool checked);

    void on_analogOutput1_dial_sliderReleased();

    void on_analogOutput2_dial_sliderReleased();

    void on_analogOutput2_dial_valueChanged(int value);

    void on_analogOutput1_dial_valueChanged(int value);

private:
    Ui::MainWindow *ui = nullptr;

    // Serial Port
    QSerialPort *m_serial = nullptr;
    void openSerialPort();
    void closeSerialPort();

    // Rx
    QByteArray receivedFrame;
    int positionToRead = 0;
    short qtCounter;
    short receivedCounter;
    void updateDigitalInputs(unsigned char inputs);
    void updateDigitalOutputs(unsigned char outputs);

    // Tx
    char transmitedFrame[24];
    void sendChangesToBluepill();

    // Convertions
    double getVoltageFromBytes(short bytes, int resolution, double minVoltage, double maxVoltage);
    short getBytesFromVoltage(double voltage, int resolution, double minVoltage, double maxVoltage);
};

#endif // MAINWINDOW_H

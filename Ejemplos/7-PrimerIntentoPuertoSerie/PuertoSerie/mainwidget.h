#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QThread>  //Manejo de hilos
#include <QMutex>   //Manejo de bloquedo de datos
#include <QtSerialPort/QSerialPort> //Manejo de puerto Serial


QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }
QT_END_NAMESPACE

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private slots:
    void recibirArreglo();

private:
    Ui::mainWidget *ui;

    QThread *mTrheadSerial;
    QMutex   mQMutex;
    QSerialPort *mSerial;
    QString cadenasRecibida = "";
};
#endif // MAINWIDGET_H

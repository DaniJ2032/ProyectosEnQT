#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>
#include <QThread>


QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }
QT_END_NAMESPACE

class serialThread;

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private slots:
    void recibirArreglos(const QByteArray& data);
    void on_Iniciar_clicked();
    void on_Finalizar_clicked();

    void on_listWidget_currentTextChanged(const QString &currentText);

private:
    Ui::mainWidget *ui;
    serialThread *mSerialThread;
    QSerialPort serialPort; //Objeto Serial

};
#endif // MAINWIDGET_H

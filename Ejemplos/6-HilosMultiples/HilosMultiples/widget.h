#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class DuThread;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_iniciarButton_clicked();

    void on_detenerButton_clicked();

private:
    Ui::Widget *ui;

    DuThread *mThread1; //Declaracion de mis objetos hilos
    DuThread *mThread2;
    DuThread *mThread3;

};
#endif // WIDGET_H

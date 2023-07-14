#include "widget.h"
#include "ui_widget.h"
#include "duthread.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mThread1 = new DuThread(10, this);  //Control de los obj hilos de DuThread
    mThread2 = new DuThread(20, this);
    mThread3 = new DuThread(30, this);


    ui->progressBar->setValue(0);
    ui->dial->setValue(0);          //Valores iniciales
    ui->lcdNumber->display(0);

    connect(mThread1, &DuThread::ValorCambiado, ui->progressBar,
            &QProgressBar::setValue);
    connect(mThread2, &DuThread::ValorCambiado, ui->dial,       //Conecto cada hilo con su corresp. front
            &QDial::setValue);

    connect(mThread3, &DuThread::ValorCambiado, ui->lcdNumber,
            static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));

//    connect(mThread3, SIGNAL(ValorCambiado(int)), ui->lcdNumber,
//            SLOT(display(int))); //Otra forma de declaracion

}

Widget::~Widget()
{
    delete ui;
}

//Acciones de los botones
void Widget::on_iniciarButton_clicked()
{
    mThread1->start();
    mThread2->start();
    mThread3->start();
}


void Widget::on_detenerButton_clicked()
{
    mThread1->terminate();
    mThread2->terminate();
    mThread3->terminate();

}


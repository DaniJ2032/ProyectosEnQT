#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comm.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(&m_thread, &comm::request, this, &MainWindow::showRequest);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRequest(const QString &s)
{
    //ui->label_2->setText(s);

    // Envio a cada LcdNumber
    QStringList values = s.split(",");

    ui->AN1->display(values[0].toInt());
    ui->AN2->display(values[1].toInt());
    ui->AN3->display(values[2].toInt());
    ui->AN4->display(values[3].toInt());
    ui->AN5->display(values[4].toInt());
    ui->AN6->display(values[5].toInt());
    ui->AN7->display(values[6].toInt());
    ui->AN8->display(values[7].toInt());

    if(values[0].toInt() > 500){
        ui->Led1->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_on.png"));
        ui->Led1->setFixedSize(30,30);
    }
    else{
        ui->Led1->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_off.png"));
        ui->Led1->setFixedSize(30,30);
    }

    if(values[1].toInt() > 500){
        ui->Led2->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_on.png"));
        ui->Led2->setFixedSize(30,30);
    }
    else{
        ui->Led2->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_off.png"));
        ui->Led2->setFixedSize(30,30);
    }

    if(values[2].toInt() > 500){
        ui->Led3->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_on.png"));
        ui->Led3->setFixedSize(30,30);
    }
    else{
        ui->Led3->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_off.png"));
        ui->Led3->setFixedSize(30,30);
    }

    if(values[3].toInt() > 500){
        ui->Led4->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_on.png"));
        ui->Led4->setFixedSize(30,30);
    }
    else{
        ui->Led4->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_off.png"));
        ui->Led4->setFixedSize(30,30);
    }

    if(values[4].toInt() > 500){
        ui->Led5->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_on.png"));
        ui->Led5->setFixedSize(30,30);
    }
    else{
        ui->Led5->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_off.png"));
        ui->Led5->setFixedSize(30,30);
    }

    if(values[5].toInt() > 500){
        ui->Led6->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_on.png"));
        ui->Led6->setFixedSize(30,30);
    }
    else{
        ui->Led6->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_off.png"));
        ui->Led6->setFixedSize(30,30);
    }

    if(values[6].toInt() > 500){
        ui->Led7->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_on.png"));
        ui->Led7->setFixedSize(30,30);
    }
    else{
        ui->Led7->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_off.png"));
        ui->Led7->setFixedSize(30,30);
    }

    if(values[7].toInt() > 500){
        ui->Led8->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_on.png"));
        ui->Led8->setFixedSize(30,30);
    }
    else{
        ui->Led8->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_off.png"));
        ui->Led8->setFixedSize(30,30);
    }

    if(values[0].toInt() > 2500){
        ui->DO1->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_on.png"));
        ui->DO1->setFixedSize(30,30);
    }
    else{
        ui->DO1->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_off.png"));
        ui->DO1->setFixedSize(30,30);
    }

    if(values[1].toInt() > 2500){
        ui->DO2->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_on.png"));
        ui->DO2->setFixedSize(30,30);
    }
    else{
        ui->DO2->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_off.png"));
        ui->DO2->setFixedSize(30,30);
    }

    if(values[2].toInt() > 2500){
        ui->DO3->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_on.png"));
        ui->DO3->setFixedSize(30,30);
    }
    else{
        ui->DO3->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_off.png"));
        ui->DO3->setFixedSize(30,30);
    }

    if(values[3].toInt() > 2500){
        ui->DO4->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_on.png"));
        ui->DO4->setFixedSize(30,30);
    }
    else{
        ui->DO4->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_off.png"));
        ui->DO4->setFixedSize(30,30);
    }

    if(values[4].toInt() > 2500){
        ui->DO5->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_on.png"));
        ui->DO5->setFixedSize(30,30);
    }
    else{
        ui->DO5->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_off.png"));
        ui->DO5->setFixedSize(30,30);
    }

    if(values[5].toInt() > 2500){
        ui->DO6->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_on.png"));
        ui->DO6->setFixedSize(30,30);
    }
    else{
        ui->DO6->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_off.png"));
        ui->DO6->setFixedSize(30,30);
    }

    if(values[6].toInt() > 2500){
        ui->DO7->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_on.png"));
        ui->DO7->setFixedSize(30,30);
    }
    else{
        ui->DO7->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_off.png"));
        ui->DO7->setFixedSize(30,30);
    }

    if(values[7].toInt() > 2500){
        ui->DO8->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_on.png"));
        ui->DO8->setFixedSize(30,30);
    }
    else{
        ui->DO8->setPixmap(QPixmap("X:/Users/DaniBrem/Desktop/ProyectosEnQT/Profe/TTGO_Serial_Reader_Threaded/TTGO_Serial_Reader_Threaded/img/Led_G_off.png"));
        ui->DO8->setFixedSize(30,30);
    }

}
void MainWindow::on_pushButton_clicked()
{
    m_thread.startSlave("COM2", 100, ui->label->text());

}

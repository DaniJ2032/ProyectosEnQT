#include "sondialog.h"
#include "ui_sondialog.h"
#include "threadnumber.h"

SonDialog::SonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SonDialog)
{
    ui->setupUi(this);
    mThread = new ThreadNumber(this);

    mThread->start(QThread::HighPriority); // Prioridad alta, inicio del hilo

    connect(mThread, &ThreadNumber::NewNumber, [&](int n){  //recibe el numero y lo pasa a la pantalla para visualizarlo
      ui->listWidget->addItem(QString::number(n));
    });
}

SonDialog::~SonDialog()
{
    delete ui;
}

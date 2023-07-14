#include "dialog.h"
#include "ui_dialog.h"
#include "sondialog.h" //--> Incluimos el hijo

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mSonDialog = new SonDialog(this);
    mSonDialog ->show();
}

Dialog::~Dialog()
{
    delete ui;
}

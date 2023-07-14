#ifndef SONDIALOG_H
#define SONDIALOG_H

#include <QDialog>

namespace Ui {
class SonDialog;
}

class ThreadNumber;

class SonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SonDialog(QWidget *parent = nullptr);
    ~SonDialog();

private:
    Ui::SonDialog *ui;
    ThreadNumber *mThread; //puntero clase thread

};

#endif // SONDIALOG_H

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "serialthread.h"

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

    void on_Iniciar_clicked();
    void on_Finalizar_clicked();
    void appendDataToListWidget(const QByteArray &currentText);

private:
    Ui::mainWidget *ui;
    serialThread *mSerialThread;
};
#endif // MAINWIDGET_H

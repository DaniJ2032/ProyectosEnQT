#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "comm.h"

#include <QMainWindow>

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
    void showRequest(const QString &s);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    comm m_thread;
};
#endif // MAINWINDOW_H

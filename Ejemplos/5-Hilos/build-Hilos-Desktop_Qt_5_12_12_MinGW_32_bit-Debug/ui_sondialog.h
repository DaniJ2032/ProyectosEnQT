/********************************************************************************
** Form generated from reading UI file 'sondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONDIALOG_H
#define UI_SONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_SonDialog
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *SonDialog)
    {
        if (SonDialog->objectName().isEmpty())
            SonDialog->setObjectName(QString::fromUtf8("SonDialog"));
        SonDialog->resize(400, 300);
        listWidget = new QListWidget(SonDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 331, 241));

        retranslateUi(SonDialog);

        QMetaObject::connectSlotsByName(SonDialog);
    } // setupUi

    void retranslateUi(QDialog *SonDialog)
    {
        SonDialog->setWindowTitle(QApplication::translate("SonDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SonDialog: public Ui_SonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QFrame *line;
    QGroupBox *groupBox;
    QLabel *Led1;
    QLabel *Led2;
    QLabel *Led3;
    QLabel *Led4;
    QLabel *Led5;
    QLabel *Led6;
    QLabel *Led7;
    QLabel *Led8;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLCDNumber *AN3;
    QLCDNumber *AN1;
    QLabel *label_5;
    QLCDNumber *AN4;
    QLCDNumber *AN5;
    QLCDNumber *AN7;
    QLCDNumber *AN2;
    QLabel *label_4;
    QLCDNumber *AN6;
    QLCDNumber *AN8;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QDial *dial_2;
    QLabel *label_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QDial *dial;
    QLabel *label;
    QGroupBox *groupBox_4;
    QLabel *DO1;
    QLabel *DO2;
    QLabel *DO3;
    QLabel *DO4;
    QLabel *DO5;
    QLabel *DO6;
    QLabel *DO7;
    QLabel *DO8;
    QPushButton *pushButton_2;
    QLabel *label_12;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1088, 451);
        MainWindow->setAcceptDrops(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(890, 280, 81, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        font.setPointSize(12);
        pushButton->setFont(font);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(30, 250, 1031, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 270, 421, 91));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setFont(font);
        Led1 = new QLabel(groupBox);
        Led1->setObjectName(QString::fromUtf8("Led1"));
        Led1->setGeometry(QRect(20, 30, 30, 30));
        sizePolicy.setHeightForWidth(Led1->sizePolicy().hasHeightForWidth());
        Led1->setSizePolicy(sizePolicy);
        Led1->setBaseSize(QSize(30, 30));
        Led1->setPixmap(QPixmap(QString::fromUtf8("img/Led_off.png")));
        Led1->setScaledContents(true);
        Led2 = new QLabel(groupBox);
        Led2->setObjectName(QString::fromUtf8("Led2"));
        Led2->setGeometry(QRect(70, 30, 30, 30));
        sizePolicy.setHeightForWidth(Led2->sizePolicy().hasHeightForWidth());
        Led2->setSizePolicy(sizePolicy);
        Led2->setPixmap(QPixmap(QString::fromUtf8("img/Led_off.png")));
        Led2->setScaledContents(true);
        Led3 = new QLabel(groupBox);
        Led3->setObjectName(QString::fromUtf8("Led3"));
        Led3->setGeometry(QRect(120, 30, 30, 30));
        sizePolicy.setHeightForWidth(Led3->sizePolicy().hasHeightForWidth());
        Led3->setSizePolicy(sizePolicy);
        Led3->setPixmap(QPixmap(QString::fromUtf8("img/Led_off.png")));
        Led3->setScaledContents(true);
        Led4 = new QLabel(groupBox);
        Led4->setObjectName(QString::fromUtf8("Led4"));
        Led4->setGeometry(QRect(170, 30, 30, 30));
        sizePolicy.setHeightForWidth(Led4->sizePolicy().hasHeightForWidth());
        Led4->setSizePolicy(sizePolicy);
        Led4->setPixmap(QPixmap(QString::fromUtf8("img/Led_off.png")));
        Led4->setScaledContents(true);
        Led5 = new QLabel(groupBox);
        Led5->setObjectName(QString::fromUtf8("Led5"));
        Led5->setGeometry(QRect(220, 30, 30, 30));
        sizePolicy.setHeightForWidth(Led5->sizePolicy().hasHeightForWidth());
        Led5->setSizePolicy(sizePolicy);
        Led5->setPixmap(QPixmap(QString::fromUtf8("img/Led_off.png")));
        Led5->setScaledContents(true);
        Led6 = new QLabel(groupBox);
        Led6->setObjectName(QString::fromUtf8("Led6"));
        Led6->setGeometry(QRect(270, 30, 30, 30));
        sizePolicy.setHeightForWidth(Led6->sizePolicy().hasHeightForWidth());
        Led6->setSizePolicy(sizePolicy);
        Led6->setPixmap(QPixmap(QString::fromUtf8("img/Led_off.png")));
        Led6->setScaledContents(true);
        Led7 = new QLabel(groupBox);
        Led7->setObjectName(QString::fromUtf8("Led7"));
        Led7->setGeometry(QRect(320, 30, 30, 30));
        sizePolicy.setHeightForWidth(Led7->sizePolicy().hasHeightForWidth());
        Led7->setSizePolicy(sizePolicy);
        Led7->setPixmap(QPixmap(QString::fromUtf8("img/Led_off.png")));
        Led7->setScaledContents(true);
        Led8 = new QLabel(groupBox);
        Led8->setObjectName(QString::fromUtf8("Led8"));
        Led8->setGeometry(QRect(370, 30, 30, 30));
        sizePolicy.setHeightForWidth(Led8->sizePolicy().hasHeightForWidth());
        Led8->setSizePolicy(sizePolicy);
        Led8->setPixmap(QPixmap(QString::fromUtf8("img/Led_off.png")));
        Led8->setScaledContents(true);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 50, 751, 201));
        groupBox_2->setFont(font);
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 731, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 3, 0, 3);
        AN3 = new QLCDNumber(layoutWidget);
        AN3->setObjectName(QString::fromUtf8("AN3"));

        gridLayout->addWidget(AN3, 1, 2, 1, 1);

        AN1 = new QLCDNumber(layoutWidget);
        AN1->setObjectName(QString::fromUtf8("AN1"));

        gridLayout->addWidget(AN1, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        AN4 = new QLCDNumber(layoutWidget);
        AN4->setObjectName(QString::fromUtf8("AN4"));

        gridLayout->addWidget(AN4, 1, 3, 1, 1);

        AN5 = new QLCDNumber(layoutWidget);
        AN5->setObjectName(QString::fromUtf8("AN5"));

        gridLayout->addWidget(AN5, 3, 0, 1, 1);

        AN7 = new QLCDNumber(layoutWidget);
        AN7->setObjectName(QString::fromUtf8("AN7"));

        gridLayout->addWidget(AN7, 3, 2, 1, 1);

        AN2 = new QLCDNumber(layoutWidget);
        AN2->setObjectName(QString::fromUtf8("AN2"));

        gridLayout->addWidget(AN2, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tahoma"));
        font1.setPointSize(12);
        font1.setBold(false);
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        AN6 = new QLCDNumber(layoutWidget);
        AN6->setObjectName(QString::fromUtf8("AN6"));

        gridLayout->addWidget(AN6, 3, 1, 1, 1);

        AN8 = new QLCDNumber(layoutWidget);
        AN8->setObjectName(QString::fromUtf8("AN8"));

        gridLayout->addWidget(AN8, 3, 3, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 2, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 2, 3, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setGeometry(QRect(790, 50, 271, 201));
        groupBox_3->setFont(font);
        groupBox_3->setAutoFillBackground(false);
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 30, 121, 161));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        dial_2 = new QDial(layoutWidget1);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));

        verticalLayout_2->addWidget(dial_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 121, 161));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dial = new QDial(layoutWidget2);
        dial->setObjectName(QString::fromUtf8("dial"));

        verticalLayout->addWidget(dial);

        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(460, 270, 421, 91));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setFont(font);
        DO1 = new QLabel(groupBox_4);
        DO1->setObjectName(QString::fromUtf8("DO1"));
        DO1->setGeometry(QRect(20, 30, 30, 30));
        sizePolicy.setHeightForWidth(DO1->sizePolicy().hasHeightForWidth());
        DO1->setSizePolicy(sizePolicy);
        DO1->setBaseSize(QSize(30, 30));
        DO1->setPixmap(QPixmap(QString::fromUtf8("img/Led_G_off.png")));
        DO1->setScaledContents(true);
        DO2 = new QLabel(groupBox_4);
        DO2->setObjectName(QString::fromUtf8("DO2"));
        DO2->setGeometry(QRect(70, 30, 30, 30));
        sizePolicy.setHeightForWidth(DO2->sizePolicy().hasHeightForWidth());
        DO2->setSizePolicy(sizePolicy);
        DO2->setPixmap(QPixmap(QString::fromUtf8("img/Led_G_off.png")));
        DO2->setScaledContents(true);
        DO3 = new QLabel(groupBox_4);
        DO3->setObjectName(QString::fromUtf8("DO3"));
        DO3->setGeometry(QRect(120, 30, 30, 30));
        sizePolicy.setHeightForWidth(DO3->sizePolicy().hasHeightForWidth());
        DO3->setSizePolicy(sizePolicy);
        DO3->setPixmap(QPixmap(QString::fromUtf8("img/Led_G_off.png")));
        DO3->setScaledContents(true);
        DO4 = new QLabel(groupBox_4);
        DO4->setObjectName(QString::fromUtf8("DO4"));
        DO4->setGeometry(QRect(170, 30, 30, 30));
        sizePolicy.setHeightForWidth(DO4->sizePolicy().hasHeightForWidth());
        DO4->setSizePolicy(sizePolicy);
        DO4->setPixmap(QPixmap(QString::fromUtf8("img/Led_G_off.png")));
        DO4->setScaledContents(true);
        DO5 = new QLabel(groupBox_4);
        DO5->setObjectName(QString::fromUtf8("DO5"));
        DO5->setGeometry(QRect(220, 30, 30, 30));
        sizePolicy.setHeightForWidth(DO5->sizePolicy().hasHeightForWidth());
        DO5->setSizePolicy(sizePolicy);
        DO5->setPixmap(QPixmap(QString::fromUtf8("img/Led_G_off.png")));
        DO5->setScaledContents(true);
        DO6 = new QLabel(groupBox_4);
        DO6->setObjectName(QString::fromUtf8("DO6"));
        DO6->setGeometry(QRect(270, 30, 30, 30));
        sizePolicy.setHeightForWidth(DO6->sizePolicy().hasHeightForWidth());
        DO6->setSizePolicy(sizePolicy);
        DO6->setPixmap(QPixmap(QString::fromUtf8("img/Led_G_off.png")));
        DO6->setScaledContents(true);
        DO7 = new QLabel(groupBox_4);
        DO7->setObjectName(QString::fromUtf8("DO7"));
        DO7->setGeometry(QRect(320, 30, 30, 30));
        sizePolicy.setHeightForWidth(DO7->sizePolicy().hasHeightForWidth());
        DO7->setSizePolicy(sizePolicy);
        DO7->setPixmap(QPixmap(QString::fromUtf8("img/Led_G_off.png")));
        DO7->setScaledContents(true);
        DO8 = new QLabel(groupBox_4);
        DO8->setObjectName(QString::fromUtf8("DO8"));
        DO8->setGeometry(QRect(370, 30, 30, 30));
        sizePolicy.setHeightForWidth(DO8->sizePolicy().hasHeightForWidth());
        DO8->setSizePolicy(sizePolicy);
        DO8->setPixmap(QPixmap(QString::fromUtf8("img/Led_G_off.png")));
        DO8->setScaledContents(true);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(984, 280, 81, 81));
        pushButton_2->setFont(font);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 0, 351, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Dubai Medium"));
        font2.setPointSize(24);
        label_12->setFont(font2);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 370, 1031, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_2->addLayout(horizontalLayout);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        layoutWidget->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        line->raise();
        groupBox->raise();
        groupBox_4->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_12->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1088, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(dial, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), pushButton, SLOT(click()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Instrumento Virtual 2023", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Conectar", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Entradas Digitales", nullptr));
        Led1->setText(QString());
        Led2->setText(QString());
        Led3->setText(QString());
        Led4->setText(QString());
        Led5->setText(QString());
        Led6->setText(QString());
        Led7->setText(QString());
        Led8->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Entradas Anal\303\263gicas", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Entrada 2 - 0 a 10V", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Entrada 1 - 0 a 10V", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Entrada 5 - 0 a 10V", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Entrada 3 - 0 a 10V", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Entrada 4 - 0 a 10V", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Entrada 6 - 0 a 10V", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Entrada 8  -5 a 5V", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Entrada 7 - 0 a 10V", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Salidas Anal\303\263gicas - PWM", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "PWM2", nullptr));
        label->setText(QApplication::translate("MainWindow", "PWM1", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Salidas Digitales", nullptr));
        DO1->setText(QString());
        DO2->setText(QString());
        DO3->setText(QString());
        DO4->setText(QString());
        DO5->setText(QString());
        DO6->setText(QString());
        DO7->setText(QString());
        DO8->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Salir", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Instrumento Virtual 2023", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Comandos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

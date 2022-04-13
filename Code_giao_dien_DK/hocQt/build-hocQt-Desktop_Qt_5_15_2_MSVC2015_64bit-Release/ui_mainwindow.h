/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *imgOriginal_2;
    QLabel *imgOriginal;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *detection;
    QPushButton *btnPauseOrResume;
    QLabel *label;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *Connect;
    QPushButton *Disconnect;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Len;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Sang_Trai;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Sang_Phai;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *Lui;
    QSpacerItem *horizontalSpacer_7;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(544, 459);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        imgOriginal_2 = new QLabel(centralwidget);
        imgOriginal_2->setObjectName(QString::fromUtf8("imgOriginal_2"));

        horizontalLayout->addWidget(imgOriginal_2);

        imgOriginal = new QLabel(centralwidget);
        imgOriginal->setObjectName(QString::fromUtf8("imgOriginal"));

        horizontalLayout->addWidget(imgOriginal);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        detection = new QPushButton(centralwidget);
        detection->setObjectName(QString::fromUtf8("detection"));

        horizontalLayout_2->addWidget(detection);

        btnPauseOrResume = new QPushButton(centralwidget);
        btnPauseOrResume->setObjectName(QString::fromUtf8("btnPauseOrResume"));
        QFont font;
        font.setPointSize(11);
        btnPauseOrResume->setFont(font);

        horizontalLayout_2->addWidget(btnPauseOrResume);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        Connect = new QPushButton(centralwidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));

        horizontalLayout_8->addWidget(Connect);

        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));

        horizontalLayout_8->addWidget(Disconnect);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_4->addWidget(comboBox);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_4->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        Len = new QPushButton(centralwidget);
        Len->setObjectName(QString::fromUtf8("Len"));

        horizontalLayout_5->addWidget(Len);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        Sang_Trai = new QPushButton(centralwidget);
        Sang_Trai->setObjectName(QString::fromUtf8("Sang_Trai"));

        horizontalLayout_3->addWidget(Sang_Trai);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        Sang_Phai = new QPushButton(centralwidget);
        Sang_Phai->setObjectName(QString::fromUtf8("Sang_Phai"));

        horizontalLayout_3->addWidget(Sang_Phai);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        Lui = new QPushButton(centralwidget);
        Lui->setObjectName(QString::fromUtf8("Lui"));

        horizontalLayout_7->addWidget(Lui);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_7);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 544, 21));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        imgOriginal_2->setText(QString());
        imgOriginal->setText(QString());
        detection->setText(QCoreApplication::translate("MainWindow", "DETECTION", nullptr));
        btnPauseOrResume->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        label->setText(QString());
        Connect->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
        Disconnect->setText(QCoreApplication::translate("MainWindow", "disconnect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        Len->setText(QCoreApplication::translate("MainWindow", "L\303\252n", nullptr));
        Sang_Trai->setText(QCoreApplication::translate("MainWindow", "Sang Tr\303\241ii", nullptr));
        Sang_Phai->setText(QCoreApplication::translate("MainWindow", "Sang Ph\341\272\243i", nullptr));
        Lui->setText(QCoreApplication::translate("MainWindow", "L\303\271i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

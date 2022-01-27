/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *num1;
    QLineEdit *num2;
    QLineEdit *res;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *plus_button;
    QPushButton *division_button;
    QPushButton *substract_button;
    QPushButton *multiplication_button;
    QLabel *label_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *uyari;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Gothic UI"));
        font.setPointSize(10);
        font.setItalic(false);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        num1 = new QLineEdit(centralwidget);
        num1->setObjectName(QString::fromUtf8("num1"));
        num1->setGeometry(QRect(230, 150, 113, 22));
        num2 = new QLineEdit(centralwidget);
        num2->setObjectName(QString::fromUtf8("num2"));
        num2->setGeometry(QRect(390, 150, 113, 22));
        res = new QLineEdit(centralwidget);
        res->setObjectName(QString::fromUtf8("res"));
        res->setGeometry(QRect(300, 220, 113, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 110, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 110, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 200, 49, 16));
        plus_button = new QPushButton(centralwidget);
        plus_button->setObjectName(QString::fromUtf8("plus_button"));
        plus_button->setGeometry(QRect(280, 290, 75, 24));
        division_button = new QPushButton(centralwidget);
        division_button->setObjectName(QString::fromUtf8("division_button"));
        division_button->setGeometry(QRect(280, 320, 75, 24));
        substract_button = new QPushButton(centralwidget);
        substract_button->setObjectName(QString::fromUtf8("substract_button"));
        substract_button->setGeometry(QRect(370, 290, 75, 24));
        multiplication_button = new QPushButton(centralwidget);
        multiplication_button->setObjectName(QString::fromUtf8("multiplication_button"));
        multiplication_button->setGeometry(QRect(370, 320, 75, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 380, 161, 16));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(40, 40, 89, 20));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(120, 40, 89, 20));
        uyari = new QLineEdit(centralwidget);
        uyari->setObjectName(QString::fromUtf8("uyari"));
        uyari->setGeometry(QRect(410, 40, 311, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Say\304\261 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Say\304\261 2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sonu\303\247", nullptr));
        plus_button->setText(QCoreApplication::translate("MainWindow", "Topla", nullptr));
        division_button->setText(QCoreApplication::translate("MainWindow", "B\303\266l", nullptr));
        substract_button->setText(QCoreApplication::translate("MainWindow", "\303\207\304\261kar", nullptr));
        multiplication_button->setText(QCoreApplication::translate("MainWindow", "\303\207arp", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\304\260lgin\303\247 Hesap Makinesi", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "T\303\274rk\303\247e", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

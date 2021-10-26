/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QLCDNumber *monedas;
    QPushButton *inicio;
    QPushButton *partida;
    QPushButton *anterior;
    QPushButton *salir;
    QPushButton *aceptar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(40, 60, 431, 271));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(76, 10, 71, 41));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(140, 12, 71, 31));
        lcdNumber->setProperty("intValue", QVariant(30));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 20, 81, 21));
        monedas = new QLCDNumber(centralwidget);
        monedas->setObjectName(QString::fromUtf8("monedas"));
        monedas->setGeometry(QRect(300, 12, 81, 31));
        inicio = new QPushButton(centralwidget);
        inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->setGeometry(QRect(150, 130, 158, 23));
        partida = new QPushButton(centralwidget);
        partida->setObjectName(QString::fromUtf8("partida"));
        partida->setGeometry(QRect(150, 160, 158, 23));
        anterior = new QPushButton(centralwidget);
        anterior->setObjectName(QString::fromUtf8("anterior"));
        anterior->setGeometry(QRect(150, 190, 158, 23));
        salir = new QPushButton(centralwidget);
        salir->setObjectName(QString::fromUtf8("salir"));
        salir->setGeometry(QRect(150, 220, 158, 23));
        aceptar = new QPushButton(centralwidget);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setGeometry(QRect(190, 270, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">TIEMPO</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">MONEDAS</span></p></body></html>", nullptr));
        inicio->setText(QCoreApplication::translate("MainWindow", "INICIO", nullptr));
        partida->setText(QCoreApplication::translate("MainWindow", "NUEVA PARTIDA", nullptr));
        anterior->setText(QCoreApplication::translate("MainWindow", "Anterior", nullptr));
        salir->setText(QCoreApplication::translate("MainWindow", "SALIR", nullptr));
        aceptar->setText(QCoreApplication::translate("MainWindow", "ACEPTAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

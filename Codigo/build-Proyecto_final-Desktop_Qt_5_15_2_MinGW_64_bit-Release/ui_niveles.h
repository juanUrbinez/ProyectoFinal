/********************************************************************************
** Form generated from reading UI file 'niveles.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVELES_H
#define UI_NIVELES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_niveles
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QLCDNumber *monedas;
    QPushButton *anterior;
    QPushButton *siguiente;
    QLCDNumber *temp;

    void setupUi(QWidget *niveles)
    {
        if (niveles->objectName().isEmpty())
            niveles->setObjectName(QString::fromUtf8("niveles"));
        niveles->resize(640, 369);
        graphicsView = new QGraphicsView(niveles);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(50, 70, 411, 291));
        label = new QLabel(niveles);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 71, 16));
        lcdNumber = new QLCDNumber(niveles);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(100, 20, 64, 23));
        lcdNumber->setProperty("intValue", QVariant(30));
        label_2 = new QLabel(niveles);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 20, 81, 21));
        monedas = new QLCDNumber(niveles);
        monedas->setObjectName(QString::fromUtf8("monedas"));
        monedas->setGeometry(QRect(350, 20, 64, 23));
        anterior = new QPushButton(niveles);
        anterior->setObjectName(QString::fromUtf8("anterior"));
        anterior->setGeometry(QRect(460, 20, 75, 23));
        siguiente = new QPushButton(niveles);
        siguiente->setObjectName(QString::fromUtf8("siguiente"));
        siguiente->setGeometry(QRect(550, 20, 75, 23));
        temp = new QLCDNumber(niveles);
        temp->setObjectName(QString::fromUtf8("temp"));
        temp->setGeometry(QRect(180, 20, 64, 23));
        temp->setProperty("intValue", QVariant(30));

        retranslateUi(niveles);

        QMetaObject::connectSlotsByName(niveles);
    } // setupUi

    void retranslateUi(QWidget *niveles)
    {
        niveles->setWindowTitle(QCoreApplication::translate("niveles", "Form", nullptr));
        label->setText(QCoreApplication::translate("niveles", "<html><head/><body><p><span style=\" font-size:12pt;\">TIEMPO</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("niveles", "<html><head/><body><p><span style=\" font-size:12pt;\">MONEDAS</span></p></body></html>", nullptr));
        anterior->setText(QCoreApplication::translate("niveles", "ANTERIOR", nullptr));
        siguiente->setText(QCoreApplication::translate("niveles", "SIGUIENTE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class niveles: public Ui_niveles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVELES_H

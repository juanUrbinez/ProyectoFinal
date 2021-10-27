/********************************************************************************
** Form generated from reading UI file 'registro.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_H
#define UI_REGISTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registro
{
public:
    QGraphicsView *graphicsView;
    QLabel *usuario;
    QLabel *contrasena;
    QLineEdit *login;
    QLineEdit *pass;
    QPushButton *enviar;
    QCommandLinkButton *entrar;
    QPushButton *volver;
    QPushButton *regist;
    QPushButton *crear;

    void setupUi(QWidget *registro)
    {
        if (registro->objectName().isEmpty())
            registro->setObjectName(QString::fromUtf8("registro"));
        registro->resize(492, 379);
        graphicsView = new QGraphicsView(registro);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(60, 40, 351, 301));
        usuario = new QLabel(registro);
        usuario->setObjectName(QString::fromUtf8("usuario"));
        usuario->setGeometry(QRect(80, 100, 71, 21));
        contrasena = new QLabel(registro);
        contrasena->setObjectName(QString::fromUtf8("contrasena"));
        contrasena->setGeometry(QRect(70, 160, 91, 16));
        login = new QLineEdit(registro);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(190, 100, 113, 20));
        pass = new QLineEdit(registro);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(190, 160, 113, 20));
        pass->setEchoMode(QLineEdit::Password);
        enviar = new QPushButton(registro);
        enviar->setObjectName(QString::fromUtf8("enviar"));
        enviar->setGeometry(QRect(260, 210, 75, 23));
        entrar = new QCommandLinkButton(registro);
        entrar->setObjectName(QString::fromUtf8("entrar"));
        entrar->setGeometry(QRect(80, 200, 172, 41));
        volver = new QPushButton(registro);
        volver->setObjectName(QString::fromUtf8("volver"));
        volver->setGeometry(QRect(70, 50, 75, 23));
        regist = new QPushButton(registro);
        regist->setObjectName(QString::fromUtf8("regist"));
        regist->setGeometry(QRect(110, 260, 91, 23));
        crear = new QPushButton(registro);
        crear->setObjectName(QString::fromUtf8("crear"));
        crear->setGeometry(QRect(220, 260, 75, 23));

        retranslateUi(registro);

        QMetaObject::connectSlotsByName(registro);
    } // setupUi

    void retranslateUi(QWidget *registro)
    {
        registro->setWindowTitle(QCoreApplication::translate("registro", "Form", nullptr));
        usuario->setText(QCoreApplication::translate("registro", "<html><head/><body><p><span style=\" font-size:10pt;\">USUARIO</span></p></body></html>", nullptr));
        contrasena->setText(QCoreApplication::translate("registro", "<html><head/><body><p><span style=\" font-size:10pt;\">CONTRASE\303\221A</span></p></body></html>", nullptr));
        enviar->setText(QCoreApplication::translate("registro", "ENVIAR", nullptr));
        entrar->setText(QCoreApplication::translate("registro", "ENTRAR", nullptr));
        volver->setText(QCoreApplication::translate("registro", "VOLVER", nullptr));
        regist->setText(QCoreApplication::translate("registro", "REGISTRARSE", nullptr));
        crear->setText(QCoreApplication::translate("registro", "LOGIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registro: public Ui_registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_H

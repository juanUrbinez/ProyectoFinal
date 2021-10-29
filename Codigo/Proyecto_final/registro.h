#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QWidget>
#include <QTextStream>




namespace Ui {
class registro;
}

class registro : public QWidget
{
    Q_OBJECT

public:
    explicit registro(QWidget *parent = nullptr);
    ~registro();
    bool correcto;
    QString nivel,score,usuario;

private slots:
    void on_volver_clicked();

    void on_entrar_clicked();

    void on_enviar_clicked();

    void on_regist_clicked();

    void on_crear_clicked();

    //void guardarProgreso();


private:
    Ui::registro *ui;
    QGraphicsScene *scene,*regist;
    short int espacio=0,cont=0;
    bool dec;
};

#endif // REGISTRO_H

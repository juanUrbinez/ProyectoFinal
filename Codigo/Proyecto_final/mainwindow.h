#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

#include "escenario.h"
#include "personaje.h"
#include "registro.h"
#include "niveles.h"


#include <QJsonArray>
#include <QMainWindow>
#include <QGraphicsScene>
#include <iostream>
#include "fstream"
#include <string>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <QDebug>
#include <QGraphicsItem>
#define tam 40

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_window();

    //presionar tecla
    void keyPressEvent(QKeyEvent * event) override;
    //soltar tecla
    void keyReleaseEvent(QKeyEvent *event) override;
    //colision
    void EvaluaColision();
    bool colision;
    QList<escenario*>plataformas;



    //void timeEvent(QTimerEvent);

private slots:
    void ActualizarPosicionPersonaje();
   // void simulacion();
    void temporizador();
    //void Mov_per();

    void on_anterior_clicked();

    //void on_siguiente_clicked();

    void on_inicio_clicked();

    void on_salir_clicked();

    void on_partida_clicked();

    void on_aceptar_clicked();

    void on_nivel_clicked();

private:
    void generar_mapa();
    //void colision();

    short int nivel1[14][50]=
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,5,5,5,5,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };


    Ui::MainWindow *ui;
    QGraphicsScene *scene, *menu,*option;//,*login;
    //QGraphicsScene *scene, *scene2;
    //QMainWindow *now;
//    QGraphicsView *news;

    QList<escenario *>plataforma;
    personaje *getPlayer() const;
    personaje *player;
     QTimer * refreshTimer;

    int tecla;
    //int w_limite;
    QTimer *time,*tempo,*timfis;
    int T=10;
    float vxo,vyo,Py,g=9.8;
    float x,y;
    unsigned long long n=0;


};
#endif // MAINWINDOW_H

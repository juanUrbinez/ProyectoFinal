#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QTimer>
#include <math.h>
//#define peso 40

class personaje : public QObject, public QGraphicsPixmapItem
{
public:
    unsigned int Vel_mov=200;
    int sprite=0,monedas=0;
    bool live=true;
    personaje(int x, int y);
    void cambio_imagen(short a);
    //void salto(int width,int heigth);
    //int get_h();
    ~personaje();
    int get_Px();
    int get_Py();
    int get_Vx();
    int get_Vy();
    void posicion(int a,int b);

private:
    int peso=40;
    QPixmap per,cam,img;
    int scaleperx=peso,scalepery=peso;
    //int w,h;
    //int H;
    double angulo, pi=3.1416;
    QTimer *timesalto,*timecaida;
    int v_caida,Px,Py,Pb,Vx,Vy;
    float g=10,t=0.1,vel;
    bool caida,Pbase;

public slots:
    //para que el jugador salte y caiga
    //void fricion();  no
    void salto();
    //void caida_libre();


    //mov parabolico
/*public:
    void pelota(int width, int heigth);
    int get_h();

private:
    int w,h;*/

};

#endif // PERSONAJE_H

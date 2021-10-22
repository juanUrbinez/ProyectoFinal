#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QTimer>
#include <math.h>
#include <QPainter>

//#define peso 40

class personaje : public QObject, public QGraphicsPixmapItem
{
public:
    unsigned int Vel_mov=50;
    int sprite=0,monedas=0;
    bool live=true;
    personaje(int x, int y);
    void cambio_imagen(short a);
   // QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //void salto(int width,int heigth);
    //int get_h();
    ~personaje();
    int get_Px();
    int get_Py();
    int get_Vx();
    int get_Vy();
    void posicion(int a,int b);
    //void MRU(int x,int v);
    void lan_very(int h,int vy);

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
    float Ax,Ay,A;
    bool caida,Pbase;

public slots:
    //para que el jugador salte y caiga
    //void fricion();  no
    void salto();
    void caida_libre();


    //mov parabolico
/*public:
    void pelota(int width, int heigth);
    int get_h();

private:
    int w,h;*/

    //laznzamiento vertical hacia arriba
   /* y=H+v0*t−0.5*g*t*t
    v=v0−g⋅t
    a=−g*/

    //caida libre
   /* y=H−0.5*t*t
    v=−g*t
    a=−g*/
};

#endif // PERSONAJE_H

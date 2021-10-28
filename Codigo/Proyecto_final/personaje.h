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
    ~personaje();
    float get_Px();
    float get_Py();
    float get_Vx();
    float get_Vy();
    //float get_radio();
   // float get_e();
    void posicion(int a,int b);
    //void actualizarmov();
    //void set_vel(float vx, float vy, float px, float py);


private:
    int peso=40;
    QPixmap per,cam,img;
    int scaleperx=peso,scalepery=peso;
    float angulo;

    float Px,Py,Vx,Vy;
    float g=9.81,t=0.1,vel;
    float Ax,Ay;
    float masa,radio,k,e;



};

#endif // PERSONAJE_H

/*

    float getV() const;
    float getAX() const;
    float getAY() const;

    float getMass() const;
    float getR() const;

    float getE() const;


};
*/

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QObject>
#include <QDebug>

class personaje :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje();
    int sprite, monedas;
    bool live=true;
    void cambio_imagen(short a);

    void Mover_A_Derecha(bool flag);
    void Mover_A_Izquierda(bool flag);


    void ActualizarMovimiento();
    void setVx(float valor);
    float getVx();


    void AumentarVelocidadDerecha();
    void AumentarVelocidadIzquierda();
    void Saltar();


    void BajarVelocidadX();
    void setVy(float valor);
    float getVy();
    void AumentarVelocidadenY();


    bool getMoviendo_Derecha();
    bool getMoviendo_Izquierda();



    int getHeight();
    int getWidth();

    bool getVolando();
    bool getSaltando();
    bool getEnElAire();
    bool getRebotando();
    void setRebotando(bool valor);



protected:

    bool Moviendo_Derecha;
    bool Moviendo_Izquierda;
    float Vx;
    float Vy;
    float aceleracionX;
    int maxVx;

    int height;
    int width;

    bool cayendo;
    bool saltando;

    bool EnElAire;
    bool rebotando;



private:
    QPixmap per;



};

#endif 

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QObject>

class personaje :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje();





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



private:
    QPixmap per;



signals:

};

#endif // PERSONAJE_H

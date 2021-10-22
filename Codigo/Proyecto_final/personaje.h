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
    float getVx();
    void AumentarVelocidadDerecha();
    void AumentarVelocidadIzquierda();
    void BajarVelocidadX();
    float getVy();
    void AumentarVelocidadenY();


    bool getMoviendo_Derecha();
    bool getMoviendo_Izquierda();

    bool Moviendo_Derecha;
    bool Moviendo_Izquierda;

protected:

    float Vx;
    float Vy;
    float aceleracionX;
    int maxVx;


private:
    QPixmap per;



signals:

};

#endif // PERSONAJE_H

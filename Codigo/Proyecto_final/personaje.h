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
    void BajarVelocidadX();
    float getVy();
    void AumentarVelocidadenY();


    bool getMoviendo_Derecha();
    bool getMoviendo_Izquierda();

    bool Moviendo_Derecha;
    bool Moviendo_Izquierda;

    int getHeight();
    int getWidth();

protected:

    float Vx;
    float Vy;
    float aceleracionX;
    int maxVx;

    int height;
    int width;



private:
    QPixmap per;



signals:

};

#endif // PERSONAJE_H

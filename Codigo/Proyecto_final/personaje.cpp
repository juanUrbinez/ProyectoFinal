#include "personaje.h"

personaje::personaje()
{
    per.load(":/Personaje/Personaje/Quieto.png");
    setPixmap(per.scaled(40,40));
    Vx=0;
    Vy=0;
    maxVx=10;
    aceleracionX=0.5;
    Moviendo_Derecha=false;
    Moviendo_Izquierda=false;

}

void personaje::Mover_A_Derecha(bool flag)
{
    Moviendo_Derecha=flag;
}

void personaje::Mover_A_Izquierda(bool flag)
{
    Moviendo_Izquierda=flag;

}

float personaje::getVx()
{
    return Vx;
}

void personaje::AumentarVelocidadDerecha()
{
    if(Vx <  maxVx){
        Vx += 1 * aceleracionX;
    }
}

void personaje::AumentarVelocidadIzquierda()
{
    if(Vx > - maxVx){
        Vx -= 1 * aceleracionX;
    }
}

void personaje::BajarVelocidadX()
{
    if(Vx > 0)
        Vx -= 1 * aceleracionX;
    if(Vx < 0)
        Vx += 1 * aceleracionX;
}

float personaje::getVy()
{
    return Vy;
}

bool personaje::getMoviendo_Derecha()
{
    return Moviendo_Derecha;
}

bool personaje::getMoviendo_Izquierda()
{
    return Moviendo_Izquierda;
}

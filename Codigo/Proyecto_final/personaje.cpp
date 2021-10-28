#include "personaje.h"

personaje::personaje()
{
    per.load(":/Personaje/Personaje/Quieto.png");
    setPixmap(per.scaled(40,40));
    this->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    width=40;
    height=40;
    Vx=0;
    Vy=0;
    maxVx=10;
    aceleracionX=0.5;
    Moviendo_Derecha=false;
    Moviendo_Izquierda=false;
    cayendo=false;
    saltando=false;
    EnElAire=false;
    //rebotando=false;
    monedas=0;

}

void personaje::Mover_A_Derecha(bool flag)
{
    Moviendo_Derecha=flag;
}

void personaje::Mover_A_Izquierda(bool flag)
{
    Moviendo_Izquierda=flag;
}

void personaje::ActualizarMovimiento()
{
    if(Vy > 0 )
        cayendo = true;
    else
        cayendo = false;

    if(Vy < 0){
        saltando = true;
    }
    else{
        saltando = false;
    }

    if(Vy == 0)
    {
        EnElAire = false;

    }
    else{
        EnElAire = true;

    }
}

void personaje::setVx(float valor)
{
    Vx=valor;
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

void personaje::Saltar()

{
    if(EnElAire == false)
    {
        Vy = -900;
        ActualizarMovimiento();

    }

}

void personaje::BajarVelocidadX()
{
    if(Vx > 0)
        Vx -= 1 * aceleracionX;
    if(Vx < 0)
        Vx += 1 * aceleracionX;
}

void personaje::setVy(float valor)
{
    Vy=valor;
    ActualizarMovimiento();
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

int personaje::getHeight()
{
    return height;
}

int personaje::getWidth()
{
    return width;
}

bool personaje::getEnElAire()
{
    return EnElAire;
}

bool personaje::getRebotando()
{
    return rebotando;
}

void personaje::setRebotando(bool valor)
{
    rebotando=valor;
}

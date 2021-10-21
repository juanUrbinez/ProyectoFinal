#include "personaje.h"

personaje::personaje()
{
    per.load(":/Personaje/Personaje/Quieto.png");
    setPixmap(per.scaled(40,40));
}

void personaje::Mover_A_Derecha(bool flag)
{
    Moviendo_Derecha=flag;
}

void personaje::Mover_A_Izquierda(bool flag)
{
    Moviendo_Izquierda=flag;
}

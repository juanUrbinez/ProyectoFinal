#include "personaje.h"

personaje::personaje(int x,int y)
{
    per.load(":/personaje/Personaje/Quieto.png");
    setPixmap(per.scaled(scaleperx,scalepery));

    Px=x;
    Py=y;
    Vx=50;
    Vy=0;
    angulo=0;
    vel=0;
    radio=20;
    masa=50;
    k=0.4;
    e=0.2;
    Ax=0;
    Ay=0;

    setPos(Px,Py);
}

void personaje::cambio_imagen(short a)
{
    switch (a)
    {
        case 'd':

            if(sprite==8) sprite=0;
            cam.load(":/personaje/Personaje/corriendo.png");
            img=cam.copy(50*sprite,0,50,55);
            setPixmap(img.scaled(scaleperx,scalepery));

        break;

        case 'a':

            if(sprite==8) sprite=0;
            cam.load(":/personaje/Personaje/corriendoizq.png");
            img=cam.copy(50*sprite,0,50,55);
            setPixmap(img.scaled(scaleperx,scalepery));

        break;

        case 'j':

            cam.load(":/personaje/Personaje/Quieto.png");
            setPixmap(per.scaled(scaleperx,scalepery));

        break;

    }
}


personaje::~personaje()
{

}

float personaje::get_Px()
{
    return Px;
}

float personaje::get_Py()
{
    return Py;
}

float personaje::get_Vx()
{
    return Vx;
}

float personaje::get_Vy()
{
    return Vy;
}

/*float personaje::get_radio()
{
    return radio;
}

float personaje::get_e()
{
    return e;
}*/

void personaje::posicion(int a, int b)
{
    Px=a;
    Py=b;
    Px=Px+Vx*t;
    Py=Py+Vy*t-(0.5*g*t*t);

}

/*void personaje::actualizarmov()
{
    vel = pow(((Vx*Vx)+(Vy*Vy)),(1/2));
    angulo = atan2(Vy,Vx);
    Ax = -((k*(vel*vel)*(radio*radio))/masa)*cos(angulo);
    Ay = (-((k*(vel*vel)*(radio*radio))/masa)*sin(angulo))-g;
    Px = Px + ((Vx*(t)))+(((Ax*(t*t)))/2);
    Py = Py + ((Vy*(t)))+(((Ay*(t*t)))/2);
    Vx = Vx + Ax*t;
    Vy = Vy + Ay*t;
}

void personaje::set_vel(float vx, float vy, float px, float py)
{
    Vx=vx;
    Vy=vy;
    Px=px;
    Py=py;
}*/

#include "personaje.h"

personaje::personaje(int x,int y)
{
    per.load(":/personaje/Personaje/Quieto.png");
    setPixmap(per.scaled(scaleperx,scalepery));

    Px=x;
    Py=y;
    Vx=50;
    Vy=-50;
    v_caida=0;
    angulo=45;
    //vel=50;
    //H=12*40;
    Pbase=true;
    caida=false;

    timesalto=new QTimer;
    timecaida=new QTimer;
    connect(timesalto,SIGNAL(timeout()),this,SLOT(salto()));
    connect(timecaida,SIGNAL(timeout()),this,SLOT(caida_libre()));

    setPos(Px,Py);
    //timesalto->start();
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

/*QRectF personaje::boundingRect() const
{
    return QRectF(0,0,scaleperx,scalepery);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),img,img.rect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}*/

/*void personaje::salto(int width, int heigth)
{
    QPixmap cam(":/personaje/Personaje/Quieto.png");
    h=heigth;
    w=width;
    setPixmap(cam.scaled(w,h));
}*/

/*int personaje::get_h()
{
    return h;
}*/

personaje::~personaje()
{
    //delete timecaida;
    delete timesalto;
}

int personaje::get_Px()
{
    return Px;
}

int personaje::get_Py()
{
    return Py;
}

int personaje::get_Vx()
{
    return Vx;
}

int personaje::get_Vy()
{
    return Vy;
}

void personaje::posicion(int a, int b)
{
    Px=a;
    Py=b;
    Px=Px+Vx*t;
    Py=Py+Vy*t-(0.5*g*t*t);
   //timesalto->start(100);
}

/*void personaje::lan_very(int h, int vy)
{
    Py=h+vy*t-(0.5*g*t*t);
    Vy=vy-g*t;
    A=-g;

    setY(Py);
}*/

/*void personaje::MRU(int x, int v)
{
    Px=x+v*t;//x=x0+v*t
}*/

//void personaje::salto()
//meter un mov retilinep uniforme
//space salta con un angulo inicial
// solo dar una veloci al movimiento
// mov rec univ y caida libre
//determinar el angulo con el que va a saltar y la aceleracion
//{
   // timesalto->start(10);
    /*Vx=vel*cos(angulo);
    Vy=vel*sin(angulo)-g*t;
    angulo=atan2(Vx,Vy);
    //angulo=(atan2(Vx,Vy)*180)/pi;
    //angulo=pow(tan(Vy/Vx),-1);
    vel=sqrt(pow(Vx,2)+pow(Vy,2));
    Px=Px+Vx*t;
    Py=Py+Vy*t+(0.5*g*pow(t,2));*/

    //Px = Px+Vx*cos(45)*t;
    //Py = Py+Vy*sin(45)*t+0.5*(-g)*t*t;


    /*if(Py>14*40){
        timesalto->stop();
        Py=-40*14*40;

    }*/

   // setPos(Px,Py);
    //timesalto->stop();
   /* timesalto->start(18);
    Pbase=false;

    if(Vy>=0) {
        caida=true;
    }
    if(Vy<0) {
        caida=false;
        Pb=523;
    }
    Vy+=g*t;
    Py += Vy*sin(45)*t;
    setY(Py);

    if(Py>=Pb){ // donde queda despues del salto

        timesalto->stop(); // despues de que salte le digo que deje de saltar, sino queda saltando y saltando.
        Py=Pb;
        Pbase=true;
        setY(Py);
        Vy=-50;
    }
}*/

/*void personaje::caida_libre()
{
    timecaida->start(18);*/

    /*Py=Py-(0.5*t*t);
    Vy=-g*t;
    A=-g;

    setY(Py);*/

   /* v_caida+=g*t;
    Pbase=false;
    Py+=v_caida*sin(45)*t;
    setY(Py);

    if(Py>=Pb) // donde queda despues del salto
    {
        timecaida->stop();
        Py=Pb;
        Pbase=true;
        setY(Py);
        v_caida=0;
    }
}*/

//mov parabolico
/*pelota::pelota(int width, int heigth)
{
    QPixmap j(":/Pelota.jpeg");
    h = heigth;
    w = width;
    setPixmap(j.scaled(w,h));
}

int pelota::get_h()
{
    return h;
}*/


/*void Jugador::salto()
{

    timerSalto->start(18);
    EstadoPosicionBase=false;

    if(velY>=0) {
        falling=true;
    }
    if(velY<0) {
        falling=false;
        Pos_Base=523;
    }
    velY+=G*Dt;
    Pos_Y += velY*Dt;
    setY(Pos_Y);

    if(Pos_Y>=Pos_Base){ // donde queda despues del salto

        timerSalto->stop(); // despues de que salte le digo que deje de saltar, sino queda saltando y saltando.
        Pos_Y=Pos_Base;
        EstadoPosicionBase=true;
        setY(Pos_Y);
        velY=-50;
    }
}*/

/*void Jugador::caidaLibre()
{
    timerCaida->start(18);
    velCaida+=G*Dt;
    EstadoPosicionBase=false;
    Pos_Y+=velCaida*Dt;
    setY(Pos_Y);

    if(Pos_Y>=Pos_Base) // donde queda despues del salto
    {
        timerCaida->stop();
        Pos_Y=Pos_Base;
        EstadoPosicionBase=true;
        setY(Pos_Y);
        velCaida=0;
    }

}*/

#include "escenario.h"

escenario::escenario(int x, int y,int a,int b, QString clase, QObject *parent): QObject(parent)
{
    Clase = clase;
    Px = x;
    Py = y;
    Alto = 40;
    Ancho = 40;
    salto = -110;
    scalex=a;
    scaley=b;
    if(Clase=="muro"){
        original.load(":/escenario/escenario/muro1.png");
        img = original.copy(16,0,16,16);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="plataforma"){
        original.load(":/escenario/escenario/muro1.png");
        img = original.copy(16,0,16,16);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="moneda"){
        original.load(":/escenario/Bonos/moneda.png");
        img = original.copy(47,0,47,46);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="orbe"){
        original.load(":/escenario/Bonos/orbes de energia.png");
        img = original.copy(106,0,106,108);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="puerta"){
        original.load(":/escenario/escenario/puerta.png");
        img = original.copy(16,0,16,16);
        setPixmap(img.scaled(scalex,scaley));
    }

    setPos(Px,Py);
}

QString escenario::getClase()
{
    return Clase;
}

/*void escenario::set_scale(int a, int b)
{
    scalex=a;
    scaley=b;
}*/

/*void escenario::CambiarOriginal(QString link)
{
    original.load(link);
}*/

/*void escenario::set_imagen(int a)
{
    img = original.copy(16*a,0,16,16);
    setPixmap(img.scaled(scalex,scaley));
}*/

/*void escenario::set_money(int a)
{
    img = original.copy(47*a,0,47,46);
    setPixmap(img.scaled(scalex,scaley));
}*/

/*void escenario::set_orbe(int a)
{
    img = original.copy(106*a,0,106,108);
    setPixmap(img.scaled(scalex,scaley));
}*/

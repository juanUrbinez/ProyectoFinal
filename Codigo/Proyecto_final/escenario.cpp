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
    else if(Clase=="muro2"){
        original.load(":/escenario/escenario/muro2.png");
        img = original.copy(16,0,16,16);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="plataforma2"){
        original.load(":/escenario/escenario/muro2.png");
        img = original.copy(16,0,16,16);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="muro3"){
        original.load(":/escenario/escenario/muro3.png");
        img = original.copy(16,0,16,16);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="plataforma3"){
        original.load(":/escenario/escenario/muro3.png");
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
    else if(Clase=="item"){
        original.load(":/escenario/Bonos/item.png");
        img = original.copy(184,0,184,146);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="item2"){
        original.load(":/escenario/Bonos/item.png");
        img = original.copy(184,0,184,146);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="torreta"){
        original.load(":/obstaculos/obstaculo/torreta.png");
        img = original.copy(174,0,174,82);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="zonaM"){
        original.load(":/obstaculos/obstaculo/zona de muerte.png");
        img = original.copy(60,0,60,60);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="torreta2"){
        original.load(":/obstaculos/obstaculo/torretader.png");
        img = original.copy(174,0,174,82);
        setPixmap(img.scaled(scalex,scaley));
    }
    else if(Clase=="VacioVenenoso"){
        original.load(":/obstaculos/obstaculo/Vacio.png");
        img = original.copy(80,0,80,80);
        setPixmap(img.scaled(scalex,scaley));
    }

    setPos(Px,Py);
}

QString escenario::getClase()
{
    return Clase;
}

QRectF escenario::boundingRect() const
{
    return QRectF(0,0,scalex,scaley);
}

void escenario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),img,img.rect());
    //UNUSED(option);
    Q_UNUSED(option);
    Q_UNUSED(widget);
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

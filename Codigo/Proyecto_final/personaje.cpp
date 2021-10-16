#include "personaje.h"

personaje::personaje()
{
    per.load(":/personaje/Personaje/Quieto.png");
    setPixmap(per.scaled(scaleperx,scalepery));
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

    }
}

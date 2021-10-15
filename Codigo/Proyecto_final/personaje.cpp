#include "personaje.h"

personaje::personaje()
{
    per.load(":/personaje/Personaje/Quieto.png");
    setPixmap(per.scaled(scaleperx,scalepery));
}

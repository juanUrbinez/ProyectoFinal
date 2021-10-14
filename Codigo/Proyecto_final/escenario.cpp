#include "escenario.h"

escenario::escenario()
{
    //original.load(link);
    //setPixmap(original.scaled(scalex,scaley));
}

void escenario::set_scale(int a, int b)
{
    scalex=a;
    scaley=b;
}

void escenario::CambiarOriginal(QString link)
{
    original.load(link);
}

void escenario::set_imagen(int a)
{
    img = original.copy(16*a,0,16,16);
    setPixmap(img.scaled(scalex,scaley));
}

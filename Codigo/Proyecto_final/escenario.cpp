#include "escenario.h"

escenario::escenario()
{
width=40;
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

int escenario::getWidth()
{
    return width;
}

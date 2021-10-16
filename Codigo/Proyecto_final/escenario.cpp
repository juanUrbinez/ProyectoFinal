#include "escenario.h"

escenario::escenario()
{

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

void escenario::set_money(int a)
{
    img = original.copy(47*a,0,47,46);
    setPixmap(img.scaled(scalex,scaley));
}

void escenario::set_orbe(int a)
{
    img = original.copy(106*a,0,106,108);
    setPixmap(img.scaled(scalex,scaley));
}

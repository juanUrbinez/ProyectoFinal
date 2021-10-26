#include "escenario.h"

escenario::escenario()
{
    QPixmap blocSprite = QPixmap(":/escenario/escenario/muro1.png");
    blocSprite = blocSprite.scaled(40,40);
    setPixmap(blocSprite);
    this->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    //width=40;
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

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
//#define peso 40

class personaje : public QObject, public QGraphicsPixmapItem
{
public:
    personaje();
    void cambio_imagen(short a);
    int peso=40;

private:
    QPixmap per;
    int scaleperx=peso,scalepery=peso;
};

#endif // PERSONAJE_H

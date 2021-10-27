#include "disparo.h"

disparo::disparo(QObject *parent): QObject(parent)
{
    timer = new QTimer();
        filas = 0;
        columnas = 0;

        pixmap = new QPixmap(":/obstaculos/obstaculo/bala.png");

        timer->start(40);
        connect(timer,&QTimer::timeout,this,&disparo::actualizar_disparo);
}

QRectF disparo::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void disparo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void disparo::disparar()
{
    setPos(posx,posy);
    actualizar_disparo();
}

void disparo::actualizar_disparo()
{
    columnas += 68;
        if(columnas >= 544){
            columnas =0;
        }
        this->update(-ancho/2, -alto/2, ancho, alto);
}

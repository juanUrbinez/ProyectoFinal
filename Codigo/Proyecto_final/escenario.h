#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <QPixmap>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

class escenario : public QObject, public QGraphicsPixmapItem
{
public:
    escenario(int x, int y,int a,int b, QString clase, QObject *parent = nullptr);
    QString getClase ();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   // void set_scale(int a, int b);
    //void CambiarOriginal(QString link);
    //void set_imagen(int a);
   // void set_money(int a);
    //void set_orbe(int a);

private:
    QPixmap original,img;
    int scalex=1,scaley=1;
    int Px,Py,Alto,Ancho,salto;
    QString Clase;
};

#endif // ESCENARIO_H

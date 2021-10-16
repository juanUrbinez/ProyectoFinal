#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <QPixmap>
#include <QObject>
#include <QGraphicsPixmapItem>
class escenario : public QObject, public QGraphicsPixmapItem
{
public:
    escenario();
    void set_scale(int a, int b);
    void CambiarOriginal(QString link);
    void set_imagen(int a);
    void set_money(int a);
    void set_orbe(int a);

private:
    QPixmap original,img;
    int scalex=1,scaley=1;

};

#endif // ESCENARIO_H

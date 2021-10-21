#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QObject>

class personaje :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje();
    void Mover_A_Derecha(bool flag);
    void Mover_A_Izquierda(bool flag);

protected:
    bool Moviendo_Derecha;
    bool Moviendo_Izquierda;

private:
    QPixmap per;



signals:

};

#endif // PERSONAJE_H

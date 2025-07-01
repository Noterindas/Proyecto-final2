#ifndef ABEJAG_H
#define ABEJAG_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "mapa.h"

class Abejag {
public:
    Abejag(Mapa* mapa, int centroX, int centroY, int radio);
    ~Abejag();

    void animar();
    void mover();
    QGraphicsPixmapItem* obtenerItem();

private:
    QPixmap* sprite;
    QGraphicsPixmapItem* item;
    Mapa* mapa;
    int x, y;
    int ancho, alto;
    int centroX, centroY;
    int radio;
    qreal angulo;
    qreal velocidadAngular;
};

#endif


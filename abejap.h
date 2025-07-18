#ifndef ABEJAP_H
#define ABEJAP_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "mapa.h"

class Abejap {
public:
    Abejap(Mapa* mapa, int xInicial, int yInicial);
    ~Abejap();

    void animar();
    void mover();
    QGraphicsPixmapItem* obtenerItem();

private:
    QPixmap* sprite;
    QPixmap* spriteArriba;
    QPixmap* spriteActual;
    QGraphicsPixmapItem* item;
    Mapa* mapa;
    int x, y;
    int ancho, alto;
    int posX, posY;
    int direccion;
    int velocidad;
};

#endif


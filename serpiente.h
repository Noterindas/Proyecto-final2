#ifndef SERPIENTE_H
#define SERPIENTE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "mapa.h"

class Serpiente {
public:
    Serpiente(Mapa* mapa, int xInicial, int yInicial);
    ~Serpiente();

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

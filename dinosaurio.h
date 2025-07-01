#ifndef DINOSAURIO_H
#define DINOSAURIO_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "mapa.h"

class Dinosaurio {
public:
    Dinosaurio(Mapa* mapa, int xInicial, int yInicial);
    ~Dinosaurio();

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


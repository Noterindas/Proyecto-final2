#ifndef COCODRILO_H
#define COCODRILO_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "mapa.h"

class Cocodrilo {
public:
    Cocodrilo(Mapa* mapa, int xInicial, int yInicial);
    ~Cocodrilo();

    void animar();
    void mover();
    QGraphicsPixmapItem* obtenerItem();

private:
    QPixmap* sprite;
    QPixmap* spriteIzquierdo;
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

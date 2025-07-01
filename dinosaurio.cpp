#include "dinosaurio.h"

Dinosaurio::Dinosaurio(Mapa* mapa, int xInicial, int yInicial) : mapa(mapa)
{
    x = 0;
    y = 0;
    posX = xInicial;
    posY = yInicial;
    ancho = 100;
    alto = 100;
    direccion = 1;
    velocidad = 10;

    sprite = new QPixmap(":/imagenes/dinosaurio.png");
    spriteArriba = new QPixmap(":/imagenes/dinosaurioArriba.png");
    spriteActual = sprite;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, ancho, alto).scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    item->setPos(posX, posY);
}

void Dinosaurio::animar()
{
    x += ancho;
    if (x >= sprite->width()) {
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Dinosaurio::mover()
{
    posY += direccion * velocidad;
    item->setPos(posX, posY);

    for (QGraphicsItem* pared : mapa->obtenerParedes()) {
        if (item->collidesWithItem(pared)) {

            direccion *= -1;
            posY += direccion * velocidad;
            item->setPos(posX, posY);

            if (direccion == -1)
                spriteActual = spriteArriba;
            else
                spriteActual = sprite;

            break;
        }
    }
}

QGraphicsPixmapItem* Dinosaurio::obtenerItem()
{
    return item;
}

Dinosaurio::~Dinosaurio()
{
    delete sprite;
    delete spriteArriba;
    delete item;
}

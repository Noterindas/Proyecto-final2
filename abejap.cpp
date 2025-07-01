#include "abejap.h"

Abejap::Abejap(Mapa* mapa, int xInicial, int yInicial) : mapa(mapa)
{
    x = 0;
    y = 0;
    posX = xInicial;
    posY = yInicial;
    ancho = 100;
    alto = 100;
    direccion = 1;
    velocidad = 10;

    sprite = new QPixmap(":/imagenes/abeja.png");
    spriteArriba = new QPixmap(":/imagenes/abejaArriba.png");
    spriteActual = sprite;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, ancho, alto).scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    item->setPos(posX, posY);
}

void Abejap::animar()
{
    x += ancho;
    if (x >= sprite->width()) {
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Abejap::mover()
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

QGraphicsPixmapItem* Abejap::obtenerItem()
{
    return item;
}

Abejap::~Abejap()
{
    delete sprite;
    delete spriteArriba;
    delete item;
}

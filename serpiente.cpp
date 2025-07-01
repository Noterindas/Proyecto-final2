#include "serpiente.h"

Serpiente::Serpiente(Mapa* mapa, int xInicial, int yInicial) : mapa(mapa)
{
    x = 0;
    y = 0;
    posX = xInicial;
    posY = yInicial;
    ancho = 100;
    alto = 100;
    direccion = 1;
    velocidad = 10;

    sprite = new QPixmap(":/imagenes/serpiente.png");
    spriteArriba = new QPixmap(":/imagenes/serpienteArriba.png");
    spriteActual = sprite;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, ancho, alto).scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    item->setPos(posX, posY);
}

void Serpiente::animar()
{
    x += ancho;
    if (x >= sprite->width()) {
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Serpiente::mover()
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

QGraphicsPixmapItem* Serpiente::obtenerItem()
{
    return item;
}

Serpiente::~Serpiente()
{
    delete sprite;
    delete spriteArriba;
    delete item;
}

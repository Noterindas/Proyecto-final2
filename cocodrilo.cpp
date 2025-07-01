#include "cocodrilo.h"
#include "mapa.h"

Cocodrilo::Cocodrilo(Mapa* mapa, int xInicial, int yInicial) : mapa(mapa)
{
    x = 0;
    y = 0;
    posX = xInicial;
    posY = yInicial;
    ancho = 100;
    alto = 100;
    direccion = 1;
    velocidad = 10;

    sprite = new QPixmap(":/imagenes/cocodrilo.png");
    spriteIzquierdo = new QPixmap(":/imagenes/cocodriloIzquierdo.png");
    spriteActual = sprite;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    item->setPos(posX, posY);
}

void Cocodrilo::animar()
{
    x += ancho;
    if (x >= sprite->width()) {
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Cocodrilo::mover()
{
    posX += direccion * velocidad;
    item->setPos(posX, posY);

    for (QGraphicsItem* pared : mapa->obtenerParedes()) {
        if (item->collidesWithItem(pared)) {

            direccion *= -1;
            posX += direccion * velocidad;
            item->setPos(posX, posY);

            if (direccion == -1)
                spriteActual = spriteIzquierdo;
            else
                spriteActual = sprite;

            break;
        }
    }
}

QGraphicsPixmapItem* Cocodrilo::obtenerItem()
{
    return item;
}

Cocodrilo::~Cocodrilo()
{
    delete sprite;
    delete spriteIzquierdo;
    delete item;
}

#include "goku.h"

Goku::Goku()
{
    x=0;
    y=0;
    posX=1640;
    posY=380;
    posicionInicial = QPointF(posX, posY);

    ancho = 100;
    alto = 100;

    spriteDerecha = new QPixmap(":/imagenes/GokuCorreDerecho.png");

    spriteIzquierda = new QPixmap(":/imagenes/GokuCorreDerechoV.png");

    spriteArriba = new QPixmap(":/imagenes/GCAR.png");

    spriteAbajo = new QPixmap(":/imagenes/GCA.png");

    spriteQuieto = new QPixmap(":/imagenes/GP2.png");

    spritePuno = new QPixmap(":/imagenes/GSalto.png");

    spriteActual = spriteQuieto;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    item->setPos(posX, posY);

}

void Goku::moverDerecha()
{
    if (spriteActual != spriteDerecha) {
        spriteActual = spriteDerecha;
        x = 0;
    }
}


void Goku::moverIzquierda()
{
    if (spriteActual != spriteIzquierda) {
        spriteActual = spriteIzquierda;
        x = 0;
    }
}


void Goku::moverArriba()
{
    if (spriteActual != spriteArriba) {
        spriteActual = spriteArriba;
        x = 0;
    }
}

void Goku::moverAbajo()
{
    if (spriteActual != spriteAbajo) {
        spriteActual = spriteAbajo;
        x = 0;
    }
}

void Goku::animar()
{
    x += ancho;
    if (x >= spriteActual->width()) {
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


void Goku::detener()
{
    if (spriteActual != spriteQuieto) {
        spriteActual = spriteQuieto;
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Goku::puno()
{
    if (spriteActual != spritePuno) {
        spriteActual = spritePuno;
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Goku::reiniciarPosicion()
{
    item->setPos(posicionInicial);
}

QGraphicsPixmapItem* Goku::obtenerItem()
{
    return item;
}

Goku::~Goku()
{
    delete spriteDerecha;
    delete spriteIzquierda;
    delete spriteArriba;
    delete spriteAbajo;
    delete spriteQuieto;
    delete item;
}

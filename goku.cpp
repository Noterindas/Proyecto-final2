#include "goku.h"

Goku::Goku()
{
    x=0;
    y=0;
    posX=1640;
    posY=380;
    posicionInicial = QPointF(posX, posY);

    spriteDerecha = new QPixmap(":/imagenes/GokuCorreDerecho.png");
    anchoDerecha = 100;
    altoDerecha = 100;

    spriteIzquierda = new QPixmap(":/imagenes/GCD.png");
    anchoIzquierda = 100;
    altoIzquierda = 100;

    spriteArriba = new QPixmap(":/imagenes/GCAR.png");
    anchoArriba = 100;
    altoArriba = 100;

    spriteAbajo = new QPixmap(":/imagenes/GCA.png");
    anchoAbajo = 100;
    altoAbajo = 100;

    spriteQuieto = new QPixmap(":/imagenes/GP2.png");
    anchoQuieto = 100;
    altoQuieto = 100;

    spriteActual = spriteQuieto;
    anchoActual = anchoQuieto;
    altoActual = altoQuieto;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, anchoActual, altoActual).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    item->setPos(posX, posY);
}

void Goku::moverDerecha()
{
    if (spriteActual != spriteDerecha) {
        spriteActual = spriteDerecha;
        anchoActual = anchoDerecha;
        altoActual = altoDerecha;
        x = 0;
    }
}


void Goku::moverIzquierda()
{
    if (spriteActual != spriteIzquierda) {
        spriteActual = spriteIzquierda;
        anchoActual = anchoIzquierda;
        altoActual = altoIzquierda;
        x = 0;
    }
}


void Goku::moverArriba()
{
    if (spriteActual != spriteArriba) {
        spriteActual = spriteArriba;
        anchoActual = anchoArriba;
        altoActual = altoArriba;
        x = 0;
    }
}

void Goku::moverAbajo()
{
    if (spriteActual != spriteAbajo) {
        spriteActual = spriteAbajo;
        anchoActual = anchoAbajo;
        altoActual = altoAbajo;
        x = 0;
    }
}

void Goku::animar()
{
    x += anchoActual;
    if (x >= spriteActual->width()) {
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, anchoActual, altoActual).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Goku::detener()
{
    if (spriteActual != spriteQuieto) {
        spriteActual = spriteQuieto;
        anchoActual = anchoQuieto;
        altoActual = altoQuieto;
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, anchoActual, altoActual).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
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

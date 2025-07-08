#include "nam.h"

Nam::Nam()
{
    x = 0;
    y = 0;
    posX = 1580;
    posY = 380;
    posicionInicial = QPointF(posX, posY);

    ancho = 100;
    alto = 100;

    spriteDerecha = new QPixmap(":/imagenes/NCD.png");
    spriteIzquierda = new QPixmap(":/imagenes/NCDIzq.png");
    spriteQuieto = new QPixmap(":/imagenes/NP.png");

    spritePuno = new QPixmap(":/imagenes/NPu.png");
    spritePunoIzq = new QPixmap(":/imagenes/NPuIzq.png");

    spriteSalto = new QPixmap(":/imagenes/NSalto.png");
    spriteSaltoIzq = new QPixmap(":/imagenes/NSaltoIzq.png");

    spritePatada = new QPixmap(":/imagenes/NPa.png");
    spritePatadaIzq = new QPixmap(":/imagenes/NPaIzq.png");

    spriteSPa = new QPixmap(":/imagenes/NSPa.png");
    spriteSPaIzq = new QPixmap(":/imagenes/NSPaIzq.png");

    spriteSPu = new QPixmap(":/imagenes/NSPu.png");
    spriteSPuIzq = new QPixmap(":/imagenes/NSPuIzq.png");

    spriteActual = spriteQuieto;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    item->setPos(posX, posY);

    mirandoDerecha = true;
}

void Nam::moverDerecha()
{
    mirandoDerecha = true;
    if (spriteActual != spriteDerecha) {
        spriteActual = spriteDerecha;
        x = 0;
    }
}

void Nam::moverIzquierda()
{
    mirandoDerecha = false;
    if (spriteActual != spriteIzquierda) {
        spriteActual = spriteIzquierda;
        x = 0;
    }
}

void Nam::puno()
{
    spriteActual = spritePuno;
    x = 0;
}

void Nam::punoIzq()
{
    spriteActual = spritePunoIzq;
    x = 0;
}

void Nam::salto()
{
    spriteActual = spriteSalto;
    x = 0;
}

void Nam::saltoIzq()
{
    spriteActual = spriteSaltoIzq;
    x = 0;
}

void Nam::patada()
{
    spriteActual = spritePatada;
    x = 0;
}

void Nam::patadaIzq()
{
    spriteActual = spritePatadaIzq;
    x = 0;
}

void Nam::SPu()
{
    spriteActual = spriteSPu;
    x = 0;
}

void Nam::SPuIzq()
{
    spriteActual = spriteSPuIzq;
    x = 0;
}

void Nam::SPa()
{
    spriteActual = spriteSPa;
    x = 0;
}

void Nam::SPaIzq()
{
    spriteActual = spriteSPaIzq;
    x = 0;
}

void Nam::detener()
{
    spriteActual = spriteQuieto;
    x = 0;
    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Nam::animar()
{
    x += ancho;
    if (x >= spriteActual->width()) {
        x = 0;
    }
    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Nam::reiniciarPosicion()
{
    item->setPos(posicionInicial);
}

QGraphicsPixmapItem* Nam::obtenerItem()
{
    return item;
}

Nam::~Nam()
{
    delete spriteDerecha;
    delete spriteIzquierda;
    delete spriteQuieto;
    delete spritePuno;
    delete spritePunoIzq;
    delete spriteSalto;
    delete spriteSaltoIzq;
    delete spritePatada;
    delete spritePatadaIzq;
    delete spriteSPa;
    delete spriteSPaIzq;
    delete spriteSPu;
    delete spriteSPuIzq;
    delete item;
}

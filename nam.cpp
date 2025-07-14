#include "nam.h"

Nam::Nam(int anchoVisual, int altoVisual)
    : anchoVisual(anchoVisual), altoVisual(altoVisual)
{
    x = 0;
    y = 0;
    posX = 1580;
    posY = 380;
    posicionInicial = QPointF(posX, posY);
    vida = 100;

    ancho = 100;
    alto = 100;

    spriteDerecha = new QPixmap(":/imagenes/NCD.png");
    spriteIzquierda = new QPixmap(":/imagenes/NCDIzq.png");
    spriteQuieto = new QPixmap(":/imagenes/NP.png");

    spritePuno = new QPixmap(":/imagenes/NPu.png");
    spritePunoIzq = new QPixmap(":/imagenes/NPuIzq.png");

    spritePatada = new QPixmap(":/imagenes/NPa.png");
    spritePatadaIzq = new QPixmap(":/imagenes/NPaIzq.png");

    spriteSPa = new QPixmap(":/imagenes/NSPa.png");
    spriteSPaIzq = new QPixmap(":/imagenes/NSPaIzq.png");

    spriteSPu = new QPixmap(":/imagenes/NSPu.png");
    spriteSPuIzq = new QPixmap(":/imagenes/NSPuIzq.png");

    spriteGolpe = new QPixmap(":/imagenes/NG.png");

    spriteActual = spriteQuieto;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, ancho, alto).scaled(anchoVisual, altoVisual, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    item->setPos(posX, posY);

    mirandoDerecha = true;
    estaSiendoEmpujado = false;
    contadorEmpuje = 0;
    direccionEmpuje = 0;
    estaAtacando = false;
    contadorAtaque = 0;
    golpeAplicado = false;
}

void Nam::moverDerecha()
{
    if (estaAtacando) return;
    mirandoDerecha = true;
    if (spriteActual != spriteDerecha) {
        spriteActual = spriteDerecha;
        x = 0;
    }
}

void Nam::moverIzquierda()
{
    if (estaAtacando) return;
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
    estaAtacando = true;
    contadorAtaque = 6;
}

void Nam::punoIzq()
{
    spriteActual = spritePunoIzq;
    x = 0;
    estaAtacando = true;
    contadorAtaque = 6;
}

void Nam::patada()
{
    spriteActual = spritePatada;
    x = 0;
    estaAtacando = true;
    contadorAtaque = 6;
}

void Nam::patadaIzq()
{
    spriteActual = spritePatadaIzq;
    x = 0;
    estaAtacando = true;
    contadorAtaque = 6;
}

void Nam::SPu()
{
    spriteActual = spriteSPu;
    x = 0;
    estaAtacando = true;
    contadorAtaque = 6;
}

void Nam::SPuIzq()
{
    spriteActual = spriteSPuIzq;
    x = 0;
    estaAtacando = true;
    contadorAtaque = 6;
}

void Nam::SPa()
{
    spriteActual = spriteSPa;
    x = 0;
    estaAtacando = true;
    contadorAtaque = 6;
}

void Nam::SPaIzq()
{
    spriteActual = spriteSPaIzq;
    x = 0;
    estaAtacando = true;
    contadorAtaque = 6;
}

void Nam::detener()
{
    spriteActual = spriteQuieto;
    x = 0;
    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(anchoVisual, altoVisual, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Nam::animar()
{
    if (estaSiendoEmpujado) {
        QPointF posActual = item->pos();

        qreal nuevoX = posActual.x() + direccionEmpuje;

        nuevoX = qBound(0.0, nuevoX, 1710.0 - item->boundingRect().width());

        item->setPos(nuevoX, posActual.y());

        contadorEmpuje--;

        item->setPixmap(spriteGolpe->copy(x, y, ancho, alto).scaled(anchoVisual, altoVisual, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        if (contadorEmpuje <= 0) {
            estaSiendoEmpujado = false;
            direccionEmpuje = 0;
            spriteActual = spriteQuieto;
        }

        return;
    }

    if (estaAtacando) {
        contadorAtaque--;
        if (contadorAtaque <= 0) {
            estaAtacando = false;
            spriteActual = spriteQuieto;
            x = 0;
            golpeAplicado = false;
        }
    }

    x += ancho;
    if (x >= spriteActual->width()) {
        x = 0;
    }
    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(anchoVisual, altoVisual, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Nam::reducirVida(int cantidad) {
    vida -= cantidad;
    if (vida < 0) vida = 0;
}

int Nam::obtenerVida() const {
    return vida;
}

void Nam::reiniciarVida() {
    vida = 100;
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
    delete spritePatada;
    delete spritePatadaIzq;
    delete spriteSPa;
    delete spriteSPaIzq;
    delete spriteSPu;
    delete spriteSPuIzq;
    delete item;
}

#include "goku.h"

Goku::Goku(int anchoVisual, int altoVisual)
    : anchoVisual(anchoVisual), altoVisual(altoVisual)
{
    x=0;
    y=0;
    posX=1640;
    posY=380;
    posicionInicial = QPointF(posX, posY);
    vida = 100;

    ancho = 100;
    alto = 100;

    spriteDerecha = new QPixmap(":/imagenes/GokuCorreDerecho.png");

    spriteIzquierda = new QPixmap(":/imagenes/GokuCorreDerechoV.png");

    spriteArriba = new QPixmap(":/imagenes/GCAR.png");

    spriteAbajo = new QPixmap(":/imagenes/GCA.png");

    spriteQuieto = new QPixmap(":/imagenes/GP2.png");

    spritePuno = new QPixmap(":/imagenes/GPuno.png");

    spritePunoIzq = new QPixmap(":/imagenes/GPunoIzq.png");

    spriteSalto = new QPixmap(":/imagenes/GSalto.png");

    spriteSaltoIzq = new QPixmap(":/imagenes/GSaltoIzq.png");

    spritePatada = new QPixmap(":/imagenes/GPa.png");

    spritePatadaIzq = new QPixmap(":/imagenes/GPaIzq.png");

    spriteSPa = new QPixmap(":/imagenes/GSPa.png");

    spriteSPaIzq = new QPixmap(":/imagenes/GSPaIzq.png");

    spriteSPu= new QPixmap(":/imagenes/GSPu.png");

    spriteSPuIzq= new QPixmap(":/imagenes/GSPuIzq.png");

    spriteGolpe= new QPixmap(":/imagenes/GG.png");

    spriteActual = spriteQuieto;

    item = new QGraphicsPixmapItem(spriteActual->copy(x, y, ancho, alto).scaled(anchoVisual, altoVisual, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    item->setPos(posX, posY);

    mirandoDerecha = true;
    estaSiendoEmpujado = false;
    contadorEmpuje = 0;
    direccionEmpuje = 0;

}

void Goku::moverDerecha()
{
    mirandoDerecha = true;
    if (spriteActual != spriteDerecha) {
        spriteActual = spriteDerecha;
        x = 0;
    }
}


void Goku::moverIzquierda()
{
    mirandoDerecha = false;
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

void Goku::puno()
{
    if (spriteActual != spritePuno) {
        spriteActual = spritePuno;
        x = 0;
    }
}

void Goku::punoIzq()
{
    if (spriteActual != spritePunoIzq) {
        spriteActual = spritePunoIzq;
        x = 0;
    }
}

void Goku::salto()
{
    if (spriteActual != spriteSalto) {
        spriteActual = spriteSalto;
        x = 0;
    }
}

void Goku::saltoIzq()
{
    if (spriteActual != spriteSaltoIzq) {
        spriteActual = spriteSaltoIzq;
        x = 0;
    }
}

void Goku::patada()
{
    if (spriteActual != spritePatada) {
        spriteActual = spritePatada;
        x = 0;
    }
}

void Goku::patadaIzq()
{
    if (spriteActual != spritePatadaIzq) {
        spriteActual = spritePatadaIzq;
        x = 0;
    }
}

void Goku::SPu()
{
    if (spriteActual != spriteSPu) {
        spriteActual = spriteSPu;
        x = 0;
    }
}

void Goku::SPuIzq()
{
    if (spriteActual != spriteSPuIzq) {
        spriteActual = spriteSPuIzq;
        x = 0;
    }
}

void Goku::SPa()
{
    if (spriteActual != spriteSPa) {
        spriteActual = spriteSPa;
        x = 0;
    }
}

void Goku::SPaIzq()
{
    if (spriteActual != spriteSPaIzq) {
        spriteActual = spriteSPaIzq;
        x = 0;
    }
}

void Goku::animar()
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

    x += ancho;
    if (x >= spriteActual->width()) {
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(anchoVisual, altoVisual, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


void Goku::detener()
{
    if (spriteActual != spriteQuieto) {
        spriteActual = spriteQuieto;
        x = 0;
    }

    item->setPixmap(spriteActual->copy(x, y, ancho, alto).scaled(anchoVisual, altoVisual, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Goku::reducirVida(int cantidad) {
    vida -= cantidad;
    if (vida < 0) vida = 0;
}

int Goku::obtenerVida() const {
    return vida;
}

void Goku::reiniciarVida() {
    vida = 100;
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

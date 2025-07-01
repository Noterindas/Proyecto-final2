#include "abejag.h"

Abejag::Abejag(Mapa* mapa,int centroX, int centroY, int radio)
    : mapa(mapa), centroX(centroX), centroY(centroY), radio(radio)
{
    x = 0;
    y = 0;
    ancho = 100;
    alto = 100;
    angulo = 0;
    velocidadAngular = 0.22;

    sprite = new QPixmap(":/imagenes/abejaCircular.png");

    item = new QGraphicsPixmapItem(sprite->copy(x, y, ancho, alto).scaled(78, 78, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    item->setPos(centroX + radio * qCos(angulo), centroY + radio * qSin(angulo));
}

void Abejag::animar()
{
    x += ancho;
    if (x >= sprite->width()) {
        x = 0;
    }

    item->setPixmap(sprite->copy(x, y, ancho, alto).scaled(78, 78, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Abejag::mover()
{
    angulo += velocidadAngular;
    qreal nuevoX = centroX + radio * qCos(angulo);
    qreal nuevoY = centroY + radio * qSin(angulo);
    item->setPos(nuevoX, nuevoY);
}

QGraphicsPixmapItem* Abejag::obtenerItem()
{
    return item;
}

Abejag::~Abejag()
{
    delete sprite;
    delete item;
}

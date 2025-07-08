#ifndef GOKU_H
#define GOKU_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Goku {
public:
    Goku();
    ~Goku();

    void animar();
    void moverDerecha();
    void moverIzquierda();
    void moverArriba();
    void moverAbajo();
    void puno();
    void salto();
    void patada();
    void SPa();
    void SPu();
    void detener();
    void reiniciarPosicion();
    QGraphicsPixmapItem* obtenerItem();

private:
    QPixmap* spriteDerecha;
    QPixmap* spriteIzquierda;
    QPixmap* spriteArriba;
    QPixmap* spriteAbajo;
    QPixmap* spriteActual;
    QPixmap* spriteQuieto;
    QPixmap* spritePuno;
    QPixmap* spriteSalto;
    QPixmap* spritePatada;
    QPixmap* spriteSPa;
    QPixmap* spriteSPu;
    QPointF posicionInicial;
    QGraphicsPixmapItem* item;
    int ancho, alto;
    int x, y;
    int posX, posY;

};

#endif

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
    QPointF posicionInicial;
    int anchoQuieto, altoQuieto;
    int anchoDerecha, altoDerecha;
    int anchoIzquierda, altoIzquierda;
    int anchoArriba, altoArriba;
    int anchoAbajo, altoAbajo;
    int anchoActual, altoActual;
    QGraphicsPixmapItem* item;
    int x, y;
    int posX, posY;
};

#endif

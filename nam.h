#ifndef NAM_H
#define NAM_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Nam {
public:
    Nam();
    ~Nam();

    void animar();
    void moverDerecha();
    void moverIzquierda();
    void puno();
    void punoIzq();
    void salto();
    void saltoIzq();
    void patada();
    void patadaIzq();
    void SPa();
    void SPaIzq();
    void SPu();
    void SPuIzq();
    void detener();
    void reiniciarPosicion();
    QGraphicsPixmapItem* obtenerItem();
    bool mirandoDerecha;

private:
    QPixmap* spriteDerecha;
    QPixmap* spriteIzquierda;
    QPixmap* spriteActual;
    QPixmap* spriteQuieto;
    QPixmap* spritePuno;
    QPixmap* spritePunoIzq;
    QPixmap* spriteSalto;
    QPixmap* spriteSaltoIzq;
    QPixmap* spritePatada;
    QPixmap* spritePatadaIzq;
    QPixmap* spriteSPa;
    QPixmap* spriteSPaIzq;
    QPixmap* spriteSPu;
    QPixmap* spriteSPuIzq;
    QPointF posicionInicial;
    QGraphicsPixmapItem* item;
    int ancho, alto;
    int x, y;
    int posX, posY;
};

#endif

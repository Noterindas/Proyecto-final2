#ifndef GOKU_H
#define GOKU_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Goku {
public:
    Goku(int anchoVisual = 50, int altoVisual = 50);
    ~Goku();

    void animar();
    void moverDerecha();
    void moverIzquierda();
    void moverArriba();
    void moverAbajo();
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
    void saltar();
    void detener();
    void reiniciarPosicion();
    QGraphicsPixmapItem* obtenerItem();
    bool mirandoDerecha;
    void reducirVida(int cantidad);
    int obtenerVida() const;
    void reiniciarVida();
    bool estaSiendoEmpujado;
    int contadorEmpuje;
    int direccionEmpuje;

private:
    QPixmap* spriteDerecha;
    QPixmap* spriteIzquierda;
    QPixmap* spriteArriba;
    QPixmap* spriteAbajo;
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
    QPixmap* spriteGolpe;
    QPointF posicionInicial;
    QGraphicsPixmapItem* item;
    int ancho, alto;
    int x, y;
    int posX, posY;
    int vida;
    int anchoVisual;
    int altoVisual;

};

#endif

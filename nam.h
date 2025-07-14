#ifndef NAM_H
#define NAM_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Nam {
public:
    Nam(int anchoVisual, int altoVisual);
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
    void reducirVida(int cantidad);
    int obtenerVida() const;
    void reiniciarVida();
    bool estaSiendoEmpujado;
    int contadorEmpuje;
    int direccionEmpuje;
    bool estaAtacando;
    int contadorAtaque;
    bool golpeAplicado;

private:
    QPixmap* spriteDerecha;
    QPixmap* spriteIzquierda;
    QPixmap* spriteActual;
    QPixmap* spriteQuieto;
    QPixmap* spritePuno;
    QPixmap* spritePunoIzq;
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

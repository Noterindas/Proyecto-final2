#ifndef NIVEL2_H
#define NIVEL2_H

#include <QGraphicsScene>
#include <QTimer>
#include "Goku.h"
#include "Nam.h"

class Nivel2 {
public:
    Nivel2();
    ~Nivel2();

    QGraphicsScene* obtenerEscena();
    void iniciarNivel(Goku* goku);
    void moverNam();

private:
    QGraphicsScene* escena;
    Goku* goku;
    Nam* nam;
    QTimer* timerNam;
};

#endif // NIVEL2_H

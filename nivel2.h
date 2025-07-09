#ifndef NIVEL2_H
#define NIVEL2_H

#include <QGraphicsScene>
#include <QTimer>
#include "Goku.h"
#include "Nam.h"
#include <QProgressBar>

class Nivel2 {
public:
    Nivel2();
    ~Nivel2();

    QGraphicsScene* obtenerEscena();
    void iniciarNivel(Goku* goku, QProgressBar* barraGoku, QProgressBar* barraNam);
    void moverNam();

private:
    QGraphicsScene* escena;
    Goku* goku;
    Nam* nam;
    QTimer* timerNam;
    QProgressBar* barraVidaGoku;
    QProgressBar* barraVidaNam;
};

#endif // NIVEL2_H

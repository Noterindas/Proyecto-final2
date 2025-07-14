#ifndef NIVEL2_H
#define NIVEL2_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "Goku.h"
#include "Nam.h"
#include <QProgressBar>

class Nivel2 : public QObject
{
    Q_OBJECT

public:
    Nivel2();
    ~Nivel2();

    QGraphicsScene* obtenerEscena();
    void iniciarNivel();
    void moverNam();
    Nam* obtenerNam();
    Goku* obtenerGoku();
    QProgressBar* obtenerBarraVidaGoku();
    QProgressBar* obtenerBarraVidaNam();

private:
    QGraphicsScene* escena;
    Goku* goku;
    Nam* nam;
    QTimer* timerNam;
    QProgressBar* barraVidaGoku;
    QProgressBar* barraVidaNam;
};

#endif // NIVEL2_H

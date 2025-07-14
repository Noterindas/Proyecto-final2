#include "Nivel2.h"
#include <QPixmap>
#include <QRandomGenerator>

Nivel2::Nivel2() {
    escena = new QGraphicsScene();
}

void Nivel2::iniciarNivel()
{
    escena = new QGraphicsScene();
    escena->setSceneRect(0, 0, 1710, 810);

    QPixmap fondo(":/imagenes/arena.gif");
    QPixmap fondoEscalado = fondo.scaled(1710, 810, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    escena->setBackgroundBrush(fondoEscalado);

    goku = new Goku(200, 200);
    goku->obtenerItem()->setPos(100, 600);
    escena->addItem(goku->obtenerItem());

    nam = new Nam(200, 200);
    nam->obtenerItem()->setPos(1200, 600);
    escena->addItem(nam->obtenerItem());

    barraVidaGoku = new QProgressBar();
    barraVidaGoku->setRange(0, 100);
    barraVidaGoku->setValue(100);

    barraVidaNam = new QProgressBar();
    barraVidaNam->setRange(0, 100);
    barraVidaNam->setValue(100);

    timerNam = new QTimer(this);
    connect(timerNam, &QTimer::timeout, this, &Nivel2::moverNam);
    timerNam->start(100);
}

QGraphicsScene* Nivel2::obtenerEscena() {
    return escena;
}

void Nivel2::moverNam() {
    QPointF posNam = nam->obtenerItem()->pos();
    QPointF posGoku = goku->obtenerItem()->pos();

    qreal distancia = QLineF(posNam, posGoku).length();

    if (distancia < 110) {
        int accion = QRandomGenerator::global()->bounded(5);
        if (accion == 0) {
            if (nam->mirandoDerecha)
                nam->puno();
            else
                nam->punoIzq();
        } else if (accion == 1) {
            if (nam->mirandoDerecha)
                nam->patada();
            else
                nam->patadaIzq();
        } else if (accion == 2) {
            if (nam->mirandoDerecha)
                nam->SPa();
            else
                nam->SPaIzq();
        } else if (accion == 3) {
            if (nam->mirandoDerecha)
                nam->SPu();
            else
                nam->SPuIzq();
        }

        if (nam->obtenerItem()->collidesWithItem(goku->obtenerItem()) && nam->golpeAplicado==false) {
            goku->reducirVida(10);
            barraVidaGoku->setValue(goku->obtenerVida());

            goku->estaSiendoEmpujado = true;
            goku->contadorEmpuje = 10;
            goku->direccionEmpuje = nam->mirandoDerecha ? 18 : -18;

            nam->golpeAplicado = true;
        }
    }

    qreal dx = 0;
    if (distancia > 90) {
        if (posGoku.x() > posNam.x()) {
            dx = 6;
            nam->moverDerecha();
        } else if (posGoku.x() < posNam.x()) {
            dx = -6;
            nam->moverIzquierda();
        }
    }

    QPointF nuevaPos = posNam + QPointF(dx, 0);
    QRectF limites = escena->sceneRect();
    qreal nuevoX = qBound(limites.left(), nuevaPos.x(), limites.right() - nam->obtenerItem()->boundingRect().width());
    qreal nuevoY = qBound(limites.top(), nuevaPos.y(), limites.bottom() - nam->obtenerItem()->boundingRect().height());
    nam->obtenerItem()->setPos(nuevoX, nuevoY);

    nam->animar();
}

Goku* Nivel2::obtenerGoku() {
    return goku;
}

Nam* Nivel2::obtenerNam() {
    return nam;
}

QProgressBar* Nivel2::obtenerBarraVidaGoku() {
    return barraVidaGoku;
}

QProgressBar* Nivel2::obtenerBarraVidaNam() {
    return barraVidaNam;
}


Nivel2::~Nivel2() {
    delete escena;
    delete nam;
    delete timerNam;
    delete barraVidaGoku;
    delete barraVidaNam;
}




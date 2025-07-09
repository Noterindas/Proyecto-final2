#include "Nivel2.h"
#include <QPixmap>
#include <QRandomGenerator>

Nivel2::Nivel2() {
    escena = new QGraphicsScene();
}

Nivel2::~Nivel2() {
    delete escena;
    delete nam;
    delete timerNam;
}

QGraphicsScene* Nivel2::obtenerEscena() {
    return escena;
}

void Nivel2::iniciarNivel(Goku* goku, QProgressBar* barraGoku, QProgressBar* barraNam) {
    this->goku = goku;this->goku = goku;
    this->barraVidaGoku = barraGoku;
    this->barraVidaNam = barraNam;

    escena->clear();
    QPixmap fondo(":/imagenes/arena.gif");
    QPixmap fondoEscalado = fondo.scaled(1700, 800, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    escena->setSceneRect(0, 0, 1700, 800);
    escena->setBackgroundBrush(fondoEscalado);

    goku->obtenerItem()->setPos(1000, 300);
    escena->addItem(goku->obtenerItem());

    nam = new Nam();
    nam->obtenerItem()->setPos(700, 300);
    escena->addItem(nam->obtenerItem());

    timerNam = new QTimer();
    QObject::connect(timerNam, &QTimer::timeout, [=]() {
        moverNam();
    });
    timerNam->start(110);
}

void Nivel2::moverNam() {
    QPointF posNam = nam->obtenerItem()->pos();
    QPointF posGoku = goku->obtenerItem()->pos();

    qreal dx = 0;
    if (posGoku.x() > posNam.x()) {
        dx = 6;
        nam->moverDerecha();
    } else if (posGoku.x() < posNam.x()) {
        dx = -6;
        nam->moverIzquierda();
    }

    QPointF nuevaPos = posNam + QPointF(dx, 0);
    nam->obtenerItem()->setPos(nuevaPos);

    if (qAbs(posGoku.x() - posNam.x()) < 60 && qAbs(posGoku.y() - posNam.y()) < 40) {
        int accion = QRandomGenerator::global()->bounded(5);
        if (accion == 0) {
            if (nam->mirandoDerecha)
                nam->puno();
            else
                nam->punoIzq();
            goku->reducirVida(10);  // QUITA VIDA
            barraVidaGoku->setValue(goku->obtenerVida());
        } else if (accion == 1) {
            if (nam->mirandoDerecha)
                nam->patada();
            else
                nam->patadaIzq();
            goku->reducirVida(10);  // QUITA VIDA
            barraVidaGoku->setValue(goku->obtenerVida());
        } else if(accion == 2) {
            if (nam->mirandoDerecha)
                nam->SPa();
            else
                nam->SPaIzq();
            goku->reducirVida(10);  // QUITA VIDA
            barraVidaGoku->setValue(goku->obtenerVida());
        } else if(accion == 3) {
            if (nam->mirandoDerecha)
                nam->SPu();
            else
                nam->SPuIzq();
            goku->reducirVida(10);  // QUITA VIDA
            barraVidaGoku->setValue(goku->obtenerVida());
        }
        else {
            if (nam->mirandoDerecha)
                nam->salto();
            else
                nam->saltoIzq();
        }
    }

    nam->animar();
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);

    timer = new QTimer(this);
    goku = new Goku();

    escena->addItem(goku->obtenerItem());

    connect(timer, &QTimer::timeout, this, &MainWindow::animarSprite);
    timer->start(80);

    mapa = new Mapa(escena);
    mapa->generarMapa();

    coco1 = new Cocodrilo(mapa, 1480, 240);
    coco2 = new Cocodrilo(mapa, 1480, 540);

    escena->addItem(coco1->obtenerItem());
    escena->addItem(coco2->obtenerItem());
    timerC = new QTimer(this);
    timerC->start(100);

    connect(timerC, &QTimer::timeout, this, &MainWindow::moverCocodrilo);

    serpi1 = new Serpiente(mapa, 70, 80);
    serpi2 = new Serpiente(mapa, 516, 520);
    serpi3 = new Serpiente(mapa, 810, 650);
    serpi4 = new Serpiente(mapa, 1105, 380);

    escena->addItem(serpi1->obtenerItem());
    escena->addItem(serpi2->obtenerItem());
    escena->addItem(serpi3->obtenerItem());
    escena->addItem(serpi4->obtenerItem());

    timerS = new QTimer(this);
    timerS->start(100);

    connect(timerC, &QTimer::timeout, this, &MainWindow::moverSerpiente);

    dino1 = new Dinosaurio(mapa, 1345, 380);
    dino2 = new Dinosaurio(mapa, 310, 520);
    dino3 = new Dinosaurio(mapa, 676, 520);

    escena->addItem(dino1->obtenerItem());
    escena->addItem(dino2->obtenerItem());
    escena->addItem(dino3->obtenerItem());

    timerS = new QTimer(this);
    timerS->start(100);

    connect(timerC, &QTimer::timeout, this, &MainWindow::moverDinosaurio);

    abeja1 = new Abejap(mapa, 224, 140);
    abeja2 = new Abejap(mapa, 590, 520);

    escena->addItem(abeja1->obtenerItem());
    escena->addItem(abeja2->obtenerItem());
    timerAp = new QTimer(this);
    timerAp->start(100);

    connect(timerC, &QTimer::timeout, this, &MainWindow::moverAbeja);

    abeja = new Abejag(mapa, 450,295,78);
    escena->addItem(abeja->obtenerItem());
    timerAg = new QTimer(this);
    timerAg->start(80);

    connect(timerC, &QTimer::timeout, this, &MainWindow::moverAbejag);

    vidas = 3;
}

void MainWindow::actualizarLabelVidas()
{
    ui->labelVidas->setText("Vidas: " + QString::number(vidas));
}

void MainWindow::animarSprite()
{
    bool seMovio = false;
    int dx = 0, dy = 0;

    if (teclasPresionadas.contains(Qt::Key_D)) {
        dx = 6;
        goku->moverDerecha();
    } else if (teclasPresionadas.contains(Qt::Key_A)) {
        dx = -6;
        goku->moverIzquierda();
    } else if (teclasPresionadas.contains(Qt::Key_W)) {
        dy = -6;
        goku->moverArriba();
    } else if (teclasPresionadas.contains(Qt::Key_S)) {
        dy = 6;
        goku->moverAbajo();
    } else if (teclasPresionadas.contains(Qt::Key_C)) {
        goku->puno();
    }

    if (dx != 0 || dy != 0) {
        QPointF posActual = goku->obtenerItem()->pos();
        QPointF nuevaPos = posActual + QPointF(dx, dy);

        goku->obtenerItem()->setPos(nuevaPos);

        if (!hayColisionConPared()) {
            seMovio = true;
        } else {
            goku->obtenerItem()->setPos(posActual);
        }
    }

    if (!seMovio) {
        goku->detener();
    } else {
        goku->animar();
    }
    QPointF pos = goku->obtenerItem()->pos();

    if (pos.x() >= 5 && pos.x() <= 15 &&
        pos.y() >= 670 && pos.y() <= 680) {

        Ganaste ventana(this);
        if (ventana.exec() == QDialog::Accepted && ventana.continuar()) {
            reiniciarJuego();
        } else {
            close();
        }
    }
}

void MainWindow::moverCocodrilo()
{
    coco1->animar();
    coco1->mover();
    coco2->animar();
    coco2->mover();

    if (goku->obtenerItem()->collidesWithItem(coco1->obtenerItem()) ||
        goku->obtenerItem()->collidesWithItem(coco2->obtenerItem())) {

        goku->reiniciarPosicion();
        vidas--;
        actualizarLabelVidas();

        if (vidas <= 0) {
            GamerOver ventana(this);
            if (ventana.exec() == QDialog::Accepted && ventana.quiereReintentar()) {
                reiniciarJuego();
            } else {
                close();
            }
        }
    }
}

void MainWindow::moverSerpiente()
{
    serpi1->animar();
    serpi1->mover();
    serpi2->animar();
    serpi2->mover();
    serpi3->animar();
    serpi3->mover();
    serpi4->animar();
    serpi4->mover();

    if (goku->obtenerItem()->collidesWithItem(serpi1->obtenerItem()) ||
        goku->obtenerItem()->collidesWithItem(serpi2->obtenerItem()) ||
        goku->obtenerItem()->collidesWithItem(serpi3->obtenerItem()) ||
        goku->obtenerItem()->collidesWithItem(serpi4->obtenerItem())) {

        goku->reiniciarPosicion();
        vidas--;
        actualizarLabelVidas();

        if (vidas <= 0) {
            GamerOver ventana(this);
            if (ventana.exec() == QDialog::Accepted && ventana.quiereReintentar()) {
                reiniciarJuego();
            } else {
                close();
            }
        }
    }
}

void MainWindow::moverDinosaurio()
{
    dino1->animar();
    dino1->mover();
    dino2->animar();
    dino2->mover();
    dino3->animar();
    dino3->mover();

    if (goku->obtenerItem()->collidesWithItem(dino1->obtenerItem()) ||
        goku->obtenerItem()->collidesWithItem(dino2->obtenerItem()) ||
        goku->obtenerItem()->collidesWithItem(dino3->obtenerItem())) {

        goku->reiniciarPosicion();
        vidas--;
        actualizarLabelVidas();

        if (vidas <= 0) {
            GamerOver ventana(this);
            if (ventana.exec() == QDialog::Accepted && ventana.quiereReintentar()) {
                reiniciarJuego();
            } else {
                close();
            }
        }
    }
}

void MainWindow::moverAbeja()
{
    abeja1->animar();
    abeja1->mover();
    abeja2->animar();
    abeja2->mover();

    if (goku->obtenerItem()->collidesWithItem(abeja1->obtenerItem()) ||
        goku->obtenerItem()->collidesWithItem(abeja2->obtenerItem())) {

        goku->reiniciarPosicion();
        vidas--;
        actualizarLabelVidas();

        if (vidas <= 0) {
            GamerOver ventana(this);
            if (ventana.exec() == QDialog::Accepted && ventana.quiereReintentar()) {
                reiniciarJuego();
            } else {
                close();
            }
        }
    }
}

void MainWindow::moverAbejag()
{
    abeja->animar();
    abeja->mover();


    if (goku->obtenerItem()->collidesWithItem(abeja->obtenerItem())) {

        goku->reiniciarPosicion();
        vidas--;
        actualizarLabelVidas();

        if (vidas <= 0) {
            GamerOver ventana(this);
            if (ventana.exec() == QDialog::Accepted && ventana.quiereReintentar()) {
                reiniciarJuego();
            } else {
                close();
            }
        }
    }
}

void MainWindow::reiniciarJuego()
{
    vidas = 3;
    actualizarLabelVidas();
    goku->reiniciarPosicion();

    teclasPresionadas.clear();
}

bool MainWindow::hayColisionConPared()
{
    QRectF gokuRect = goku->obtenerItem()->sceneBoundingRect();

    for (QGraphicsItem* pared : mapa->obtenerParedes()) {
        QRectF paredRect = pared->sceneBoundingRect();

        if (gokuRect.intersects(paredRect)) {
            return true;
        }
    }

    return false;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    teclasPresionadas.insert(event->key());
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    teclasPresionadas.remove(event->key());
}

MainWindow::~MainWindow()
{
    delete goku;
    delete coco1;
    delete coco2;
    delete serpi1;
    delete serpi2;
    delete serpi3;
    delete serpi4;
    delete dino1;
    delete dino2;
    delete dino3;
    delete abeja1;
    delete abeja2;
    delete abeja;
    delete timer;
    delete timerC;
    delete timerS;
    delete timerAp;
    delete timerAg;
    delete mapa;
    delete escena;
    delete ui;
}

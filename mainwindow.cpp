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

    coco = new Cocodrilo(mapa);
    escena->addItem(coco->obtenerItem());
    timerC = new QTimer(this);
    timerC->start(100);

    connect(timerC, &QTimer::timeout, this, &MainWindow::moverCocodrilo);
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

    if (!seMovio)
        goku->detener();
    else
        goku->animar();
}

void MainWindow::moverCocodrilo()
{
    coco->animar();
    coco->mover();
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
    delete timer;
    delete escena;
    delete ui;
}

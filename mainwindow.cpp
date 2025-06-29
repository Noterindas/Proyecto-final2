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
}

void MainWindow::animarSprite()
{
    bool seMovio = false;

    if (teclasPresionadas.contains(Qt::Key_D)) {
        goku->moverDerecha();
        seMovio = true;
    } else if (teclasPresionadas.contains(Qt::Key_A)) {
        goku->moverIzquierda();
        seMovio = true;
    } else if (teclasPresionadas.contains(Qt::Key_W)) {
        goku->moverArriba();
        seMovio = true;
    } else if (teclasPresionadas.contains(Qt::Key_S)) {
        goku->moverAbajo();
        seMovio = true;
    }

    if (!seMovio) {
        goku->detener();
    } else {
        goku->animar();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    teclasPresionadas.insert(event->key());
    QMainWindow::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    teclasPresionadas.remove(event->key());
    QMainWindow::keyReleaseEvent(event);
}

MainWindow::~MainWindow()
{
    delete goku;
    delete timer;
    delete escena;
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);

    vidas = 3;
    nivelActual = 1;
    cargarNivel(nivelActual);
}

void MainWindow::actualizarLabelVidas()
{
    ui->labelVidas->setText("Vidas: " + QString::number(vidas));
}

void MainWindow::cargarNivel(int nivel)
{
    teclasPermitidas.clear();

    if (nivel == 1) {

        teclasPermitidas << Qt::Key_W << Qt::Key_S << Qt::Key_A << Qt::Key_D ;

        mapa = new Mapa(escena);
        mapa->generarMapa();

        goku = new Goku(50, 50);
        goku->reiniciarPosicion();
        escena->addItem(goku->obtenerItem());

        coco1 = new Cocodrilo(mapa, 1480, 240);
        coco2 = new Cocodrilo(mapa, 1480, 540);
        escena->addItem(coco1->obtenerItem());
        escena->addItem(coco2->obtenerItem());

        serpi1 = new Serpiente(mapa, 70, 80);
        serpi2 = new Serpiente(mapa, 516, 520);
        serpi3 = new Serpiente(mapa, 810, 650);
        serpi4 = new Serpiente(mapa, 1105, 380);
        escena->addItem(serpi1->obtenerItem());
        escena->addItem(serpi2->obtenerItem());
        escena->addItem(serpi3->obtenerItem());
        escena->addItem(serpi4->obtenerItem());

        dino1 = new Dinosaurio(mapa, 1345, 380);
        dino2 = new Dinosaurio(mapa, 310, 520);
        dino3 = new Dinosaurio(mapa, 676, 520);
        escena->addItem(dino1->obtenerItem());
        escena->addItem(dino2->obtenerItem());
        escena->addItem(dino3->obtenerItem());

        abeja1 = new Abejap(mapa, 224, 140);
        abeja2 = new Abejap(mapa, 590, 520);
        abeja = new Abejag(mapa, 450, 295, 78);
        escena->addItem(abeja1->obtenerItem());
        escena->addItem(abeja2->obtenerItem());
        escena->addItem(abeja->obtenerItem());

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::animarSprite);
        timer->start(80);

        timerC = new QTimer(this);
        connect(timerC, &QTimer::timeout, this, &MainWindow::moverCocodrilo);
        timerC->start(100);

        timerS = new QTimer(this);
        connect(timerS, &QTimer::timeout, this, &MainWindow::moverSerpiente);
        timerS->start(100);

        timerD = new QTimer(this);
        connect(timerD, &QTimer::timeout, this, &MainWindow::moverDinosaurio);
        timerD->start(100);

        timerAp = new QTimer(this);
        connect(timerAp, &QTimer::timeout, this, &MainWindow::moverAbeja);
        timerAp->start(100);

        timerAg = new QTimer(this);
        connect(timerAg, &QTimer::timeout, this, &MainWindow::moverAbejag);
        timerAg->start(80);
    }

    if (nivel == 2) {
        teclasPermitidas << Qt::Key_A << Qt::Key_D << Qt::Key_Space << Qt::Key_C << Qt::Key_V;

        nivel2 = new Nivel2();
        nivel2->iniciarNivel();

        goku = nivel2->obtenerGoku();
        namNivel2 = nivel2->obtenerNam();

        escena = nivel2->obtenerEscena();
        ui->graphicsView->setScene(escena);

        barraVidaGoku = nivel2->obtenerBarraVidaGoku();
        barraVidaNam = nivel2->obtenerBarraVidaNam();

        barraVidaGoku->setParent(this);
        barraVidaNam->setParent(this);

        barraVidaGoku->setGeometry(50, 30, 200, 20);
        barraVidaNam->setGeometry(1450, 30, 200, 20);

        barraVidaGoku->show();
        barraVidaNam->show();

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::animarSprite);
        timer->start(80);
    }
}

void MainWindow::limpiar()
{
    if (goku) {
        delete goku;
        goku = nullptr;
    }

    delete coco1; coco1 = nullptr;
    delete coco2; coco2 = nullptr;
    delete serpi1; serpi1 = nullptr;
    delete serpi2; serpi2 = nullptr;
    delete serpi3; serpi3 = nullptr;
    delete serpi4; serpi4 = nullptr;
    delete dino1; dino1 = nullptr;
    delete dino2; dino2 = nullptr;
    delete dino3; dino3 = nullptr;
    delete abeja1; abeja1 = nullptr;
    delete abeja2; abeja2 = nullptr;
    delete abeja;  abeja = nullptr;

    delete mapa; mapa = nullptr;

    if (timer) { timer->stop(); delete timer; timer = nullptr; }
    if (timerC) { timerC->stop(); delete timerC; timerC = nullptr; }
    if (timerS) { timerS->stop(); delete timerS; timerS = nullptr; }
    if (timerD) { timerD->stop(); delete timerD; timerD = nullptr; }
    if (timerAp){ timerAp->stop(); delete timerAp; timerAp = nullptr; }
    if (timerAg){ timerAg->stop(); delete timerAg; timerAg = nullptr; }
}

void MainWindow::animarSprite()
{
    bool estaAtacando = false;
    int dx = 0, dy = 0;

    if (teclasPresionadas.contains(Qt::Key_Space) && teclasPresionadas.contains(Qt::Key_C)) {
        if (goku->mirandoDerecha)
            goku->SPu();
        else
            goku->SPuIzq();
        estaAtacando = true;

        if (nivelActual == 2) {
            if (goku->obtenerItem()->collidesWithItem(namNivel2->obtenerItem())) {
                namNivel2->reducirVida(4);
                barraVidaNam->setValue(namNivel2->obtenerVida());

                namNivel2->estaSiendoEmpujado = true;
                namNivel2->contadorEmpuje = 10;
                namNivel2->direccionEmpuje = goku->mirandoDerecha ? 18 : -18;
            }
        }
    }
    else if (teclasPresionadas.contains(Qt::Key_Space) && teclasPresionadas.contains(Qt::Key_V)) {
        if (goku->mirandoDerecha)
            goku->SPa();
        else
            goku->SPaIzq();
        estaAtacando = true;

        if (nivelActual == 2) {
            if (goku->obtenerItem()->collidesWithItem(namNivel2->obtenerItem())) {
                namNivel2->reducirVida(4);
                barraVidaNam->setValue(namNivel2->obtenerVida());

                namNivel2->estaSiendoEmpujado = true;
                namNivel2->contadorEmpuje = 10;
                namNivel2->direccionEmpuje = goku->mirandoDerecha ? 18 : -18;
            }
        }
    }

    else if (teclasPresionadas.contains(Qt::Key_D)) {
        dx = 6;
        goku->mirandoDerecha = true;

        if (teclasPresionadas.contains(Qt::Key_C)) {
            goku->puno();
            if (nivelActual == 2) {
                if (goku->obtenerItem()->collidesWithItem(namNivel2->obtenerItem())) {
                    namNivel2->reducirVida(4);
                    barraVidaNam->setValue(namNivel2->obtenerVida());

                    namNivel2->estaSiendoEmpujado = true;
                    namNivel2->contadorEmpuje = 10;
                    namNivel2->direccionEmpuje = goku->mirandoDerecha ? 18 : -18;
                }
            }
        } else if (teclasPresionadas.contains(Qt::Key_V)) {
            goku->patada();
            if (nivelActual == 2) {
                if (goku->obtenerItem()->collidesWithItem(namNivel2->obtenerItem())) {
                    namNivel2->reducirVida(4);
                    barraVidaNam->setValue(namNivel2->obtenerVida());

                    namNivel2->estaSiendoEmpujado = true;
                    namNivel2->contadorEmpuje = 10;
                    namNivel2->direccionEmpuje = goku->mirandoDerecha ? 18 : -18;
                }
            }
        } else if (teclasPresionadas.contains(Qt::Key_Space)) {
            goku->salto();
        } else {
            goku->moverDerecha();
        }
    }
    else if (teclasPresionadas.contains(Qt::Key_A)) {
        dx = -6;
        goku->mirandoDerecha = false;

        if (teclasPresionadas.contains(Qt::Key_C)) {
            goku->punoIzq();
            if (nivelActual == 2) {
                if (goku->obtenerItem()->collidesWithItem(namNivel2->obtenerItem())) {
                    namNivel2->reducirVida(4);
                    barraVidaNam->setValue(namNivel2->obtenerVida());

                    namNivel2->estaSiendoEmpujado = true;
                    namNivel2->contadorEmpuje = 10;
                    namNivel2->direccionEmpuje = goku->mirandoDerecha ? 18 : -18;
                }
            }
        } else if (teclasPresionadas.contains(Qt::Key_V)) {
            goku->patadaIzq();
            if (nivelActual == 2) {
                if (goku->obtenerItem()->collidesWithItem(namNivel2->obtenerItem())) {
                    namNivel2->reducirVida(4);
                    barraVidaNam->setValue(namNivel2->obtenerVida());

                    namNivel2->estaSiendoEmpujado = true;
                    namNivel2->contadorEmpuje = 10;
                    namNivel2->direccionEmpuje = goku->mirandoDerecha ? 18 : -18;
                }
            }
        } else if (teclasPresionadas.contains(Qt::Key_Space)) {
            goku->saltoIzq();
        } else {
            goku->moverIzquierda();
        }
    }

    else if (teclasPresionadas.contains(Qt::Key_W) && teclasPermitidas.contains(Qt::Key_W)) {
        dy = -6;
        goku->moverArriba();
    }
    else if (teclasPresionadas.contains(Qt::Key_S) && teclasPermitidas.contains(Qt::Key_S)) {
        dy = 6;
        goku->moverAbajo();
    }

    else if (teclasPresionadas.contains(Qt::Key_Space)) {
        if (goku->mirandoDerecha)
            goku->salto();
        else
            goku->saltoIzq();
        estaAtacando = true;
    }
    else if (teclasPresionadas.contains(Qt::Key_C)) {
        if (goku->mirandoDerecha)
            goku->puno();
        else
            goku->punoIzq();
        estaAtacando = true;

        if (nivelActual == 2) {
            if (goku->obtenerItem()->collidesWithItem(namNivel2->obtenerItem())) {
                namNivel2->reducirVida(4);
                barraVidaNam->setValue(namNivel2->obtenerVida());

                namNivel2->estaSiendoEmpujado = true;
                namNivel2->contadorEmpuje = 10;
                namNivel2->direccionEmpuje = goku->mirandoDerecha ? 18 : -18;
            }
        }
    }
    else if (teclasPresionadas.contains(Qt::Key_V)) {
        if (goku->mirandoDerecha)
            goku->patada();
        else
            goku->patadaIzq();
        estaAtacando = true;

        if (nivelActual == 2) {
            if (goku->obtenerItem()->collidesWithItem(namNivel2->obtenerItem())) {
                namNivel2->reducirVida(4);
                barraVidaNam->setValue(namNivel2->obtenerVida());

                namNivel2->estaSiendoEmpujado = true;
                namNivel2->contadorEmpuje = 10;
                namNivel2->direccionEmpuje = goku->mirandoDerecha ? 18 : -18;
            }
        }
    }

    if (dx != 0 || dy != 0) {
        QPointF posActual = goku->obtenerItem()->pos();
        QPointF nuevaPos = posActual + QPointF(dx, dy);

        QRectF limites = escena->sceneRect();
        qreal nuevoX = qBound(limites.left(), nuevaPos.x(), limites.right() - goku->obtenerItem()->boundingRect().width());
        qreal nuevoY = qBound(limites.top(), nuevaPos.y(), limites.bottom() - goku->obtenerItem()->boundingRect().height());
        goku->obtenerItem()->setPos(nuevoX, nuevoY);

        if (hayColisionConPared()) {
            goku->obtenerItem()->setPos(posActual);
        }
    }

    if (dx == 0 && dy == 0 && !estaAtacando) {
        goku->detener();
    }

    goku->animar();

    QPointF pos = goku->obtenerItem()->pos();
    if(nivelActual == 1){
        if (pos.x() >= 5 && pos.x() <= 15 && pos.y() >= 660 && pos.y() <= 690) {
            Ganaste ventana(this);
            if (ventana.exec() == QDialog::Accepted && ventana.continuar()) {
                nivelActual++;
                if (nivelActual == 2) {
                     limpiar();
                    ui->labelVidas->hide();
                    cargarNivel(nivelActual);
                    teclasPermitidas = { Qt::Key_A, Qt::Key_D, Qt::Key_Space, Qt::Key_C,  Qt::Key_V};
                    teclasPresionadas.clear();
                }
            } else {
                close();
            }
        }
    }

    if (nivelActual == 2 && goku->obtenerVida() <= 0) {
        timer->stop();

        GamerOver ventana(this, true);
        ventana.exec();
        close();
        return;
    }

    if (nivelActual == 2 && namNivel2->obtenerVida() <= 0) {
        timer->stop();

        Ganaste ventana(this, true);
        ventana.exec();
        close();
        return;
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
                nivelActual++;
                cargarNivel(nivelActual);
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
    if (!mapa) return false;

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
    if (teclasPermitidas.contains(event->key()))
        teclasPresionadas.insert(event->key());
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (teclasPermitidas.contains(event->key()))
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
    delete nivel2;
}

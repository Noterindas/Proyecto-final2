#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "goku.h"
#include <QKeyEvent>
#include <QSet>
#include "mapa.h"
#include "cocodrilo.h"
#include "serpiente.h"
#include "dinosaurio.h"
#include "abejap.h"
#include "abejag.h"
#include "gamerover.h"
#include "ganaste.h"
#include "nam.h"
#include <QRandomGenerator>
#include "nivel2.h"
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) ;
    void keyReleaseEvent(QKeyEvent *event) ;

private slots:
    void animarSprite();
    void moverCocodrilo();
    void moverSerpiente();
    void moverDinosaurio();
    void moverAbeja();
    void moverAbejag();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;
    QTimer* timer;
    QTimer* timerC;
    QTimer* timerS;
    QTimer* timerD;
    QTimer* timerAp;
    QTimer* timerAg;
    Goku* goku;
    Nam* namNivel2;
    Cocodrilo* coco1;
    Cocodrilo* coco2;
    Serpiente* serpi1;
    Serpiente* serpi2;
    Serpiente* serpi3;
    Serpiente* serpi4;
    Dinosaurio* dino1;
    Dinosaurio* dino2;
    Dinosaurio* dino3;
    Abejap* abeja1;
    Abejap* abeja2;
    Abejag* abeja;
    Mapa* mapa;
    QSet<int> teclasPresionadas;
    QSet<int> teclasPermitidas;
    bool hayColisionConPared();
    int vidas;
    void actualizarLabelVidas();
    void reiniciarJuego();
    int nivelActual = 1;
    void cargarNivel(int nivel);
    Nivel2* nivel2;
    QProgressBar* barraVidaGoku;
    QProgressBar* barraVidaNam;
    void limpiar();

};

#endif

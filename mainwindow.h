#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "goku.h"
#include <QKeyEvent>
#include "mapa.h"
#include "Cocodrilo.h"

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
    void direccionActual();

private slots:
    void animarSprite();
    void moverCocodrilo();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;
    QTimer* timer;
    QTimer* timerC;
    Goku* goku;
    Cocodrilo* coco;
    Mapa* mapa;
    QSet<int> teclasPresionadas;
    bool hayColisionConPared();

};

#endif

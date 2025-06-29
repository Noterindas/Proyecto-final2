#ifndef MAPA_H
#define MAPA_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Mapa
{
public:
    Mapa(QGraphicsScene* escena);
    void generarMapa();

private:
    QGraphicsScene* escena;
    static const int filas = 11;
    static const int columnas = 23;
    static const int tamañoCelda = 60;

    char mapa[filas][columnas] = {
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
        {'X',' ','X',' ','X','X',' ','X','X',' ','X',' ','X',' ','X','X',' ',' ','X','X','X',' ','X'},
        {'X',' ',' ','X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ','X','X',' ','X',' ',' ','X'},
        {'X',' ','X',' ',' ',' ',' ',' ',' ',' ','X',' ','X',' ','X',' ','X','X',' ','X','X',' ','X'},
        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {'X',' ','X',' ','X','X',' ','X','X','X','X',' ','X',' ','X',' ','X','X',' ','X','X',' ','X'},
        {'X',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ','X','X',' ','X',' ',' ','X'},
        {'X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X','X',' ',' ','X','X','X',' ','X'},
        {' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
    };
};

#endif

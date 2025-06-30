#ifndef MAPA_H
#define MAPA_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVector>

class Mapa
{
public:
    Mapa(QGraphicsScene* escena);
    void generarMapa();
    QVector<QGraphicsItem*> obtenerParedes() const;

private:
    QGraphicsScene* escena;
    QVector<QGraphicsItem*> paredes;
    static const int filas = 11;
    static const int columnas = 23;
    static const int tamañoCelda = 74;

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

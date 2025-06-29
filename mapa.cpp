#include "Mapa.h"
#include <QBrush>
#include <QColor>

Mapa::Mapa(QGraphicsScene* escena)
    : escena(escena)
{
}

void Mapa::generarMapa()
{
    QPixmap imagenPared(":/imagenes/pared2.png");

    for (int fila = 0; fila < filas; ++fila) {
        for (int col = 0; col < columnas; ++col) {
            if (mapa[fila][col] == 'X') {
                QGraphicsPixmapItem* item = new QGraphicsPixmapItem(imagenPared.scaled(tamañoCelda, tamañoCelda, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                item->setPos(col * tamañoCelda, fila * tamañoCelda);
                escena->addItem(item);
            }
        }
    }
}

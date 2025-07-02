#include "ganaste.h"
#include "ui_ganaste.h"

Ganaste::Ganaste(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ganaste)
{
    ui->setupUi(this);
    setModal(true);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    QPixmap imagen(":/imagenes/Win.jpeg");
    ui->labelImagen->setPixmap(imagen);
    ui->labelImagen->setScaledContents(true);
}

void Ganaste::on_btnSiguienteLvl_clicked()
{
    continuarJuego = true;
    accept();
}


void Ganaste::on_btnSalir_clicked()
{
    continuarJuego = false;
    reject();
}

bool Ganaste::continuar() const
{
    return continuarJuego;
}

Ganaste::~Ganaste()
{
    delete ui;
}

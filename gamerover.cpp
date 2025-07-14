#include "gamerover.h"
#include "ui_gamerover.h"

GamerOver::GamerOver(QWidget *parent, bool soloSalir)
    : QDialog(parent)
    , ui(new Ui::GamerOver)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setModal(true);
    QPixmap imagen(":/imagenes/GameOver.jpeg");
    ui->labelImagen->setPixmap(imagen);
    ui->labelImagen->setScaledContents(true);

    if (soloSalir) {
        ui->btnReintentar->hide();
    }
}

void GamerOver::on_btnReintentar_clicked()
{
    reintentar = true;
    accept();
}


void GamerOver::on_btnSalir_clicked()
{
    reintentar = false;
    reject();
}


bool GamerOver::quiereReintentar() const
{
    return reintentar;
}

GamerOver::~GamerOver()
{
    delete ui;
}



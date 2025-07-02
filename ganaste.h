#ifndef GANASTE_H
#define GANASTE_H

#include <QDialog>

namespace Ui {
class Ganaste;
}

class Ganaste : public QDialog
{
    Q_OBJECT

public:
    explicit Ganaste(QWidget *parent = nullptr);
    bool continuar() const;
    ~Ganaste();

private slots:

    void on_btnSiguienteLvl_clicked();
    void on_btnSalir_clicked();

private:
    Ui::Ganaste *ui;
    bool continuarJuego = false;
};

#endif // GANASTE_H

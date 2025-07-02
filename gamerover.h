#ifndef GAMEROVER_H
#define GAMEROVER_H

#include <QDialog>

namespace Ui {
class GamerOver;
}

class GamerOver : public QDialog
{
    Q_OBJECT

public:
    explicit GamerOver(QWidget *parent = nullptr);
    bool quiereReintentar() const;
    ~GamerOver();


private slots:
    void on_btnReintentar_clicked();
    void on_btnSalir_clicked();

private:
    Ui::GamerOver *ui;
    bool reintentar = false;
};

#endif // GAMEROVER_H

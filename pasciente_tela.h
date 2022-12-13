#ifndef PASCIENTE_TELA_H
#define PASCIENTE_TELA_H

#include <QDialog>
#include <pasciente.h>

namespace Ui {
class Pasciente_tela;
}

class Pasciente_tela : public QDialog
{
    Q_OBJECT

public:
    explicit Pasciente_tela(QWidget *parent = nullptr);
    ~Pasciente_tela();
    void set_pasciente(dwp::Pasciente pasciente);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Pasciente_tela *ui;
    dwp::Pasciente autenticado;
};

#endif // PASCIENTE_TELA_H

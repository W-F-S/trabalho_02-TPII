#ifndef ATENDENTE_TELA_H
#define ATENDENTE_TELA_H

#include "atendente.h"
#include <QDialog>
#include "atendente_cadastrar_usuario.h"

namespace Ui {
class Atendente_tela;
}

class Atendente_tela : public QDialog
{
    Q_OBJECT

public:
    Atendente_tela(dwp::Atendente *autenticado);
    explicit Atendente_tela(QWidget *parent = nullptr);
    ~Atendente_tela();

private slots:
    void on_pushButton_2_clicked();

private:
    dwp::Atendente *autenticado;

    Ui::Atendente_tela *ui;
};

#endif // ATENDENTE_TELA_H

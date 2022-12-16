#ifndef MEDICO_PASCIENTE_TELA_H
#define MEDICO_PASCIENTE_TELA_H

//funcionalidade não implementada, atualemente, ao tentar fazer uma pesquisa, o programa quebra.
#include <QDialog>
#include <pasciente.h>

namespace Ui {
class Medico_pasciente_tela;
}

class Medico_pasciente_tela : public QDialog
{
    Q_OBJECT

public:
    void set_pasciente(dwp::Pasciente autenticado);
    explicit Medico_pasciente_tela(QWidget *parent = nullptr, dwp::Pasciente *autenticado = nullptr);
    ~Medico_pasciente_tela();

private:

    Ui::Medico_pasciente_tela *ui;
};

#endif // MEDICO_PASCIENTE_TELA_H

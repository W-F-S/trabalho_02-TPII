#include "medico_pasciente_tela.h"
#include "ui_medico_pasciente_tela.h"

//funcionalidade não implementada, atualemente, ao tentar fazer uma pesquisa, o programa quebra.

Medico_pasciente_tela::Medico_pasciente_tela(QWidget *parent, dwp::Pasciente *autenticado) :
    QDialog(parent),
    ui(new Ui::Medico_pasciente_tela)
{
    ui->setupUi(this);

    QString *agenda = autenticado->get_agenda(autenticado->getNum_matricula());
    ui->textEdit_agenda->setText(*agenda);
}

Medico_pasciente_tela::~Medico_pasciente_tela()
{
    delete ui;
}

/**
void Medico_pasciente_tela::set_pasciente(dwp::Pasciente autenticado)
{
    Medico_pasciente_tela::autenticado = autenticado;
}
*/

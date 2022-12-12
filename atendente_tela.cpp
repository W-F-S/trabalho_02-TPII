#include "atendente_tela.h"
#include "ui_atendente_tela.h"

Atendente_tela::Atendente_tela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Atendente_tela)
{
    ui->setupUi(this);
}

Atendente_tela::~Atendente_tela()
{
    delete ui;
}

void Atendente_tela::set_atendente(dwp::Atendente *autenticado)
{
    Atendente_tela::autenticado = autenticado;

}

void Atendente_tela::on_pushButton_2_clicked()
{
    cadastrar_pasciente = new Atendente_cadastrar_usuario(this);
    cadastrar_pasciente->show();


}


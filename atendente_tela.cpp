#include "atendente_tela.h"
#include "ui_atendente_tela.h"
#include <QMessageBox>


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

void Atendente_tela::on_pushButton_cadastrarUsuario_clicked()
{
    cadastrar_medico = new Atendente_cadastrar_medico(this);
    cadastrar_medico->show();
}

void Atendente_tela::on_pushButton_consultarAgenda_clicked()
{
    g_agenda = new get_agenda(this);
    g_agenda->show();
}

void Atendente_tela::on_pushButton_3_clicked()
{
    a_agenda = new Adicionar_agenda(this);
    a_agenda->show();
}


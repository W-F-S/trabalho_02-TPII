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

void Atendente_tela::set_atendente(dwp::Atendente autenticado)
{
    Atendente_tela::autenticado = autenticado;
    Atendente_tela::autenticado.mostrar_dados();

}

void Atendente_tela::on_pushButton_2_clicked()
{
    cadastrar_pasciente = new Atendente_cadastrar_usuario(this);
    cadastrar_pasciente->show();
}

void Atendente_tela::on_pushButton_cadastrarUsuario_clicked()
{
    if(Atendente_tela::autenticado.get_Secretaria_geral())
    {
        cadastrar_medico = new Atendente_cadastrar_medico(this);
        cadastrar_medico->show();
    }
    else
    {
        QMessageBox::critical(this, "Atendente", "Erro. Você não possui permições para cadastrar um médico                          ");
    }
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


void Atendente_tela::on_pushButton_clicked()
{
    if(Atendente_tela::autenticado.get_Secretaria_geral())
    {
        cadastrar_atend = new cadastrar_atendente(this);
        cadastrar_atend->show();
    }
    else
    {
        QMessageBox::critical(this, "Atendente", "Erro. Você não possui permições para cadastrar um atendente");
    }
}


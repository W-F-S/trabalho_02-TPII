#include "pasciente_tela.h"
#include "ui_pasciente_tela.h"

Pasciente_tela::Pasciente_tela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pasciente_tela)
{
    ui->setupUi(this);
    QString *agenda = (Pasciente_tela::autenticado.get_agenda(autenticado.getNum_matricula()));
    Pasciente_tela::autenticado.mostrar_dados();
    ui->textEdit_agenda->setText(*agenda);
    //colocando a agenda do pasciente na tela
    ui->lineEdit_cpf->setText(Pasciente_tela::autenticado.getNome());

}

Pasciente_tela::~Pasciente_tela()
{
    delete ui;
}

void Pasciente_tela::set_pasciente(dwp::Pasciente pasciente)
{
    Pasciente_tela::autenticado = pasciente;
}

void Pasciente_tela::on_pushButton_clicked()
{

}


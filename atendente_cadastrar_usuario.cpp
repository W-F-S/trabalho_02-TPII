#include "atendente_cadastrar_usuario.h"
#include "ui_atendente_cadastrar_usuario.h"
#include "atendente.h"
#include <QDialog>
#include <QMessageBox>


Atendente_cadastrar_usuario::Atendente_cadastrar_usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Atendente_cadastrar_usuario)
{
    ui->setupUi(this);
}

Atendente_cadastrar_usuario::~Atendente_cadastrar_usuario()
{
    delete ui;
}

void Atendente_cadastrar_usuario::on_pushButton_cadastrar_clicked()
{

    bool particular = false;
    QString convenio = "";

    QString nome_pasciente  = ui->lineEdit_nome->text();
    long cpf_pasciente  = ui->lineEdit_cpf->text().toLong();
    QString email = ui->lineEdit_email->text();
    long telefone = ui->lineEdit_telefone->text().toLong();
    long whatsapp = ui->lineEdit_whatsapp->text().toLong();
    long cpf_medico = ui->lineEdit_cpf_medico->text().toLong();
    QString senha = ui->lineEdit_senha->text();



    if(ui->checkBox_convenio->isChecked())
    {
        particular = true;
        convenio = ui->lineEdit_convenio->text();
    }

    dwp::Pasciente novo_pasciente{
        nome_pasciente,
        cpf_pasciente,
        email,
        telefone,
        whatsapp,
        senha,
        cpf_medico,
        particular,
        convenio
    };

    dwp::Atendente tmp{};
    QString teste = novo_pasciente.buscar_usuario(cpf_pasciente);
    qDebug() << teste;
    if(novo_pasciente.buscar_usuario(cpf_pasciente) != "")
    {
        QMessageBox::critical(this, "Cadastro de pasciente", "Erro. Este usuário já está cadastrado no sistema");
    }
    else{
        tmp.cadastrar_pasciente(&novo_pasciente);
        QMessageBox::information(this, "Cadastro de pasciente", "Usuário cadastrado com sucesso");
        close();
    }
}


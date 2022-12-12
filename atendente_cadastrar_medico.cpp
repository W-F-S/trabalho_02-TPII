#include "atendente_cadastrar_medico.h"
#include "ui_atendente_cadastrar_medico.h"
#include <QDialog>
#include <QMessageBox>


Atendente_cadastrar_medico::Atendente_cadastrar_medico(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Atendente_cadastrar_medico)
{
    ui->setupUi(this);
}

Atendente_cadastrar_medico::~Atendente_cadastrar_medico()
{
    delete ui;
}

void Atendente_cadastrar_medico::on_pushButton_cadastrar_clicked()
{
    bool particular = false;
    long *cpfs = new long[3];

    QString nome_medico  = ui->lineEdit_nome->text();
    long cpf_medico  = ui->lineEdit_cpf->text().toLong();
    QString email = ui->lineEdit_email->text();
    long telefone = ui->lineEdit_telefone->text().toLong();
    long whatsapp = ui->lineEdit_whatsapp->text().toLong();
    QString senha = ui->lineEdit_senha->text();

    long crm = ui->lineEdit_crm->text().toLong();
    QString tmp = ui->lineEdit_pascientes->text();
    QString especialidade = ui->lineEdit_especialidade->text();
    cpfs[0] = especialidade.split(',')[0].toLong();
    cpfs[1] = especialidade.split(',')[1].toLong();
    cpfs[2] = especialidade.split(',')[2].toLong();

    if(ui->checkBox_particular->isChecked())
    {
        particular = true;
    }

    dwp::Medico novo_medico{
        nome_medico,
        cpf_medico,
        email,
        telefone,
        whatsapp,
        senha,
        especialidade,
        particular,
        crm,
        cpfs
    };

    dwp::Atendente temp{};
    temp.cadastrar_medico(&novo_medico);
    QMessageBox::information(this, "Cadastro de médico", "Médico cadastrado com sucesso");

    close();
}


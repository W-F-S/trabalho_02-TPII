#include "cadastrar_medico.h"
#include "ui_cadastrar_medico.h"
#include "medico.h"
cadastrar_medico::cadastrar_medico(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrar_medico)
{
    ui->setupUi(this);
    ui->lineEditConvenio1->setEnabled(false);
    ui->lineEditConvenio2->setEnabled(false);
    ui->lineEditConvenios3->setEnabled(false);
    if(ui->checkBoxConvenio->isChecked()){
        ui->lineEditConvenio1->setEnabled(true);
        ui->lineEditConvenio2->setEnabled(true);
        ui->lineEditConvenios3->setEnabled(true);
    }
}

cadastrar_medico::~cadastrar_medico()
{
    delete ui;
}

void cadastrar_medico::on_pushButtonCadastrarMedico_clicked()
{

    QString Nome=ui->lineEditNome->text();
    long cpf=ui->lineEditCPF->text().toLong();
    QString email=ui->lineEditEmail->text();
    long tel=ui->lineEditTelefone->text().toLong();
    long whatsapp=ui->lineEditWhatsapp->text().toLong();
    QString senha=ui->lineEditSenha->text();
    bool particular=ui->checkBoxParticular->isChecked();
    long CRM=ui->lineEditCRM->text().toLong();
    QString Especialidade=ui->lineEditEspecialidade->text();
    QString convenio1=ui->lineEditConvenio1->text();
    QString convenio2=ui->lineEditConvenio2->text();
    QString convenio3=ui->lineEditConvenios3->text();
    dwp::Medico m(Nome,cpf,email,tel,whatsapp,senha,Especialidade,particular,CRM,convenio1,convenio2,convenio3);

}


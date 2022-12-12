#include "adicionar_agenda.h"
#include "ui_adicionar_agenda.h"

Adicionar_agenda::Adicionar_agenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adicionar_agenda)
{
    ui->setupUi(this);
}

Adicionar_agenda::~Adicionar_agenda()
{
    delete ui;
}

void Adicionar_agenda::on_pushButton_cadastrar_clicked()
{
    dwp::Sistema tmp;

    long cpf = ui->lineEdit_cpf->text().toLong();

    QString texto = ui->plainTextEdit_texto->toPlainText();


    QString usuario = tmp.buscar_usuario(cpf);

    tmp.adicionar_agenda(usuario.split(',')[1].toLong(), &texto);
}


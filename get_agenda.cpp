#include "get_agenda.h"
#include "ui_get_agenda.h"

get_agenda::get_agenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::get_agenda)
{
    ui->setupUi(this);
}

get_agenda::~get_agenda()
{
    delete ui;
}

void get_agenda::on_pushButton_clicked()
{
    long cpf = ui->lineEdit_cpf->text().toLong();
    dwp::Sistema tmp;

    QString usuario = tmp.buscar_usuario(cpf);

    QString *agenda = (tmp.get_agenda(usuario.split(',')[1].toInt()));

    ui->textEdit_agenda->setText(*agenda);
}


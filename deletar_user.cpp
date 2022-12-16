#include "deletar_user.h"
#include "ui_deletar_user.h"

deletar_user::deletar_user(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::deletar_user)
{
  ui->setupUi(this);
}

deletar_user::~deletar_user()
{
  delete ui;
}

void deletar_user::on_pushButton_deletar_clicked()
{
  dwp::Atendente tmp{};
  dwp::Sistema tmp2;

  long cpf = ui->lineEdit_cpf->text().toLong();

  QString in = tmp2.buscar_usuario(cpf);

  if(tmp.deletar_usuario(in.split(',')[1].toInt()))
  {
    QMessageBox::information(this, "Exclusão", "Usuário deletado com sucesso.");
  }else{
    QMessageBox::warning(this, "Exclusão"," Erro ao deletar o usuário");

  }
}


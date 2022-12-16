#include "cadastrar_atendente.h"
#include "ui_cadastrar_atendente.h"


cadastrar_atendente::cadastrar_atendente(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::cadastrar_atendente)
{
  ui->setupUi(this);
}

cadastrar_atendente::~cadastrar_atendente()
{
  delete ui;
}

void cadastrar_atendente::on_pushButtonCadastrar_clicked()
{
  //coletando dados dos campos
  long *cpfs = new long[3];
  QString nome  = ui->lineEditNome->text();
  long cpf  = ui->lineEditCPF->text().toLong();
  QString email = ui->lineEditEmail->text();
  long telefone = ui->lineEditTelefone->text().toLong();
  long whatsapp = ui->lineEditWpp->text().toLong();
  QString senha = ui->lineEditSenha->text();
  bool secretaria_geral = false;
  QString medicos = ui->lineEditMedicos->text();
  cpfs[0] = medicos.split(',')[0].toLong();
  cpfs[1] = medicos.split(',')[1].toLong();
  cpfs[2] = medicos.split(',')[2].toLong();

  if(ui->checkBoxSGeral->isChecked())
  {
    secretaria_geral = true;
  }

  dwp::Atendente novo_atendente{
    nome,
      cpf,
      email,
      telefone,
      whatsapp,
      senha,
      secretaria_geral,
      cpfs
  };

  dwp::Atendente temp{};

  if(novo_atendente.buscar_usuario(cpf)!= "")
  {
    QMessageBox::critical(this, "Cadastro de Atendente", "Erro. Este usuário já está cadastrado no sistema");
  }
  else
  {
    temp.cadastrar_atendente(&novo_atendente);
    QMessageBox::information(this, "Cadastro de Atendente", "Atendente cadastrado com sucesso");
    close();
  }
}

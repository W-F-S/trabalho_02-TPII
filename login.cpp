#include "login.h"
#include "ui_login.h"
#include "sistema.h"
#include "atendente_tela.h"
#include "pasciente_tela.h"

#include <QMessageBox>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{


}

void Login::on_pushButton_login_clicked()
{
    int flag;
    dwp::Sistema sis;
    dwp::Atendente tmp;

    long cpf = ui->lineEdit_cpf->text().toLong();
    QString senha = ui->lineEdit_senha->text();
    qDebug() << cpf;
    qDebug() << senha;

    flag = sis.login(cpf, senha);
    qDebug() << flag;
    switch(flag)
    {
    case -1:
    {
        qDebug() << "usuário não encontrado";
        QMessageBox::warning(this, "Login"," Usuário não cadastrado no sistema");
        break;
    }

    case 0:
    {
        qDebug() << "bem vindo";
        QMessageBox::information(this, "Login", "Bem vindo");
        hide();
        QString busca = sis.buscar_usuario(cpf);
        switch(busca.at(0).digitValue())
        {
            case 0:
            {
                qDebug() << "Usuario do tipo atendente";
                dwp::Atendente *tmp2 = tmp.buscar_atendente(busca.split(',')[1].toInt());
                Atendente_tela janela_atendente{};
                janela_atendente.set_atendente(*tmp2);
                janela_atendente.setModal(true);
                janela_atendente.exec();
                break;
            }
            case 1:
            {
                qDebug() << "Usuario do tipo médico";
                break;
            }
            case 2:
            {
                qDebug() << "Usuario do tipo pasciente";
                dwp::Pasciente *tmp2 = tmp.buscar_pasciente(busca.split(',')[1].toInt());
                Pasciente_tela janela_pasciente{};
                janela_pasciente.set_pasciente(*tmp2);
                janela_pasciente.setModal(true);
                janela_pasciente.exec();
                break;
            }
            default:
            {
                qDebug() << "erro";
                break;
            }
        }
        break;
    }
    case 1:
    {
        qDebug() << "senha incorreta";
        QMessageBox::warning(this, "Login", " Senha incorreta");
        break;
    }
    default:
    {
        qDebug() << "erro";
        break;
    }
    }
}


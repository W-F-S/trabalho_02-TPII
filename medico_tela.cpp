#include "medico_tela.h"
#include "ui_medico_tela.h"

Medico_tela::Medico_tela(QWidget *parent, dwp::Medico *medico) :
    QDialog(parent),
    ui(new Ui::Medico_tela)
{
    //pegando a agenda e os dados do medico cadastrado e mostrando na tela
    ui->setupUi(this);
    Medico_tela::autenticado = medico;
    QString *agenda = (medico->get_agenda(medico->getNum_matricula()));
    medico->mostrar_dados();
    ui->textEdit_agenda->setText(*agenda);
    ui->textEdit_dados_medico->setText(medico->dados_do_medico());
}

Medico_tela::~Medico_tela()
{
    delete ui;
}

void Medico_tela::on_pushButton_pesquisar_pasciente_clicked()
{

    //função responsável por mostrar, na tela do médico, os dados do pasciente pesquisado.
    //a funcionalidade não está pronta, programa quebra caso o médico tente pesquisar por um cpf
/**    qDebug() << "teste";
    long *cpfs = (Medico_tela::autenticado->getPascientes());
    long cpf1 = cpfs[0];
    long cpf2 = cpfs[1];
    long cpf3 = cpfs[2];
    qDebug() << "teste2";
    long in = ui->lineEdit_cpf_pasciente->text().toLong();

    if(cpf1 == in || cpf2 == in || cpf3 == in )
    {
        dwp::Atendente tmp{};
        QString tmp3 = tmp.buscar_usuario(in);
        dwp::Pasciente *tmp2 = tmp.buscar_pasciente(tmp3.split(',')[1].toLong());

        mp_tela = new Medico_pasciente_tela(this);
        mp_tela->show();
    }
    else
    {
        QMessageBox::warning(this, "Login"," Atenção, você não tem permição para acessar os dados desse pasciente");

    }
*/
}

void Medico_tela::set_medico(dwp::Medico *medico)
{
    Medico_tela::autenticado = medico;

}


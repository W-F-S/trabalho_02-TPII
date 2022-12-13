//#include "mainwindow.h"
/*#include "ui_mainwindow.h"
#include<atendente.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonEntrar_clicked()
{
    dwp::Atendente atendente;
    //atendente.cadastrar_atendente(&atendente);
    dwp::Sistema sis;
    int usuarioA=ui->lineEditUsuarioAtendente->text().toInt();
    int usuarioM=ui->lineEditUsuarioMedico->text().toInt();

    if(usuarioA==0)atendente.set_path(usuarioM);
    if(usuarioM==0)atendente.set_path(usuarioA);

    atendente.buscar_atendente(usuarioA);
    atendente.buscar_medico(usuarioM);
    QString textoAtendente="CPF: \n"+QString::number(atendente.getCpf())+"\n Medicos assessorados: \n"
        +QString::number(atendente.get_medicos_assessorados()[0])
        +"\n"+QString::number(atendente.get_medicos_assessorados()[1])
        +"\n"+QString::number(atendente.get_medicos_assessorados()[2]);
    ui->textEdit->setText(textoAtendente);
    ui->lineEditUsuarioAtendente->clear();
    ui->lineEditUsuarioMedico->clear();
}

*/

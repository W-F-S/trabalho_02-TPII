#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    int usuario=ui->lineEditUsuario->text().toInt();
    int senha=ui->lineEditSenha->text().toInt();
    QString textoAtendente="CPF: \n"+QString::number(atendente.getCpf())+"\n Medicos assessorados: \n"
        +QString::number(atendente.get_medicos_assessorados()[0])
        +"\n"+QString::number(atendente.get_medicos_assessorados()[1])
        +"\n"+QString::number(atendente.get_medicos_assessorados()[2]);
    ui->textEdit->setText(textoAtendente);
}


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
    Sistema sis;
int usuario=ui->lineEditUsuario->text().toInt();
int senha=ui->lineEditSenha->text().toInt();
atendente.set_path(usuario);
QString texto=atendente.verificar_usuario(usuario,senha).split(',')[1];
ui->textEdit->setText(atendente.mostrar_dados());
ui->lineEditUsuario->clear();
ui->lineEditSenha->clear();
}


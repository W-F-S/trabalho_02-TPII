#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agenda.h"
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


void MainWindow::on_pushButtonMostrar_clicked()
{
QString texto=p.getNome();
ui->textEditSaida->setText(texto);

}


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

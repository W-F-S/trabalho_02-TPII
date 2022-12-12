#ifndef CADASTRAR_ATENDENTE_H
#define CADASTRAR_ATENDENTE_H
#include "atendente.h"
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class cadastrar_atendente;
}

class cadastrar_atendente : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrar_atendente(QWidget *parent = nullptr);
    ~cadastrar_atendente();

private slots:
    void on_pushButtonCadastrar_clicked();

private:
    Ui::cadastrar_atendente *ui;
};

#endif // CADASTRAR_ATENDENTE_H

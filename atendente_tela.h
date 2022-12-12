#ifndef ATENDENTE_TELA_H
#define ATENDENTE_TELA_H

#include "atendente.h"
#include <QDialog>
#include "atendente_cadastrar_usuario.h"
#include "atendente_cadastrar_medico.h"
#include "get_agenda.h"
#include "adicionar_agenda.h"


namespace Ui {
class Atendente_tela;
}

class Atendente_tela : public QDialog
{
    Q_OBJECT

public:
    void set_atendente(dwp::Atendente *autenticado);
    explicit Atendente_tela(QWidget *parent = nullptr);
    ~Atendente_tela();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_cadastrarUsuario_clicked();

    void on_pushButton_consultarAgenda_clicked();

    void on_pushButton_3_clicked();

private:
    dwp::Atendente *autenticado;
    Atendente_cadastrar_usuario *cadastrar_pasciente;
    Atendente_cadastrar_medico *cadastrar_medico;
    get_agenda *g_agenda;
    Adicionar_agenda *a_agenda;

    Ui::Atendente_tela *ui;
};

#endif // ATENDENTE_TELA_H

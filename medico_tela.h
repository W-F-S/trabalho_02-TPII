#ifndef MEDICO_TELA_H
#define MEDICO_TELA_H
#include "get_agenda.h"
#include "medico_pasciente_tela.h"
#include "atendente.h"
#include <QMessageBox>


#include <QDialog>

namespace Ui {
class Medico_tela;
}

class Medico_tela : public QDialog
{
    Q_OBJECT

public:
    explicit Medico_tela(QWidget *parent = nullptr,dwp::Medico *medico = nullptr);
    ~Medico_tela();

    void set_medico(dwp::Medico *medico);

private slots:
  void on_pushButton_pesquisar_pasciente_clicked();

private:
    dwp::Medico *autenticado;
    get_agenda *g_agenda;
    Medico_pasciente_tela *mp_tela;

    Ui::Medico_tela *ui;
};

#endif // MEDICO_TELA_H

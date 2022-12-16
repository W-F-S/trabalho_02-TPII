#ifndef ADICIONAR_AGENDA_H
#define ADICIONAR_AGENDA_H
#include "atendente.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
  class Adicionar_agenda;
}

class Adicionar_agenda : public QDialog
{
  Q_OBJECT

  public:
    explicit Adicionar_agenda(QWidget *parent = nullptr);
    ~Adicionar_agenda();

    private slots:
      void on_pushButton_cadastrar_clicked();

  private:
    Ui::Adicionar_agenda *ui;
};

#endif // ADICIONAR_AGENDA_H

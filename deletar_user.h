#ifndef DELETAR_USER_H
#define DELETAR_USER_H

#include "atendente.h"
#include <QDialog>
#include <QMessageBox>


namespace Ui {
  class deletar_user;
}

class deletar_user : public QDialog
{
  Q_OBJECT

  public:
    explicit deletar_user(QWidget *parent = nullptr);
    ~deletar_user();

    private slots:
      void on_pushButton_deletar_clicked();

  private:
    Ui::deletar_user *ui;
};

#endif // DELETAR_USER_H

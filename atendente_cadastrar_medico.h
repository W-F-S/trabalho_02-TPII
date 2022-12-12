#ifndef ATENDENTE_CADASTRAR_MEDICO_H
#define ATENDENTE_CADASTRAR_MEDICO_H

#include <QDialog>
#include "atendente.h"

namespace Ui {
class Atendente_cadastrar_medico;
}

class Atendente_cadastrar_medico : public QDialog
{
    Q_OBJECT

public:
    explicit Atendente_cadastrar_medico(QWidget *parent = nullptr);
    ~Atendente_cadastrar_medico();

private slots:
    void on_pushButton_cadastrar_clicked();

private:
    Ui::Atendente_cadastrar_medico *ui;
};

#endif // ATENDENTE_CADASTRAR_MEDICO_H

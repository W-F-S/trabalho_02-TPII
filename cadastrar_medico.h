#ifndef CADASTRAR_MEDICO_H
#define CADASTRAR_MEDICO_H

#include <QDialog>

namespace Ui {
class cadastrar_medico;
}

class cadastrar_medico : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrar_medico(QWidget *parent = nullptr);
    ~cadastrar_medico();

private slots:
    void on_pushButtonCadastrarMedico_clicked();

private:
    Ui::cadastrar_medico *ui;
};

#endif // CADASTRAR_MEDICO_H

#ifndef ATENDENTE_CADASTRAR_USUARIO_H
#define ATENDENTE_CADASTRAR_USUARIO_H

#include <QDialog>

namespace Ui {
class Atendente_cadastrar_usuario;
}

class Atendente_cadastrar_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit Atendente_cadastrar_usuario(QWidget *parent = nullptr);
    ~Atendente_cadastrar_usuario();

private slots:
    void on_pushButton_cadastrar_clicked();

private:
    Ui::Atendente_cadastrar_usuario *ui;
};

#endif // ATENDENTE_CADASTRAR_USUARIO_H

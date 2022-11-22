#ifndef ATENDENTE_H
#define ATENDENTE_H
#include <sistema.h>
namespace dwp {


class Atendente : private sistema{
private:

    bool secretaria_geral;
    Sistema *usuario;


public:
    Atendente();

    Atendente(QString nome, int cpf, QString email, int telefone, bool secretaria_geral);

    void cadastrar_usuario(int cargo, Sistema usuario);


};
}
#endif // ATENDENTE_H

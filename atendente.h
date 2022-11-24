#ifndef ATENDENTE_H
#define ATENDENTE_H
#include <sistema.h>
namespace dwp {
class Atendente : private Sistema{
private:

    bool secretaria_geral;
    long *medicos_assessorados;
    Sistema *usuario;


public:
    Atendente();
    Atendente(Sistema *usuario, bool geral, long *medicos);
    Atendente(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, bool secretaria_geral, long *medicos);

    void cadastrar_usuario(int cargo, Sistema *usuario);
    bool cadastrar_atendente(Sistema *usuario, bool geral, long *medicos);
    bool cadastrar_atendente(Atendente *atendente);

    bool get_Secretaria_geral();
    long *get_medicos_assessorados();
    void mostrar_dados_atendente();

};
}
#endif // ATENDENTE_H

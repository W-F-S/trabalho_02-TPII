#ifndef ATENDENTE_H
#define ATENDENTE_H

#include <medico.h>
namespace dwp {
class Atendente : private Sistema
{
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


        static Atendente* get_dados_atendente(int id);


        void set_Secretaria_geral(bool resp);


        void set_Medicos_acessorados(long *cpfs);

        bool get_Secretaria_geral();
        long *get_medicos_assessorados();
        void mostrar_dados_atendente();

        bool adicionar_agenda(QString *agenda);


        QDir *set_path();
};
}
#endif // ATENDENTE_H

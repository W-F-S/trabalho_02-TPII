#ifndef ATENDENTE_H
#define ATENDENTE_H

#include <medico.h>
namespace dwp {
class Atendente : public Sistema
{
    private:
        bool secretaria_geral;
        long *medicos_assessorados;

    public:
        Atendente();
        Atendente(Sistema *usuario, bool geral, long *medicos);
        Atendente(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, bool secretaria_geral, long *medicos);

        bool get_Secretaria_geral();
        long *get_medicos_assessorados();
        void set_Secretaria_geral(bool resp);
        void set_Medicos_acessorados(long *cpfs);
        Atendente* buscar_atendente(int id);
        Medico* buscar_medico(int id);
        bool deletar_usuario(int id);

        QTextStream* cadastrar_usuario(Sistema* usuario);
        bool cadastrar_atendente(Sistema *usuario, bool geral, long *medicos);
        bool cadastrar_atendente(Atendente *atendente);
        bool cadastrar_medico(Medico *medico);

        QString adicionar_agenda(QString *agenda);
        QString adicionar_lista_usuarios(int tipo, int id,  long cpf, QString senha);

        void mostrar_dados();
        QString set_path(int id);

        QString verificar_usuario(int id);
        QString verificar_usuario(long cpf);

};
}
#endif // ATENDENTE_H

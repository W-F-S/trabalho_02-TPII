#include "atendente.h"
namespace dwp{
Atendente::Atendente()
{
    Atendente::secretaria_geral = false;
    Atendente::usuario = new Sistema();
}

Atendente::Atendente(QString nome, int cpf, QString email, int telefone, bool secretaria_geral)
{
    Atendente::secretaria_geral = secretaria_geral;
    Atendente::usuario = new Sistema(nome, cpf, email, telefone);
}


bool Atendente::cadastrar_paciente(string nome, string email, int telefone)
{

}
}

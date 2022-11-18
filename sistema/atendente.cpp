#include "atendente.h"

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


void Atendente::cadastrar_usuario(string nome, Sistema usuario)
{

    string localpath = "";
    if(nome == "Secretaria" && !Atendente::secretaria_geral)
    {
        cout<< "Erro, este usuário não tem permissão para criar um usuário" << endl;
    }


    localpath = filesystem::current_path();





}

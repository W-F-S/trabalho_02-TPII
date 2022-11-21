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


void Atendente::cadastrar_usuario(int tipo, Sistema usuario)
{
    string pasta;
    //verificando o tipo de usuario a ser criado
    switch
    {
        case 0:
            pasta = "atendente";
        break;
        case 1:
            pasta = "medico";
        break;
        case 2:
            pasta = "paciente";
        break;
        default:
            cout << "erro";
            exit(1);
        break;
    }

    //apenas atendentes gerais podem criar novas atendentes
    string localpath = "";
    if(tipo == 0 && !Atendente::secretaria_geral)
    {
        cout<< "Erro, este usuário não tem permissão para criar um usuário" << endl;
    }

    localpath = filesystem::current_path(); //coletando to caminho do arquivo atual
    filesystem::create_directory(loacalpath+"/"+pasta);

}

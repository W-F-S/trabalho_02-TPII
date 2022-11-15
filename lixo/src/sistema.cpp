#include <iostream>
#include <QtCore/QString> 
#include <string>

using namespace std;

class Sistema {
  private:
    string nome;
    int cpf;
    string email;
    int telefone;
    int num_matricula;

  public:

    Sistema();

    bool realizar_autenticacao(int cargo, string email, string senha);
    void consultar_agenda_pasciente();

    //void consultar geral
    bool salvar_dados_em_arquivo();
     pegar_dados_de_arquivo();
    //void encriptar_senha
    //void desencriptar_senha
    //void verificarpermissões
};

Sistema :: Sistema()
{
    nome = "";
    cpf = 0;
    email = "";
    telefone = 0;
    num_matricula = 0;
}



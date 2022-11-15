#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <QString>
#include <string>

#include "sistema_global.h"

using namespace std;

class SISTEMA_EXPORT Sistema
{
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
  QString pegar_dados_de_arquivo();
  //void encriptar_senha
  //void desencriptar_senha
  //void verificarpermissões
};

#endif // SISTEMA_H




/**
class Atendente : private Sistema{
      private:
        string cargo;
        bool secretaria_geral;
      public:
        bool excluir_secretaria();
        bool cadastrar_paciente();

};
*/

#ifndef ATENDENTE_H
#define ATENDENTE_H
#pragma once
#include "medico.h"
#include "pasciente.h"


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
      Pasciente* buscar_pasciente(int id);
      bool deletar_usuario(int id);

      bool cadastrar_atendente(Sistema *usuario, bool geral, long *medicos);
      bool cadastrar_atendente(Atendente *atendente);
      bool cadastrar_medico(Medico *medico);

      bool cadastrar_pasciente(Pasciente *pasciente);
      void mostrar_dados();
  };
}
#endif // ATENDENTE_H

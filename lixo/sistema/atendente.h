#ifndef ATENDENTE_H
#define ATENDENTE_H

#include "sistema.h"

class atendente : private Sistema{

public:
    atendente();
    bool cadastrar_paciente(string nome, string email, int telefone, int num_matricula);
};

#endif // ATENDENTE_H

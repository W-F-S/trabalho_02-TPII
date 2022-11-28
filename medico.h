#ifndef MEDICO_H
#define MEDICO_H

#include <sistema.h>
namespace dwp
{
class Medico : public Sistema
{
    private:
       QString especialidade;
       bool particular;
       Sistema *usuario;
       long *pascientes;

    public:
       Medico();
       Medico(Sistema *usuario, QString especialidade, long *pascientes);
       Medico(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString especialidade, long *pascientes);

};
}
#endif // MEDICO_H

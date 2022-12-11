#ifndef MEDICO_H
#define MEDICO_H
#pragma once

#include <sistema.h>
namespace dwp
{
class Medico : public Sistema
{
    private:
       QString especialidade;
       bool particular;
       long crm;
       long *pascientes;

    public:
       Medico();
       Medico(Sistema *usuario, QString especialidade,  bool particular,  long crm, long *pascientes);
       Medico(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, QString especialidade,  bool particular,  long crm, long *pascientes);

       QString getEspecialidade() const;
       void setEspecialidade(const QString &newEspecialidade);
       bool getParticular() const;
       void setParticular(bool newParticular);
       long getCrm();

       void setCrm(long crm);

       long *getPascientes() const;
       void setPascientes(long *newPascientes);

       void mostrar_dados();
};
}
#endif // MEDICO_H

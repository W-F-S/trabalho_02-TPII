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
       Medico(Sistema *usuario, QString especialidade,  bool particular, long *pascientes);
       Medico(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, QString especialidade,  bool particular, long *pascientes);
       void mostrar_dados();

       QString getEspecialidade() const;
       void setEspecialidade(const QString &newEspecialidade);
       bool getParticular() const;
       void setParticular(bool newParticular);
       Sistema getUsuario() const;
       void setUsuario(Sistema *newUsuario);
       long *getPascientes() const;
       void setPascientes(long *newPascientes);


};
}
#endif // MEDICO_H

#include "medico.h"

namespace dwp
{
QString Medico::getEspecialidade() const
{
    return especialidade;
}

void Medico::setEspecialidade(const QString &newEspecialidade)
{
    especialidade = newEspecialidade;
}

bool Medico::getParticular() const
{
    return particular;
}

void Medico::setParticular(bool newParticular)
{
    particular = newParticular;
}

Sistema Medico::getUsuario() const
{
    return *usuario;
}

void Medico::setUsuario(Sistema *newUsuario)
{
    usuario = newUsuario;
}

long *Medico::getPascientes() const
{
    return pascientes;
}

void Medico::setPascientes(long *newPascientes)
{
    pascientes = newPascientes;
}

Medico::Medico()
{
    Medico::especialidade = "";
    Medico::particular = false;
    Medico::usuario = new Sistema();
    Medico::pascientes = new long[3];

}

Medico::Medico(Sistema *usuario, QString especialidade,  bool particular, long *pascientes)
{
    Medico::usuario = usuario;
    Medico::especialidade = especialidade;
    Medico::particular = particular;
    Medico::pascientes = pascientes;
}

Medico::Medico(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, QString especialidade,  bool particular, long *pascientes)
{
    Medico::usuario = new Sistema
    {
            nome,
            cpf,
            email,
            telefone,
            telefone_whatsapp,
            senha
    };
    Medico::especialidade = especialidade;
    Medico::particular = particular;
    Medico::pascientes = pascientes;
}

void Medico::mostrar_dados()
{
    cout << Medico::usuario->getNome().toStdString() << endl;
    cout << to_string(Medico::usuario->getCpf()) << endl;
    cout << Medico::usuario->getEmail().toStdString() << endl;
    cout <<  to_string(Medico::usuario->getTelefone()) << endl;
    cout <<  to_string(Medico::usuario->getTelefone_whatsapp()) << endl;
    cout << to_string(Medico::usuario->getNum_matricula()) << endl;
    cout << Medico::getEspecialidade().toStdString() << endl;
    cout << Medico::getPascientes()[0] << endl;
    cout << Medico::getPascientes()[1] << endl;
    cout << Medico::getPascientes()[2]<< endl;
}
}

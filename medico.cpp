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

long Medico::getCrm()
{
    return Medico::crm;
}

void Medico::setCrm(long crm)
{
    Medico::particular = crm;
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
    Medico::pascientes = new long[3];
}

Medico::Medico(Sistema *usuario, QString especialidade,  bool particular, long crm, long *pascientes)
{
    Sistema::setNome(usuario->getNome());
    Sistema::setCpf(usuario->getCpf());
    Sistema::setEmail(usuario->getEmail());
    Sistema::setTelefone(usuario->getTelefone());
    Sistema::setTelefone_whatsapp(usuario->getTelefone_whatsapp());
    Sistema::setNum_matricula(usuario->getNum_matricula());
    Sistema::setSenha(usuario->getSenha());
    Medico::especialidade = especialidade;
    Medico::particular = particular;
    Medico::crm = crm;

    Medico::pascientes = pascientes;
}

Medico::Medico(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, QString especialidade,  bool particular, long crm, long *pascientes)
{
    Sistema::setNome(nome);
    Sistema::setCpf(cpf);
    Sistema::setEmail(email);
    Sistema::setTelefone(telefone);
    Sistema::setTelefone_whatsapp(telefone_whatsapp);
    Sistema::setSenha(senha);
    Medico::especialidade = especialidade;
    Medico::particular = particular;
    Medico::crm = crm;
    Medico::pascientes = pascientes;
}

QString Medico::mostrar_dados()
{
    QString texto= Medico::getNome()+"\n"+
    Medico::getCpf()+"\n"+
    Medico::getEmail()+"\n"+
    Medico::getTelefone()+"\n"+
    Medico::getTelefone_whatsapp()+"\n"+
    Medico::getNum_matricula()+"\n"+
     Medico::getEspecialidade()+"\n"+
    Medico::getPascientes()[0]+"\n"+
    Medico::getPascientes()[1]+"\n"+
    Medico::getPascientes()[2];

}
}

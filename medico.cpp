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
    Sistema::setNum_matricula(Sistema::gerar_num_matricula());
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

void Medico::mostrar_dados()
{
    std::cout << Medico::getNome().toStdString() << endl;
    std::cout << std::to_string(Medico::getCpf()) << endl;
    std::cout << Medico::getEmail().toStdString() << endl;
    std::cout <<  std::to_string(Medico::getTelefone()) << endl;
    std::cout <<  std::to_string(Medico::getTelefone_whatsapp()) << endl;
    std::cout << std::to_string(Medico::getNum_matricula()) << endl;
    std::cout << Medico::getEspecialidade().toStdString() << endl;
    std::cout << Medico::getPascientes()[0] << endl;
    std::cout << Medico::getPascientes()[1] << endl;
    std::cout << Medico::getPascientes()[2]<< endl;
}
}

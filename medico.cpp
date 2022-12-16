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

/**
 * Função que mostra os dados do médico na tela
 * @brief Medico::mostrar_dados
 */
void Medico::mostrar_dados()
{
    qDebug() << Medico::getNome() ;
    qDebug() << Medico::getCpf() ;
    qDebug() << Medico::getEmail() ;
    qDebug() <<  (Medico::getTelefone()) ;
    qDebug() <<  (Medico::getTelefone_whatsapp()) ;
    qDebug() << (Medico::getNum_matricula()) ;
    qDebug() << Medico::getEspecialidade();
    qDebug() << QString::number(Medico::getPascientes()[0]) ;
    qDebug() << QString::number(Medico::getPascientes()[1]) ;
    qDebug() << QString::number(Medico::getPascientes()[2]);
}

/**
 * Função que retorna uma QString contendo os dados do médico formatados
 * Usada na tela de login do médico
 *
 * @brief Medico::dados_do_medico
 * @return
 */
QString Medico::dados_do_medico()
{
    QString retorno =
    "Nome: " + Medico::getNome() + "\n" +
    "Cpf: "  + Medico::getCpf() + "\n" +
    "Email: "+ Medico::getEmail() + "\n" +
    "Telefone: "       + QString::number(Medico::getTelefone()) + "\n" +
    "Whatsapp: "      + QString::number(Medico::getTelefone_whatsapp()) + "\n" +
    "Codigo interno: "     + QString::number(Medico::getNum_matricula()) + "\n" +
    "Especialidade: "    + Medico::getEspecialidade() + "\n" +
    "Pascientes acessorados: "  + "\n" +
    "01: "   + QString::number(Medico::getPascientes()[0]) + "\n" +
    "02: "  + QString::number(Medico::getPascientes()[1]) + "\n" +
    "03: " + QString::number(Medico::getPascientes()[2]);
    return retorno;
}
}


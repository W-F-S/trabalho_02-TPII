#include "pasciente.h"
namespace dwp {


long Pasciente::getMedico() const
{
    return medico;
}

void Pasciente::setMedico(long newMedico)
{
    medico = newMedico;
}

bool Pasciente::getParticular() const
{
    return particular;
}

void Pasciente::setParticular(bool newParticular)
{
    particular = newParticular;
}

QString Pasciente::getConvenio() const
{
    return convenio;
}

void Pasciente::setConvenio(const QString &newConvenio)
{
    if(Pasciente::particular)
    {
        convenio = newConvenio;
    }
}

Pasciente::Pasciente()
{
    Pasciente::particular = false;
    Pasciente::medico = 00000000000;
    Pasciente::convenio = "";
}

Pasciente::Pasciente(Sistema *usuario, long medico, bool particular, QString convenio)
{
    Pasciente::particular = particular;
    Pasciente::medico = medico;
    Pasciente::convenio = convenio;
    Sistema::setNome(usuario->getNome());
    Sistema::setCpf(usuario->getCpf());
    Sistema::setEmail(usuario->getEmail());
    Sistema::setTelefone(usuario->getTelefone());
    Sistema::setTelefone_whatsapp(usuario->getTelefone_whatsapp());
    Sistema::setNum_matricula(usuario->getNum_matricula());
    Sistema::setSenha(usuario->getSenha());
}

Pasciente::Pasciente(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, long medico, bool particular, QString convenio)
{
    Pasciente::particular = particular;
    Pasciente::medico = medico;
    Pasciente::convenio = convenio;

    Sistema::setNome(nome);
    Sistema::setCpf(cpf);
    Sistema::setEmail(email);
    Sistema::setTelefone(telefone);
    Sistema::setTelefone_whatsapp(telefone_whatsapp);
    Sistema::setSenha(senha);
}


/**
 * @brief Pasciente::mostrar_dados_Pasciente
 * mostra na tela todos os dados da Pasciente
 * inclusive os medicos assessorados
 */
QString Pasciente::mostrar_dados()
{
     QString texto= Pasciente::getNome() +"\n"+
     QString::number(Pasciente::getCpf()) +"\n"+
     Pasciente::getEmail()+"\n"+
     QString::number(Pasciente::getTelefone()) +"\n"+
     QString::number(Pasciente::getTelefone_whatsapp()) +"\n"+
     QString::number(Pasciente::getNum_matricula()) +"\n"+
     Pasciente::getConvenio()+"\n"+
     Pasciente::getMedico()+"\n"+
     Pasciente::getParticular();
     return texto;

}}

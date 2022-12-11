#include "pasciente.h"

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
void Pasciente::mostrar_dados()
{
    cout << Pasciente::getNome().toStdString() << endl;
    cout << to_string(Pasciente::getCpf()) << endl;
    cout << Pasciente::getEmail().toStdString() << endl;
    cout <<  to_string(Pasciente::getTelefone()) << endl;
    cout <<  to_string(Pasciente::getTelefone_whatsapp()) << endl;
    cout << to_string(Pasciente::getNum_matricula()) << endl;
    cout << (Pasciente::getConvenio().toStdString());
    cout << (Pasciente::getMedico());
    cout << (Pasciente::getParticular());

}

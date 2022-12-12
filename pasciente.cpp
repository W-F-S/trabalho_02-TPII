#include "pasciente.h"
namespace dwp
{
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
    std::cout << Pasciente::getNome().toStdString() << endl;
    std::cout << std::to_string(Pasciente::getCpf()) << endl;
    std::cout << Pasciente::getEmail().toStdString() << endl;
    std::cout <<  std::to_string(Pasciente::getTelefone()) << endl;
    std::cout <<  std::to_string(Pasciente::getTelefone_whatsapp()) << endl;
    std::cout << std::to_string(Pasciente::getNum_matricula()) << endl;
    std::cout << (Pasciente::getConvenio().toStdString());
    std::cout << (Pasciente::getMedico());
    std::cout << (Pasciente::getParticular());

}
}

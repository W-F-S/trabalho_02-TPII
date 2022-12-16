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

    Sistema::setNum_matricula(Sistema::gerar_num_matricula());

}


/**
 * @brief Pasciente::mostrar_dados_Pasciente
 * mostra na tela todos os dados da Pasciente
 * inclusive os medicos assessorados
 */
void Pasciente::mostrar_dados()
{
    qDebug() << Pasciente::getNome() ;
    qDebug() << (Pasciente::getCpf()) ;
    qDebug() << Pasciente::getEmail() ;
    qDebug() <<  (Pasciente::getTelefone()) ;
    qDebug() <<  (Pasciente::getTelefone_whatsapp()) ;
    qDebug() << (Pasciente::getNum_matricula()) ;
    qDebug() << (Pasciente::getConvenio());
    qDebug() << (Pasciente::getMedico());
    qDebug() << (Pasciente::getParticular());

}

QString Pasciente::dados_do_pasciente()
{
    QString retorno =
    "Nome: " + Pasciente::getNome() + "\n" +
    "Cpf: "  + Pasciente::getCpf() + "\n" +
    "Email: "+ Pasciente::getEmail() + "\n" +
    "Telefone: "       + QString::number(Pasciente::getTelefone()) + "\n" +
    "Whatsapp: "      + QString::number(Pasciente::getTelefone_whatsapp()) + "\n" +
    "Codigo interno: "     + QString::number(Pasciente::getNum_matricula()) + "\n" +
    "Medico responsável" + QString::number(Pasciente::getMedico()) + "\n";
    if(Pasciente::getParticular())
    {
        retorno += QString::fromStdString("Particular: sim") + "\n" +
                Pasciente::getConvenio();
    }
    else
    {
        retorno += "Particula: não";
    }
    return retorno;
}

}

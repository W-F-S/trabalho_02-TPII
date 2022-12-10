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

}

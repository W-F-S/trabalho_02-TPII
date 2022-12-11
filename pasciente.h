#ifndef PASCIENTE_H
#define PASCIENTE_H

#pragma once

#include <sistema.h>

class Pasciente: public Sistema
{
    private:
        long medico;
        bool particular;
        QString convenio;
public:
    Pasciente();
    Pasciente(Sistema *usuario, long medico, bool particular, QString convenio);
    Pasciente(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, long medico, bool particular, QString convenio);

    long getMedico() const;
    void setMedico(long newMedico);
    bool getParticular() const;
    void setParticular(bool newParticular);
    QString getConvenio() const;
    void setConvenio(const QString &newConvenio);

    void mostrar_dados();

};

#endif // PASCIENTE_H

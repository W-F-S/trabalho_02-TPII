#ifdef _WIN32
#include <direct.h>
#endif

#ifndef SISTEMA_H
#define SISTEMA_H

#include "sistema_global.h"
#include <QString>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include <QDir>

#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

class SISTEMA_EXPORT Sistema
{
private:
    QString nome;
     //filesystem::current_path(); //coletando to caminho do arquivo atual

    int cpf;
    QString email;
    int telefone;
    int telefone_whatsapp;
    int num_matricula;

    int gerar_num_matricula();
public:
    QDir working_path{};

    Sistema();
    Sistema(QString nome, int cpf, QString email, int telefone);
    bool realizar_autenticacao(int cargo, QString email, QString senha);
    void consultar_agenda_paciente();


    const QString &getNome() const;
    void setNome(const QString &newNome);
    int getCpf() const;
    void setCpf(int newCpf);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    int getTelefone() const;
    void setTelefone(int newTelefone);
    int getTelefone_whatsapp() const;
    void setTelefone_whatsapp(int newTelefone_whatsapp);
    int getNum_matricula() const;
    void setNum_matricula(int newNum_matricula);
};

#endif // SISTEMA_H

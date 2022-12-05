#include <QString>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QStringList>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include <QDir>

#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

class Sistema
{
    private:
    QString nome;
     //filesystem::current_path(); //coletando to caminho do arquivo atual

    long cpf;
    QString email;
    long telefone;
    long telefone_whatsapp;
    int num_matricula;
    QString senha;

    int gerar_num_matricula();
public:
    QDir working_path{};

    Sistema();
    Sistema(Sistema*);
    Sistema(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha);
    bool realizar_autenticacao(int cargo, QString email, QString senha);
    void consultar_agenda_paciente();

    const QString &getNome() const;
    void  setNome(const QString &newNome);
    long  getCpf() const;
    void  setCpf(long newCpf);
    const QString &getEmail() const;
    void  setEmail(const QString &newEmail);
    long  getTelefone() const;
    void  setTelefone(long newTelefone);
    long  getTelefone_whatsapp() const;
    void  setTelefone_whatsapp(long newTelefone_whatsapp);
    int   getNum_matricula() const;
    void  setNum_matricula(int newNum_matricula);
    void  setSenha(QString newSenha);
    QString getSenha();

    void mostar_usuario();
};

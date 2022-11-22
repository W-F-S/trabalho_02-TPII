#ifndef SISTEMA_H
#define SISTEMA_H
#include <QString>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
namespace dwp{
class sistema
{
private:
    QString nome;
    int cpf;
    QString email;
    int telefone;
    int telefone_whatsapp;
    int num_matricula;

    int gerar_num_matricula();
public:
    Sistema();
    Sistema(QString nome, int cpf, QString email, int telefone);
    bool realizar_autenticacao(int cargo, QString email, QString senha);
    void consultar_agenda_pasciente();
};
}

#endif // SISTEMA_H

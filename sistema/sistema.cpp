#include "sistema.h"

/**
 * Gera um número sequencial baseado um número contido no arquivo "numero_de_matricula"
 * o arquivo será gerado caso o mesmo não exista.
 */
const QString &Sistema::getNome() const
{
    return nome;
}

void Sistema::setNome(const QString &newNome)
{
    nome = newNome;
}

int Sistema::getCpf() const
{
    return cpf;
}

void Sistema::setCpf(int newCpf)
{
    cpf = newCpf;
}

const QString &Sistema::getEmail() const
{
    return email;
}

void Sistema::setEmail(const QString &newEmail)
{
    email = newEmail;
}

int Sistema::getTelefone() const
{
    return telefone;
}

void Sistema::setTelefone(int newTelefone)
{
    telefone = newTelefone;
}

int Sistema::getTelefone_whatsapp() const
{
    return telefone_whatsapp;
}

void Sistema::setTelefone_whatsapp(int newTelefone_whatsapp)
{
    telefone_whatsapp = newTelefone_whatsapp;
}

int Sistema::getNum_matricula() const
{
    return num_matricula;
}

void Sistema::setNum_matricula(int newNum_matricula)
{
    num_matricula = newNum_matricula;
}

int Sistema::gerar_num_matricula(){
    int num_matricula = 1;
    string codigo;
    ifstream infile;
    ofstream outfile;

    infile.open("numero_de_matricula");
    if( !infile )
    {
//      cout << "criando arquivo de numero de matricula" << endl;
      outfile.open("numero_de_matricula");
      outfile << num_matricula;
      outfile.close();
    }
    else
    {
     getline(infile, codigo );
     num_matricula = stoi(codigo);
     num_matricula += 1;
     infile.close();
     outfile.open("numero_de_matricula"); //reescrevendo o arquivo original;
     outfile<<num_matricula;
     outfile.close();
    }
    return num_matricula;
}

Sistema::Sistema()
{
    Sistema::nome = "";
    Sistema::cpf = 0;
    Sistema::email = "";
    Sistema::telefone = 0;

}

Sistema::Sistema(QString nome, int cpf, QString email, int telefone)
{
    Sistema::nome = nome;
    Sistema::cpf = cpf;
    Sistema::email = email;
    Sistema::telefone = telefone;
    Sistema::num_matricula = gerar_num_matricula();

}

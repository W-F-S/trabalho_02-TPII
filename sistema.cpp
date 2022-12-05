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

long Sistema::getCpf() const
{
    return cpf;
}

void Sistema::setCpf(long newCpf)
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

long Sistema::getTelefone() const
{
    return telefone;
}

void Sistema::setTelefone(long newTelefone)
{
    telefone = newTelefone;
}

long Sistema::getTelefone_whatsapp() const
{
    return telefone_whatsapp;
}

void Sistema::setTelefone_whatsapp(long newTelefone_whatsapp)
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

void Sistema::setSenha(QString senha)
{
    Sistema::senha = senha;
}

QString Sistema::getSenha()
{
    return Sistema::senha;

}

int Sistema::gerar_num_matricula(){
    int num_matricula = 1;
    QFile infile("numero_de_matricula.txt") ;

    if(!infile.exists()){
        cout << "arquivo inexistente" << endl;
    }

    if( !infile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        cout << "erro ao abrir o arquivo de ids" << endl;
    }
    QTextStream in{&infile};

    num_matricula = in.readLine().toInt();
    num_matricula += 1;
    infile.close();
    infile.open(QIODevice::WriteOnly | QIODevice::Text);
    in << num_matricula;
    infile.close();
    return num_matricula;
}




Sistema::Sistema()
{
    Sistema::nome = "";
    Sistema::cpf = 0;
    Sistema::email = "";
    Sistema::telefone = 0;
    Sistema::telefone_whatsapp = 0;
    Sistema::senha = "";
}

Sistema::Sistema(Sistema *usuario)
{
    Sistema::nome = usuario->getNome();
    Sistema::cpf = usuario->getCpf();
    Sistema::email = usuario->getEmail();
    Sistema::telefone = usuario->getTelefone();
    Sistema::telefone_whatsapp = usuario->getTelefone_whatsapp();
    Sistema::num_matricula = usuario->getNum_matricula();

}

Sistema::Sistema(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha)
{
    Sistema::nome = nome;
    Sistema::cpf = cpf;
    Sistema::email = email;
    Sistema::telefone = telefone;
    Sistema::telefone_whatsapp = telefone_whatsapp;
    Sistema::num_matricula = gerar_num_matricula();
    Sistema::senha = senha;
}


void Sistema::mostar_usuario()
{
        cout << Sistema::getNome().toStdString() << endl;
        cout << to_string(Sistema::getCpf()) << endl;
        cout << Sistema::getEmail().toStdString() << endl;
        cout <<  to_string(Sistema::getTelefone()) << endl;
        cout <<  to_string(Sistema::getTelefone_whatsapp()) << endl;
        cout << to_string(Sistema::getNum_matricula()) << endl;
}

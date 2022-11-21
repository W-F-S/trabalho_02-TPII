#include "sistema.h"
namespace dwp{
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

}

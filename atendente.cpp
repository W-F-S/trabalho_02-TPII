#include "atendente.h"
namespace dwp{
Atendente::Atendente()
{
    Atendente::secretaria_geral = false;
    Atendente::usuario = new Sistema();
}

Atendente::Atendente(Sistema *usuario, bool geral, long *medicos)
{
    Atendente::medicos_assessorados = new long[3];
    Atendente::medicos_assessorados = medicos;
    Atendente::secretaria_geral = geral,
 //usuario -> mostar_usuario();
            Atendente::usuario = new Sistema{*usuario};
}

Atendente::Atendente(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, bool secretaria_geral, long *medicos)
{
    Atendente::secretaria_geral = secretaria_geral;
    Atendente::usuario = new Sistema(nome, cpf, email, telefone, telefone_whatsapp);
    Atendente::medicos_assessorados = new long[3];
    Atendente::medicos_assessorados = medicos;
}

void Atendente::cadastrar_usuario(int tipo, Sistema *usuario)
{
    //verificando o tipo de usuario a ser criado
    QDir path{};

    qDebug() << path.path();
    switch(tipo)
    {
    case 0:
        if(path.mkdir(QString::fromStdString("atendente")))
        {
            cout << "sucesso ao criar pasta atendente";
        }
        break;
    case 1:
        if(path.mkdir(QString::fromStdString("medico")))
        {
            cout << "sucesso ao criar pasta medico";
        }
        break;
    case 2:
        if(path.mkdir(QString::fromStdString("paciente")))
        {
            cout << "sucesso ao criar pasta pasciente";
        }
        break;
    default:
        cout << "erro ao tentar criar pasta de usuario" << endl;
        exit(1);
        break;
    }

    //apenas atendentes gerais podem criar novas atendentes

    if(tipo == 0 && !Atendente::secretaria_geral)
    {
        cout<< "Erro, este usuário não tem permissão para criar um usuário" << endl;
        exit(1);
    }


}

bool Atendente::cadastrar_atendente(Atendente *atendente)
{
    QDir path{};
    QString filename{"dados.txt"};
    QFile arquivo{filename};
    QTextStream in{&arquivo};



    if(!get_Secretaria_geral())
    {
        cout << "erro, você não tem permissões para cadastrar uma secretaria" << endl;
        return false;
    }

    cout << "criando pasta secretaria" << endl;

    if(path.mkpath(QString::fromStdString("atendente/")+QString::number(atendente->usuario->getNum_matricula())))
    {
        cout << "Pasta da secretaria de id:" + to_string(atendente->getNum_matricula()) + " criada" << endl;
    }
    path.setCurrent(QString::fromStdString("./atendente/")+QString::number(atendente->usuario->getNum_matricula()));
    cout << path.path().toStdString();
    if(arquivo.exists())
    {
        cout << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, gostaria de sobreescrever os dados existentes?" << endl;
        arquivo.remove();
        getchar();
    }
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "Erro ao tentar abrir o arquivo em modo de escrita" << endl;

        return false;
    }

    in << atendente->usuario->getNome()                                      + "\n" +
          QString::number(atendente->usuario->getCpf())                      + "\n" +
          atendente->usuario->getEmail()                                     + "\n" +
          QString::number(atendente->usuario->getTelefone())                 + "\n" +
          QString::number(atendente->usuario->getTelefone_whatsapp())        + "\n" +
          QString::number(atendente->usuario->getNum_matricula())            + "\n" +
          QString::number(atendente->get_Secretaria_geral())                         + "\n" +
          QString::number(atendente->get_medicos_assessorados()[0]) + "," +
          QString::number(atendente->get_medicos_assessorados()[1]) + "," +
          QString::number(atendente->get_medicos_assessorados()[2]);

    cout << "arquivo de dados da secretaria criada" << endl;
    arquivo.close();
    //)
    /**   QString dados("");
    dados.append(atendente->getNome()                                      + "\n" +
                 QString::number(atendente->getCpf())                      + "\n" +
                 atendente->getEmail()                                     + "\n" +
                 QString::number(atendente->getTelefone())                 + "\n" +
                 QString::number(atendente->getTelefone_whatsapp())        + "\n" +
                 QString::number(atendente->getNum_matricula())            + "\n" +
                 atendente->get_Secretaria_geral()                         + "\n" +
                 QString::number(atendente->get_medicos_assessorados()[0]) + "," +
                 QString::number(atendente->get_medicos_assessorados()[1]) + "," +
                 QString::number(atendente->get_medicos_assessorados()[2])
    );**/






    return true;
}

bool Atendente::get_Secretaria_geral()
{
    return Atendente::secretaria_geral;
}

long *Atendente::get_medicos_assessorados()
{
    return Atendente::medicos_assessorados;
}

void Atendente::mostrar_dados_atendente()
{
    cout << Atendente::usuario->getNome().toStdString() << endl;
    cout << to_string(Atendente::usuario->getCpf()) << endl;
    cout << Atendente::usuario->getEmail().toStdString() << endl;
    cout <<  to_string(Atendente::usuario->getTelefone()) << endl;
    cout <<  to_string(Atendente::usuario->getTelefone_whatsapp()) << endl;
    cout << to_string(Atendente::usuario->getNum_matricula()) << endl;
    cout << to_string(Atendente::get_Secretaria_geral()) << endl;
    cout << Atendente::get_medicos_assessorados()[0] << endl;
    cout << Atendente::get_medicos_assessorados()[1] << endl;
    cout << Atendente::get_medicos_assessorados()[2]<< endl;
}




}

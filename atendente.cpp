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

/**
 * Método que cadastra uma funcionaria em um arquivo, os dados cadastrados
 * são os parâmetros da funcionario
 *
 * @brief Atendente::cadastrar_atendente
 * @param atendente - atendente que deve ser cadastrada
 * @return true - caso o cadastro tenha executado com sucesso
 */
bool Atendente::cadastrar_atendente(Atendente *atendente)
{
    QDir path{};
    QString filename{"dados.txt"};
    QFile arquivo{filename};

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

    //por padrão vamos sobreescrever dados existentes
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

    QTextStream in{&arquivo};

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

    return true;
}

//TODO: temos que colocar as variaveis long em longlong já que long no c++ vai até 4294967295

Atendente* Atendente::get_dados_atendente(int id)
{
    QDir path{};
    QString filename{"dados.txt"};
    QFile arquivo{filename};
    Atendente *retornar = new Atendente();
    bool ok;
    QStringList lista_acessorados;
    long *cpfs = new long[3];

    if(!path.exists("atendente/"+QString::number(id))){
        cout << "Atenção. Pasta \"Atendentes\" inexistente ou atendente de id:" << id << "não existe." << endl;
        exit(1);
    }

    if(!path.setCurrent(QString::fromStdString("./atendente/")+QString::number(id)))
    {
        cout << "Erro ao tentar abrir a pasta da funcionaria" << endl;
        exit(1);
    }

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout << "Erro ao tentar abrir o arquivo em modo de leitura" << endl;
        exit(1);
        //return false;
    }
    QTextStream in{&arquivo};

    retornar->usuario->setNome(in.readLine());

    retornar->usuario->setCpf(in.readLine().toLong());
    retornar->usuario->setEmail(in.readLine());
    retornar->usuario->setTelefone(in.readLine().toLong());
    retornar->usuario->setTelefone_whatsapp(in.readLine().toLong());
    retornar->usuario->setNum_matricula(in.readLine().toInt(&ok, 10));
    retornar->set_Secretaria_geral(in.readLine().toInt(&ok, 2));

    lista_acessorados = in.readLine().split(',');
    cpfs[0] = lista_acessorados[0].toLong();
    cpfs[1] = lista_acessorados[1].toLong();
    cpfs[2] = lista_acessorados[2].toLong();
    retornar->set_Medicos_acessorados(cpfs);

    arquivo.close();
    return retornar;
}

//bool Atendente::exist()

bool Atendente::get_Secretaria_geral()
{
    return Atendente::secretaria_geral;
}

void Atendente::set_Secretaria_geral(bool resp)
{
    Atendente::secretaria_geral = resp;
}


long *Atendente::get_medicos_assessorados()
{
    return Atendente::medicos_assessorados;
}

void Atendente::set_Medicos_acessorados(long *resp)
{
    Atendente::medicos_assessorados = resp;
}

/**
 * @brief Atendente::mostrar_dados_atendente
 * mostra na tela todos os dados da atendente
 * inclusive os medicos assessorados
 */
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

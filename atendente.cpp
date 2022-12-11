#include "atendente.h"
//visando suporte para windows, devemos usar fromNativeSeparators() e toNativeSeparators().
//será necessário implementar algum tipo de exception no código
//TODO: temos que colocar as variaveis long em longlong já que long no c++ vai até 4294967295

namespace dwp{
Atendente::Atendente()
{
    Atendente::secretaria_geral = false;
    Atendente::medicos_assessorados = new long[3];

}

Atendente::Atendente(Sistema *usuario, bool geral, long *medicos)
{
    Atendente::medicos_assessorados = new long[3];
    Atendente::medicos_assessorados = medicos;
    Atendente::secretaria_geral = geral,
    Sistema::setNome(usuario->getNome());
    Sistema::setCpf(usuario->getCpf());
    Sistema::setEmail(usuario->getEmail());
    Sistema::setTelefone(usuario->getTelefone());
    Sistema::setTelefone_whatsapp(usuario->getTelefone_whatsapp());
    Sistema::setNum_matricula(usuario->getNum_matricula());
    Sistema::setSenha(usuario->getSenha());

}

Atendente::Atendente(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, bool secretaria_geral, long *medicos)
{
    Atendente::secretaria_geral = secretaria_geral;
    Atendente::medicos_assessorados = new long[3];
    Atendente::medicos_assessorados = medicos;

    Sistema::setNome(nome);
    Sistema::setCpf(cpf);
    Sistema::setEmail(email);
    Sistema::setTelefone(telefone);
    Sistema::setTelefone_whatsapp(telefone_whatsapp);
    Sistema::setSenha(senha);
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
 * Método que cadastra uma funcionaria em um arquivo, os dados cadastrados
 * são os parâmetros da funcionario
 *
 * caso seja necessário mostrar paths na tela, use preferencialmente .currentPath()
 *
 * @brief Atendente::cadastrar_atendente
 * @param atendente - atendente que deve ser cadastrada
 * @return true - caso o cadastro tenha executado com sucesso
 */
bool Atendente::cadastrar_atendente(Atendente *atendente)
{
    int id = atendente->getNum_matricula();
    QDir path{};
    QString raiz = path.absolutePath();
    QString folder = "atendente/";
    QString filename{"dados.txt"};
    QFile arquivo{filename};

    if(!get_Secretaria_geral())
    {
        qCritical() << "Erro, você não tem permissões para cadastrar uma secretaria";
        return false;
    }
    if(path.mkpath(folder+QString::number(id)))
    {
        qDebug() << "Pasta da secretaria de id:" + QString::number(id) + " criada";
    }
    path.setCurrent(folder+QString::number(id));

    //por padrão vamos sobreescrever dados existentes
    if(arquivo.exists())
    {
        qCritical() << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual";
        getchar();
    }                 //writeOnly por padrão sobreescreve os arquivos
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical() << "Erro ao tentar abrir o arquivo em modo de escrita";
        path.setCurrent(raiz);
        return false;
    }

    QTextStream in{&arquivo};

    in << atendente->getNome()                               + "\n" +
          QString::number(atendente->getCpf())               + "\n" +
          atendente->getEmail()                              + "\n" +
          QString::number(atendente->getTelefone())          + "\n" +
          QString::number(atendente->getTelefone_whatsapp()) + "\n" +
          QString::number(atendente->getNum_matricula())     + "\n" +
          (atendente->getSenha())                                     + "\n" +
          QString::number(atendente->get_Secretaria_geral())          + "\n" +
          QString::number(atendente->get_medicos_assessorados()[0])   + "," +
          QString::number(atendente->get_medicos_assessorados()[1])   + "," +
          QString::number(atendente->get_medicos_assessorados()[2]);
    arquivo.close();
    path.setCurrent(raiz);
    cout << "3path atual: " << path.currentPath().toStdString() << endl;
    Sistema::adicionar_lista_usuarios(0,  atendente->getNum_matricula(), atendente->getCpf(), atendente->getSenha() );
    return true;
}

/**
 * @brief Atendente::cadastrar_medico
 * @param medico
 * @return
 */
bool Atendente::cadastrar_medico(Medico *medico)
{
    QDir path{};
    QString raiz = path.absolutePath();
    QString folder_name = "medico/";
    QString filename{"dados.txt"};
    QFile arquivo{filename};
    int id = medico->getNum_matricula();

    if(!Atendente::get_Secretaria_geral())
    {
        qCritical() << "erro, você não tem permissões para cadastrar um médico";
        return false;
    }
    if(path.mkpath(folder_name + QString::number(id)))
    {
        qDebug() << "Pasta do médico de id: " + QString::number(id) + "criada";
    }

    path.setCurrent(folder_name + QString::number(id));

    //por padrão vamos sobreescrever dados existentes
    if(arquivo.exists())
    {
        qCritical() << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual";
        getchar();
    }                 //writeOnly por padrão sobreescreve os arquivos
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical() << "Erro ao tentar abrir o arquivo em modo de escrita";
        path.setCurrent(raiz);
        return false;
    }

    QTextStream in{&arquivo};
    in <<  medico->getNome()                               + "\n" +
           QString::number(medico->getCpf())               + "\n" +
           medico->getEmail()                              + "\n" +
           QString::number(medico->getTelefone())          + "\n" +
           QString::number(medico->getTelefone_whatsapp()) + "\n" +
           QString::number(medico->getNum_matricula())     + "\n" +
           medico->getSenha()                              + "\n" +
           medico->getEspecialidade()                      + "\n" +
           medico->getCrm()                                + "\n" +
           medico->getParticular()                         + "\n" +
           QString::number(medico->getPascientes()[0])     + "," +
           QString::number(medico->getPascientes()[1])     + "," +
           QString::number(medico->getPascientes()[2]);
    qDebug() << "cadastro do medico completo";

    arquivo.close();
    path.setCurrent(raiz);
    Sistema::adicionar_lista_usuarios(1, id, medico->getCpf(), medico->getSenha() );
    return true;
}



bool Atendente::cadastrar_pasciente(Pasciente *pasciente)
{
    QDir path{};
    QString raiz = path.absolutePath();
    QString folder_name = "pasciente/";
    QString filename{"dados.txt"};
    QFile arquivo{filename};
    int id = pasciente->getNum_matricula();


    if(path.mkpath(folder_name + QString::number(id)))
    {
        qDebug() << "Pasta do pasciente de id: " + QString::number(id) + "criada";
    }

    path.setCurrent(folder_name + QString::number(id));

    //por padrão vamos sobreescrever dados existentes
    if(arquivo.exists())
    {
        qCritical() << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual";
        getchar();
    }                 //writeOnly por padrão sobreescreve os arquivos
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical() << "Erro ao tentar abrir o arquivo em modo de escrita";
        path.setCurrent(raiz);
        return false;
    }

    QTextStream in{&arquivo};
    in <<  pasciente->getNome()                               + "\n" +
           QString::number(pasciente->getCpf())               + "\n" +
           pasciente->getEmail()                              + "\n" +
           QString::number(pasciente->getTelefone())          + "\n" +
           QString::number(pasciente->getTelefone_whatsapp()) + "\n" +
           QString::number(pasciente->getNum_matricula())     + "\n" +
           pasciente->getSenha()                              + "\n" +
           pasciente->getParticular()                      + "\n" +
           pasciente->getConvenio()                                + "\n" +
           QString::number(pasciente->getMedico());

    qDebug() << "cadastro do pasciente completo";

    arquivo.close();
    path.setCurrent(raiz);
    Sistema::adicionar_lista_usuarios(2, id, pasciente->getCpf(), pasciente->getSenha() );
    return true;
}


Atendente* Atendente::buscar_atendente(int id)
{
    QDir path{};
    QString raiz = path.absolutePath();
    QFile arquivo{"dados.txt"};
    Atendente *retornar = new Atendente();
    bool ok;
    QStringList lista_acessorados;
    long *cpfs = new long[3];

    if(!path.setCurrent(QString::fromStdString("./atendente/")+QString::number(id)))
    {
        cout << "Erro ao tentar abrir a pasta da funcionaria" << endl;
        if(!path.exists("atendente/"+QString::number(id))){
            cout << "Atenção. Pasta \"Atendentes\" inexistente ou atendente de id:" << id << "não existe." << endl;
        }
        exit(1);
    }

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout << "Erro ao tentar abrir o arquivo em modo de leitura" << endl;
        exit(1);
        //return false;
    }
    QTextStream in{&arquivo};

    retornar->setNome(in.readLine());
    retornar->setCpf(in.readLine().toLong());
    retornar->setEmail(in.readLine());
    retornar->setTelefone(in.readLine().toLong());
    retornar->setTelefone_whatsapp(in.readLine().toLong());
    retornar->setNum_matricula(in.readLine().toInt(&ok, 10));
    retornar->setSenha(in.readLine());
    retornar->set_Secretaria_geral(in.readLine().toInt(&ok, 2));
    lista_acessorados = in.readLine().split(',');
    cpfs[0] = lista_acessorados[0].toLong();
    cpfs[1] = lista_acessorados[1].toLong();
    cpfs[2] = lista_acessorados[2].toLong();
    retornar->set_Medicos_acessorados(cpfs);

    arquivo.close();
    path.setCurrent(raiz);
    return retornar;
}

bool Atendente::deletar_usuario(int id)
{
    QDir path{};
    QString raiz = path.absolutePath();
    char resp;
    QString caminho = set_path(id);

    if(caminho == "./")
    {
        qCritical() << "Atenção. Erro ao tentar encontrar usuário";
        return false;
    }

    path.setCurrent(caminho);

    cout << "Atenção, a seguinte pasta e seus dados será deleta. você está de acordo?[s/N]"<< endl;
    qDebug() << path.currentPath();
    cin >> resp;

    if(!(resp == 's'))
    {
        cout << "operação cancelada" << endl;
        return false;
    }
    if(!path.removeRecursively())
    {
        qDebug() << "Atenção. Houve algum erro ao tentar deletar a pasta";
        if(path.exists())
        {
            path.cdUp();
            qDebug() << "pastas ainda existem. Tentando novamente";
//            qDebug() << path.currentPath();
            if(!path.rmdir(QString::number(id)))
            {
                qDebug() << "Erro ao tentar deletar a pasta novamente";
            }else{
                qDebug() << "Pasta deletada";
                return true;
            }
        }
    }else
    {
        cout << "Pasta deletada" << endl;
    }
    path.setCurrent(raiz);
    Sistema::remover_lista_usuarios(id);
    return true;
}

/**
 * @brief Atendente::get_dados_medico Função que constroi um objeto Medico com base em um arquivo de dados
 * @param id - Id do medico
 * @return *Medico - Ponteiro para o objeto construido
 */
Medico* Atendente::buscar_medico(int id)
{
    QDir path{};
    QString raiz = path.absolutePath();
    QFile arquivo{"dados.txt"};
    Medico *retornar = new Medico{};
    QString especialidade;
    QStringList lista_acessorados;
    long *cpfs = new long[3];
    bool ok;

    if(!path.setCurrent(QString::fromStdString("./medico/")+QString::number(id)))
    {
        cout << "Erro ao tentar abrir a pasta do médico" << endl;
        if(!path.exists("./medico/"+QString::number(id)))
        {
            cout << "Atenção. Pasta de médicos inexistente ou médico de id:" << id << "não existe." << endl;
        }
        exit(1);
    }

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout << "Erro ao tentar abrir o arquivo em modo de leitura" << endl;
        exit(1);
        //return false;
    }
    QTextStream in{&arquivo};

    retornar->setNome(in.readLine());
    retornar->setCpf(in.readLine().toLong());
    retornar->setEmail(in.readLine());
    retornar->setTelefone(in.readLine().toLong());
    retornar->setTelefone_whatsapp(in.readLine().toLong());
    retornar->setNum_matricula(in.readLine().toInt(&ok, 10));
    retornar->setSenha(in.readLine());
    retornar->setEspecialidade(in.readLine());

    retornar->setParticular(in.readLine().toInt(&ok, 2));
    retornar->setCrm(in.readLine().toLong());
    lista_acessorados = in.readLine().split(',');
    cpfs[0] = lista_acessorados[0].toLong();
    cpfs[1] = lista_acessorados[1].toLong();
    cpfs[2] = lista_acessorados[2].toLong();
    retornar->setPascientes(cpfs);

    arquivo.close();
    path.setCurrent(raiz);
    return retornar;
}


/**
 * @brief Atendente::get_dados_medico Função que constroi um objeto Medico com base em um arquivo de dados
 * @param id - Id do medico
 * @return *Medico - Ponteiro para o objeto construido
 */
Pasciente* Atendente::buscar_pasciente(int id)
{
    QDir path{};
    QString raiz = path.absolutePath();
    QFile arquivo{"dados.txt"};
    Pasciente *retornar = new Pasciente{};
    QString especialidade;
    QStringList lista_acessorados;
    long *cpfs = new long[3];
    bool ok;

    if(!path.setCurrent(QString::fromStdString("./pasciente/")+QString::number(id)))
    {
        cout << "Erro ao tentar abrir a pasta do pasciente" << endl;
        if(!path.exists("./pasciente/"+QString::number(id)))
        {
            cout << "Atenção. Pasta de médicos inexistente ou pasciente de id:" << id << "não existe." << endl;
        }
        exit(1);
    }

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout << "Erro ao tentar abrir o arquivo em modo de leitura" << endl;
        exit(1);
        //return false;
    }
    QTextStream in{&arquivo};

    retornar->setNome(in.readLine());
    retornar->setCpf(in.readLine().toLong());
    retornar->setEmail(in.readLine());
    retornar->setTelefone(in.readLine().toLong());
    retornar->setTelefone_whatsapp(in.readLine().toLong());
    retornar->setNum_matricula(in.readLine().toInt(&ok, 10));
    retornar->setSenha(in.readLine());
    retornar->setParticular(in.readLine().toInt());
    retornar->setConvenio(in.readLine());
    retornar->setMedico(in.readLine().toLong());

    arquivo.close();
    path.setCurrent(raiz);
    return retornar;
}

/**
 * @brief Atendente::mostrar_dados_atendente
 * mostra na tela todos os dados da atendente
 * inclusive os medicos assessorados
 */
void Atendente::mostrar_dados()
{
    cout << Atendente::getNome().toStdString() << endl;
    cout << to_string(Atendente::getCpf()) << endl;
    cout << Atendente::getEmail().toStdString() << endl;
    cout <<  to_string(Atendente::getTelefone()) << endl;
    cout <<  to_string(Atendente::getTelefone_whatsapp()) << endl;
    cout << to_string(Atendente::getNum_matricula()) << endl;
    cout << to_string(Atendente::get_Secretaria_geral()) << endl;
    cout << Atendente::get_medicos_assessorados()[0] << endl;
    cout << Atendente::get_medicos_assessorados()[1] << endl;
    cout << Atendente::get_medicos_assessorados()[2]<< endl;
}


}

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

Atendente::Atendente(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, bool secretaria_geral, long *medicos)
{
    Atendente::secretaria_geral = secretaria_geral;
    Atendente::usuario = new Sistema(nome, cpf, email, telefone, telefone_whatsapp, senha);
    Atendente::medicos_assessorados = new long[3];
    Atendente::medicos_assessorados = medicos;
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
    int id = atendente->usuario->getNum_matricula();
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
    path.setCurrent(folder+QString::number(atendente->usuario->getNum_matricula()));

    //por padrão vamos sobreescrever dados existentes
    if(arquivo.exists())
    {
        qCritical() << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual" << endl;
        getchar();
    }                 //writeOnly por padrão sobreescreve os arquivos
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical() << "Erro ao tentar abrir o arquivo em modo de escrita";
        path.setCurrent(raiz);
        return false;
    }

    QTextStream in{&arquivo};

    in << atendente->usuario->getNome()                               + "\n" +
          QString::number(atendente->usuario->getCpf())               + "\n" +
          atendente->usuario->getEmail()                              + "\n" +
          QString::number(atendente->usuario->getTelefone())          + "\n" +
          QString::number(atendente->usuario->getTelefone_whatsapp()) + "\n" +
          QString::number(atendente->usuario->getNum_matricula())     + "\n" +
          (atendente->usuario->getSenha())                            + "\n" +
          QString::number(atendente->get_Secretaria_geral())          + "\n" +
          QString::number(atendente->get_medicos_assessorados()[0])   + "," +
          QString::number(atendente->get_medicos_assessorados()[1])   + "," +
          QString::number(atendente->get_medicos_assessorados()[2]);
    arquivo.close();
    path.setCurrent(raiz);
    cout << "3path atual: " << path.currentPath().toStdString() << endl;
    adicionar_lista_usuarios(0,  atendente->usuario->getNum_matricula(), atendente->usuario->getCpf(), atendente->usuario->getSenha() );
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
    Sistema usuario = medico->getUsuario();
    int id = usuario.getNum_matricula();

    if(!Atendente::get_Secretaria_geral())
    {
        qCritical() << "erro, você não tem permissões para cadastrar um médico";
        return false;
    }
    if(path.mkpath(folder_name + QString::number(id)))
    {
        qDebug() << "Pasta do médico de id: " + QString::number(id) + "criada";
    }

    path.setCurrent(folder_name + QString::number(usuario.getNum_matricula()));

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
    in <<  usuario.getNome()                               + "\n" +
           QString::number(usuario.getCpf())               + "\n" +
           usuario.getEmail()                              + "\n" +
           QString::number(usuario.getTelefone())          + "\n" +
           QString::number(usuario.getTelefone_whatsapp()) + "\n" +
           QString::number(usuario.getNum_matricula())     + "\n" +
           usuario.getSenha()                              + "\n" +
           medico->getEspecialidade()                      + "\n" +
           medico->getParticular()                         + "\n" +
           QString::number(medico->getPascientes()[0])     + "," +
           QString::number(medico->getPascientes()[1])     + "," +
           QString::number(medico->getPascientes()[2]);
    qDebug() << "cadastro do medico completo";

    arquivo.close();
    path.setCurrent(raiz);
    adicionar_lista_usuarios(1, usuario.getNum_matricula(), usuario.getCpf(), usuario.getSenha() );
    return true;
}

//TODO: temos que colocar as variaveis long em longlong já que long no c++ vai até 4294967295
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

    retornar->usuario->setNome(in.readLine());
    retornar->usuario->setCpf(in.readLine().toLong());
    retornar->usuario->setEmail(in.readLine());
    retornar->usuario->setTelefone(in.readLine().toLong());
    retornar->usuario->setTelefone_whatsapp(in.readLine().toLong());
    retornar->usuario->setNum_matricula(in.readLine().toInt(&ok, 10));
    retornar->usuario->setSenha(in.readLine());
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

/**bool Atendente::deletar_atendente(int id)
{

}*/


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
    Medico *retornar;
    Sistema *usuario = new Sistema();
    QString especialidade;
    bool particular;
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

    usuario->setNome(in.readLine());
    usuario->setCpf(in.readLine().toLong());
    usuario->setEmail(in.readLine());
    usuario->setTelefone(in.readLine().toLong());
    usuario->setTelefone_whatsapp(in.readLine().toLong());
    usuario->setNum_matricula(in.readLine().toInt(&ok, 10));
    usuario->setSenha(in.readLine());
    especialidade = in.readLine();
    particular = in.readLine().toInt(&ok, 2);
    lista_acessorados = in.readLine().split(',');
    cpfs[0] = lista_acessorados[0].toLong();
    cpfs[1] = lista_acessorados[1].toLong();
    cpfs[2] = lista_acessorados[2].toLong();

    retornar = new Medico{usuario,especialidade, particular, cpfs};

    arquivo.close();
    path.setCurrent(raiz);
    return retornar;
}


/**
 * @brief Atendente::adicionar_agenda Função que adiciona algum texto na agenda do funcionario.
 * @param agenda - dados que devem ser adicionados a agenda do usuário
 * @return QString - " " caso não seja possível criar agenda
 */
QString Atendente::adicionar_agenda(QString *agenda)
{
    QFile arquivo{"agenda.txt"};

    if(!arquivo.exists())
    {
        cout << "Atenção. Agenda da atendente não existe. Criando arquivo..." << endl;
    }
    if (!arquivo.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        cout << "Erro ao criar arquivo;" << endl;
        return " ";
    }
    QTextStream in{&arquivo};
    while(!arquivo.atEnd())
    {
         in.seek(EOF);
    }
    in << + "[\n"
          + *agenda
          + "\n]";
    arquivo.close();
    return "true";
}

/**
 * @brief Atendente::adicionar_lista_usuarios Função que adiciona tipo, cpf e senha de um usuário em um arquivc auxiliar
 * @param tipo - tipo de usuario. 0 atendente, 1 medico, 2 pasciente
 * @param cpf
 * @param senha
 * @return
 */
QString Atendente::adicionar_lista_usuarios(int tipo, int id,long cpf, QString senha)
{
    QFile arquivo{"lista_usuarios.txt"};
    if(!arquivo.exists())
    {
        cout << "arquivo de dados não existente" << endl;
    }

    if (!arquivo.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        cout << "Erro ao tentar criar o aquivo" << endl;
        return " ";
    }

    QTextStream in{&arquivo};
    while(!in.atEnd())
    {
        in.readLine();
    }

    in << tipo << "," << id << "," << cpf << "," << senha << "\n";
    arquivo.close();
    return "true";
}

/**
 * @brief Atendente::verificar_usuario Função que verifica se o usuário está cadastrado no sistema
 * @param cpf - cpf do usuário a ser pesquisado
 * @return dados QString contendo tipo, id, cpf, senha do funcionario cadastrado, separados por vírgulas e sem espaços
 * @return "" caso o usuário não tenha sido encontrado
 */
QString Atendente::verificar_usuario(long cpf)
{
    QFile arquivo{"lista_usuarios.txt"};
    QString dados;
    bool contains = false;

    if(!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << "Erro ao tentar abrir o arquivo" << arquivo.fileName();
        if(!arquivo.exists())
        {
            qCritical() << "Erro, arquivo" << arquivo.fileName() << "não existe";
            return "";
        }
        return "";
    }
    QTextStream in{&arquivo};

    while(!contains && !in.atEnd())
    {
        dados = in.readLine();
        if(dados.contains(QString::number(cpf)))
        {
            qDebug() << "Usuário:\n" << dados << "\nencontrado";
            contains = true;
        }
    }
    arquivo.close();
    return dados;
}

/**
 * @brief Atendente::verificar_usuario Função que verifica se o usuário está cadastrado no sistema
 * @param id - id do usuário
 * @return dados QString contendo tipo, id, cpf, senha do funcionario cadastrado, separados por vírgulas e sem espaços
 * @return "" caso o usuário não tenha sido encontrado
 */
QString Atendente::verificar_usuario(int id,int senha)
{
    QFile arquivo{"lista_usuarios.txt"};
    QString dados;
    bool contains = false;

    if(!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << "Erro ao tentar abrir o arquivo" << arquivo.fileName();
        if(!arquivo.exists())
        {
            qCritical() << "Erro, arquivo" << arquivo.fileName() << "não existe";
            return "";
        }
        return "";
    }
    QTextStream in{&arquivo};

    while(!contains && !in.atEnd())
    {
        dados = in.readLine();
        if(dados.contains(QString::number(id)+","))
        {
            qDebug() << "Usuário:\n" << dados << "\nencontrado";
            contains = true;
        }
    }
    while(!contains && !in.atEnd())
    {
        dados = in.readLine();
        if(dados.contains(QString::number(senha)+","))
        {
            qDebug() << "Usuário:\n" << dados << "\nencontrado";
            contains = true;
        }
    }
    arquivo.close();
    return dados;
}

/**
 * @brief Atendente::mostrar_dados_atendente
 * mostra na tela todos os dados da atendente
 * inclusive os medicos assessorados
 */
QString Atendente::mostrar_dados()
{
    Atendente u;
    QString texto = u.getNome() + "\n" + QString::number(u.getCpf()) + "\n"+u.getEmail() + "\n" +
            QString::number(u.getTelefone()) + "\n"+QString::number(u.getTelefone_whatsapp()) + "\n" +
            QString::number(u.getNum_matricula()) + "\n" + u.get_Secretaria_geral() + "\n" +
            QString::number(u.get_medicos_assessorados()[0]) + "\n" + QString::number(u.get_medicos_assessorados()[1])
            + "\n" + QString::number(u.get_medicos_assessorados()[2]);
    return texto;
}

/**
 * @brief Atendente::set_path Função que retorna o absolute path do funcionario
 * @return path do id da funcionaria.
 */
QString Atendente::set_path(int id)
{
    QDir *path = new QDir();

    QString dados = verificar_usuario(id);
    QString pasta;

    switch(dados.split(',')[0].toInt())
    {
        case 0:
            pasta = "atendente";
        break;
        case 1:
            pasta = "medico";
        break;
        case 2:
            pasta = "usuario";
        break;
    }
    //vericando se a pasta de nome(id) existe e se consigo acessar a pasta
    if(!path->absolutePath().contains(pasta + "/" + QString::number(id)) && !path->setCurrent(pasta + QString::number(id)))
    {
        qCritical() << "Path atual: " << path->absolutePath();
        qCritical() << "Atenção. Pasta " << pasta << " inexistente ou atendente de id:" << id << "não existe.";
        return "./";
    }
    qDebug() << path->absolutePath();
    return path->absolutePath();
}

}

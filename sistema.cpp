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

/**
 * @brief Atendente::adicionar_agenda Função que adiciona algum texto na agenda do funcionario.
 * @param agenda - dados que devem ser adicionados a agenda do usuário
 * @return QString - " " caso não seja possível criar agenda
 */
QString Sistema::adicionar_agenda( int id, QString *agenda)
{
    QFile arquivo{"agenda.txt"};
    QDir path{};
    QString path_usuario = Sistema::set_path(id);
    cout << "passando do set_path";
    if(path_usuario == "")
    {
        qCritical() << "Erro ao tentar pegar o path do usuario";
        return "";
    }

    path.setCurrent(path_usuario);

    if(!arquivo.exists())
    {
        qCritical() << "Atenção. Agenda do usuario não existe. Criando arquivo...";
    }
    if (!arquivo.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qCritical() << "Erro ao ler o arquivo;";
        return " ";
    }
    QTextStream in{&arquivo};
    while(!arquivo.atEnd())
    {
         in.readLine();
    }
    in << + "[\n"
          + *agenda
          + "\n]";
    arquivo.close();
    qDebug() << "Agenda escrita com sucesso.";
    return "true";
}

/**
 * @brief Sistema::adicionar_lista_usuarios Função que adiciona tipo, cpf e senha de um usuário em um arquivc auxiliar
 * @param tipo - tipo de usuario. 0 atendente, 1 medico, 2 pasciente
 * @param cpf
 * @param senha
 * @return
 */
QString Sistema::adicionar_lista_usuarios(int tipo, int id,long cpf, QString senha)
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


QString *Sistema::get_agenda(int id)
{
    QFile arquivo{"agenda.txt"};
    QDir path{};
    QString *agenda = new QString{""};

    path.setCurrent(Sistema::set_path(id));

    if(!arquivo.exists())
    {
        qCritical() << "Atenção. Agenda do usuario não existe";
        return agenda;
    }
    if (!arquivo.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qCritical() << "Erro ao criar arquivo";
        return agenda;
    }
    QTextStream in{&arquivo};
    *agenda = in.readAll();
    arquivo.close();
    return agenda;
}


bool Sistema::remover_lista_usuarios(int id)
{
    QFile arquivo{"lista_usuarios.txt"};
    QString tmp = "";
    QString dados = "";
    if(!arquivo.exists())
    {
        cout << "arquivo de dados não existente" << endl;
    }

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout << "Erro ao tentar criar o aquivo" << endl;
        return false;
    }

    QTextStream in{&arquivo};
    while(!in.atEnd())
    {
        tmp = in.readLine();
        if(tmp.split(',')[1].toInt() == id)
                continue;
        dados += tmp + "\n";
    }

    //removendo extra "\n" desnecessário
    //dados.remove(dados.size()-2, dados.size()-1);
    arquivo.close();

    //abrindo o arquivo novamente, dessa vez sobreescrevendo os dados
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "Erro ao tentar criar o aquivo" << endl;
        return false;
    }

    in << dados;

    arquivo.close();
    return true;
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

/**
 * @brief Sistema::buscar_usuario
 * Função que verifica se o usuário está cadastrado no sistema
 * @param cpf - cpf do usuário a ser pesquisado
 * @return dados QString contendo tipo, id, cpf, senha do funcionario cadastrado, separados por vírgulas e sem espaços
 * @return "" caso o usuário não tenha sido encontrado
 */
QString Sistema::buscar_usuario(long cpf)
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
    if(!contains)
            dados = "";
    arquivo.close();
    return dados;
}

/**
 * @brief Atendente::buscar_usuario Função que verifica se o usuário está cadastrado no sistema
 * @param id - id do usuário
 * @return dados QString contendo tipo, id, cpf, senha do funcionario cadastrado, separados por vírgulas e sem espaços
 * @return "" caso o usuário não tenha sido encontrado
 */
QString Sistema::buscar_usuario(int id)
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
        if(dados.split(',')[1].toInt() == id)
        {
            qDebug() << "Usuário:\n" << dados << "\nencontrado";
            contains = true;
        }
    }
    if(!contains)
        dados = "";

    arquivo.close();
    return dados;
}

/**
 * @brief Atendente::set_path Função que retorna o absolute path do funcionario
 * @return path do id da funcionaria.
 */
QString Sistema::set_path(int id)
{
    QDir *path = new QDir();

    QString dados = buscar_usuario((int) id);
    QString pasta;
    bool ok;


    qCritical() << dados.split(',')[0].toInt(&ok, 10);
    //verificando o tipo de usuário
    switch(dados.split(',')[0].toInt(&ok, 10))
    {
        case 0:
            pasta = "atendente";
        break;

        case 1:
            pasta = "medico";
        break;

        case 2:
            pasta = "pasciente";
        break;
    }

    //vericando se a pasta de nome(id) existe e se consigo acessar a pasta
    qDebug() << pasta << "/" << id;
    if(path->absolutePath().contains("./" + pasta + "/" + QString::number(id)))
    {
        cout << "pasta_existe";
    }else{
        if(path->absolutePath().contains(pasta))
        {
            qCritical() << "Path atual:" << path->absolutePath();
            qCritical() << "Atenção, você está em uma pasta de usuário. Subindo um nível";
            while(path->absolutePath().contains(pasta))
            {
                qCritical() << "Path atual:" << path->absolutePath();
                path->cdUp();
            }
        }
    }

   if(!path->setCurrent(pasta+"/"+QString::number(id)))
    {
        qCritical() << path->currentPath();
        qCritical() << "Erro ao tentar abrir a pasta do" << pasta << "de id:" << id;
        return "";
    }
    qCritical() << path->currentPath();
    return path->currentPath();
}

/**
 * Não está completa
 * Função para reduzir a quantidade e a repetivivdade de codigo na classe Atendente.
* @brief Atendente::cadastrar_usuario Cadastra usuarios independente do tipo deles, 
* @param tipo - tipo de usuario a ser cadastrado
* @param usuario - copia do objeto 'usuario' da classe
*/
void Atendente::cadastrar_usuario(int tipo, Sistema usuario)
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
 * caso seja necessário mostrar paths na tela, use preferencialmente .currentPath()
 *
 * @brief Atendente::cadastrar_atendente
 * @param atendente - atendente que deve ser cadastrada
 * @return true - caso o cadastro tenha executado com sucesso
 */
bool Atendente::cadastrar_atendente(Atendente *atendente)
{
    QDir path{};
    QString raiz = path.absolutePath();
    QString folder = "atendente/";
    QString filename{"dados.txt"};
    QFile arquivo{filename};

//   cout << "1path atual: " << path.currentPath().toStdString() << endl;
    if(!get_Secretaria_geral())
    {
        cout << "erro, você não tem permissões para cadastrar uma secretaria" << endl;
        return false;
    }
    if(path.mkpath(folder+QString::number(atendente->usuario->getNum_matricula())))
    {
        cout << "Pasta da secretaria de id:" + to_string(atendente->usuario->getNum_matricula()) + " criada" << endl;
    }
    path.setCurrent(folder+QString::number(atendente->usuario->getNum_matricula()));

    //por padrão vamos sobreescrever dados existentes
    if(arquivo.exists())
    {
        cout << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual" << endl;
        getchar();
    }                 //writeOnly por padrão sobreescreve os arquivos
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "Erro ao tentar abrir o arquivo em modo de escrita" << endl;
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
    adicionar_lista_usuarios(0, atendente->usuario->getCpf(), atendente->usuario->getSenha() );
    return true;
}












//
//função para economizar codigo, atribuindo a tarefa de cadastrar usuarios no sistema a outra classe
//posso fazer isso sem ter que retornar o ponteiro, mas terei que abrir o arquivo duas vezes e fazer umseek para chegar no final dele.
//
//
//posso cadastrar o funcionario (medico, atendente etc) primeiro e depois inserir o Sistema::usuario no arquivo, já que por padrão o ponteiro do arquivo fica no começo do arquivo.
QTextStream* cadastrar_usuario(Sistema* usuario)
{
    QFile arquivo{"dados.txt"};

    if(arquivo.exists())
    {
        cout << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual" << endl;
        getchar();
    }
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qFatal("Erro ao tentar abrir o arquivo em modo de escrita");

    }


    QTextStream *in = new QTextStream{&arquivo};

    *in << usuario->getNome()                               + "\n" +
          QString::number(usuario->getCpf())               + "\n" +
          usuario->getEmail()                              + "\n" +
          QString::number(usuario->getTelefone())          + "\n" +
          QString::number(usuario->getTelefone_whatsapp()) + "\n" +
          QString::number(usuario->getNum_matricula())     + "\n" +
          usuario->getSenha()                              + "\n";

    return in;
}

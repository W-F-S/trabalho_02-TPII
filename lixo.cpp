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



         * @brief Atendente::cadastrar_medico
         * @param medico
         * @return

        template <typename T>
        bool cadastrar_usuario(int flag, T *usuario)
        {
            QDir path{};
            QString raiz = path.absolutePath();
            QString folder_name;
            QString filename{"dados.txt"};
            QFile arquivo{filename};
            QString dados = "";

            int id = usuario->getNum_matricula();

            dados = usuario->getNome()                            + "\n" +
                    QString::number(usuario->getCpf())               + "\n" +
                    usuario->getEmail()                              + "\n" +
                    QString::number(usuario->getTelefone())          + "\n" +
                    QString::number(usuario->getTelefone_whatsapp()) + "\n" +
                    QString::number(usuario->getNum_matricula())     + "\n" +
                    usuario->getSenha()                              + "\n";

            switch(flag)
            {
                case 0:
                    folder_name = "atendente/";
                    if(!Atendente::get_Secretaria_geral())
                    {
                        qCritical() << "erro, você não tem permissões para cadastrar um médico";
                        return false;
                    }
                    dados += QString::number(usuario->get_Secretaria_geral())          + "\n" +
                             QString::number(usuario->get_medicos_assessorados()[0])   + "," +
                             QString::number(usuario->get_medicos_assessorados()[1])   + "," +
                             QString::number(usuario->get_medicos_assessorados()[2]);
                break;

                case 1:
                    folder_name = "medico/";
                    dados += usuario->getEspecialidade()                      + "\n" +
                             usuario->getCrm()                                + "\n" +
                             usuario->getParticular()                         + "\n" +
                             QString::number(usuario->getPascientes()[0])     + "," +
                             QString::number(usuario->getPascientes()[1])     + "," +
                             QString::number(usuario->getPascientes()[2]);
                break;

                case 2:
                    folder_name = "usuario/";
                break;
            }


            if(path.mkpath(folder_name + QString::number(id)))
            {
                qDebug() << "Pasta do \" " + folder_name + " \" de id:"+ QString::number(id) + "criada";
            }

            path.setCurrent(folder_name + QString::number(id));

            //por padrão vamos sobreescrever dados existentes
            if(arquivo.exists())
            {
                qCritical() << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual";
                getchar();
            }
            //writeOnly por padrão sobreescreve os arquivos
            if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                qCritical() << "Erro ao tentar abrir o arquivo em modo de escrita";
                path.setCurrent(raiz);
                return false;
            }

            QTextStream in{&arquivo};
            in << dados;
            arquivo.close();

            qDebug() << "cadastro do medico completo";

            path.setCurrent(raiz);
            adicionar_lista_usuarios(flag, id, usuario->getCpf(), usuario->getSenha());
            return true;






















/**
 * Método que cadastra uma funcionaria em um arquivo, os dados cadastrados
 * são os parâmetros da funcionario
 * 
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

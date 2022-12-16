#include "atendente.h"
//visando suporte para windows, devemos usar fromNativeSeparators() e toNativeSeparators().
//será necessário implementar algum tipo de exception no código
//caso seja necessário mostrar paths na tela, use preferencialmente .currentPath()

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
    Sistema::setNum_matricula(Sistema::gerar_num_matricula());

  }

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
   * Método que cadastra uma funcionaria em um arquivo
   * Uma pasta com o id da atendente será criada, juntamente com um arquivo .txt contendo os dados da atendente cadastrada.
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

    if(path.mkpath(folder+QString::number(id)))
    {
      qDebug() << "Pasta da secretaria de id:" + QString::number(id) + " criada";
    }
    path.setCurrent(folder+QString::number(id));

    //por padrão vamos sobreescrever dados existentes
    if(arquivo.exists())
    {
      qCritical() << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual";
    } 

    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
      qCritical() << "Erro ao tentar abrir o arquivo em modo de escrita";
      //voltando a raiz do sistema
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
    Sistema::adicionar_lista_usuarios(0,  atendente->getNum_matricula(), atendente->getCpf(), atendente->getSenha() );
    return true;
  }

  /**
   * Função que cadastra um médico no sistema. 
   * Uma pasta com o id do médico será criada, juntamente com um arquivo .txt contendo os dados do médico cadastrado.
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

    if(path.mkpath(folder_name + QString::number(id)))
    {
      qDebug() << "Pasta do médico de id: " + QString::number(id) + "criada";
    }

    path.setCurrent(folder_name + QString::number(id));

    //por padrão vamos sobreescrever dados existentes
    if(arquivo.exists())
    {
      qCritical() << "ATENÇÃO:: já existe um arquivo de dados no diretorio do usuário, precione qualquer tecla para sobreescrever o arquivo atual";
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


  /**
   * Função que cadastra um Pasciente no sistema
   * Uma pasta com o id do pasciente será criada, juntamente com um arquivo .txt contendo os dados do pasciente cadastrado.
   *
   * @brief Atendente::cadastrar_medico
   * @param *Pasciente pasciente 
   * @return true - caso o cadastro tenha sido realizado
   */
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


  /**
   * Função que deleta um usuário a partir do id do mesmo.
   * A função busca pelo caminho da pasta do usuário usando o método "set_path()".
   * essa função deleta todos os dados do usuário e remove os dados do mesmo do arquivo "lista_de_usuário.txt"
   *
   * @brief Atendente::deletar_usuario
   * @param int id  - id do usuário a ser deletado
   * @return true - caso a exclusão tenha sido um sucesso
   */
  bool Atendente::deletar_usuario(int id)
  {
    QDir path{};
    QString raiz = path.absolutePath();
    QString caminho = set_path(id);

    //a função set_path retorna um "./" caso ocorra algum erro
    if(caminho == "./")
    {
      qCritical() << "Atenção. Erro ao tentar encontrar usuário";
      return false;
    }

    path.setCurrent(caminho);

    qDebug() << "Atenção, a seguinte pasta e seus dados será deleta. você está de acordo?[s/N]"<< &Qt::endl;
    qDebug() << path.currentPath();

    if(!path.removeRecursively())
    {
      qDebug() << "Atenção. Houve algum erro ao tentar deletar a pasta";
      if(path.exists())
      {
        path.cdUp();
        qDebug() << "pastas ainda existem. Tentando novamente";
        qDebug() << path.currentPath();
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
      qDebug() << "Pasta deletada" << &Qt::endl;
    }
    path.setCurrent(raiz);
    Sistema::deletar_usuario(id);
    return true;
  }

  /**
   * Função que constroi uma Atendente e retorna um ponteiro para o objeto construido
   *
   * @brief Atendente::buscar_atendente
   * @param int id
   * @return Atendente* - ponteiro para o objeto Atendente contruido
   *         nullptr - caso não tenha sido possível construir o objeto
   */
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
      qDebug() << "Erro ao tentar abrir a pasta da funcionaria" << &Qt::endl;
      if(!path.exists("atendente/"+QString::number(id))){
        qDebug() << "Atenção. Pasta \"Atendentes\" inexistente ou atendente de id:" << id << "não existe." << &Qt::endl;
      }
      return nullptr;
    }

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      qDebug() << "Erro ao tentar abrir o arquivo em modo de leitura" << &Qt::endl;
      exit(1);
      return nullptr;
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

  /**
   * Função que constroi uma Atendente e retorna um ponteiro para o objeto construido
   *
   * @brief Atendente::buscar_medico
   * @param int id
   * @return Medico* - ponteiro para o objeto Medico contruido
   *         nullptr - caso não tenha sido possível construir o objeto
   */
  Medico* Atendente::buscar_medico(int id)
  {
    QDir path{};
    QString raiz = path.absolutePath();
    QFile arquivo{"dados.txt"};
    Medico *retornar = new Medico{};
    QStringList lista_acessorados;
    long *cpfs = new long[3];
    bool ok;

    if(!path.setCurrent(QString::fromStdString("./medico/")+QString::number(id)))
    {
      qDebug() << "Erro ao tentar abrir a pasta do médico" << &Qt::endl;
      if(!path.exists("./medico/"+QString::number(id)))
      {
        qDebug() << "Atenção. Pasta de médicos inexistente ou médico de id:" << id << "não existe." << &Qt::endl;
      }
      exit(1);
    }

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      qDebug() << "Erro ao tentar abrir o arquivo em modo de leitura" << &Qt::endl;
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
   * Função que constroi um Pasciente e retorna um ponteiro para o objeto construido
   *
   * @brief Atendente::buscar_pasciente
   * @param int id
   * @return Pasciente* - ponteiro para o objeto Pasciente contruido
   *         nullptr - caso não tenha sido possível construir o objeto
   */
  Pasciente* Atendente::buscar_pasciente(int id)
  {
    QDir path{};
    QString raiz = path.absolutePath();
    QFile arquivo{"dados.txt"};
    Pasciente *retornar = new Pasciente{};
    bool ok;

    if(!path.setCurrent(QString::fromStdString("./pasciente/")+QString::number(id)))
    {
      qDebug() << "Erro ao tentar abrir a pasta do pasciente" << &Qt::endl;
      if(!path.exists("./pasciente/"+QString::number(id)))
      {
        qDebug() << "Atenção. Pasta de médicos inexistente ou pasciente de id:" << id << "não existe." << &Qt::endl;
      }
      return nullptr;
    }

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      qDebug() << "Erro ao tentar abrir o arquivo em modo de leitura" << &Qt::endl;
      return nullptr;
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
   * Função que mostra os dados da atendente na tela
   *
   * @brief Atendente::mostrar_dados
   */
  void Atendente::mostrar_dados()
  {
    qDebug() << Atendente::getNome() << &Qt::endl;
    qDebug() << (Atendente::getCpf()) << &Qt::endl;
    qDebug() << Atendente::getEmail() << &Qt::endl;
    qDebug() <<  (Atendente::getTelefone()) << &Qt::endl;
    qDebug() <<  (Atendente::getTelefone_whatsapp()) << &Qt::endl;
    qDebug() << (Atendente::getNum_matricula()) << &Qt::endl;
    qDebug() << (Atendente::get_Secretaria_geral()) << &Qt::endl;
    qDebug() << Atendente::get_medicos_assessorados()[0] << &Qt::endl;
    qDebug() << Atendente::get_medicos_assessorados()[1] << &Qt::endl;
    qDebug() << Atendente::get_medicos_assessorados()[2] << &Qt::endl;
  }
}

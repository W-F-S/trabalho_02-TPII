#ifndef ATENDENTE_H
#define ATENDENTE_H

#include <medico.h>
namespace dwp {
class Atendente : public Sistema
{
    private:
        bool secretaria_geral;
        long *medicos_assessorados;

    public:
        Atendente();
        Atendente(Sistema *usuario, bool geral, long *medicos);
        Atendente(QString nome, long cpf, QString email, long telefone, long telefone_whatsapp, QString senha, bool secretaria_geral, long *medicos);

        bool get_Secretaria_geral();
        long *get_medicos_assessorados();
        void set_Secretaria_geral(bool resp);
        void set_Medicos_acessorados(long *cpfs);
        Atendente* buscar_atendente(int id);
        Medico* buscar_medico(int id);
        bool deletar_usuario(int id);


 /**
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
        }*/

        bool cadastrar_atendente(Sistema *usuario, bool geral, long *medicos);
        bool cadastrar_atendente(Atendente *atendente);
        bool cadastrar_medico(Medico *medico);

        QString adicionar_agenda(int id, QString *agenda);
        QString *get_agenda(int id);

        QString adicionar_lista_usuarios(int tipo, int id,  long cpf, QString senha);

        bool remover_lista_usuarios(int id);


        void mostrar_dados();
        QString set_path(int id);

        QString verificar_usuario(int id);
        QString verificar_usuario(long cpf);

};
}
#endif // ATENDENTE_H

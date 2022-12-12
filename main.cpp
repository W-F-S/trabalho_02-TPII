#include "mainwindow.h"
#include "login.h"
#include "atendente.h"
#include <QApplication>

using namespace dwp;
int main(int argc, char *argv[])
{
 /*   long *cpf = new long[3];
    cpf[0] = 72576240558;
    cpf[1] = 13215465130;
    cpf[2] = 15413533256;

    Sistema usuario_atendente{
        "nova_atendente",
        46578952546,
        "nova_atendente@email.com",
        35557856884,
        35557856884,
        "nova_atendente_senha"
    };

    Sistema usuario_medico(
        "novo_medico",
        46254898795,
        "novo_medico@email.com",
        35557856884,
        35557856884,
        "novo_medico_senha"
    );

    Sistema usuario_usuario(
        "novo_usuario",
        54654689513,
        "novo_usuario@email.com",
        35557856884,
        35557856884,
        "novo_usuario_senha"
    );


    Atendente nova_atendente{&usuario_atendente, true, cpf};
    Medico novo_medico {&usuario_medico,"cardiologista",true,46578953506, cpf};
    Pasciente novo_pasciente{&usuario_usuario, 89382818828, true, "santa maria"  };

    nova_atendente.cadastrar_atendente(&nova_atendente);
    nova_atendente.cadastrar_medico(&novo_medico);
    nova_atendente.cadastrar_pasciente(&novo_pasciente);
    Sistema tmp{};
    QString nov = "Adicionando algo na agenda.";

    Atendente nova_atendente{};

    tmp.adicionar_agenda((int)6, &nov);
    cout << tmp.get_agenda(6)->toStdString();
    int id_atendente = tmp.buscar_usuario(46578952546).split(',')[1].toInt();
    int id_medico = tmp.buscar_usuario(46254898795).split(',')[1].toInt();
    int id_pasciente = tmp.buscar_usuario(54654689513).split(',')[1].toInt();

    Atendente *atedente_buscada = nova_atendente.buscar_atendente(id_atendente);
    atedente_buscada->mostrar_dados();
    getchar();

    Medico *medico_buscado =  nova_atendente.buscar_medico(id_medico);
    medico_buscado->mostrar_dados();
    getchar();

    Pasciente *pasciente_buscado = nova_atendente.buscar_pasciente(id_pasciente);
    pasciente_buscado->mostrar_dados();
    getchar();

    cout << "criando nova atendente";*/
    long *cpf = new long[3];
      cpf[0] = 72576240558;
      cpf[1] = 13215465130;
      cpf[2] = 15413533256;

    Sistema usuario_atendente{
        "nova_atendente",
        46578952546,
        "nova_atendente@email.com",
        35557856884,
        35557856884,
        "nova_atendente_senha"
    };

    Atendente nova_atendente{&usuario_atendente, true, cpf};

    nova_atendente.cadastrar_atendente(&nova_atendente);

    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}


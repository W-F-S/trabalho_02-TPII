#include "mainwindow.h"
#include "login.h"
#include "atendente_cadastrar_usuario.h"
#include "get_agenda.h"
#include <QApplication>

using namespace dwp;
int main(int argc, char *argv[])
{
    Sistema tmp;
    if (tmp.buscar_usuario((long)11111111111) != "")
    {
        long *cpf = new long[3];
        cpf[0] = 11111111111;
        cpf[1] = 11111111111;
        cpf[2] = 11111111111;

        Sistema usuario_atendente{
            "atendente",
            11111111111,
            "atendente@email.com",
            11111111111,
            11111111111,
            "senha"
        };

        Atendente nova_atendente{&usuario_atendente, true, cpf};

        nova_atendente.cadastrar_atendente(&nova_atendente);
    }
    else
    {
        qDebug() << "atendente padrão já existe no sistema";
    }
    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}


#include "mainwindow.h"
#include "atendente.h"
#include <QApplication>

using namespace dwp;
int main(int argc, char *argv[])
{
    long *cpfs = new long[3];
    cpfs[0] = 45875614558;
    cpfs[1] = 55598745841;
    cpfs[2] = 45685275951;

    long *cpf2 = new long[3];
    cpf2[0] = 45624583589;
    cpfs[1] = 79513875548;
    cpfs[2] = 46843354683;

    Sistema *usuario = new Sistema{
            "atendente pessoa",
            15857425983,
            "user@email.com",
            62668475991,
            62668475991,
            "123"
    };

    Sistema *usuario2 = new Sistema{
            "atendente pessoa",
            15857425983,
            "user@email.com",
            62668475991,
            62668475991,
            "321"
    };

    Atendente *novo = new Atendente{
            usuario,
            true,
            cpfs
    };

    Medico *novo2 = new Medico{usuario2, "radiologista", true, cpfs};


    novo->cadastrar_medico(novo2);
    novo->cadastrar_atendente(novo);

    QString dados = novo->verificar_usuario(15857425983);
    cout << dados.toStdString();

}

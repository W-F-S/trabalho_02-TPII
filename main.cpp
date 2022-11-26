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

    Sistema *usuario = new Sistema{
        "pessoa",
        15857425983,
        "user@email.com",
        62668475991,
        62668475991
    };



/**    Atendente *novo = new Atendente{
            usuario,
            true,
            cpfs
   };*/

    Atendente *novo = new Atendente{};

    //novo -> mostrar_dados_atendente();
   // novo ->cadastrar_atendente(novo);


    novo = novo->get_dados_atendente(13);
    novo ->mostrar_dados_atendente();
/**
    QDir path{};
    qDebug() << path.path();

    cout << path.mkdir(QString::fromStdString("tendente"));
**/


   /* QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    //return a.exec();
}

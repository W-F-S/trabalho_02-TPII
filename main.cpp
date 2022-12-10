#include "mainwindow.h"
#include "atendente.h"
#include <QApplication>

using namespace dwp;
int main()
{
    Atendente nova_atendente{};
    QString nov = "Adicionando algo na agenda.";

    nova_atendente.adicionar_agenda(14, &(nov));

}

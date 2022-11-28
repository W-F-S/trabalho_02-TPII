#include "medico.h"

namespace dwp
{
Medico::Medico()
{
    Medico::especialidade = "";
    Medico::particular = false;
    Medico::usuario = new Sistema();
    Medico::pascientes = new long[3];

}
}

#include "sistema.cpp"


class Atendente : private Sistema{
      private:
        string cargo;
        bool secretaria_geral;
      public:
        bool excluir_secretaria();
        bool cadastrar_paciente();
      
};


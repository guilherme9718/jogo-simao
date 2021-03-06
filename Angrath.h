#pragma once
#include "stdafx.h"
#include "Jogador.h"
#include "Corpo_Grafico.h"
#include "Animadora.h"

using namespace Controladoras;
using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Angrath : public Jogador {
    public:
        Angrath(Gerenciador_Grafico* g = NULL);
        ~Angrath();

        void mover();
        void executar();

    private:
    };
}


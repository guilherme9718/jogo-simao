#pragma once
#include "stdafx.h"
#include "Jogador.h"
#include "Animadora.h"
#include "Corpo_Grafico.h"

using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Huatli : public Jogador {
    public:
        Huatli(Gerenciador_Grafico* g = NULL);
        ~Huatli();

        void mover();
        void executar();

    private:
    };
}

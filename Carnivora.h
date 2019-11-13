#pragma once
#include "stdafx.h"
#include "Obstaculo.h"
#include "Corpo_Grafico.h"

using namespace GerenciadoresEntidades;

namespace Obstaculos {
    class Carnivora : public Obstaculo {
    public:
        Carnivora(Gerenciador_Grafico* g);
        ~Carnivora();

    private:

    };
}



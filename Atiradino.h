#pragma once
#include "stdafx.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "Plataforma.h"
#include "Corpo_Grafico.h"
#include "Animadora.h"

using namespace Auxiliares;
using namespace GerenciadoresEntidades;

namespace Inimigos {
    class Atiradino : public Inimigo {
    public:
        Atiradino(Plataforma* plataforma);
        ~Atiradino();

        void executar();
        void imprimir();

        Projetil* getProjetil() { return hitbox; }
    private:

        bool ataquePronto;

    };
}


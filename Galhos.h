#pragma once
#include "stdafx.h"
#include "Obstaculo.h"
#include "Plataforma.h"

using namespace Auxiliares;
using namespace Obstaculos;

namespace Obstaculos {
    class Galhos : public Obstaculo {
    public:
        Galhos(Plataforma* plataforma = NULL);
        ~Galhos();

    private:

    };
}


#pragma once
#include "stdafx.h"
#include "Obstaculo.h"
#include "Plataforma.h"

class Pedra : public Obstaculo {
public:
    Pedra(Plataforma* plat);
    ~Pedra();

    void executar();

private:

};



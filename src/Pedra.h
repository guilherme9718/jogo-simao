#pragma once
#include "stdafx.h"
#include "Obstaculo.h"

class Pedra : public Obstaculo {
public:
    Pedra(Gerenciador_Grafico* g);
    ~Pedra();

    void executar() {}

private:

};



#pragma once
#include "stdafx.h"
#include "Obstaculo.h"

class Carnivora : public Obstaculo {
public:
    Carnivora(Gerenciador_Grafico* g);
    ~Carnivora();

    void executar();
private:

};



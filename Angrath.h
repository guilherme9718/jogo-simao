#pragma once
#include "stdafx.h"
#include "Jogador.h"

class Angrath : public Jogador {
public:
    Angrath(Gerenciador_Grafico* g);
    ~Angrath();

    void mover();
    void executar();

private:

    float pulo;

};


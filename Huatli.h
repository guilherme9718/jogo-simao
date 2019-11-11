#pragma once
#include "stdafx.h"
#include "Jogador.h"

class Huatli : public Jogador {
public:
    Huatli(Gerenciador_Grafico* g = NULL);
    ~Huatli();

    void mover();
    void executar();

private:
};

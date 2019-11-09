#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Inimigo : public Personagem {
public:
    Inimigo(Gerenciador_Grafico* g = NULL);
    virtual ~Inimigo();

    virtual void executar();
    virtual void imprimir();

protected:
    Vector3f fronteira;
    float posicaoInicial;
};



#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem : public Entidade {
public:
    Personagem(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Personagem();
    
    virtual void mover();
    virtual void executar();
protected:
    int vidas;
    float velocidade;
};



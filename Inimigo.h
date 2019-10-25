#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Inimigo : public Personagem {
public:
    Inimigo(Gerenciador_Grafico* g = NULL);
    virtual ~Inimigo();
    
    const bool getMorto() const { return morto; }
protected:
    bool morto;
};



#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem : public Entidade {
public:
    Personagem();
    virtual ~Personagem();
    
private:
    int vidas;
};



#pragma once
#include "stdafx.h"

class Entidade {
public:
    Entidade();
    virtual ~Entidade();
    
    virtual void executar();
    void imprimir();
protected:
    Vector2f posicao;
};



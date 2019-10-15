#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"

class Fase : public Entidade {
public:
    Fase();
    virtual ~Fase();
    
    void executar();
    void gerenciar_colisoes();
    
protected:
    ListaEntidade objetos;
    ListaEntidade personagens;
    ListaEntidade obstaculos;
    
    
};


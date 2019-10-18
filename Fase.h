#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Ent.h"

class Fase : public Ent {
public:
    Fase();
    virtual ~Fase();
    
    void executar();
    void gerenciar_colisoes();
    
protected:
    ListaEntidade entidades;
    
    
};


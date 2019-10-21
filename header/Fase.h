#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Ent.h"
#include "Huatli.h"

class Jogo;

class Fase : public Ent {
public:
    Fase(Jogo* jooj = NULL);
    virtual ~Fase();
    
    virtual void executar();
    void gerenciar_colisoes();
    
    //Sets e Gets
    
    void setJogo(Jogo* jooj) { pJogo = jooj; }
protected:
    ListaEntidade entidades;
    
    Jogo* pJogo;
    Huatli* jogador;
    
};


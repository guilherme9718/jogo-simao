#pragma once
#include "stdafx.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "Plataforma.h"

class ChefeDino : public Inimigo {
public:
    ChefeDino(Plataforma* p);
    ~ChefeDino();
    
    void executar();
    void mover();
    void imprimir();
    
    //Sets e Gets
    Projetil* getProjetil() { return hitbox; }
private:
    float pulo;
    Projetil* hitbox;
    bool ataquePronto;
    
};


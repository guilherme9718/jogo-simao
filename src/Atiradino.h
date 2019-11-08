#pragma once
#include "stdafx.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "Plataforma.h"

class Atiradino : public Inimigo {
public:
    Atiradino(Plataforma* plataforma);
    ~Atiradino();

    void executar();
    void imprimir();

    Projetil* getProjetil() { return hitbox; }
private:

    Projetil* hitbox;
    bool ataquePronto;

};


#pragma once
#include "stdafx.h"
#include "Inimigo.h"

class Andino : public Inimigo {
public:
    Andino(Gerenciador_Grafico* g = NULL, Vector3f f = Vector3f(0.0f, 0.0f, 0.0f));
    ~Andino();
    
    void mover();
    void morrer();
private:
    Vector3f fronteira;
    float pulo;
    short lado;
};


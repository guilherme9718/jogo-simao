#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Corpo_Grafico.h"

class Plataforma : public Entidade {
public:
    Plataforma(Vector2f tam = Vector2f(0.0f, 0.0f));
    ~Plataforma();
    
    void executar();
private:
    
};


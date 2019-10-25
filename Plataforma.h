#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Corpo_Grafico.h"

class Plataforma : public Entidade {
public:
    Plataforma(Vector2f tam = Vector2f(100.0f, 100.0f), Texture* tex = NULL);
    ~Plataforma();

    void executar();
private:

};


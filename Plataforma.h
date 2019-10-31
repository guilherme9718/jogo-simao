#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Corpo_Grafico.h"

class Plataforma : public Entidade {
public:
    Plataforma(Vector2f tam = Vector2f(100.0f, 100.0f), Texture* tex = NULL);
    ~Plataforma();

    void executar() {corpo.atualizaAnimacao(0.1, true, 0, 0, 0, 0);};
    //void Colidindo(Vector2f direcao) {} ;

private:

};


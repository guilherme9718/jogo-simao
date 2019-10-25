#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem : public Entidade {
public:
    Personagem(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Personagem();
    
    virtual void Colidindo(Vector2f direcao);
    virtual void mover();
    virtual void executar();
    virtual void morrer() = 0;
protected:
    int vidas;
    float velocidade;
    float totalT;
    bool noChao;
    bool aDireita;
    Vector2f movimento;
};



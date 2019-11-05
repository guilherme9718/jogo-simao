#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem : public Entidade {
public:
    Personagem(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Personagem();

    virtual void imprimir();
    //virtual void Colidindo(Vector2f direcao);
    virtual void executar();

    virtual void animar(Vector2f movimento);

protected:
    float velocidade;

    bool atacando;
    float totalT;

    bool aDireita;
    short int lado;



};



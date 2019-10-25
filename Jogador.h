#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Inimigo.h"

class Jogador : public Personagem {
public:
    Jogador(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Jogador();
    
    virtual void morrer();
    bool atacar(Inimigo* inim);
    
    void imprimir();
    
    virtual void executar();
protected:
    Vector2f posInicial;
    Corpo_Grafico hitbox;
    bool atacando;
    
};



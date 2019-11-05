#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Inimigo.h"
#include "Projetil.h"

class Jogador : public Personagem {
public:
    Jogador(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Jogador();

    virtual void morrer();
    bool atacar(Inimigo* inim);

    void imprimir();

    virtual void executar() = 0;

    //Sets e Gets

    const bool getAtacando() const { return atacando; }
    Corpo_Grafico* getHitbox() { return hitbox->getCorpoGraf(); }
    
    Projetil* getProjetil() { return hitbox; }

protected:
    Vector2f posInicial;
    Projetil* hitbox;
    bool ataquePronto;
    short ladoAtaque;

};



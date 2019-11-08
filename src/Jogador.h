#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Inimigo.h"
#include "Projetil.h"

class Jogador : public Personagem {
public:
    Jogador(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Jogador();

    void morrer();
    void morrer(Vector2f pos);
    bool atacar(Inimigo* inim);

    void imprimir();

    virtual void executar() = 0;

    //Sets e Gets

    const bool getAtacando() const { return atacando; }
    Corpo_Grafico* getHitbox() { return hitbox->getCorpoGraf(); }
    
    Projetil* getProjetil() { return hitbox; }
    
    void setPontos (const int p) { pontos += p; }
    int getPontos() const { return pontos; }

protected:
    Vector2f posInicial;
    Projetil* hitbox;
    bool ataquePronto;
    short ladoAtaque;

    int pontos;
};


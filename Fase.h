#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Ent.h"
#include "Huatli.h"
#include "Angrath.h"


class Jogo;

class Fase : public Ent {
public:
    Fase(Jogo* jooj = NULL);
    virtual ~Fase();

    virtual void executar();
    virtual void gerenciar_colisoes();
    virtual void reiniciar();

    //Sets e Gets
    Huatli* getJogador1() { return jogador1; }
    Angrath* getJogador2() { return jogador2; }

    void setJogo(Jogo* jooj) { pJogo = jooj; }
protected:
    ListaEntidade entidades;

    Jogo* pJogo;
    Huatli* jogador1;
    Angrath* jogador2;

};


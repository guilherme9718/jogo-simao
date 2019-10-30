#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Inimigo : public Personagem {
public:
    Inimigo(Gerenciador_Grafico* g = NULL);
    virtual ~Inimigo();

    void executar();
    virtual void imprimir();

    //Gerenciadoras de colisão

    virtual bool verificarAtacando(Colisora* outro, Vector2f& direcao);
    //Retorna true se está havendo colisao e o outro está sobrevivendo à colisão

    virtual bool verificarAtaque(Colisora* outro, Vector2f& direcao)
        { return corpo.getColisora()->verificarColisao(outro, direcao, 1.0f);}
    //Retorna true se está havendo colisão e se o jogador pode matar quem esta entidade

protected:
    bool morto;

};



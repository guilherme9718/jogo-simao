#pragma once
#include "stdafx.h"
#include "Ent.h"
#include "Gerenciador_Grafico.h"
#include "Corpo_Grafico.h"
#include "Colisora.h"

class Entidade : public Ent {
public:
    Entidade(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Entidade();

    virtual void executar() = 0;
    virtual void imprimir();

    //Sets e gets

    Vector2f getPosicao() { return corpo.getCorpo()->getPosition(); }
    Vector2f getTamanho() { return corpo.getCorpo()->getSize(); }
    Colisora* getColisora() { return corpo.getColisora(); }
    bool verificarColisao(Colisora* outro, Vector2f& direcao, float f) { return corpo.getColisora()->verificarColisao(outro, direcao, f); } 
    Corpo_Grafico* getCorpoGraf() { return &corpo; }
    
    

    void setGerenciador(Gerenciador_Grafico *gerenciador) { pGG = gerenciador; }
protected:
    Corpo_Grafico corpo;
    Gerenciador_Grafico *pGG;
};



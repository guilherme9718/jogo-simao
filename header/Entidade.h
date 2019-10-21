#pragma once
#include "stdafx.h"
#include "Ent.h"
#include "Gerenciador_Grafico.h"
#include "Corpo_Grafico.h"

class Entidade : public Ent {
public:
    Entidade(Gerenciador_Grafico* gerenciador = NULL);
    Entidade(Vector2f tam = Vector2f(100.0f, 100.0f));
    virtual ~Entidade();
    
    virtual void executar() = 0;
    virtual void imprimir();
    
    //Sets e gets

    Vector2f getPosicao() { return corpo.getCorpo()->getPosition(); }
    Corpo_Grafico* getCorpoGraf() { return &corpo; }
    
    void setGerenciador(Gerenciador_Grafico *gerenciador) { pGG = gerenciador; }
protected:
    Corpo_Grafico corpo;
    Gerenciador_Grafico *pGG;
};



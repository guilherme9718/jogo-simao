#pragma once
#include "stdafx.h"
#include "Ent.h"
#include "Gerenciador_Grafico.h"
#include "Corpo_Grafico.h"
#include "Colisora.h"

class Plataforma;

class Entidade : public Ent {
public:
    Entidade(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Entidade();

    virtual void executar() = 0;
    virtual void mover() {}
    virtual void imprimir();


    //Sets e gets

    Vector2f getPosicao() { return corpo.getCorpo()->getPosition(); }
    Vector2f getTamanho() { return corpo.getCorpo()->getSize(); }
    Corpo_Grafico* getCorpoGraf() { return &corpo; }

    Plataforma* getPlataforma() { return plat; }
    void setPlataforma(Plataforma* p) { plat  = p; }

    void setGerenciador(Gerenciador_Grafico *gerenciador) { pGG = gerenciador; }

    void setMovimento(Vector2f mov) { movimento = mov; }
    Vector2f getMovimento() { return movimento; }

    void setChao(bool chao) { noChao = chao; }
    bool getChao() { return noChao; }

    bool getPodeMorrer() { return podeMorrer; }
    bool getPodeMatar() { return podeMatar; }
    float getEmpurrao() { return empurrao; }

    int getVidas() { return vidas; }
    void setVidas(int v) { vidas = v; }

    bool tomarDano();
    
    Gerenciador_Grafico* getGerenciador() { return pGG; }

protected:
    Corpo_Grafico corpo;
    Gerenciador_Grafico *pGG;
    Plataforma* plat;

    Vector2f movimento;

    int vidas;

    bool noChao;

    bool podeMatar;
    bool podeMorrer;
    float empurrao;
};



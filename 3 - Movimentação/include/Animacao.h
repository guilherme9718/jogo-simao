#pragma once

#include "stdafx.h"

class Animacao
{
private:

    Vector2u imgCont;
    Vector2u imgAtual;

    float tempoTotal;
    float tempoTroca;

    bool lado;

public:

    IntRect uvRet;

public:

    Animacao(Texture* tex, Vector2u cont, float tempoTroca, bool l);
    ~Animacao();

    void Atualiza(int linha, float tempo);

    void setLado(bool l) {lado = l;}


};

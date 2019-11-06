#pragma once
#include "stdafx.h"
#include "Fase.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Huatli.h"
#include "Andino.h"
#include "Carnivora.h"
#include "Colisora.h"
#include "Pedra.h"

class Montanha : public Fase {
public:
    Montanha(Jogo* jooj = NULL);
    ~Montanha();

    void executar();
    //void gerenciar_colisoes();
    
    void instanciaPlataformas();
    void instanciaInimigos(Plataforma* plat);
    void instanciaObstaculos(Plataforma* plat);
    void instanciaFundo();

private:

    Colisora* colisora;

    Andino* andi;
    Carnivora* carn;

    RectangleShape fundo[5];
    Texture texturaFundo[5];

    int i;

    unsigned short int contPlat;
    unsigned short int contInim;
    unsigned short int contObs;
    unsigned short int contJog;
};


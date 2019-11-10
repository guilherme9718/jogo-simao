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
#include "Fundo.h"
#include "Gerenciador_Grafico.h"
#include "MontanhaEstado.h"
#include "Atiradino.h"

class Montanha : public Fase, public MontanhaEstado {
public:
    Montanha(Jogo* jooAj = NULL, bool dois = false);
    ~Montanha();

    void executar();
    void pontuacao();
    //void gerenciar_colisoes();

    void instanciaPlataformas();
    void instanciaInimigos(Plataforma* plat);
    void instanciaObstaculos(Plataforma* plat);
    void instanciaFundo();

private:

    Colisora* colisora;

    Fundo fundo;
    Gerenciador_Grafico* pGG;
};


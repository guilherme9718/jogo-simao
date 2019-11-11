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
#include "FlorestaEstado.h"
#include "Atiradino.h"
#include "Galhos.h"
#include "ChefeDino.h"

class Floresta : public Fase, public FlorestaEstado {
public:
    Floresta(Jogo* jooj = NULL, bool dois = false, Huatli* j1 = NULL, Angrath* j2 = NULL);
    ~Floresta();
    
    void executar();
    void pontuacao();

    void instanciaPlataformas();
    void instanciaInimigos(Plataforma* plat);
    void instanciaObstaculos(Plataforma* plat);
    void instanciaFundo();
private:
    Colisora* colisora;

    Fundo fundo;
    Gerenciador_Grafico* pGG;
};


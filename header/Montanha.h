#pragma once
#include "stdafx.h"
#include "Fase.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Huatli.h"

class Montanha : public Fase {
public:
    Montanha(Jogo* jooj = NULL);
    ~Montanha();
    
    void executar();
    void gerenciar_colisoes();
private:
    
    Plataforma plat;
    
    
};


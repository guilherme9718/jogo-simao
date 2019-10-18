#pragma once
#include "stdafx.h"
#include "Fase.h"
#include "Jogador.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "Montanha.h"
#include "Floresta.h"
#include "Huatli.h"
#include "Angrath.h"

class Jogo {
public:
    Jogo();
    ~Jogo();
    
    void executar();
    
private:
    Huatli* j1; 
    Angrath* j2;
    
    Menu m1;
    
    Montanha* f1;
    Floresta* f2; 
    
    Gerenciador_Grafico GG;
};
#pragma once
#include "stdafx.h"
#include "Fase.h"
#include "Jogador.h"
#include "Menu.h"

class Jogo {
public:
    Jogo();
    ~Jogo();
    
    void executar();
    
private:
    Jogador* j1; 
    Jogador* j2;
    
    Menu m1;
    
    Fase* f1;
    Fase* f2; 
    
};
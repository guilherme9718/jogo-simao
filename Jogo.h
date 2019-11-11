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
#include "MenuPrincipal.h"

class Jogo {
public:
    Jogo();
    ~Jogo();

    void executar();
    
    void tirarEstado();
    void colocarEstado(Estado* est) { estados.push(est); }
    const bool pilhaVazia() { return estados.empty(); }
    const unsigned int pilhaTam() const { return estados.size(); }
    Estado* getTopo() const { if(not estados.empty()) return estados.top(); }
    

    //Sets e Gets

    Gerenciador_Grafico* getGerenciador() { return &GG; }
private:


    stack<Estado*> estados;
    stack<Estado*> lixo;

    Gerenciador_Grafico GG;
};

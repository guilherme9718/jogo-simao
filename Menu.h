#pragma once
#include "stdafx.h"
#include "Ent.h"
#include "Gerenciador_Grafico.h"
#include "Fundo.h"

class Jogo;

class Menu : public Ent {
public:
    Menu(Jogo* jogo = NULL);
    ~Menu();
    
    void executar();
    
    void leEntradas();
    
    //Sets e gets
    
    void setJogo(Jogo* jogo) { pJogo = jogo; }
protected:
    Jogo* pJogo;
    Gerenciador_Grafico* pGG;
    
    bool menuAtivo;
    int opcao;
    int selecionado;
    bool pressionar;
    
    Fundo fundo;
    
    Font fonte;
    Text texto[5];
    
    float totalT;
};



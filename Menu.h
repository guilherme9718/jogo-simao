#pragma once
#include "stdafx.h"
#include "Ent.h"
#include "Gerenciador_Grafico.h"

class Jogo;

class Menu : public Ent {
public:
    Menu(Jogo* jogo = NULL);
    ~Menu();
    
    void executar();
    
    void leEntradas();
    
    //Sets e gets
    
    void setJogo(Jogo* jogo) { pJogo = jogo; }
private:
    Jogo* pJogo;
    Gerenciador_Grafico* pGG;
    
    bool menuAtivo;
    int opcao;
    int selecionado;
    
    RectangleShape fundo;
    Texture texFundo;
    
    Font fonte;
    Text texto[5];
};



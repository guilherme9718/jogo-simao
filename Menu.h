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
    void posicionarTexto();
  
    //Sets e gets
    void setPressionar(const bool press) { pressionar = press; }
    void setJogo(Jogo* jogo) { pJogo = jogo; }
protected:
    Jogo* pJogo;
    Gerenciador_Grafico* pGG;

    int opcao;
    int selecionado;
    bool pressionar;
    

    Fundo fundo;

    Font fonte;
    vector<Text> texto;

    float totalT;
};



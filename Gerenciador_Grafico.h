#pragma once
#include "stdafx.h"

class Gerenciador_Grafico {
public:
    Gerenciador_Grafico();
    virtual ~Gerenciador_Grafico();
    
    RenderWindow* getJanela() { return &janela; }
    bool getAberto () const { return janela.isOpen(); }
    void limpar () { janela.clear(); }
    void leEventos ();
    void desenhar (RectangleShape* elem) { janela.draw(*elem); }
private:
    RenderWindow janela;
    
};



#pragma once
#include "stdafx.h"

class Gerenciador_Grafico {
public:
    Gerenciador_Grafico();
    virtual ~Gerenciador_Grafico();
    
    RenderWindow* getJanela() { return &janela; }
    bool getAberto () const { return janela.isOpen(); }
    void limpar ();
    void leEventos ();
    void desenhar (RectangleShape* elem) { janela.draw(*elem); }
    View* getVisao () { return &visao; }
private:
    RenderWindow janela;
    View visao;
    
};



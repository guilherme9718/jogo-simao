#pragma once
#include "stdafx.h"
#include "Animadora.h"
#include "Colisora.h"

class Corpo_Grafico {
public:
    Corpo_Grafico(Vector2f tam, string textura);
    Corpo_Grafico();
    virtual ~Corpo_Grafico();
    
    //Sets e Gets
    
    RectangleShape* getCorpo () { return &corpo; }
private:
    RectangleShape corpo;
    Animadora animacao;
    Colisora colisor;
    Texture textura;
};

#pragma once
#include "stdafx.h"
#include "Animadora.h"
#include "Colisora.h"

class Corpo_Grafico {
public:
    Corpo_Grafico();
    virtual ~Corpo_Grafico();
    
    void inicializa(Vector2f tam);
    
    //Sets e Gets
    
    RectangleShape* getCorpo() { return corpo; }
    Colisora* getColisora() { return colisor; }
private:
    RectangleShape* corpo;
    Animadora* animacao;
    Colisora* colisor;
    Texture* textura;
};

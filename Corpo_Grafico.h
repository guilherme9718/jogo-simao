#pragma once
#include "stdafx.h"
#include "Animadora.h"
#include "Colisora.h"

class Corpo_Grafico {
public:
    Corpo_Grafico();
    virtual ~Corpo_Grafico();
    
    void inicializa(Vector2f tam, Texture* tex);

    //Sets e Gets

    RectangleShape* getCorpo() { return corpo; }
    Colisora* getColisora() { return colisor; }
    
    Vector2f getPosicao() { return corpo->getPosition(); }
    Vector2f getTamanho() { return corpo->getSize(); }
    
private:
    RectangleShape* corpo;
    Animadora* animacao;
    Colisora* colisor;
    Texture* textura;
};

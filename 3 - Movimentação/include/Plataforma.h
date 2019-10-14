#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "stdafx.h"
#include "Collider.h"

class Plataforma
{
public:
    Plataforma(Texture* tex, Vector2f tam, Vector2f pos);
    virtual ~Plataforma();

    void desenha(RenderWindow& janela) {janela.draw(corpo);}
    Collider getCollider() {return Collider(corpo);}

private:

    RectangleShape corpo;
};

#endif // PLATAFORMA_H

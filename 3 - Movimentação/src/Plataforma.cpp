#include "Plataforma.h"

Plataforma::Plataforma(Texture* tex, Vector2f tam, Vector2f pos)
{
    corpo.setSize(tam);
    corpo.setTexture(tex);
    corpo.setOrigin(tam / 2.0f);
    corpo.setPosition(pos);
}

Plataforma::~Plataforma()
{

}


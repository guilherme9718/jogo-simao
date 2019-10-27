#include "Plataforma.h"

Plataforma::Plataforma(Vector2f tam, Texture* tex)
{
    corpo.inicializa(tam, tex);
    corpo.getCorpo()->setFillColor(Color::Cyan);
}

Plataforma::~Plataforma() {
}

bool Plataforma::verificarColisao(Colisora* outro, Vector2f& direcao)
{
    return corpo.getColisora()->verificarColisao(outro, direcao, 1.0f);
}

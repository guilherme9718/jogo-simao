#include "Plataforma.h"

Plataforma::Plataforma(Vector2f tam, Texture* tex)
{
    corpo.inicializa(tam, tex);
    corpo.getCorpo()->setFillColor(Color::Cyan);
}

Plataforma::~Plataforma() {
}

void Plataforma::executar() {

}


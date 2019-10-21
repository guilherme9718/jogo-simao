#include "Plataforma.h"

Plataforma::Plataforma(Vector2f tam):
Entidade(tam)
{
    corpo.getCorpo()->setFillColor(Color::Cyan);
}

Plataforma::~Plataforma() {
}

void Plataforma::executar() {
    
}


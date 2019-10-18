#include "Corpo_Grafico.h"

Corpo_Grafico::Corpo_Grafico():
corpo(Vector2f(100.0f, 100.0f)),
animacao()
{
    corpo.setFillColor(Color::White);
    corpo.setOrigin(corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f);
}

Corpo_Grafico::~Corpo_Grafico() {
}



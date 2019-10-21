#include "Corpo_Grafico.h"

Corpo_Grafico::Corpo_Grafico()
{
    
}

Corpo_Grafico::~Corpo_Grafico() {
    delete corpo;
    delete colisor;
}

void Corpo_Grafico::inicializa(Vector2f tam) {
    corpo = new RectangleShape(tam);
    colisor = new Colisora(corpo);
    corpo->setFillColor(Color::White);
    corpo->setOrigin(tam.x / 2.0f, tam.y / 2.0f);
}



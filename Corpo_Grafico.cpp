#include "Corpo_Grafico.h"

Corpo_Grafico::Corpo_Grafico()
{

}

Corpo_Grafico::~Corpo_Grafico() {
    delete corpo;
    delete animacao;
    delete colisor;
    delete textura;
}

void Corpo_Grafico::inicializa(Vector2f tam, Texture* tex) {
    corpo = new RectangleShape(tam);
    corpo->setOrigin(tam / 2.0f);
    corpo->setFillColor(Color::White);

    corpo->setTexture(tex);

    colisor = new Colisora(corpo);
}



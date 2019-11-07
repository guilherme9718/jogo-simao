#include "Pedra.h"

Pedra::Pedra(Gerenciador_Grafico* g):
Obstaculo(g)
{
    podeMatar = false;
    podeMorrer = true;
    empurrao = 0.0f;

    corpo.inicializa(Vector2f(100.0f, 100.0f), NULL);
    corpo.getCorpo()->setFillColor(Color::Green);
    corpo.setTextura("Texturas/Obstaculos/Pedra.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(1, 1), Vector2u(1, 1));
    corpo.atualizaAnimacao(0.0f, false, 0, 0, 1, 0);

}

Pedra::~Pedra() {
}


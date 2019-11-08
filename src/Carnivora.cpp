#include "Carnivora.h"

Carnivora::Carnivora(Gerenciador_Grafico* g):
Obstaculo(g)
{
    podeMatar = true;
    podeMorrer = false;
    empurrao = 1.0f;

    corpo.inicializa(Vector2f(60.0f, 60.0f), NULL);
    corpo.getCorpo()->setFillColor(Color::White);
    corpo.setTextura("Texturas/Obstaculos/Espinho.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(1, 1), Vector2u(1, 1));
    corpo.atualizaAnimacao(0.0f, false, 0, 0, 1, 0);
}

Carnivora::~Carnivora() {
}

void Carnivora::executar() {
    
}

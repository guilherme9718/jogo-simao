#include "Andino.h"


Andino::Andino(Gerenciador_Grafico* g, Vector3f f):
Inimigo(g), pulo(350), fronteira(f), lado(-1)
{
    noChao = true;
    velocidade = 200.0f;
    corpo.inicializa(Vector2f(100.0f, 100.0f), NULL);
    corpo.getCorpo()->setPosition(Vector2f ((fronteira.x + fronteira.y) / 2.0f, fronteira.z));
    corpo.getCorpo()->setFillColor(Color::Green);
    totalT = 0;
}

Andino::~Andino() {

}

void Andino::mover() {

    int chancePulo;
    float dT = pGG->getDt();
    totalT += dT;
    movimento.x = velocidade * lado;
    
    chancePulo = rand() % 1000;
    
    if(!chancePulo && noChao)
    {
        noChao = false;

        movimento.y = -sqrtf(2.0 * 981.0 * pulo);
    }

    movimento.y += 981.0 * dT;

    if (movimento.x == 0.0f) {
        //Animação parado
    }
    else {
        
        if (movimento.x > 0.0f) {
            //Animação de andar para a direita
        }
        else {
            //Animação de andar para a esquerda
        }
    }
    
    float tempoTroca = 0.1f;
    
    if((corpo.getCorpo()->getPosition().x < fronteira.x || corpo.getCorpo()->getPosition().x > fronteira.y) && totalT >= tempoTroca) {
        lado *= -1;
        totalT -= tempoTroca;
    }
    
    corpo.getCorpo()->move(movimento * dT);

}

void Andino::morrer() {
    morto = true;
    
}

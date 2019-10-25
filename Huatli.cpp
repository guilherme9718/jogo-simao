#include "Huatli.h"

Huatli::Huatli(Gerenciador_Grafico* g):
Jogador(g), pulo(350)
{
    corpo.inicializa(Vector2f(100.0f, 100.0f), NULL);
    posInicial = Vector2f(corpo.getPosicao().x / 2.0f, (float)(pGG->getJanela()->getSize().y) - (3.0f * corpo.getTamanho().y) / 2.0f);
    corpo.getCorpo()->setPosition(posInicial);
}

Huatli::~Huatli() {

}

void Huatli::mover() {

    float dT = pGG->getDt();
    movimento.x = 0;

    if(Keyboard::isKeyPressed(Keyboard::D))
        movimento.x += velocidade;

    if(Keyboard::isKeyPressed(Keyboard::A))
        movimento.x -= velocidade;
    
    if(Keyboard::isKeyPressed(Keyboard::Key::Space) && noChao)
    {
        noChao = false;

        movimento.y = -sqrtf(2.0 * 981.0 * pulo);
    }

    movimento.y += 981.0 * dT * 2;

    if(Keyboard::isKeyPressed(Keyboard::W)) {
        movimento.y -= 10.0f;
    }

    if (movimento.x == 0.0f) {
        //Animação parado
    }
    else {
        if (movimento.y > 0.0f) {
            //Animação de andar para a direita
            aDireita = true;
        }
        else {
            //Animação de andar para a esquerda
            aDireita = false;
        }
    }

    corpo.getCorpo()->move(movimento * dT);

}


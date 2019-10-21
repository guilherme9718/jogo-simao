#include "Huatli.h"

Huatli::Huatli(Gerenciador_Grafico* gerenciador):
Jogador(gerenciador)
{
    
}

Huatli::~Huatli() {
    
}

void Huatli::mover() {
    Vector2f movimento(0.0f, 0.0f);
    if(Keyboard::isKeyPressed(Keyboard::D))
        movimento.x += velocidade;
    
    if(Keyboard::isKeyPressed(Keyboard::A))
        movimento.x -= velocidade;
    
    if(Keyboard::isKeyPressed(Keyboard::S))
        movimento.y += velocidade;
    
    if(Keyboard::isKeyPressed(Keyboard::W))
        movimento.y -= velocidade;
    
    if (movimento.x == 0.0f) {
        //Animação parado
    }
    else {
        if (movimento.y > 0.0f) {
            //Animação de andar para a direita
        }
        else {
            //Animação de andar para a esquerda
        }
    }
    
    corpo.getCorpo()->move(movimento);
    
}

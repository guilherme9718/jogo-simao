#include "Personagem.h"

Personagem::Personagem(Gerenciador_Grafico* gerenciador):
Entidade(gerenciador), lado(-1)
{
    totalT = 0;
    vidas = 3;
    velocidade = 500.0f;
    noChao = true;
    movimento = Vector2f(0.0f, 0.0f);
    
}

Personagem::~Personagem() {
}

void Personagem::mover() {

}

void Personagem::executar() {
    mover();
}

void Personagem::Colidindo(Vector2f direcao) {
    
    if(direcao.x < 0) //Colidindo na esquerda
        movimento.x = 0;

    else if(direcao.x > 0) //Colidindo na direita
        movimento.x = 0;

    if(direcao.y > 0) //Colidindo em cima
    {
        movimento.y = 0;
    }

    else if(direcao.y < 0) //Colidindo em baixo
    {
        movimento.y = 0;
        noChao = true;
    }
}

bool Personagem::verificarColisao(Colisora* outro, Vector2f& direcao, float f) {
    bool colidiu;
    colidiu = corpo.getColisora()->verificarColisao(outro, direcao, f);
    if(colidiu)
        Colidindo(direcao);
    
    return colidiu;
}


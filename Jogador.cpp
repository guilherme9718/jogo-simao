#include "Jogador.h"

Jogador::Jogador(Gerenciador_Grafico* gerenciador):
Personagem(gerenciador)
{
    lado = 1;
    atacando = false;
    hitbox.inicializa(Vector2f(100.0f, 20.0f), NULL);
    posInicial = Vector2f(0.0f, 0.0f);
    hitbox.getCorpo()->setFillColor(Color::Blue);
}

Jogador::~Jogador() {
    
}

void Jogador::executar() {
    totalT += pGG->getDt();
    if(Keyboard::isKeyPressed(Keyboard::F) && totalT >= 0.5f) {
        atacando = true;
        totalT -= 0.5f;
    }
    if(atacando && totalT >= 0.5f) {
        atacando = false;
        totalT -= 0.5f;
    }
        
    mover();
}

void Jogador::morrer() {
    vidas--;
    if(vidas > 0) {
        corpo.getCorpo()->setPosition(posInicial);
    }
}

bool Jogador::atacar(Inimigo* inim) {
    
    if(atacando) {
        Vector2f direcao(0.0f, 0.0f);
        hitbox.getCorpo()->setPosition(corpo.getPosicao().x + (100.0f * lado), corpo.getPosicao().y);

        if(inim->verificarColisao(hitbox.getColisora(), direcao, 0.0f)) {
            return true;
        }
    }
    return false;
    
}

void Jogador::imprimir() {
    pGG->desenhar(corpo.getCorpo());
    
    if(atacando)
        pGG->desenhar(hitbox.getCorpo());
    
}
#include "Jogador.h"

Jogador::Jogador(Gerenciador_Grafico* gerenciador):
Personagem(gerenciador), ataquePronto(true), ladoAtaque(1)
{
    lado = 1;
    aDireita = true;
    hitbox.inicializa(Vector2f(100.0f, 100.0f), NULL);
    posInicial = Vector2f(0.0f, 0.0f);
}

Jogador::~Jogador() {

}

void Jogador::executar() {
    totalT += pGG->getDt();
    if(Keyboard::isKeyPressed(Keyboard::F) && ataquePronto) {
        atacando = true;
        totalT -= 0.5f;
        hitbox.getCorpo()->setPosition(corpo.getPosicao().x + (100.0f * lado), corpo.getPosicao().y);
        ataquePronto = false;
        ladoAtaque = lado;
    }
    if(atacando && totalT >= 0.5f) {
        atacando = false;
        totalT -= 0.5f;
        ataquePronto = true;
    }
    
    hitbox.getCorpo()->move(291.0f * pGG->getDt() * ladoAtaque, 0.0f);
    
    if(atacando)
        hitbox.getAnimadora()->atualizarLinhasSequencial(pGG->getDt(), aDireita, Vector2u(8, 8), 5, 0.1f);
        

    if(corpo.getPosicao().y > 2000.0f)
        morrer();
    
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

        if(inim->verificarColisao(hitbox.getColisora(), direcao, 0.0f)) {
            return true;
        }
    }
    return false;

}

void Jogador::imprimir() {

    if(atacando)
        pGG->desenhar(hitbox.getCorpo());

    pGG->desenhar(corpo.getCorpo());

}

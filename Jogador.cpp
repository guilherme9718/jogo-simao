#include "Jogador.h"

Jogador::Jogador(Gerenciador_Grafico* gerenciador):
Personagem(gerenciador), ataquePronto(true), ladoAtaque(1)
{
    vidas = 5;
    lado = 1;
    aDireita = true;
    hitbox = new Projetil(pGG);
    hitbox->getCorpoGraf()->inicializa(Vector2f(100.0f, 100.0f), NULL);
    posInicial = Vector2f(0.0f, 0.0f);

    podeMatar = false;
}

Jogador::~Jogador() {

}

void Jogador::morrer() {
    vidas--;
    if(vidas > 0) {
        corpo.getCorpo()->setPosition(posInicial);
    }
}

//bool Jogador::atacar(Inimigo* inim) {
//
//    if(atacando) {
//        Vector2f direcao(0.0f, 0.0f);
//
//        if(inim->verificarColisao(hitbox.getColisora(), direcao, 0.0f)) {
//            return true;
//        }
//    }
//    return false;
//
//}

void Jogador::imprimir() {

    if(atacando)
        pGG->desenhar(hitbox->getCorpoGraf()->getCorpo());

    pGG->desenhar(corpo.getCorpo());

}

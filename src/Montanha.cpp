#include "Montanha.h"
#include "Jogo.h"

Montanha::Montanha(Jogo* jooj):
Fase(jooj),
plat(Vector2f(100.0f, 200.0f))
{
    plat.setGerenciador(pJogo->getGerenciador());
    
}

Montanha::~Montanha() {
    
}

void Montanha::executar() {
    
    plat.executar();
    jogador->executar();
    gerenciar_colisoes();
    jogador->imprimir();
    plat.imprimir();
    
}

void Montanha::gerenciar_colisoes() {
    jogador->getCorpoGraf()->getColisora()->verificarColisao(plat.getCorpoGraf()->getColisora(), 0.0f);
    plat.getCorpoGraf()->getColisora()->verificarColisao(jogador->getCorpoGraf()->getColisora(), 1.0f);
}
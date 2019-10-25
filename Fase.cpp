#include "Fase.h"
#include "Jogo.h"

Fase::Fase(Jogo* jooj):
Ent()
{
    pJogo = jooj;
    jogador = new Huatli(pJogo->getGerenciador());
    pJogo->setJogador1(jogador);
}

Fase::~Fase() {
}

void Fase::executar() {
    
}
void Fase::gerenciar_colisoes() {
    
}

void Fase::reiniciar() {
    
}


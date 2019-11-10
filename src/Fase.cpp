#include "Fase.h"
#include "Jogo.h"

Fase::Fase(Jogo* jooj, bool dois):
Ent(), jogador1(NULL), jogador2(NULL)
{
    doisJogadores = dois;
    pJogo = jooj;
}

Fase::~Fase() {
}

void Fase::executar() {

}
void Fase::gerenciar_colisoes() {

}

void Fase::reiniciar() {

}


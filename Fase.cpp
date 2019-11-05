#include "Fase.h"
#include "Jogo.h"

Fase::Fase(Jogo* jooj):
Ent()
{
    doisJogadores = false;
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


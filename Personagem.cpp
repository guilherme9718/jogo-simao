#include "Personagem.h"

Personagem::Personagem(Gerenciador_Grafico* gerenciador):
Entidade(gerenciador)
{
    vidas = 3;
    velocidade = 0.2f;
}

Personagem::~Personagem() {
}

void Personagem::imprimir() {
    pGG->desenhar(corpo.getCorpo());
}


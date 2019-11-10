#include "Inimigo.h"
#include "Plataforma.h"

Inimigo::Inimigo(Gerenciador_Grafico* g):
Personagem(g)
{
    podeMatar = true;
    podeMorrer = true;
    empurrao = 1.0f;

    noChao = true;
    aDireita = false;
}

Inimigo::~Inimigo() {
}

void Inimigo::executar()
{
    mover();
}

void Inimigo::imprimir(){
    pGG->desenhar(corpo.getCorpo());
}

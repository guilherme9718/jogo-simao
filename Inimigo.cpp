#include "Inimigo.h"

Inimigo::Inimigo(Gerenciador_Grafico* g):
Personagem(g)
{
    vidas = 1;
    morto = false;
}

Inimigo::~Inimigo() {
}


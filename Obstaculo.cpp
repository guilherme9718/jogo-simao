#include "Obstaculo.h"

Obstaculo::Obstaculo(Gerenciador_Grafico* g):
Entidade(g)
{
    podeMatar = false;
    podeMorrer = false;
    empurrao = 1.0f;
}

Obstaculo::~Obstaculo() {
}


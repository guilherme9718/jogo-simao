#include "Entidade.h"
#include "Plataforma.h"
#include "Projetil.h"

Entidade::Entidade(Gerenciador_Grafico* gerenciador):
podeMatar(true), podeMorrer(true), empurrao(1.0f), movimento(0.0f, 0.0f), noChao(true), morto(false)
{
    vidas = 10;
    plat = NULL;
    pGG = gerenciador;
}

Entidade::~Entidade() {

}

void Entidade::executar() {

}

void Entidade::imprimir() {
    pGG->desenhar(corpo.getCorpo());
}

bool Entidade::tomarDano()
{
    vidas--;
    if(vidas < 0)
        return true;

    return false;
}

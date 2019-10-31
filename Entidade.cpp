#include "Entidade.h"
#include "Plataforma.h"

Entidade::Entidade(Gerenciador_Grafico* gerenciador):
Ent(), podeMatar(true), podeMorrer(true), empurrao(1.0f), movimento(0.0f, 0.0f), noChao(true)
{
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

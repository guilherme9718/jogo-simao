#include "Entidade.h"

Entidade::Entidade(Gerenciador_Grafico* gerenciador):
Ent()
{
    pGG = gerenciador;
}

Entidade::Entidade(Vector2f tam):
corpo(tam)
{
    
}

Entidade::~Entidade() {
    
}

void Entidade::executar() {
    
}

void Entidade::imprimir() {
    pGG->desenhar(corpo.getCorpo());
}

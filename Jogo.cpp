#include "Jogo.h"

Jogo::Jogo()
{
    j1 = new Huatli(&GG);
}

Jogo::~Jogo() {
    
}
    
void Jogo::executar() {
    while (GG.getAberto()) {
        GG.getJanela()->clear(Color::Black);
        GG.leEventos();
        
        
        j1->mover();
        j1->imprimir();
        GG.getJanela()->display();
    }
}
#include "Jogo.h"

Jogo::Jogo()
{
    f1 = new Montanha(this);
}

Jogo::~Jogo() {
    
}
    
void Jogo::executar() {
    while (GG.getAberto()) {
        GG.limpar();
        GG.leEventos();
        
        f1->executar();
        
        GG.getVisao()->setCenter(j1->getPosicao());
        j1->imprimir();
        
        GG.getJanela()->display();
    }
}
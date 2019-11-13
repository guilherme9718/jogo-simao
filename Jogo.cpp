#include "Jogo.h"
#include "MenuPrincipal.h"
using namespace Controladoras;

Jogo::Jogo()
{
    srand(time(NULL));
    
    estados.push(reinterpret_cast<Estado*>(new MenuPrincipal(this)));

}

Jogo::~Jogo() {
}

void Jogo::executar() {

    float dT;
    Clock clock;

    while (GG.getAberto())
    {
        dT = clock.restart().asSeconds();
        if(dT > 1.0f / 20.0f)
            dT = 1.0f / 20.0f;

        GG.setDt(dT);

        GG.limpar();
        GG.leEventos();

        if(not estados.empty())
            estados.top()->executar();
        else {
            GG.getJanela()->close();
        }
        
        if(not lixo.empty()) {
            delete lixo.top();
            lixo.pop();
        }

        GG.getJanela()->display();
    }
}

void Jogo::tirarEstado(bool excluir) {
    if(!estados.empty()) { 
        if(excluir)
            lixo.push(estados.top());
        
        estados.pop();
    }
}
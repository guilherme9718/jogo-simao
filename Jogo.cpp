#include "Jogo.h"

Jogo::Jogo()
{
    montanha = new Montanha(this);
    j2 = montanha->getJogador2();
    srand(time(NULL));
    doisJogadores = true;
}

Jogo::~Jogo() {

}

void Jogo::executar() {
    while (GG.getAberto())
    {
        dT = clock.restart().asSeconds();
        if(dT > 1.0f / 20.0f)
            dT = 1.0f / 20.0f;

        GG.setDt(dT);

        GG.limpar();
        GG.leEventos();

        montanha->executar();
        
        if(doisJogadores)
            GG.getVisao()->setCenter(Vector2f((j1->getPosicao().x + j2->getPosicao().x) / 2.0f, 960.0f / 2.0f));
        else
        GG.getVisao()->setCenter(Vector2f(j1->getPosicao().x + 1280.0f / 4.0f, 960.0f / 2.0f));
        GG.imprimePontuacao(j1->getPontos());
        GG.getJanela()->display();
    }
}

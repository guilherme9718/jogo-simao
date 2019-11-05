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
        {
            GG.imprimePontuacao(j1->getPontos(), j1->getVidas(), j2->getPontos(), j2->getVidas());
            GG.getVisao()->setCenter(Vector2f((j1->getPosicao().x + j2->getPosicao().x) / 2.0f, 960.0f / 2.0f));
        }

        else
        {
            GG.imprimePontuacao(j1->getPontos(), j1->getVidas());
            GG.getVisao()->setCenter(Vector2f(j1->getPosicao().x + 1280.0f / 4.0f, 960.0f / 2.0f));
        }

        GG.getJanela()->display();
    }
}

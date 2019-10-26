#include "Montanha.h"
#include "Jogo.h"

Montanha::Montanha(Jogo* jooj):
Fase(jooj)
{
    plat = new Plataforma(Vector2f(1000.0f, 200.0f));
    plat2 = new Plataforma(Vector2f(1000.0f, 200.0f));
    
    entidades.incluir(static_cast<Entidade*>(plat));
    entidades.incluir(static_cast<Entidade*>(plat2));
    
    plat->setGerenciador(pJogo->getGerenciador());
    plat->getCorpoGraf()->getCorpo()->setPosition(Vector2f(jogador->getPosicao().x, jogador->getPosicao().y + 50.0f / 2 + 200.0f / 2));
    
    plat2->setGerenciador(pJogo->getGerenciador());
    plat2->getCorpoGraf()->getCorpo()->setPosition(Vector2f(jogador->getPosicao().x + 1000.0f + 10.0f, jogador->getPosicao().y + 50.0f / 2 + 200.0f / 2));
    plat2->getCorpoGraf()->getCorpo()->setFillColor(sf::Color::Red);
    andi = new Andino(pJogo->getGerenciador(), Vector3f(plat2->getPosicao().x - 450.0f, plat2->getPosicao().x + 450.0f, plat2->getPosicao().y - 150.0f));
}

Montanha::~Montanha() {

}

void Montanha::executar() {
    
    
    plat->executar();
    if(andi)
        andi->mover();
    jogador->executar();
    gerenciar_colisoes();
    if(andi)
        andi->imprimir();
    jogador->imprimir();
    plat->imprimir();
    plat2->imprimir();

}

void Montanha::gerenciar_colisoes() {
    Vector2f direcao;
    
    if(plat->verificarColisao(jogador->getColisora(), direcao, 1.0f))
        jogador->Colidindo(direcao);
    if(plat2->verificarColisao(jogador->getColisora(), direcao, 1.0f))
        jogador->Colidindo(direcao);
    
    if(andi) {
        if(plat2->verificarColisao(andi->getColisora(), direcao, 1.0f))
            andi->Colidindo(direcao);
        if(jogador->verificarColisao(andi->getColisora(), direcao, 0.0f)) {
                jogador->morrer();
        }
        if(jogador->atacar(static_cast<Inimigo*>(andi)))
        {
            delete andi;
            andi = NULL;
        }
    }
    
}

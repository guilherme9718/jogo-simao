#include "Inimigo.h"
#include "Plataforma.h"

Inimigo::Inimigo(Gerenciador_Grafico* g):
Personagem(g)
{
    podeMatar = true;
    podeMorrer = true;
    empurrao = 1.0f;

    noChao = true;
}

Inimigo::~Inimigo() {
}

void Inimigo::executar()
{
    mover();
}

void Inimigo::imprimir(){
    pGG->desenhar(corpo.getCorpo());
}

//bool Inimigo::verificarAtacando(Colisora* outro, Vector2f& direcao)
//{
//    if(corpo.getColisora()->verificarColisao(plat->getColisora(), direcao, 0.0f)) {
//        noChao = true;
//        Colidindo(direcao);
//    }
//
//    if(verificarColisao(outro, direcao))
//        return false;
//    else
//        return true;
//}

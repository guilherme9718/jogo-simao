#include "Animacao.h"

Animacao::Animacao(Texture* tex, Vector2u cont, float troca, bool l):
imgCont(cont), tempoTroca(troca), tempoTotal(0.0), lado(l)
{
    imgAtual.x = 0;

    uvRet.width = tex->getSize().x / (float) (imgCont.x);
    uvRet.height = tex->getSize().y / (float) (imgCont.y);
}

Animacao::~Animacao()
{

}

void Animacao::Atualiza(int linha, float tempo)
{
    imgAtual.y = linha;
    tempoTotal += tempo;

    if(tempoTotal >= tempoTroca)
    {
        tempoTotal -= tempoTroca;
        imgAtual.x ++;

        if(imgAtual.x >= imgCont.x)
            imgAtual.x = 0;
    }

    uvRet.top = imgAtual.y * uvRet.height;

    if(lado)
    {
        uvRet.left = imgAtual.x * abs(uvRet.width);
        uvRet.width = abs(uvRet.width);
    }

    else
    {
        uvRet.left = (imgAtual.x + 1) * abs(uvRet.width);
        uvRet.width = -abs(uvRet.width);
    }
}

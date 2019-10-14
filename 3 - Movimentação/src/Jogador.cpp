#include "Jogador.h"

Jogador::Jogador(Vector2f tam, float velo, Texture* tex, Vector2u cont, float troca, bool lado, float tP):
anim(tex, cont, troca, lado), velocidade(velo), linha(0), tamAltura(tP)
{
    corpo.setSize(tam);
    corpo.setTexture(tex);
    corpo.setOrigin(corpo.getSize() / 2.0f);
}

Jogador::~Jogador()
{
}

void Jogador::Atualiza(float deltaTempo)
{
    mov.x = 0.0;

    if(Keyboard::isKeyPressed(Keyboard::Key::Space) && pula)
    {
        pula = false;

        mov.y = -sqrtf(2.0 * 981.0 * tamAltura);
    }

    mov.y += 981.0 * deltaTempo;


    if(Keyboard::isKeyPressed(Keyboard::Key::A))
    {
        mov.x -= velocidade;
        anim.setLado(false);
    }

    if(Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        mov.x += velocidade;
        anim.setLado(true);
    }

    if(mov.x == 0)
        linha = 0;
    else if(!pula)
        linha = 2;
    else
        linha = 1;

    anim.Atualiza(linha, deltaTempo);
    corpo.setTextureRect(anim.uvRet);
    corpo.move(mov * deltaTempo);

}

void Jogador::Colidindo(Vector2f direcao)
{
    if(direcao.x < 0) //Colidindo na esquerda
        mov.x = 0;

    else if(direcao.x > 0) //Colidindo na direita
        mov.x = 0;

    if(direcao.y > 0) //Colidindo em cima
    {
        mov.y = 0;
    }

    else if(direcao.y < 0) //Colidindo em baixo
    {
        mov.y = 0;
        pula = true;
    }
}


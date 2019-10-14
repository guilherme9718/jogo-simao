#ifndef JOGADOR_H
#define JOGADOR_H

#include "stdafx.h"
#include "Animacao.h"
#include "Collider.h"

class Jogador
{
public:
    Jogador(Vector2f tam, float velocidade, Texture* tex, Vector2u cont, float troca, bool lado, float tP);
    virtual ~Jogador();

    void setPosition(Vector2f pos) {corpo.setPosition(pos.x, pos.y);}
    float getPosition() const {return corpo.getPosition().x;}

    void desenha(RenderWindow& janela) {janela.draw(corpo);}
    void Atualiza(float deltaTempo);

    void Colidindo(Vector2f direcao);

    Collider getCollider() {return Collider(corpo);}

protected:

private:

    RectangleShape corpo;
    Animacao anim;

    unsigned int linha;
    float velocidade;

    Vector2f mov;
    bool pula;
    float tamAltura;

};

#endif // JOGADOR_H

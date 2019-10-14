#include "Collider.h"

Collider::Collider(RectangleShape& c):
corpo(c)
{
}

Collider::~Collider()
{
}

bool Collider::checar(Collider outro, Vector2f& direcao, float f)
{
    Vector2f outroPos = outro.getTamanho();
    Vector2f outroMet = outro.getMetade();

    Vector2f pos = getTamanho();
    Vector2f met = getMetade();

    float deltaX = outroPos.x - pos.x;
    float deltaY = outroPos.y - pos.y;

    float interX = abs(deltaX) - outroMet.x - met.x;
    float interY = abs(deltaY) - outroMet.y - met.y;

    if(interX < 0 && interY < 0)
    {
        f = std::min(std::max(f,0.0f),1.0f);

        if(abs(interX) < abs(interY))
        {
            if(deltaX > 0)
            {
                mover(interX * (1 - f), 0);
                outro.mover(-interX * f,0);

                direcao.x = 1;
                direcao.y = 0;
            }
            if(deltaX < 0)
            {
                mover(-interX * (1 - f), 0);
                outro.mover(interX * f, 0);

                direcao.x = -1;
                direcao.y = 0;
            }
        }
        else
        {
            if(deltaY > 0)
            {
                mover(0, interY * (1 - f));
                outro.mover(0, -interY * f);

                direcao.x = 0;
                direcao.y = 1;
            }
            if(deltaY < 0)
            {
                mover(0, -interY * (1 - f));
                outro.mover(0, interY * f);

                direcao.x = 0;
                direcao.y = -1;
            }
        }

        return true;
    }

    return false;
}

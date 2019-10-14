#ifndef COLLIDER_H
#define COLLIDER_H

#include "stdafx.h"

class Collider
{
public:
    Collider(RectangleShape& c);
    virtual ~Collider();

    void mover(float dx, float dy) {corpo.move(dx, dy);}

    bool checar(Collider outro, Vector2f& direcao, float f);
    Vector2f getTamanho() {return corpo.getPosition();}
    Vector2f getMetade() {return corpo.getSize() / 2.0f;}

protected:

private:

    RectangleShape& corpo;
};

#endif // COLLIDER_H

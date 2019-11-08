#include "Plataforma.h"

Plataforma::Plataforma(Vector2f tam)
{
    podeMatar = false;
    podeMorrer = false;
    empurrao = 1.0f;

    corpo.inicializa(tam, NULL);

    if(tam.x < 500.0f)
        corpo.setTextura("Texturas/Plataforma/PlatGramaP.png");

    else if(tam.x < 1000.0f)
        corpo.setTextura("Texturas/Plataforma/PlatGramaM.png");

    else
        corpo.setTextura("Texturas/Plataforma/PlatGramaG.png");

    corpo.inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(1, 1), Vector2u(1, 1));

}

Plataforma::~Plataforma() {

}
#include "Jogo.h"

Jogo::Jogo()
{
    srand(time(NULL));

    menu = new MenuPrincipal(this);
    estado = reinterpret_cast<Estado*>(menu);

}

Jogo::~Jogo() {
    delete menu;
}

void Jogo::executar() {

    float dT;
    Clock clock;

    while (GG.getAberto())
    {
        dT = clock.restart().asSeconds();
        if(dT > 1.0f / 20.0f)
            dT = 1.0f / 20.0f;

        GG.setDt(dT);

        GG.limpar();
        GG.leEventos();

        estado->executar();

        GG.getJanela()->display();
    }
}

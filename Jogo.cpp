#include "Jogo.h"

Jogo::Jogo()
{
//    j1 = NULL;
//    j2 = NULL;
//    menu = NULL;
//    estado = NULL;
//    montanha = NULL;
    
    srand(time(NULL));
    doisJogadores = false;

    menu = new MenuPrincipal(this);
    //menuAtivo = true;
    estado = reinterpret_cast<Estado*>(menu);
    
}

Jogo::~Jogo() {
    delete menu;
    delete j1;
    if(doisJogadores)
        delete j2;
}

void Jogo::executar() {

    while (GG.getAberto())
    {
        //executaMenu();
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

void Jogo::executaMenu() {
//    while(menuAtivo) {
//        menu->executar();
//        GG.leEventos();
//        GG.getJanela()->display();
//    }
}

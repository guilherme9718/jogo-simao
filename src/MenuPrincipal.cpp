#include "MenuPrincipal.h"
#include "Jogo.h"

MenuPrincipal::MenuPrincipal(Jogo* jogo):
Menu(jogo)
{
    texto[0].setString("Um Jogador");
    texto[1].setString("Dois Jogadores");
    texto[2].setString("Opções");
    texto[3].setString("Carregar");
    texto[4].setString("Sair");
}

MenuPrincipal::~MenuPrincipal() {
    if(montanha)
        delete montanha;
}

void MenuPrincipal::executar() {
    int i;
    fundo.imprimir();
    totalT += pGG->getDt();

    texto[selecionado].setFillColor(Color::Cyan);
    for(i = 0; i < 5; i++) {
        pGG->getJanela()->draw(texto[i]);
    }
    texto[selecionado].setFillColor(Color::Black);
    opcao = -1;

    leEntradas();

    switch (opcao) {
        case 0:
            if(!montanha)
                montanha = new Montanha(pJogo, false);
            //pJogo->setMontanha(montanha);
            pJogo->setEstado( reinterpret_cast<Estado*>(montanha) );
            //Um jogador
            break;
        case 1:
            if(!montanha)
                montanha = new Montanha(pJogo, true);
            pJogo->setEstado( reinterpret_cast<Estado*>(montanha) );
            //Dois jogadores
            break;
        case 2:
            //Salvar
            break;
        case 3:
            //Carregar
            break;
        case 4:
            pGG->getJanela()->close();
            //Sair
            break;

        default:
            break;

    }
}


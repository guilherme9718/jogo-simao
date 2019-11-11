#include "MenuPrincipal.h"
#include "Jogo.h"

MenuPrincipal::MenuPrincipal(Jogo* jogo):
Menu(jogo)
{
    texto[0].setString("Um Jogador");
    texto[1].setString("Dois Jogadores");
    texto[2].setString("Ranking");
    texto[3].setString("Carregar");
    texto[4].setString("Sair");
}

MenuPrincipal::~MenuPrincipal() {
}

void MenuPrincipal::executar() {
    int i;
    posicionarTexto();
    fundo.setPosicao(pGG->getVisao()->getCenter());
    fundo.imprimir();

    texto[selecionado].setFillColor(Color::Cyan);
    for(i = 0; i < 5; i++) {
        pGG->getJanela()->draw(texto[i]);
    }
    texto[selecionado].setFillColor(Color::Black);
    opcao = -1;

    leEntradas();
    switch (opcao) {
        case 0:
            pJogo->colocarEstado( reinterpret_cast<Estado*>(new Montanha(pJogo, false)) );
            pressionar = false;
            totalT = 0.0f;
            //Um jogador
            break;
        case 1:
            pJogo->colocarEstado( reinterpret_cast<Estado*>(new Montanha(pJogo, true)) );
            pressionar = false;
            totalT = 0.0f;
            //Dois jogadores
            break;
        case 2:
            //Ranking
            break;
        case 3:
            //Carregar
            break;
        case 4:
            pJogo->tirarEstado();
            pGG->getJanela()->close();
            //Sair
            break;

        default:
            break;

    }
}


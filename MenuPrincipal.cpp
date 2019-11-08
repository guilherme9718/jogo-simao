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
            pJogo->setDoisJogadores(false);
            if(!montanha)
                montanha = new Montanha(pJogo);
            pJogo->setMontanha(montanha);
            pJogo->setEstado( reinterpret_cast<Estado*>(montanha) );
            //Um jogador
            break;
        case 1:
            pJogo->setDoisJogadores(true);
            if(!montanha)
                montanha = new Montanha(pJogo);
            pJogo->setMontanha(montanha);
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
            //Sair
            break;
            
        default:
            break;
        
    }
}


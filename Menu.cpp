#include "Menu.h"
#include "Jogo.h"

Menu::Menu(Jogo* jogo):
pJogo(jogo), menuAtivo(true)
{
    pGG = pJogo->getGerenciador();
    
    fundo.setSize(Vector2f(1980.0f, 960.0f));
    texFundo.loadFromFile("Texturas/Menu/bg.png");
    fundo.setTexture(&texFundo);
    fundo.setPosition(pGG->getVisao()->getCenter());
    
    
    selecionado = 0;
    
    fonte.loadFromFile("Texturas/Fontes/Pixel.TTF");
    int i;
    for(i = 0; i < 5; i++) {
        texto[i].setFont(fonte);
        texto[i].setCharacterSize(50);
        texto[i].setOutlineThickness(0.5);
        texto[i].setFillColor(Color::Black);
    }
    
    texto[0].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 400);
    texto[1].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 300);
    texto[2].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 200);
    texto[3].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 100);
    texto[4].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 000);
    
    texto[0].setString("Um Jogador");
    texto[1].setString("Dois Jogadores");
    texto[2].setString("Opções");
    texto[3].setString("Carregar");
    texto[4].setString("Sair");
}

Menu::~Menu() {
    
}

void Menu::executar() {
    int i;
    pGG->desenhar(&fundo);
    
    texto[selecionado].setFillColor(Color::Cyan);
    for(i = 0; i < 5; i++) {
        pGG->getJanela()->draw(texto[i]);
    }
    texto[selecionado].setFillColor(Color::Black);
    opcao = -1;

    leEntradas();

    switch (opcao) {
        case 0:
            //pJogo->setMenuAtivo(false);
            //Um jogador
            break;
        case 1:
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

void Menu::leEntradas() {
    if(Keyboard::isKeyPressed(Keyboard::Up)) {
        selecionado--;
        if(selecionado < 0)
            selecionado = 4;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Down)) {
        selecionado++;
        if(selecionado >= 5)
            selecionado = 0;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Return)) {
        opcao = selecionado;
    }
}


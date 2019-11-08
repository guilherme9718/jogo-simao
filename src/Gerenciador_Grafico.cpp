#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico():
AJ(960.0f), LJ(1280.0f), LP(150.0f), AP(150.0f),
janela(VideoMode(1280, 960), "Jogo-Simao", Style::Default),
visao(Vector2f(0.0f, 0.0f), Vector2f(1280, 960)),
dT(0)
{
   instanciaTexto();
}

Gerenciador_Grafico::~Gerenciador_Grafico() {

}

void Gerenciador_Grafico::leEventos () {
    Event evento;
    while (janela.pollEvent(evento)) {
        switch (evento.type)
        {
        case (Event::Closed):
            janela.close();
            break;
        case (Event::Resized):
            break;
        case (Event::KeyPressed):
            break;
        default:
            break;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape))
        janela.close();
}

void Gerenciador_Grafico::limpar() {
    janela.clear(Color::Black);
    janela.setView(visao);
}

void Gerenciador_Grafico::instanciaTexto() {
    fonte.loadFromFile("Texturas/Fontes/Dinosaur.ttf");
    texto.setFont(fonte);

    texto.setCharacterSize(50);
    texto.setOutlineThickness(0.5);

    texto.setFillColor(sf::Color::Green);
    texto.setOutlineColor(sf::Color::Yellow);
}

void Gerenciador_Grafico::imprimePontuacao(int p, int v){

    //Desenha pontos
    string s1 = "Pontos: ";
    string s2 = "000";

    if(p > 999)
        p = 999;

    s2 = to_string(p);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x - 600, 20);

    janela.draw(texto);

    //Desenha vidas
    s1 = "Vidas: ";
    s2 = to_string(v);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x - 600, 80);

    janela.draw(texto);
}

void Gerenciador_Grafico::imprimePontuacao(int p, int v, int p2, int v2){

    texto.setFillColor(sf::Color::Green);
    texto.setOutlineColor(sf::Color::Yellow);

    //Desenha pontos jogador 1
    string s1 = "Pontos: ";
    string s2 = "000";

    if(p > 999)
        p = 999;

    s2 = to_string(p);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x - 600, 20);

    janela.draw(texto);

    //Desenha vidas jogador 1
    s1 = "Vidas: ";
    s2 = "000";

    s2 = to_string(v);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x - 600, 80);

    janela.draw(texto);

    texto.setFillColor(sf::Color::Yellow);
    texto.setOutlineColor(sf::Color::Green);

    //Desenha pontos jogador 2
    s1 = "Pontos: ";

    if(p2 > 999)
        p2 = 999;

    s2 = to_string(p2);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x + 350, 20);

    janela.draw(texto);

    //Desenha vidas jogador 2
    s1 = "Vidas: ";
    s2 = "000";

    s2 = to_string(v2);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x + 350, 80);

    janela.draw(texto);
}
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

    texto.setCharacterSize(40);
    texto.setFillColor(sf::Color::Yellow);
}

void Gerenciador_Grafico::imprimePontuacao(int pontos){
    string total = "Pontos: ";
    string pontuacao = "000";
    
    if(pontos > 999)
        pontos = 999;
    
    
    pontuacao = to_string(pontos);
    
    texto.setString(total + pontuacao);
    texto.setPosition(visao.getCenter().x + 400, 50);
    
    janela.draw(texto);
}

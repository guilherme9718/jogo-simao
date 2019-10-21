#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico():
janela(VideoMode(512, 512), "Jogo-Simao", Style::Default),
visao(Vector2f(0.0f, 0.0f), Vector2f(512.0f, 512.0f))
{
    
}

Gerenciador_Grafico::~Gerenciador_Grafico() {
    
}

void Gerenciador_Grafico::leEventos () {
    Event evento;
    while (janela.pollEvent(evento)) {
            switch (evento.type) {
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
}

void Gerenciador_Grafico::limpar() {
    janela.clear(Color::Black);
    janela.setView(visao);
}
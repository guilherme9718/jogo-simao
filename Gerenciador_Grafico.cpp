#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico():
janela(VideoMode(512, 512), "Jogo-Simao", Style::Default)
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
                    if(evento.text.unicode < 120)
                    cout << evento.text.unicode << " ";
                    break;
                default:
                    break;
            }
            
        }
}


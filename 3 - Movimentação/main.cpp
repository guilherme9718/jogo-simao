#include "stdafx.h"
#include "Jogador.h"
#include "Plataforma.h"

const float W1(1280);
const float H1(960);

const float WJ1(100);
const float HJ1(150);

const float WP1(200);
const float HP1(45);

void RedCam (const RenderWindow& janela, View& camera)
{
    float prop = float(janela.getSize().x) / float(janela.getSize().y);

    camera.setSize(H1 * prop, H1);
}

int main()
{
    Event evento1;
    RenderWindow janela1(VideoMode(W1,H1), "Janela 1", Style::Default);
    View camera1(Vector2f(0,0), Vector2f(W1, H1));

    float deltaTempo;
    Clock clock;

    Texture gnu;
    gnu.loadFromFile("Texturas/gnu.png");

    Texture droid;
    droid.loadFromFile("Texturas/droid.png");

    Texture plat1Tex;
    plat1Tex.loadFromFile("Texturas/plat1.png");

    Jogador jog1(Vector2f (WJ1, HJ1), 500, &gnu, Vector2u (3,9), 0.2, true, 200);
    jog1.setPosition(Vector2f (WJ1/2, H1 - HJ1/2));
    //jog1.setPosition(Vector2f (WJ1/2, 0));

    Jogador jog2(Vector2f (WJ1, HJ1), 0, &droid, Vector2u (3,9), 0.2, false, 0);
    //jog2.setPosition(Vector2f (W1 - WJ1/2, H1 - HJ1/2));
    jog2.setPosition(Vector2f (W1 - WJ1/2, 0));

    vector<Plataforma> plataformas;

    plataformas.push_back(Plataforma(&plat1Tex, Vector2f(WP1, HP1), Vector2f(WP1/2 + W1/4, H1 - HP1/2)));
    plataformas.push_back(Plataforma(&plat1Tex, Vector2f(WP1, HP1), Vector2f(-WP1/2 + 3*(W1/4), H1 - HP1/2)));
    plataformas.push_back(Plataforma(&plat1Tex, Vector2f(W1*2, 10), Vector2f(W1/2, H1)));


    while(janela1.isOpen())
    {
        deltaTempo = clock.restart().asSeconds();

        if(deltaTempo > 1.0f / 20.0f)
            deltaTempo = 1.0f / 20.0f;

        while(janela1.pollEvent(evento1))
        {
            switch (evento1.type)
            {
            case Event::Closed:
                janela1.close();
                break;

            case Event::Resized:
                RedCam(janela1, camera1);
                break;

            default:
                break;
            }
        }

        jog1.Atualiza(deltaTempo);
        jog2.Atualiza(deltaTempo);

        Vector2f direcao;

        for(Plataforma& plataforma : plataformas)
        {
            if(plataforma.getCollider().checar(jog1.getCollider(), direcao, 1))
                jog1.Colidindo(direcao);
            if(plataforma.getCollider().checar(jog2.getCollider(), direcao, 1))
                jog2.Colidindo(direcao);
        }

        jog1.getCollider().checar(jog2.getCollider(), direcao, 1);

        camera1.setCenter(Vector2f(jog1.getPosition() + W1/4, H1/2));

        janela1.clear(Color::White);
        janela1.setView(camera1);

        jog1.desenha(janela1);
        jog2.desenha(janela1);

        for(Plataforma& plataforma : plataformas)
            plataforma.desenha(janela1);

        janela1.display();
    }

    return 0;
}

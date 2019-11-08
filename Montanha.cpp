#include "Montanha.h"
#include "Jogo.h"

Montanha::Montanha(Jogo* jooj):
Fase(jooj), fundo(5, pJogo->getGerenciador())
{
    pGG = pJogo->getGerenciador();
    doisJogadores = pJogo->getDoisJogadores();
    srand(time(NULL));
    colisora = new Colisora();

    //Instanciar jogador

    jogador1 = new Huatli(pJogo->getGerenciador());
    pJogo->setJogador1(jogador1);
    entidades.incluir(static_cast<Entidade*>(jogador1));

    if(doisJogadores) {
        jogador2 = new Angrath(pJogo->getGerenciador());
        pJogo->setJogador2(jogador2);
        entidades.incluir(static_cast<Entidade*>(jogador2));
    }

    instanciaFundo();

    // Instanciar plataformas
    instanciaPlataformas();

    //Posicao em y da plataforma:
    //Tamanho da janela (960) - (plat->getTamanho().y / 2.0f) == mais baixo possivel

    //Para colar duas plataformas: 480 de posicao em x uma da outra
    //Distancia ideal de pulo: (tamanho da plataforma + 400)  de posicao em x uma da outra considerando mesma altura


}

Montanha::~Montanha() {
    
}

void Montanha::executar() {

    fundo.setPosicao(pJogo->getGerenciador()->getVisao()->getCenter());
    fundo.imprimir();

    entidades.executar();
    entidades.imprimir();

    if(doisJogadores) {
        entidades.colidir(jogador1, jogador2, colisora);
        if(jogador1->getPosicao().y > 2000.0f)
            jogador1->morrer(Vector2f(jogador2->getPosicao().x, -1000));
        if(jogador2->getPosicao().y > 2000.0f)
            jogador2->morrer(Vector2f(jogador1->getPosicao().x, -1000));
    }
    else {
        entidades.colidir(jogador1, colisora);
        
        if(jogador1->getPosicao().y > 2000.0f)
            jogador1->morrer();
    }

    pontuacao();

    //cout << jogador1->getPosicao().x << " " << jogador1->getPosicao().y << endl;
}

void Montanha::instanciaPlataformas() {
    ifstream plats ("Arquivos/Plataformas.txt", ios::in);
    Vector2f pos, tam;
    Plataforma* plat;
    float aux, aux2;
    int tipo;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,2);

    if (!plats)
    {
        cout << "a";
    }

    plats >> contPlat;

    //Instancia a plataforma do jogador

    plats >> tam.x >> tam.y;
    plats >> pos.x >> pos.y;
    plats >> tipo;

    plat = new Plataforma(tam);
    plat->setGerenciador(pJogo->getGerenciador());
    plat->getCorpoGraf()->setPosicao(pos);
    entidades.incluir(static_cast<Entidade*>(plat));

    //Instancia as outras plataformas

    for (int i = 1; i < contPlat; i++)
    {
        plats >> tam.x >> tam.y;
        plats >> pos.x >> pos.y;
        plats >> tipo;

        plat = new Plataforma(tam);
        plat->setGerenciador(pJogo->getGerenciador());
        plat->getCorpoGraf()->setPosicao(pos);
        entidades.incluir(static_cast<Entidade*>(plat));

        int aleatorio = dist(rng);
        aleatorio = rand()%3;

        if(tipo) {
            if(aleatorio == 0) {
                instanciaInimigos(plat);
                instanciaObstaculos(plat);
            }
            else if (aleatorio == 1)
                instanciaObstaculos(plat);
            else if (aleatorio == 2)
                instanciaInimigos(plat);
        }

    }

    plats.close();
}

void Montanha::instanciaInimigos(Plataforma* plat) {

    Andino* andi;
    Carnivora* carn;

    andi = new Andino(plat);
    entidades.incluir(static_cast<Entidade*>(andi));

//    carn = new Carnivora(pJogo->getGerenciador());
//    carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 100.0f, plat->getPosicao().y - 70.0f));
//    entidades.incluir(static_cast<Entidade*>(carn));
//
//    carn = new Carnivora(pJogo->getGerenciador());
//    carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f, plat->getPosicao().y - 70.0f));
//    entidades.incluir(static_cast<Entidade*>(carn));
}

void Montanha::instanciaObstaculos(Plataforma* plat) {

    Carnivora* carn;
    Pedra* pedra;
    
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<uint32_t> distribuicao(0,1);

    int aleatorio = distribuicao(rng);
    aleatorio = rand()%2;

    if(aleatorio == 0) {
        carn = new Carnivora(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 200.0f, plat->getPosicao().y - 70.0f));
        entidades.incluir(static_cast<Entidade*>(carn));

        carn = new Carnivora(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 200.0f, plat->getPosicao().y - 70.0f));
        entidades.incluir(static_cast<Entidade*>(carn));

        carn = new Carnivora(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x, plat->getPosicao().y - 70.0f));
        entidades.incluir(static_cast<Entidade*>(carn));
    }

    else if (aleatorio == 1) {
        carn = new Carnivora(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 110.0f, plat->getPosicao().y - 70.0f));
        entidades.incluir(static_cast<Entidade*>(carn));

        carn = new Carnivora(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 40.0f, plat->getPosicao().y - 70.0f));
        entidades.incluir(static_cast<Entidade*>(carn));

        carn = new Carnivora(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 30.0f , plat->getPosicao().y - 70.0f));
        entidades.incluir(static_cast<Entidade*>(carn));

        carn = new Carnivora(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f , plat->getPosicao().y - 70.0f));
        entidades.incluir(static_cast<Entidade*>(carn));
    }
    
    else if (aleatorio == 2)
    {
        pedra = new Pedra(plat);
        entidades.incluir(static_cast<Entidade*>(pedra));
    }
}

void Montanha::instanciaFundo() {
    int i;

    fundo.setTextura("Texturas/Montanha/parallax-mountain-bg.png", 0);
    fundo.setTextura("Texturas/Montanha/parallax-mountain-montain-far.png", 1);
    fundo.setTextura("Texturas/Montanha/parallax-mountain-mountains.png", 2);
    fundo.setTextura("Texturas/Montanha/parallax-mountain-trees.png", 3);
    fundo.setTextura("Texturas/Montanha/parallax-mountain-foreground-trees.png", 4);

    fundo.setTamanho(Vector2f(1280.0f, 960.0f));
}

void Montanha::pontuacao() {
    if(doisJogadores)
        {
            pGG->imprimePontuacao(jogador1->getPontos(), jogador1->getVidas(), jogador2->getPontos(), jogador2->getVidas());
            pGG->getVisao()->setCenter(Vector2f((jogador1->getPosicao().x + jogador2->getPosicao().x) / 2.0f, 960.0f / 2.0f));
        }

        else
        {
            pGG->imprimePontuacao(jogador1->getPontos(), jogador1->getVidas());
            pGG->getVisao()->setCenter(Vector2f(jogador1->getPosicao().x + 1280.0f / 4.0f, 960.0f / 2.0f));
        }
}
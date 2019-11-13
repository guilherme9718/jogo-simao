#include "Floresta.h"
#include "Jogo.h"

using namespace Fases;

Floresta::Floresta(Jogo* jooj, bool dois, Huatli* j1, Angrath* j2):
Fase(jooj, dois), fundo(2, pJogo->getGerenciador())
{
    id = 1;
    pGG = pJogo->getGerenciador();
    srand(time(NULL));
    colisora = new Colisora();
    
    //Instanciar jogador
    jogador1 = new Huatli(pGG);
    jogador1->setVidas(j1->getVidas());
    jogador1->setPontos(j1->getPontos());
    jogador1->setPosicao(Vector2f(jogador1->getPosicao().x, -1000.0f));
    entidades.incluir(static_cast<Entidade*>(jogador1));

    if(doisJogadores) {
        jogador2 = new Angrath(pGG);
        jogador2->setVidas(j2->getVidas());
        jogador2->setPontos(j2->getPontos());
        jogador2->setPosicao(Vector2f(jogador2->getPosicao().x, -1000.0f));
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

Floresta::Floresta(Jogo* jooj, bool dois, string salvo):
Fase(jooj, dois), fundo(2, pJogo->getGerenciador())
{
    id = 0;
    pGG = pJogo->getGerenciador();
    srand(time(NULL));
    colisora = new Colisora();
    jogador2 = NULL;
    jogador1 = NULL;
    instanciaFundo();
    
    if(salvo == "") {
        //Instanciar jogador

        jogador1 = new Huatli(pJogo->getGerenciador());
        entidades.incluir(static_cast<Entidade*>(jogador1));

        if(doisJogadores) {
            jogador2 = new Angrath(pJogo->getGerenciador());
            entidades.incluir(static_cast<Entidade*>(jogador2));
        }

        // Instanciar plataformas
        instanciaPlataformas();
    }
    else {
        //Carregar jogo Salvo
        carregar(salvo, 1);
    }

}

Floresta::~Floresta() {

}

void Floresta::executar() {

    menuPause();
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
    
    reiniciar();

    pontuacao();

}

void Floresta::instanciaPlataformas() {
    ifstream plats ("Arquivos/PlataformasFloresta.txt", ios::in);
    Vector2f pos, tam;
    Plataforma* plat;
    Atiradino* atr;
    ChefeDino* chefe;
    int tipo;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,2);

    if (!plats)
    {
        cerr << "Erro ao carregar o arquivo de Plataformas";
    }

    plats >> contPlat;


    //Instancia as outras plataformas

    for (int i = 0; i < contPlat; i++)
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

        if(tipo == 1) {
            if(aleatorio == 0) {
                instanciaInimigos(plat);
                instanciaObstaculos(plat);
            }
            else if (aleatorio == 1)
                instanciaObstaculos(plat);
            else if (aleatorio == 2)
                instanciaInimigos(plat);
        }
        else if(tipo == 2)
        {
            if(aleatorio)
            {
                atr = new Atiradino(plat);
                entidades.incluir(static_cast<Entidade*>(atr));
                entidades.incluir(static_cast<Entidade*>(atr->getProjetil()));
            }
        }
        else if(tipo == 3)
        {
            chefe = new ChefeDino(plat);
            int numJog = (int)doisJogadores + 1;
            chefe->setVidas(numJog * 4);
            entidades.incluir(static_cast<Entidade*>(chefe));
            entidades.incluir(static_cast<Entidade*>(chefe->getProjetil()));
        }
    }

    plats.close();
}

void Floresta::instanciaInimigos(Plataforma* plat) {
    Andino* andi;
    Atiradino* atr;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<uint32_t> distribuicao(0,1);

    int aleatorio = distribuicao(rng);
    aleatorio = rand()%2;

    if(aleatorio == 0)
    {
        andi = new Andino(plat);
        entidades.incluir(static_cast<Entidade*>(andi));

        andi = new Andino(plat);
        entidades.incluir(static_cast<Entidade*>(andi));
    }

    else if(aleatorio == 1)
    {
        atr = new Atiradino(plat);
        entidades.incluir(static_cast<Entidade*>(atr));
        entidades.incluir(static_cast<Entidade*>(atr->getProjetil()));

        andi = new Andino(plat);
        entidades.incluir(static_cast<Entidade*>(andi));
    }
}

void Floresta::instanciaObstaculos(Plataforma* plat) {

    Carnivora* carn;
    Pedra* pedra;
    Galhos* galho;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<uint32_t> distribuicao(0,1);

    int aleatorio = distribuicao(rng);
    aleatorio = rand() % 4;

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

        carn = new Carnivora(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f , plat->getPosicao().y - 70.0f));
        entidades.incluir(static_cast<Entidade*>(carn));
    }
    
    else if (aleatorio == 3) {
        galho = new Galhos(plat);
        entidades.incluir(static_cast<Entidade*>(galho));
    }
}

void Floresta::instanciaFundo() {

    fundo.setTextura("Texturas/Floresta/Nuvens.png", 0);
    fundo.setTextura("Texturas/Floresta/Backgroud3.png", 1);

    fundo.setTamanho(Vector2f(1280.0f, 960.0f));
}

void Floresta::pontuacao() {
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

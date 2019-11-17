#include "FabricaFloresta.h"

using namespace Fabricas;

FabricaFloresta::FabricaFloresta(Jogo* jogo):
FabricaFase(jogo)
{
    idFase = 1;
}

FabricaFloresta::~FabricaFloresta() {
}

Fase* FabricaFloresta::criar() {
    fase = static_cast<Fase*>(new Floresta(pJogo, doisJogadores));
    
    if(carrega) {
        carregar();
    }
    else {
        instanciaJogadores();
        instanciaPlataformas();
    }
    
    instanciaFundo();
    limpar();
    
    return fase;  
}

void FabricaFloresta::instanciaJogadores() {

    if(not j1) {
        j1 = new Huatli(pJogo->getGerenciador());        
    }
    if(not j2) {
        if(doisJogadores) {
            j2 = new Angrath(pJogo->getGerenciador());   
        }
    }
    fase->incluirEntidade(static_cast<Entidade*>(j1));
    fase->incluirEntidade(static_cast<Entidade*>(j2));
    fase->setJogador1(j1);
    fase->setJogador2(j2);
}

void FabricaFloresta::instanciaPlataformas() {
    ifstream plats ("Arquivos/PlataformasFloresta.txt", ios::in);
    Vector2f pos, tam;
    Plataforma* plat;
    Atiradino* atr;
    ChefeDino* chefe;
    int tipo;

    if (!plats)
    {
        cerr << "Erro ao carregar o arquivo de Plataformas";
    }

    //Instancia as outras plataformas

    while (plats >> tam.x >> tam.y)
    {
        plats >> pos.x >> pos.y;
        plats >> tipo;

        plat = new Plataforma(tam);
        plat->setGerenciador(pJogo->getGerenciador());
        plat->getCorpoGraf()->setPosicao(pos);
        fase->incluirEntidade(static_cast<Entidade*>(plat));

        int aleatorio;
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
                fase->incluirEntidade(static_cast<Entidade*>(atr));
                fase->incluirEntidade(static_cast<Entidade*>(atr->getProjetil()));
            }
        }
        else if(tipo == 3)
        {
            chefe = new ChefeDino(plat);
            int numJog = (int)doisJogadores + 1;
            chefe->setVidas(numJog * 4);
            fase->incluirEntidade(static_cast<Entidade*>(chefe));
            fase->incluirEntidade(static_cast<Entidade*>(chefe->getProjetil()));
        }
    }

    plats.close();
}

void FabricaFloresta::instanciaInimigos(Plataforma* plat) {
    Andino* andi;
    Atiradino* atr;
    int aleatorio;
    
    aleatorio = rand()%2;

    if(aleatorio == 0)
    {
        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade*>(andi));

        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade*>(andi));
    }

    else if(aleatorio == 1)
    {
        atr = new Atiradino(plat);
        fase->incluirEntidade(static_cast<Entidade*>(atr));
        fase->incluirEntidade(static_cast<Entidade*>(atr->getProjetil()));

        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade*>(andi));
    }
}

void FabricaFloresta::instanciaObstaculos(Plataforma* plat) {

    Espinho* carn;
    Pedra* pedra;
    Galho* galho;

    int aleatorio;
    
    aleatorio = rand() % 4;

    if(aleatorio == 0) {
        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 200.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade*>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 200.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade*>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade*>(carn));
    }

    else if (aleatorio == 1) {
        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 110.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade*>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 40.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade*>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 30.0f , plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade*>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f , plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade*>(carn));
    }

    else if (aleatorio == 2)
    {
        pedra = new Pedra(plat);
        fase->incluirEntidade(static_cast<Entidade*>(pedra));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f , plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade*>(carn));
    }
    
    else if (aleatorio == 3) {
        galho = new Galho(plat);
        fase->incluirEntidade(static_cast<Entidade*>(galho));
    }
}

void FabricaFloresta::instanciaFundo() {
    Fundo* fundo = new Fundo(2, pJogo->getGerenciador());
            
    fundo->setTextura("Texturas/Floresta/Nuvens.png", 0);
    fundo->setTextura("Texturas/Floresta/Backgroud3.png", 1);

    fundo->setTamanho(Vector2f(1280.0f, 960.0f));
    
    fase->setFundo(fundo);
}
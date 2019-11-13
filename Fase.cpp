#include "Fase.h"
#include "MenuPause.h"

using namespace Fases;

Fase::Fase(Jogo* jooj, bool dois):
jogador1(NULL), jogador2(NULL)
{
    Plataforma::setContIdPlat(0);
    doisJogadores = dois;
    pJogo = jooj;
    id = -1;
}

Fase::~Fase() {
}

void Fase::executar() {

}
void Fase::gerenciar_colisoes() {

}

void Fase::reiniciar() {
    if(doisJogadores) {
        if(jogador2->getVidas() <= 0)
            pJogo->tirarEstado();
    }
    if(jogador1->getVidas() <= 0)
        pJogo->tirarEstado();
}

void Fase::menuPause() {
    if(Keyboard::isKeyPressed(Keyboard::Escape)) {
        pJogo->colocarEstado( reinterpret_cast<Estado*>(new MenuPause(pJogo)) );
    }
}

void Fase::salvar(string nome) {
    pers.setNome(nome);
    entidades.gravar(&pers);
    pers.gravarFase(id);
}

void Fase::carregar(string salvo, int idFase) {
    //instanciaFundo();
    ifstream leitor;
    ifstream plats;
    
    if(idFase == 0)
        plats.open("Arquivos/PlataformasMontanha.txt", ios::in);
    else if(idFase == 1)
        plats.open("Arquivos/PlataformasFloresta.txt", ios::in);
    
    if(!plats) {
        cerr << "Falha ao abrir o Arquivo";
    }
    
    int tipo=0, id=0, aux1=0, aux2=0, numJogadores = 1, i=0;
    Vector2f pos, tam;
    
    Entidade* ent = NULL;
    Inimigo* inim = NULL;
    Plataforma* plat = NULL;
    Andino* andi = NULL;
    Atiradino* atira = NULL;
    Carnivora* esp = NULL;
    ChefeDino* chefe = NULL;
    Galhos* galho = NULL;
    Pedra* pedra = NULL;
    Jogador* jog = NULL;
    
    if(doisJogadores)
        numJogadores = 2;
    
    leitor.open("Arquivos/Jogos/Jogador" + salvo + ".dino", ios::in);
    
    if(!leitor) {
        cerr << "Falha ao abrir arquivo";
    }
    
    for(i = 0; i < numJogadores; i++) {
        leitor >> id;
        if(id == 7) {
            jogador1 = new Huatli(pJogo->getGerenciador());
            jog = static_cast<Jogador*>(jogador1);
        }
        else {
            jogador2 = new Angrath(pJogo->getGerenciador());
            jog = static_cast<Jogador*>(jogador2);
        }
            
        //Pontos
        leitor >> aux1;
        //Vidas
        leitor >> aux2;
        //Posição x, y
        leitor >> pos.x >> pos.y;
        
        jog->setPontos(aux1);
        jog->setVidas(aux2);
        jog->setPosicao(pos);   
        entidades.incluir(static_cast<Entidade*>(jog));
    }
    leitor.close();

    plats >> contPlat;
    plataformas.reserve(contPlat);
    for (int i = 0; i < contPlat; i++)
    {
        plats >> tam.x >> tam.y;
        plats >> pos.x >> pos.y;
        plats >> tipo;

        plat = new Plataforma(tam);
        plat->setGerenciador(pJogo->getGerenciador());
        plat->getCorpoGraf()->setPosicao(pos);
        entidades.incluir(static_cast<Entidade*>(plat));
        plataformas.push_back(plat);
    }

    plats.close();
    
    leitor.open("Arquivos/Jogos/Objetos" + salvo + ".dino", ios::in);
    
    if(!leitor) {
        cerr << "Falha ao abrir arquivo";
    }
    
    while(leitor >> id) {
        inim = NULL;
        
        //Plataforma
        leitor >> aux1;
        
        //Posição
        leitor >> pos.x >> pos.y;
        
        switch (id) {
            case 1:
                inim = static_cast<Inimigo*>(new Andino(plataformas.at(aux1)));
                ent = static_cast<Entidade*>(inim);
                break;
            case 3:
                inim = static_cast<Inimigo*>(new Atiradino(plataformas.at(aux1)));
                ent = static_cast<Entidade*>(inim);
                break;
            case 4:
                ent = static_cast<Entidade*>( new Carnivora(pJogo->getGerenciador()) );
                break;
            case 5:
                inim = static_cast<Inimigo*>(new ChefeDino(plataformas.at(aux1)));
                ent = static_cast<Entidade*>(inim);
                break;
            case 6:
                ent = static_cast<Entidade*>(new Galhos(plataformas.at(aux1)));
                break;
            case 8:
                ent = static_cast<Entidade*>(new Pedra(plataformas.at(aux1)));
                break;
            default:
                break;
        }
        
        ent->setPosicao(pos);
        if(inim) {
            //Vidas
            leitor >> aux2;
            inim->setVidas(aux2);
        }
        
        entidades.incluir(ent);
    }
    
    leitor.close();
}

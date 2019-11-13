#include "Persistidora.h"

/*

 * 1 - Andino
 * 2 - Angrath
 * 3 - Atiradino
 * 4 - Espinho
 * 5 - ChefeDino
 * 6 - Galhos
 * 7 - Huatli
 * 8 - Pedra

 */

Persistidora::Persistidora() {
    doisJogadores = 0;
    pontosTotais = 0;
    string nome = "Sem nome";
}

Persistidora::~Persistidora() {
}

void Persistidora::criarArquivos() {
    ofstream arquivo;
    string aux;
    
    arq[0] = ("Arquivos/Jogos/" + ("Jogador" + nome)) + ".dat";
    arquivo.open(arq[0], ios::out | ios::trunc);
    arquivo.close();
    
    arq[1] = ("Arquivos/Jogos/" + ("Objetos" + nome)) + ".dat";
    arquivo.open(arq[1], ios::out | ios::trunc);
    arquivo.close();
    
    arq[2] = ("Arquivos/Jogos/" + ("Fase" + nome)) + ".dat";
    arquivo.open(arq[2], ios::out | ios::trunc);
    arquivo.close();
    
    aux = "Arquivos/Jogos/Salvos.dat";
    arquivo.open(aux, ios::app);
    arquivo << nome << endl;
    arquivo.close();
}

void Persistidora::gravar(pair<Entidade*,int> p) {
    switch (p.second) {
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            gravarInimigosObstaculos(p.first, p.second);
            break;
        case 2:
        case 7:
            gravarJogadores(reinterpret_cast<Jogador*>(p.first), p.second);
            break;
        default:
            break;
    }
    
}

void Persistidora::gravarInimigosObstaculos(Entidade* ent, int id) {
    ofstream gravador(arq[1], ios::app);
    Inimigo* inim;
    
    if(!gravador) {
        cerr << "erro ao abrir o arquivo";
        return;
    }
    
    gravador << id << ' ';
    
    if(ent->getPlataforma())
        gravador << ent->getPlataforma()->getIdPlataforma() << ' ';
    else
        gravador << -1 << ' ';
    
    gravador << ent->getPosicao().x << ' ' << ent->getPosicao().y << ' ';
    
    if(id == 1 || id == 3 || id == 5) {
        inim = reinterpret_cast<Inimigo*>(ent);
        gravador << inim->getVidas() << ' ';
    }
    
    gravador << endl;
    gravador.close();
}

void Persistidora::gravarJogadores(Jogador* j, int id) {
    ofstream gravador(arq[0], ios::app);
    
    if(!gravador) {
        cerr << "erro ao abrir o arquivo";
        return;
    }
    if(id == 2)
        doisJogadores = 1;
    
    pontosTotais += j->getPontos();
    
    gravador << id << ' ';
    gravador << j->getPontos() << ' ';
    gravador << j->getVidas() << ' ';
    gravador << j->getPosicao().x << ' ' << j->getPosicao().y << ' ';
    gravador << endl;
    gravador.close();
}

void Persistidora::gravarFase(const unsigned int id) {
    ofstream gravador(arq[2], ios::app);
    
    gravador << id << endl;
    gravador << doisJogadores << endl;
    gravador << pontosTotais << endl;
    gravador.close();
}
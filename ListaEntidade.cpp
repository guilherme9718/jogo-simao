#include "ListaEntidade.h"
#include "Jogador.h"


ListaEntidade::ListaEntidade() {
    
}

ListaEntidade::~ListaEntidade() {
    limpar();
}



void ListaEntidade::percorrerExecutar() {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro();
    
    while(itr) {
        itr->getAtual()->executar();
        itr = itr->getProx();
    }
}
void ListaEntidade::percorrerImprimir() {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro();
    
    while(itr) {
        itr->getAtual()->imprimir();
        itr = itr->getProx();
    }
}

void ListaEntidade::colidirTodos(Jogador* jog) {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro(), *aux = NULL;
    Vector2f direcao(0.0f, 0.0f);
    
    while(itr) {
        aux = itr->getProx();
        if(itr->getAtual()->verificarColisao(jog->getColisora(), direcao, 0.0f);
        if(jog->getAtacando())
            if(itr->getAtual()->verificarColisao(jog->getHitbox()->getColisora(), direcao)) {
                excluir(itr);
            }
        
        itr = aux;
    }
}

void ListaEntidade::incluir(Entidade* ent) {
    LEs.incluir(ent);
}

void ListaEntidade::limpar() {
    LEs.limpar();
}

void ListaEntidade::excluir(Lista<Entidade>::Elemento<Entidade>* no) {
    Lista<Entidade>::Elemento<Entidade> *aux = NULL;
    
    if(no) {
        if(no->getProx()) {
            if(no->getAnt()) {
                no->getAnt()->setProx(no->getProx());
                no->getProx()->setAnt(no->getAnt());
            }
            else {
                no->getProx()->setAnt(NULL);
            }
        }
        else {
            no->getAnt()->setProx(NULL);
        }
        delete no->getAtual();
        delete no;
    }
}

void ListaEntidade::excluir(int id) {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro(), *aux = NULL;
    
    while(itr) {
        if(itr->getAtual()->getId() == id) {
            aux = itr->getProx();
            itr = itr->getAnt();
            delete (itr->getProx());
            itr->setProx(aux);
        }
        itr = itr->getProx();
    }
}


#include "ListaEntidade.h"


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

void ListaEntidade::colidirTodos(Entidade* obj) {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro();
    Vector2f direcao(0.0f, 0.0f);
    
    while(itr) {
        if(itr->getAtual() != obj)
            itr->getAtual()->verificarColisao(obj->getColisora(), direcao, 0.0f);
        
        itr = itr->getProx();
    }
}

void ListaEntidade::incluir(Entidade* ent) {
    LEs.incluir(ent);
}

void ListaEntidade::limpar() {
    LEs.limpar();
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


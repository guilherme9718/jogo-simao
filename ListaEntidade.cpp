#include "ListaEntidade.h"

ListaEntidade::ListaEntidade() {
    
}

ListaEntidade::~ListaEntidade() {
    limpar();
}

void ListaEntidade::percorrer() {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro();
    
    while(itr) {
        itr->getAtual()->executar();
        itr = itr->getProx();
    }
}

void ListaEntidade::incluir(Entidade* ent) {
    LEs.incluir(ent);
}

void ListaEntidade::limpar() {
    LEs.limpar();
}

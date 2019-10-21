#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Lista.h"

class ListaEntidade {
public:
    ListaEntidade();
    ~ListaEntidade();
    
    void percorrer();
    
    void incluir(Entidade* ent);
    void limpar();
private:
    Lista<Entidade> LEs;

};



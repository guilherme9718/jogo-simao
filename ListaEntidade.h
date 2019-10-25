#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Lista.h"

class ListaEntidade {
public:
    ListaEntidade();
    ~ListaEntidade();
    
    void percorrerExecutar();
    void percorrerImprimir();
    
    void colidirTodos(Entidade* obj);
    
    void incluir(Entidade* ent);
    void excluir(int id);
    void limpar();
private:
    Lista<Entidade> LEs;

};



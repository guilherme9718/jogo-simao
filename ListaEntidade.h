#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Lista.h"
#include "Jogador.h"

class ListaEntidade {
public:
    ListaEntidade();
    ~ListaEntidade();
    
    void percorrerExecutar();
    void percorrerImprimir();
    
    void colidirTodos(Jogador* jog);
    
    void incluir(Entidade* ent);
    void excluir(int id);
    void limpar();
private:
    Lista<Entidade> LEs;
    void excluir(Lista<Entidade>::Elemento<Entidade>* no);
};



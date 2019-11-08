#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Lista.h"
#include "Jogador.h"

class ListaEntidade {
public:
    ListaEntidade();
    ~ListaEntidade();

    void executar();
    void imprimir();
    
    void colidir(Jogador* j, Colisora* colisora);
    void colidir(Jogador* j, Jogador* j2, Colisora* colisora);

    void incluir(Entidade* ent);
    //void excluir(int id);
    void limpar();
private:
    Lista<Entidade> LEs;
    void excluir(Lista<Entidade>::Elemento<Entidade>* no);
};


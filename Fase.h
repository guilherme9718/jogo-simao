#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Ent.h"
#include "Huatli.h"
#include "Angrath.h"
#include "Persistidora.h"
#include "Andino.h"
#include "Atiradino.h"
#include "Carnivora.h"
#include "ChefeDino.h"
#include "Galhos.h"
#include "Pedra.h"
#include "Jogo.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
using namespace GerenciadoresFases;
using namespace Inimigos;
using namespace Personagens;
using namespace Obstaculos;
using namespace Controladoras;


namespace Fases {
    class Fase {
    public:
        Fase(Jogo* jooj = NULL, bool dois = false);
        virtual ~Fase();

        //virtual void instanciaFundo() = 0;
        virtual void executar();
        virtual void gerenciar_colisoes();
        virtual void reiniciar();
        void salvar(string nome = "SemNome");
        void menuPause();
        virtual void carregar(string salvo, int idFase=0);

        //Sets e Gets
        Huatli* getJogador1() { return jogador1; }
        Angrath* getJogador2() { return jogador2; }

        void setJogo(Jogo* jooj) { pJogo = jooj; }
    protected:
        ListaEntidade entidades;
        vector<Plataforma*> plataformas;
        Persistidora pers;

        Jogo* pJogo;
        Huatli* jogador1;
        Angrath* jogador2;

        bool doisJogadores;

        unsigned short int contPlat;
        unsigned short int contInim;
        unsigned short int contObs;
        unsigned short int contJog;

        unsigned short id;

    };
}


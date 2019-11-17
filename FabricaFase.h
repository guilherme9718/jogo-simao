#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Huatli.h"
#include "Angrath.h"
#include "Persistidora.h"
#include "Andino.h"
#include "Atiradino.h"
#include "Espinho.h"
#include "ChefeDino.h"
#include "Galho.h"
#include "Pedra.h"
#include "Jogo.h"
#include "Fase.h"
#include "Jogador.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
using namespace GerenciadoresFases;
using namespace Inimigos;
using namespace Personagens;
using namespace Obstaculos;
using namespace Controladoras;
using namespace Fases;

namespace Fabricas {
    class FabricaFase {
    public:
        FabricaFase(Jogo* jogo = NULL);
        virtual ~FabricaFase();
        
        virtual Fase* criar() = 0;
        
        void limpar();
        
        //Sets e Gets
        void setCarregar(const bool c) { carrega = c; }
        void setDoisJogadores(const bool dois) { doisJogadores = dois; }
        void setJogadores(Huatli* jog1, Angrath* jog2);
        
    protected:
        
        virtual void carregar();
        
        Jogo* pJogo;
        bool carrega;
        bool doisJogadores;
        
        short idFase;
        
        Huatli* j1;
        Angrath* j2;
        
        
        Fase* fase;
        vector<Plataforma*> plataformas;
    };
}
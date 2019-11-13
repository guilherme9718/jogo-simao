#pragma once
#include "stdafx.h"
#include "Ent.h"
#include "Gerenciador_Grafico.h"
#include "Fundo.h"
#include "Jogo.h"
#include "Montanha.h"

using namespace Fases;


namespace Controladoras {
    class Menu : public Ent {
    public:
        Menu(Jogo* jogo = NULL);
        ~Menu();

        void executar();

        void leEntradas();
        void posicionarTexto();
        void carregar(string nome = "SemNome");
        void limparEstados();

        //Sets e gets
        void setPressionar(const bool press) { pressionar = press; }
        void setJogo(Jogo* jogo) { pJogo = jogo; }
    protected:
        Jogo* pJogo;
        Gerenciador_Grafico* pGG;

        int opcao;
        int selecionado;
        bool pressionar;


        Fundo fundo;

        Font fonte;
        vector<Text> texto;

        float totalT;
    };

}

#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"
#include "Estado.h"



using namespace Estados;

namespace Controladoras {
    class Jogo {
    public:
        Jogo();
        ~Jogo();

        void executar();

        void tirarEstado(bool excluir = true);
        void colocarEstado(Estado* est) { estados.push(est); }
        const bool pilhaVazia() { return estados.empty(); }
        const unsigned int pilhaTam() const { return estados.size(); }
        Estado* getTopo() const { if(not estados.empty()) return estados.top(); }


        //Sets e Gets

        Gerenciador_Grafico* getGerenciador() { return &GG; }
    private:


        stack<Estado*> estados;
        stack<Estado*> lixo;

        Gerenciador_Grafico GG;
    };
}
#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Projetil : public Entidade {
public:
    Projetil(Gerenciador_Grafico* GG = NULL);
    ~Projetil();
    
    void executar() { }
    
private:
    
};


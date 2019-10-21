#pragma once
#include "stdafx.h"
#include "Jogador.h"

class Huatli : public Jogador {
public:
    Huatli(Gerenciador_Grafico* gerenciador = NULL);
    ~Huatli();
    
    void mover();
private:
    

};


#pragma once
#include "stdafx.h"
#include "Ent.h"
#include "Gerenciador_Grafico.h"
#include "Corpo_Grafico.h"

class Entidade : public Ent {
public:
    Entidade(Gerenciador_Grafico* gerenciador = NULL);
    virtual ~Entidade();
    
    virtual void executar();
    virtual void imprimir() = 0;
protected:
    Corpo_Grafico corpo;
    Gerenciador_Grafico *pGG;
};



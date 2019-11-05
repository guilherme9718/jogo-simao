#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Obstaculo : public Entidade {
public:
    Obstaculo(Gerenciador_Grafico* g);
    virtual ~Obstaculo();

    void Colidindo(Vector2f direcao) {} ;

protected:

};



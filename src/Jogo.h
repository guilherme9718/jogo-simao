#pragma once
#include "stdafx.h"
#include "Fase.h"
#include "Jogador.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "Montanha.h"
#include "Floresta.h"
#include "Huatli.h"
#include "Angrath.h"
#include "MenuPrincipal.h"

class Jogo {
public:
    Jogo();
    ~Jogo();

    void executar();

    //Sets e Gets

    Gerenciador_Grafico* getGerenciador() { return &GG; }

    void setEstado(Estado* est) { estado = est; }
private:

    MenuPrincipal* menu;

    Estado* estado;

    Gerenciador_Grafico GG;
};

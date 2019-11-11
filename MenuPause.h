#pragma once
#include "stdafx.h"
#include "Menu.h"
#include "MenuPauseEstado.h"

class MenuPause : public Menu, public MenuPauseEstado {
public:
    MenuPause(Jogo* jogo);
    virtual ~MenuPause();
    
    void executar();
private:

};


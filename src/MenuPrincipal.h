#pragma once
#include "stdafx.h"
#include "MenuPrincipalEstado.h"
#include "Menu.h"
#include "Estado.h"
#include "Montanha.h"

class MenuPrincipal : public Menu, public MenuPrincipalEstado {
public:
    MenuPrincipal(Jogo* jogo);
    ~MenuPrincipal();

    void executar();
private:
    Montanha* montanha;
    Floresta* floresta;

};

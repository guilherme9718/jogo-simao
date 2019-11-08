#pragma once
#include "stdafx.h"
#include "MenuPrincipalEstado.h"
#include "Menu.h"

class MenuPrincipal : public Menu, public MenuPrincipalEstado {
public:
    MenuPrincipal();
    virtual ~MenuPrincipal();
private:

};
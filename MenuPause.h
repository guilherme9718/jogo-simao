#pragma once
#include "stdafx.h"
#include "Menu.h"
#include "MenuPauseEstado.h"
#include "MenuPrincipal.h"

using namespace Controladoras;
using namespace Estados;

namespace Controladoras {
    class MenuPause : public Menu, public MenuPauseEstado {
    public:
        MenuPause(Jogo* jogo);
        virtual ~MenuPause();

        void executar();
    private:

    };
}


#pragma once
#include "stdafx.h"
#include "MenuPrincipalEstado.h"
#include "Menu.h"
#include "Estado.h"
#include "Montanha.h"
#include "Floresta.h"

using namespace Controladoras;
using namespace Estados;
using namespace Fases;


namespace Controladoras {
    class MenuPrincipal : public Menu, public MenuPrincipalEstado {
    public:
        MenuPrincipal(Jogo* jogo);
        ~MenuPrincipal();

        void executar();
        void setSelecionado(const int s) { selecionado = s; }

    private:
        Montanha* montanha;
        Floresta* floresta;

    };
}

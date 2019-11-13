#pragma once
#include "stdafx.h"
#include "MenuEstado.h"


using namespace Estados;

namespace Estados {
    class MenuPrincipalEstado : public MenuEstado {
    public:
        MenuPrincipalEstado();
        virtual ~MenuPrincipalEstado();

        virtual void executar();
    private:

    };
}


#pragma once
#include "stdafx.h"




namespace Estados {
    class Estado {
    public:
        Estado();
        virtual ~Estado();

        virtual void executar() = 0;
    private:

    };
}


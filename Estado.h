#pragma once
#include "stdafx.h"

class Estado {
public:
    Estado();
    virtual ~Estado();
    
    virtual void executar() = 0;
private:

};


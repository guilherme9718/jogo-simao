#pragma once
#include "stdafx.h"

class Ent {
public:
    Ent();
    virtual ~Ent();
protected:
    int id;
    static int cont;
};
#pragma once
#include "stdafx.h"

template <class TL>
class Lista {
public:
    Lista();
    ~Lista();
    
    void incluir(TL* elemento);
    void limpar();
private:
    
    template <class TE>
    class Elemento {
        public:
            TE* atual;
            Elemento<TE>* pProx;
            
    };
    
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

};

template <class TL>
Lista<TL>::Lista() {
}

template <class TL>
Lista<TL>::~Lista() {
}

template <class TL>
void Lista<TL>::incluir(TL* elemento) {
    
}

template <class TL>
void Lista<TL>::limpar() {
    
}



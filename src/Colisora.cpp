#include "Colisora.h"

Colisora::Colisora(RectangleShape* crp) {
    corpo = crp;
}

Colisora::~Colisora() {
}

bool Colisora::verificarColisao(Colisora* outro, float empurrao) {
    
    Vector2f outroPos = outro->getPosicao();
    Vector2f outroTam = outro->getTamanhoMetade();
    Vector2f thisPos = getPosicao();
    Vector2f thisTam = getTamanhoMetade();
    
    float deltaX = outroPos.x - thisPos.x;
    float deltaY = outroPos.y - thisPos.y;
    
    float intersectaX = abs(deltaX) - (thisTam.x + outroTam.x);
    float intersectaY = abs(deltaY) - (thisTam.y + outroTam.y);
    
    if(intersectaX < 0.0f && intersectaY < 0.0f) {
        
        empurrao = min(max(0.0f, empurrao), 1.0f);
        
        if(intersectaX > intersectaY) {
            
            if(deltaX > 0.0f) {
                mover(intersectaX * (1.0f - empurrao), 0.0f);
                outro->mover(-intersectaX * (1.0f - empurrao), 0.0f);
            }
            else {
                mover(-intersectaX * (1.0f - empurrao), 0.0f);
                outro->mover(intersectaX * (1.0f - empurrao), 0.0f);
            }
            
        }
        else {
            if(deltaY > 0.0f) {
                mover(0.0f, intersectaY * (1.0f - empurrao));
                outro->mover(0.0f, -intersectaY * (1.0f - empurrao));
            }
            else {
                mover(0.0f, -intersectaY * (1.0f - empurrao));
                outro->mover(0.0f, intersectaY * (1.0f - empurrao));
            }
        }
        
        return true;
    }
    
    
    
    
    return false;
}

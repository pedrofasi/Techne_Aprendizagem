#ifndef BATALHA_H
#define BATALHA_H

#include <iostream>
#include <string>
#include <vector>
#include "Personagem.h"
using namespace std;

class Batalha{
    public:
    
    bool ordemTurno(Personagem& a, Personagem& b);
};

#endif
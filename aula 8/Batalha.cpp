#include <iostream>
#include <string>
#include <vector>
#include "Batalha.h"
#include "Personagem.h"
using namespace std;

bool Batalha::ordemTurno(Personagem& a, Personagem& b){
        if(a.Velocidade >= b.Velocidade){
                // Personagem[i] começa a ação
                return true;
        }else{
                // Inimigo começa a ação
                return false;
        }
}

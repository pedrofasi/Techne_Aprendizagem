#include <iostream>
#include <string>
#include <vector>
#include "Batalha.h"
#include "Personagem.h"
using namespace std;

int Batalha::ordemTurno(Personagem& a, Personagem& b){
        if(a.Velocidade >= b.Velocidade){
                // A começa a ação
                return 1;
        }else{
                // B começa a ação
                return 0;
        }
}

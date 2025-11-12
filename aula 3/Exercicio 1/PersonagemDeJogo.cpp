
/*
1. Classe PersonagemDeJogo
Crie um personagem para um jogo com:
Atributos: nome, tipo (guerreiro, mago, arqueiro), vida, força.

Métodos:

atacar(): imprime uma frase com o tipo de ataque.

receberDano(int dano): diminui a vida.

exibirStatus(): mostra o nome, tipo e vida atual.

Desafio extra: Crie dois personagens e simule uma pequena luta no main.
*/
#include "PersonagemDeJogo.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void PersonagemDeJogo::atacar(){
    if(tipo == "guerreiro"){
        std::cout << "[ATAQUE] " << "[" << nome << "]"<< " - Atacou com sua espada!" << endl;
    }else if(tipo == "mago"){
        std::cout << "[ATAQUE] " << "[" << nome << "]"<< " - Lancou uma bola de fogo!" << endl;
    }else if(tipo == "arqueiro"){
        std::cout << "[ATAQUE] " << "[" << nome << "]"<< "- Atirou uma flecha!" << endl;
    }
} 

void PersonagemDeJogo::receberDano(int dano){
    if(dano >= vida){
        vida = 0;
        std::cout << "[DANO] " <<"[" << nome << "]"<< " - Voce MORREU!" << endl;
    }else{
        vida = vida - dano;
        std::cout << "[DANO] " <<"[" << nome << "]"<< " - Tomou "<< dano << " de dano! E esta agora com: "<< vida << "de vida!" << endl;
    }
}

void PersonagemDeJogo::exibirStatus(){
    cout << "[STATUS] " <<"[" << nome << "] - [" << tipo << "] - ["<< vida << "]" << endl;
}
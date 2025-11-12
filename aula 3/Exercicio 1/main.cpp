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

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "PersonagemDeJogo.h"
#include "PersonagemDeJogo.cpp"
using namespace std;


int main(){
    vector <PersonagemDeJogo> Jogadores;
    PersonagemDeJogo aux;
    // Simulando uma luta
    aux.nome = "Lucas";
    aux.vida = 100;
    aux.tipo = "guerreiro";
    aux.forca = 30;

    Jogadores.push_back(aux);

    aux.nome = "Pedro";
    aux.vida = 100;
    aux.tipo = "mago";
    aux.forca = 25;
    Jogadores.push_back(aux);
    int tamanho = Jogadores.size();
    for(int i = 0; i< tamanho; i++){
        if(i == 1){
            Jogadores[i].atacar();
            Jogadores[i].receberDano(Jogadores[i-1].forca);
            Jogadores[i].exibirStatus();
            if(Jogadores[i].vida == 0){
                break;
            }  
            i = i-2;

        }else{
            Jogadores[i].atacar();
            Jogadores[i].receberDano(Jogadores[i+1].forca);
            Jogadores[i].exibirStatus();
            if(Jogadores[i].vida == 0){
                break;
            }  
        }
        
    }
    printf("Luta finalizada!");
    return 0;

}
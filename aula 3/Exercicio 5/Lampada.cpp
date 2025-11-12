/*
5. Classe Lâmpada
Simule uma lâmpada inteligente:
Atributos: ligada (boolean), cor (branco, amarelo...).

Métodos:

ligar(), desligar()

trocarCor(String novaCor)

mostrarEstado()

Desafio extra: Se a lâmpada estiver desligada, não permita trocar a cor.
*/

#include <iostream>
#include <string>
#include "Lampada.h"
using namespace std;

void Lampada::ligar(){
    ligada = true;
    cout << "Luz acesa!" << endl;
}

void Lampada::desligar(){
    ligada = false;
    cout << "Luz apagada!" << endl;
}

void Lampada::trocarCor(string novaCor){
    if(ligada){
        cor = novaCor;
        cout << "Cor alterada com sucesso!" << endl;
    }else{
        cout << "Ligue a lampada antes de trocar a cor!" << endl;
    }

}
void Lampada::mostrarEstado(){
    if(ligada){
        cout << "Lampada acesa, com a cor " << cor << endl;
    }else{
        cout << "Lampada desligada" << endl;
    }
}

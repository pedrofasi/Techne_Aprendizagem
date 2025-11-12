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

#include "Lampada.h"
#include "Lampada.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    int opcao;
    Lampada lampada;
    lampada.cor = "branca";
    while(true){
        cout << "[1] Ligar lampada \n[2] Desligar lampada\n[3] Alterar cor\n[4] Mostrar status\n[0] Sair" << endl;
        cin >> opcao;
        if(opcao == 0){
            break;
        }else if(opcao == 1){
            lampada.ligar();
        }else if(opcao == 2){
            lampada.desligar();
        }else if(opcao == 3){
            string novaCor;
            cout << "Qual a nova cor?" << endl;
            cin >> novaCor;
            lampada.trocarCor(novaCor);
        }else if(opcao == 4){
            lampada.mostrarEstado();
        }
        else{
            cout << "Opção Inválida" << endl;
        }
    }
    return 0;
}
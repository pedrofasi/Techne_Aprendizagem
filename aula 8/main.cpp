
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <chrono>
#include "Personagem.h"
#include "Batalha.h"
#include "Habilidade.h"
#include "Jogo.h"


int main(){
    Jogo jogo;

    while(true){
        int opc;
        cout << "\nSEJA BEM VINDO AO JOGO" << endl;
        cout << "[1] Para iniciar o jogo" << endl;
        cout << "[0] Para sair" << endl;
        cin >> opc;
        if(opc == 1){
            jogo.menu();
        }else if(opc == 0){
            break;
        }else{
            cout << "DIGITE UMA OPCAO VALIDA!" << endl;
        }
    }
    return 0;
}
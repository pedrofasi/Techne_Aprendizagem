#include <iostream>


#include "ContaBancaria.h"
#include "ContaBancaria.cpp"

int main(){


    ContaBancaria conta;
   
    while(true){

        std::cout << "1) Cadastrar \n2) Sacar \n3) Imprimir Dados \n0) Sair\nOpção: " << std::endl;
        int menu;
        std::cin >> menu;
        if(menu == 0) break;

        switch(menu){
            case 1:
                conta.cadastrar();
                break;
            case 2:
                conta.sacar();
                break;
            case 3:
                conta.imprimirDados();
                break;
            default:
                std::cout << "Opcao invalida." << std::endl;
        }
   }

    return 0;
}






#include <iostream>
#include <string>
#include "PetVirtual.h"
#include "PetVirtual.cpp"
using namespace std;

int main(){

    PetVirtual pet;
    pet.felicidade = 0;
    pet.fome = 50;
    pet.nome = "Bilu";
    
    for(int i = 0 ; i < 100; i++){
        if(i < 5){
            pet.alimentar();
            pet.brincar();
        }
        else if(i > 5 && i < 20){
            pet.brincar();
        }
        else if(i >= 20){
            pet.alimentar();
        }
    }

    return 0;
}
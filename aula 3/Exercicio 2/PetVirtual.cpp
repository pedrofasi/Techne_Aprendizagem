#include "PetVirtual.h"
#include <iostream>
#include <string>
using namespace std;

/*

2. Classe PetVirtual
Simule um bichinho virtual:
Atributos: nome, fome, felicidade (0–100).

Métodos:

alimentar(): diminui a fome.

brincar(): aumenta felicidade.

status(): imprime o estado atual do pet.

Desafio extra: Se a fome passar de 80, o pet fica triste (felicidade diminui).

*/

void PetVirtual::alimentar(){
    if(fome <= 0){
        fome = 0;
        cout << nome << " Ja esta sem fome! Pare de alimentar! Fome atual:" << fome << endl;
    }else{
        fome -= 10;
        cout << "Voce alimentou o " << nome << "! Sua fome agora eh: " << fome << endl;
    }
    
}

void PetVirtual::brincar(){
    if(fome >= 80){
        felicidade = 0;
        fome += 20;
        cout << nome << " ESTA FAMINTO! Sua felicidade agora eh: " << felicidade << " e sua fome aumentou: " << fome << endl;
    }else{
        felicidade = felicidade + 10;
        fome += 20;
        cout << "Voce brincou com o " << nome << "! Sua felicidade agora eh: " << felicidade << " e sua fome aumentou: " << fome << endl;
    }
    
}

void PetVirtual::status(){
    cout << "[PET] - [" << nome << "] esta com " << fome << " de fome e " << felicidade << " de felicidade" << endl;
}
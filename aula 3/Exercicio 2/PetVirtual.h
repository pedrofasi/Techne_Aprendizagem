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

#ifndef PETVIRTUAL_H
#define PETVIRTUAL_H

#include <string>
#include <iostream>
using namespace std;

class PetVirtual{
    public:
        string nome;
        int fome;
        int felicidade;
    void alimentar();
    void brincar();
    void status();
};

#endif
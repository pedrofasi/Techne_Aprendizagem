/*
Exercício 1: Crie uma classe base chamada "Funcionario" com atributos como "Nome" e "Salario". 
Crie uma classe derivada chamada "Gerente" que herde de "Funcionario" e adicione um atributo adicional chamado "Setor".
*/

#include "Funcionario.h"
#include "Gerente.h"
#include <iostream>
#include <string>

int main(){
    Gerente g1;
    g1.nome = "Pedro";
    g1.salario = 32.5;
    g1.setor = "Bancario";

    std::cout << g1.nome << g1.salario << g1.setor;
}
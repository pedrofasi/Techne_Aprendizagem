/*
Exercício 1: Crie uma classe base chamada "Funcionario" com atributos como "Nome" e "Salario". 
Crie uma classe derivada chamada "Gerente" que herde de "Funcionario" e adicione um atributo adicional chamado "Setor".
*/
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario{
    public:
        std::string nome;
        float salario;
};

#endif
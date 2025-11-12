/*
Exercício 1: Crie uma classe base chamada "Funcionario" com atributos como "Nome" e "Salario". 
Crie uma classe derivada chamada "Gerente" que herde de "Funcionario" e adicione um atributo adicional chamado "Setor".
*/
#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include <string>

class Gerente:public Funcionario{
    public:
        std::string setor;
};

#endif
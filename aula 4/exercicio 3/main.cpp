/*
Exercício 3: Crie uma classe base chamada "Pessoa" com um atributo "Nome". 
Crie uma classe derivada chamada "Estudante" que herde de "Pessoa" e adicione um atributo adicional chamado "Matricula".
 */

#include <iostream>
#include <string>
using namespace std;

class Pessoa{
    public:
        string nome;
};

class Estudante:public Pessoa{
    public:
        int matricula;
};

int main(){
    Estudante e1;
    e1.matricula = 10;
    e1.nome = "Pedro";

    cout << e1.matricula << " - " << e1.nome;

}


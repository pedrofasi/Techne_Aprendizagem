/*

Exercício 2: Crie uma classe base chamada "Produto" com atributos como "Nome" e "Preco". 
Crie uma classe derivada chamada "Livro" que herde de "Produto" e adicione um atributos de um livro. 
Crie 4 livros.
 */

#include <iostream>
#include "Produto.h"
#include "Livro.h"
#include <vector>

int main(){
    std::vector <Livro> livros;
    Livro l1;
    l1.nome = "Livro Infantil";
    l1.preco = 30.99;
    l1.titulo = "Alice in Bordelands";
    l1.autor = "Nao faco ideia";
    l1.dataLancamento = "22/11/2003";

    livros.push_back(l1);

    l1.nome = "Livro Infantil";
    l1.preco = 30.99;
    l1.titulo = "Alice in Bordelands2";
    l1.autor = "Nao faco ideia";
    l1.dataLancamento = "22/11/2003";

    livros.push_back(l1);

    l1.nome = "Livro Infantil";
    l1.preco = 30.99;
    l1.titulo = "Alice in Bordelands3";
    l1.autor = "Nao faco ideia";
    l1.dataLancamento = "22/11/2003";

    livros.push_back(l1);

    l1.nome = "Livro Infantil";
    l1.preco = 30.99;
    l1.titulo = "Alice in Bordelands4";
    l1.autor = "Nao faco ideia";
    l1.dataLancamento = "22/11/2003";

    livros.push_back(l1);

    int tam;
    tam = livros.size();
    for(int i = 0; i< tam ; i++){
        std::cout << livros[i].nome<< " - " << livros[i].preco << " - " << livros[i].titulo << " - " << livros[i].autor << " - " <<livros[i].dataLancamento << std::endl;
    }
    return 0;
}
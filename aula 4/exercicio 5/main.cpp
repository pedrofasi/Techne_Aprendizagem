/*
Exercício 5 (mais desafiador): Crie uma hierarquia de classes para um sistema de uma loja de eletrônicos. Crie uma classe base chamada "Produto" com propriedades como "Nome" e "Preco".
Crie classes derivadas como "Celular" e "Notebook" que herdem de "Produto" e adicionem propriedades adicionais específicas para cada tipo de produto. 
Implemente métodos ou funcionalidades relevantes, como "CalcularDesconto" ou "VerificarDisponibilidade".
*/

#include <string>
#include <iostream>

class Produto{
    public:
        std::string nome;
        float preco;
    virtual void calcularDesconto(){
        std::cout << "Sem desconto para celulares." << std::endl;
    };
};

class Celular:public Produto{
    public:
        std::string marca;
        std::string modelo;
        std::string anoLancamento;
};

class Notebook:public Produto{
    public:
        std::string marca;
        std::string modelo;
        std::string anoLancamento;
    void calcularDesconto() override{
        std::cout << "Desconto para notebooks: " << preco * 0.9 << std::endl;
    };
};

int main(){
    Celular c1;
    Notebook n1;

    c1.nome = "Celular";
    c1.preco = 100;

    n1.nome = "Notebook";
    n1.preco = 100;

    c1.calcularDesconto();
    n1.calcularDesconto();
    return 0;
}


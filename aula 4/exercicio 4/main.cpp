/*
Exercício 4: Crie uma classe base chamada "Figura" com um método "CalcularArea()" que retorna a área da figura. 
Crie uma classe derivada chamada "Retangulo" que herde de "Figura" e implemente o método "CalcularArea()" para calcular a área do retângulo.
 */


#include <iostream>
#include <string>

class Figura{
    public:
        int ladoX;
        int ladoY;

    Figura(int lX, int lY){
        ladoX = lX;
        ladoY = lY;
    };
    virtual void CalcularArea(){
        std::cout << "Ue";
    };
};

class Retangulo: public Figura{
    public:

    Retangulo(int lX, int lY):Figura(lX,lY){
        ladoX = lX;
        ladoY = lY;
    };
    void CalcularArea() override{
        std::cout << "A area desta figura eh " << ladoX * ladoY << std::endl;
    };
};

int main(){
    Retangulo r1(10,20);
    r1.CalcularArea();

}
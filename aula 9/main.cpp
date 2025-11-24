#include <iostream>
#include "minha_matematica.h"
 
int main() {
    int x = 5;
    int y = 10;
 
    int soma = somar(x, y);
    int produto = multiplicar(x, y);
 
    std::cout << "Soma: " << soma << std::endl;
    std::cout << "Produto: " << produto << std::endl;
 
    return 0;
}
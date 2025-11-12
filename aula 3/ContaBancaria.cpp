#include <iostream>
#include <string>
#include "ContaBancaria.h"

void ContaBancaria::imprimirDados(){
    std::cout << "Titular: " << titular << std::endl;
    std::cout << "Numero da Conta: " << numeroConta << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
}

void ContaBancaria::sacar(){
    double valor;
    std::cout << "Digite o valor do saque: ";
    std::cin >> valor;
    if(valor <= saldo){
        saldo -= valor;
        std::cout << "Saque de " << valor << " realizado com sucesso." << std::endl;
    } else {
        std::cout << "Saldo insuficiente para saque de " << valor << "." << std::endl;
    }
}

void ContaBancaria::cadastrar(){
    std::cout << "Digite o nome do titular: ";
    std::cin >> titular;

    std::cout << "Digite o numero da conta: ";
    std::cin >> numeroConta;

    std::cout << "Digite o saldo inicial: ";
    std::cin >> saldo;
    std::cout << "Cadastrado com sucesso." << std::endl;

}

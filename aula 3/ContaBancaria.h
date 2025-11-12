#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>
#include <iostream>

using namespace std;

class ContaBancaria{
    public:
        string titular;
        int numeroConta;
        double saldo;

    void imprimirDados();
    void sacar();
    void cadastrar();
};

#endif
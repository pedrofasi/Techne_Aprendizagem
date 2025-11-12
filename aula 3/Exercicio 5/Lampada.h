/*
5. Classe Lâmpada
Simule uma lâmpada inteligente:
Atributos: ligada (boolean), cor (branco, amarelo...).

Métodos:

ligar(), desligar()

trocarCor(String novaCor)

mostrarEstado()

Desafio extra: Se a lâmpada estiver desligada, não permita trocar a cor.
*/

#ifndef LAMPADA_H
#define LAMPADA_H

#include <string>
#include <iostream>
using namespace std;

class Lampada{
    public:
        bool ligada;
        string cor;
    void ligar();
    void desligar();
    void trocarCor(string novaCor);
    void mostrarEstado();
};

#endif
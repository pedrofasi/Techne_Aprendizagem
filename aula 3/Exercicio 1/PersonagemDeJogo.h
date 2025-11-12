#ifndef PERSONAGEMDEJOGO_H
#define PERSONAGEMDEJOGO_H
/*
1. Classe PersonagemDeJogo
Crie um personagem para um jogo com:
Atributos: nome, tipo (guerreiro, mago, arqueiro), vida, força.

Métodos:

atacar(): imprime uma frase com o tipo de ataque.

receberDano(int dano): diminui a vida.

exibirStatus(): mostra o nome, tipo e vida atual.

Desafio extra: Crie dois personagens e simule uma pequena luta no main.
*/
#include <string>
using namespace std;

class PersonagemDeJogo{
    public:
        string nome;
        string tipo;
        int vida;
        int forca;

    void atacar();
    void receberDano(int dano);
    void exibirStatus();
};

#endif
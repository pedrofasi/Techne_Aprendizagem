#ifndef JOGO_H
#define JOGO_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <chrono>
#include "Personagem.h"
#include "Batalha.h"
#include "Habilidade.h"
#include "Jogo.h"

class Jogo{
    public:
        vector <Personagem*> personagens;
        vector <Inimigo*> inimigos;
        int batalhas = 1;
    void menu();
    void criarInimigo();
    void criarPersonagem();
    void Batalhar();
    void mostrarInimigo();
    void reiniciar();
    void inimigoAtacar(int i);
    double opcItem(int i);
    double opcHabilidade(int i);
    void opcDefender(int i);
    void opcFugir(int i);
    void statusPersonagens();
};
#endif
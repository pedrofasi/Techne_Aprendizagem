#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "Item.h"
#include <random>

using namespace std;

void Item::abrirBau(){
    // ===== GERADOR ALEATÓRIO USANDO CHRONO =====
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
   
    // ===== LISTA DE ITENS PRE-DEFINIDOS =====
    map<int, string> bancoItens = {
        {0, "Pocao de Cura"},
        {1, "Pocao de Mana"},
        {2, "Elixir da Forca"},
        {3, "Elixir da Resistencia"},
        {4, "Pergaminho Misterioso"},
        {5, "Pedra Energetica"},
        {6, "Cristal do Poder"},
        {7, "Bombinha Arcaica"},
        {8, "Medalhao Antigo"},
        {9, "Anel das Sombras"}
    };

    uniform_int_distribution<> rangeAleatorio(0, 100);
    uniform_int_distribution<> distItem(0, bancoItens.size() - 1);

    int id = distItem(gen);
    Nome = bancoItens[id];

    int raridade = rangeAleatorio(gen);
    // COMUM -> 55%
    // RARO -> 25%
    // EPICO -> 15%
    // LENDARIO -> 5%
    if(raridade <= 55){
        // COMUM
        Raridade = "Comum";
        danoBase = 250;
    }else if(raridade <= 80){
        // RARO
        Raridade = "Raro";
        danoBase = 500;
    }else if(raridade <= 95){
        // EPICO
        Raridade = "Epico";
        danoBase = 1000;
    }else if(raridade <= 100){
        // LENDARIO
        Raridade = "Lendario";
        danoBase = 2000;
    }
}
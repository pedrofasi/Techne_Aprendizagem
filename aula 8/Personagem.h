#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "Habilidade.h"
#include "Item.h"
#include <random>

using namespace std;

class Personagem{
    public:
        string Nome;
        string Classe;
        int PontosVida;
        int Forca;
        int Defesa;
        int Velocidade;
        bool Fuga = false;
        int nivel;
        int xpAtual;
        int mortesFeitas;
        vector <Habilidade*> habilidades;
        vector <Item*> items;

    Personagem(string N, string Cl, int Pv, int F, int D, int V){
        Nome = N;
        Classe = Cl;
        PontosVida = Pv;
        Forca = F;
        Defesa = D;
        Velocidade = V;
        nivel = 1;
        xpAtual = 0;
    }
    void atacar(Personagem& a, double danoAdicional);
    void defender();
    void fugir();
    void upgrade(int XP);
    virtual bool estaVivo();
};

class Guerreiro:public Personagem{
    public:
        int Armadura;
        int Folego;
    Guerreiro(string N, string Cl, int Pv, int F, int D, int V):Personagem(N, Cl, Pv, F, D, V){
        Armadura = 100;
        Folego = 100;
        Habilidade* habilidade = new Habilidade;
        habilidade->DanoBase = 100;
        habilidade->Nome = "Espada Flamejante";
        habilidade->Tipo = "Terrestre";
        habilidades.push_back(habilidade);
    }
};

class Mago:public Personagem{
    public:
        int PontosMagia;
        int Stamina;
    Mago(string N, string Cl, int Pv, int F, int D, int V):Personagem(N, Cl, Pv, F, D, V){
        PontosMagia = 100;
        Stamina = 100;
        for(int i = 0; i< 3; i++){
            Habilidade* habilidade = new Habilidade;
            if(i == 0){
                habilidade->DanoBase = PontosMagia*0.8;
                habilidade->Nome = "Bola de Fogo";
                habilidade->Tipo = "Fogo";
                habilidades.push_back(habilidade);
            }else if(i == 1){
                habilidade->DanoBase = PontosMagia*0.9;
                habilidade->Nome = "Bola de Gelo";
                habilidade->Tipo = "Gelo";
                habilidades.push_back(habilidade);
            }else{
                habilidade->DanoBase = PontosMagia*0.7;
                habilidade->Nome = "Bola de Agua";
                habilidade->Tipo = "Agua";
                habilidades.push_back(habilidade);
            }
        }
    }
};

class Arqueiro:public Personagem{
    public:
        int Destreza;
        int Flechas;
    Arqueiro(string N, string Cl, int Pv, int F, int D, int V):Personagem(N, Cl, Pv, F, D, V){
        Destreza = 100;
        Flechas = 100;
        Habilidade* habilidade = new Habilidade;
        habilidade->DanoBase = 100;
        habilidade->Nome = "Flecha Explosiva";
        habilidade->Tipo = "Voador";
        habilidades.push_back(habilidade);
    }
};

class Inimigo:public Personagem{
    public:
        string Tipo;
        int RecompensaXP;
    Inimigo(string N, string Cl, int Pv, int F, int D, int V):Personagem(N, Cl, Pv, F, D, V){
        
        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        mt19937 gen(seed);  
        uniform_int_distribution<> distTipo(1, 5);

        int aleatorio = distTipo(gen); 

        if(aleatorio == 1){
            Tipo = "Fogo";
        }else if(aleatorio == 2){
            Tipo = "Agua";
        }else if(aleatorio == 3){
            Tipo = "Gelo";
        }else if(aleatorio == 4){
            Tipo = "Voador";
        }else if(aleatorio == 5){
            Tipo = "Terrestre";
        }
        RecompensaXP = Pv/5;
    }

    double calcularDano(Habilidade habilidade);
    bool estaVivo() override;
};

#endif
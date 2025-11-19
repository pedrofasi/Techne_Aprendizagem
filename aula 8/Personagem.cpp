#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include "Personagem.h"
#include "Habilidade.h"
using namespace std;

void Personagem::atacar(Personagem& a, double danoAdicional){
        cout << "[" <<Classe << "] " << Nome << " aplicou " << Forca + danoAdicional << " de dano ao inimigo: <" << a.Nome <<">" << endl;
        a.PontosVida -= Forca + danoAdicional;
}

void Personagem::defender(){
        PontosVida += Defesa;
        cout << "[" << Classe << "] " << Nome << " aplicou <" << Defesa << "> de escudo em sua vida. <VIDA ATUAL: " << PontosVida << ">" << endl;
}

void Personagem::fugir(){
        cout << "[" << Classe << "] " << Nome << " esta tentando fugir... "<< endl;
        mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<> dist(1, 2);
        
        int aleatorio = dist(gen);

        if(aleatorio == 1){
                cout << "[" << Classe << "] " << Nome << " fugiu com sucesso!"<< endl;
                cout << "[STATUS] " << Nome << " esta fora desta batalha!" << endl;
                Fuga = true;
        }else if(aleatorio == 2){
                cout << "[" << Classe << "] " << Nome << " falhou ao tentar fugir!"<< endl;
                cout << "[STATUS] " << Nome << " continua nesta batalha!" << endl;
        }
}

bool Personagem::estaVivo(){
        if(PontosVida <= 0){
                cout << "[" << Classe << "] " << Nome << " morreu!" << endl;
                return false;
        }else{
                return true;
        }
}

bool Inimigo::estaVivo(){
        if(PontosVida <= 0){
                cout << "[" << Nome << "] morreu dropando " << RecompensaXP << " de XP!" << endl;
                return false;
        }else{
                return true;
        }
}

double Inimigo::calcularDano(Habilidade habilidade){
        // habilidades -> vetor de habilidades (tipo, fogo, agua, gelo, flechaExplosiva, EspadaFlamejante etc)
        // Inimigo b -> tipo (tipo fogo, agua, gelo, voador, animal)
        if(habilidade.Tipo == "Fogo"){
                if(Tipo == "Gelo"){
                        return habilidade.DanoBase*2;
                }else{
                        return habilidade.DanoBase*0.5;
                }
        }else if(habilidade.Tipo == "Agua"){
                if(Tipo == "Fogo"){
                        return habilidade.DanoBase*2;
                }else{
                        return habilidade.DanoBase*0.5;
                }
        }else if(habilidade.Tipo == "Gelo"){
                if(Tipo == "Agua"){
                        return habilidade.DanoBase*2;
                }else{
                        return habilidade.DanoBase*0.5;
                }
        }else if(habilidade.Tipo == "Voador"){
                if(Tipo == "Voador"){
                        return habilidade.DanoBase*2;
                }else{
                        return habilidade.DanoBase*0.5;
                }
        }else if(habilidade.Tipo == "Terrestre"){
                if(Tipo == "Terrestre"){
                        return habilidade.DanoBase*2;
                }else{
                        return habilidade.DanoBase*0.5;
                }
        }
}
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include "Personagem.h"
#include "Habilidade.h"
#include "Dano.h"
using namespace std;

void Personagem::atacar(Personagem& a, double danoAdicional){
        cout << "[" <<Classe << "] " << Nome << " aplicou <" << Forca + danoAdicional << "> de dano ao inimigo: <" << a.Nome <<">" << endl;
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

void Personagem::upgrade(int XP){
        xpAtual += XP;
        int resto;
        if(xpAtual >= 100){
                int resto = xpAtual-100;
                xpAtual = 100;
        }
        // a cada 100 de xp, upa +1 nivel
        if(xpAtual % 100 == 0){
                nivel++;
                PontosVida *= nivel;
                Forca *= nivel;
                Defesa *= nivel;
                Velocidade += nivel;
                xpAtual = resto;
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

    auto relacao = TabelaElementos::getRelacao(habilidade.Tipo);

    double multiplicador = relacao->calcularMultiplicador(Tipo);

    return habilidade.DanoBase * multiplicador;

}
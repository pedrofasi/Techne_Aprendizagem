#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Personagem.h"
#include "Habilidade.h"
using namespace std;

void Personagem::atacar(Personagem& a, double danoAdicional){
        cout << "\nAplicando " << Forca + danoAdicional << " de dano ao inimigo: " << a.Nome << endl;
        a.PontosVida -= Forca + danoAdicional;
}

void Personagem::defender(Personagem &a){
        cout << "\nAplicando " << Defesa << " de escudo à vida de: " << Nome << endl;
        PontosVida += Defesa; 
        PontosVida -= a.Forca;
}

void Personagem::fugir(Personagem& a){
        cout << "\nTentando fugir... "<< endl;
        random_device rd;  
        mt19937 gen(rd());  
        uniform_int_distribution<> dist(1, 2);  

        int aleatorio = dist(gen); 

        if(aleatorio == 1){
                cout << "Fuga realzada com sucesso!\n0 de Dano tomado!" << endl;
        }else if(aleatorio == 2){
                PontosVida -= a.Forca;
                cout << "Fuga nao realizada, dano aplicado" << endl;
        }
        PontosVida += Defesa; 
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
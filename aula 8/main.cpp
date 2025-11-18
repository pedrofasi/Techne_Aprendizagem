
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Personagem.h"
#include "Batalha.h"
#include "Habilidade.h"

class Jogo{
    public:
        vector <Personagem*> personagens;
        vector <Inimigo*> inimigos;
        int batalhas = 1;
    void menu(){
        while(true){
            cout << "\n[1] - Criar Personagens\n[2] - Criar Inimigos\n[3] - Iniciar Batalha\n[0] - Retornar ao menu" << endl;
            int opc;
            cin >> opc;
            if(opc == 0){
                break;
            }else if(opc == 1){
                criarPersonagem();
            }else if(opc == 2){
                criarInimigo();
            }else if(opc == 3){
                Batalhar();
            }else{
                cout << "Escolha uma alternativa valida" << endl;
            }
        }
    }   

    void criarInimigo(){
        if(inimigos.size() == 1){
            cout << "Ja existe um inimigo no campo de batalha!" << endl;
        }else{
            string nome;
            cout << "Digite um nome para seu inimigo!" << endl;
            cin.ignore(1000, '\n');
            getline(cin, nome);
            inimigos.push_back(new Inimigo(nome,2000,100,100,1));
            cout << "Inimigo criado com sucesso!\nNome: " << inimigos[0]->Nome << "\nTipo: " << inimigos[0]->Tipo << "\nVida: " << inimigos[0]->PontosVida << "\nDano: " << inimigos[0]->Forca << "\nDefesa: " << inimigos[0]->Defesa << "\nInicie a batalha para lutar..." << endl;
        }
    }

    void criarPersonagem(){
        int qntdPersonagens;
        cout << "\nInforme quantos personagens" << endl;
        cin >> qntdPersonagens;
        for(int i = 0; i< qntdPersonagens; i++){
            string nome;
            cout << "\nInforme o nome do " << i+1 << " personagem:" << endl;
            cin >> nome;
            cout << "\nEscolha sua classe:\n[1] Guerreiro\n[2] Mago\n[3] Arqueiro" << endl;
            int opcao;
            cin >> opcao;
            while(true){
                if(opcao == 1){
                    personagens.push_back(new Guerreiro(nome,100,60,80,3));
                    break;
                }else if(opcao == 2){
                    personagens.push_back(new Mago(nome,100,20,20,5));
                    break;
                }else if(opcao == 3){
                    personagens.push_back(new Arqueiro(nome,100,40,50,6));
                    break;
                }else{
                    cout << "\nDigite uma opcao valida" << endl;
                }
            }

        }
        cout << "\nPersonagens criados:" << endl;
        for(int i = 0 ; i< personagens.size(); i++){
            cout << personagens[i]->Nome << " - " << endl;
        }
    }

    void Batalhar(){

        if(inimigos.size() == 0){
            cout << "Nao existem inimigos por perto! Crie um" << endl;
            return;
        }

        int tam = personagens.size();
        cout << "Rodada " << batalhas << " iniciada!" << endl;
        for(int i = 0 ; i < tam ; i++){
            
            cout << "Vez de jogador -> " << personagens[i]->Nome << endl;
            cout << "Escolha a habilidade a ser utilizada: " << endl;
            int opcao;
            for(int j = 0 ; j < personagens[i]->habilidades.size() ; j++){
                cout << "[" << j << "]" << personagens[i]->habilidades[j]->Nome << endl;
            }
            cin >> opcao;
            if(opcao == 0){
                // Por enquanto Arqueiro e Guerreiro so tem apenas 1 habilidade
                int danoAdicional;
                Habilidade *a;
                a = personagens[i]->habilidades[opcao];
                danoAdicional = inimigos[0]->calcularDano(*a);
                personagens[i]->atacar(*inimigos[0], danoAdicional);
            }else if(opcao == 1){
                int danoAdicional;
                Habilidade *a;
                a = personagens[i]->habilidades[opcao];
                danoAdicional = inimigos[0]->calcularDano(*a);
                personagens[i]->atacar(*inimigos[0], danoAdicional);

            }else if(opcao == 2){
                int danoAdicional;
                Habilidade *a;
                a = personagens[i]->habilidades[opcao];
                danoAdicional = inimigos[0]->calcularDano(*a);
                personagens[i]->atacar(*inimigos[0], danoAdicional);
            }

            cout << "\nVIDA ATUAL DO INIMIGO <"<< inimigos[0]->Nome << ">: " << inimigos[0]->PontosVida << endl;
        }
        batalhas++;
    }
};

int main(){
    Jogo jogo;

    while(true){
        int opc;
        cout << "SEJA BEM VINDO AO JOGO" << endl;
        cout << "[1] Para iniciar o jogo" << endl;
        cout << "[2] Para sair" << endl;
        cin >> opc;
        if(opc == 1){
            jogo.menu();
        }else if(opc == 2){
            break;
        }else{
            cout << "DIGITE UMA OPCAO VALIDA!" << endl;
        }
    }

    return 0;
}
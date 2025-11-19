
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <chrono>
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
            cout << "\n[1] - Criar Personagens\n[2] - Criar Inimigos\n[3] - Iniciar Batalha\n[4] - Status dos Personagens\n[0] - Retornar ao menu" << endl;
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
            }else if(opc == 4){
                statusPersonagens();
            }
            else{
                cout << "Escolha uma alternativa valida" << endl;
            }
        }
    }   
    void criarInimigo() {
        if (inimigos.size() == 1) {
            cout << "Ja existe um inimigo no campo de batalha!" << endl;
            return;
        }

        // ----- LISTA DE INIMIGOS PRE-DEFINIDOS -----
        struct InfoInimigo {
            string nome;
            string classe;
        };

        vector<InfoInimigo> banco = {
            {"Goblin", "Ladino"},
            {"Orc Guerreiro", "Brutamonte"},
            {"Esqueleto", "Morto-Vivo"},
            {"Dragao Vermelho", "Dragao"},
            {"Troll da Caverna", "Gigante"}
        };

        // ----- GERADOR ALEATÓRIO -----

        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        mt19937 gen(seed);

        uniform_int_distribution<> distInimigo(0, banco.size() - 1);
        uniform_int_distribution<> distVida(100, 500);
        uniform_int_distribution<> distForca(100, 200);
        uniform_int_distribution<> distDefesa(100, 200);
        uniform_int_distribution<> distVelocidade(4, 8);

        // Sorteio do tipo de inimigo
        int idx = distInimigo(gen);

        // ------ ATRIBUTOS ALEATÓRIOS ------
        int vida = distVida(gen);
        int forca = distForca(gen);
        int defesa = distDefesa(gen);
        int velocidade = distVelocidade(gen);

        // ------ CRIAÇÃO DO INIMIGO ------
        inimigos.push_back(new Inimigo(
            banco[idx].nome,      // Nome
            banco[idx].classe,      // Tipo
            vida,                 // Pontos de Vida
            forca,                // Força
            defesa,               // Defesa
            velocidade            // Velocidade
        ));

        // ------ EXIBIÇÃO ------
        cout << "Inimigo criado com sucesso!\n";
        cout << "Nome: "      << inimigos[0]->Nome        << endl;
        cout << "Classe: "      << inimigos[0]->Classe        << endl;
        cout << "Tipo: "      << inimigos[0]->Tipo        << endl;
        cout << "Vida: "      << inimigos[0]->PontosVida  << endl;
        cout << "Forca: "     << inimigos[0]->Forca       << endl;
        cout << "Defesa: "    << inimigos[0]->Defesa      << endl;
        cout << "Velocidade: "<< inimigos[0]->Velocidade  << endl;
        cout << "Inicie a batalha para lutar..." << endl;
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
                    personagens.push_back(new Guerreiro(nome,"Guerreiro",100,60,80,3));
                    break;
                }else if(opcao == 2){
                    personagens.push_back(new Mago(nome,"Mago",100,20,20,5));
                    break;
                }else if(opcao == 3){
                    personagens.push_back(new Arqueiro(nome,"Arqueiro",100,40,50,6));
                    break;
                }else{
                    cout << "\nDigite uma opcao valida" << endl;
                }
            }

        }
        cout << "\nPersonagens criados:" << endl;
        for(int i = 0 ; i< personagens.size(); i++){
            cout << "[" << personagens[i]->Classe << "] - " << personagens[i]->Nome << endl;
        }
    }

    void Batalhar(){

        if(inimigos.size() == 0){
            cout << "Nao existem inimigos por perto!\nCrie um..." << endl;
            return;
        }
        if(personagens.size() == 0){
            cout << "Nao existem personagens!\nCrie um..." << endl;
            return;
        }
        else{
            int tam = personagens.size();
            cout << "Rodada " << batalhas << " iniciada!" << endl;
            mostrarInimigo();
            for(int i = 0 ; i < tam ; i++){
                int contador = 0;
                if(!personagens[i]->Fuga){
                    cout << "[" << personagens[i]->Classe << "] " << personagens[i]->Nome << " jogando:" << endl;
                    // 1) ATACAR / 2) DEFENDER / 3) FUGIR
                    while(true){
                        int opcRodada;
                        cout << "1) Atacar\n2) Defender\n3) Fugir" << endl;
                        cin >> opcRodada;

                        if(opcRodada == 1){
                            Batalha x;
                            // Decide quem vai atacar primeiro
                            // Analisa se Velocidade de Personagem[i] é maior que a velocidade do Inimigo
                            if(x.ordemTurno(*personagens[i],*inimigos[0])){ 
                                // Calcular dano adicional dependendo da escolha da habilidade
                                double danoAdd;
                                danoAdd = opcHabilidade(i);

                                // Personagem[i] atacando
                                personagens[i]->atacar(*inimigos[0], danoAdd);

                                // Checa se Inimigo morreu
                                if(!inimigos[0]->estaVivo()){
                                    reiniciar();
                                    return;
                                }

                                // Inimigo Atacando
                                inimigoAtacar(i);

                                // Checa se Personagem morreu
                                if(!personagens[i]->estaVivo()){
                                    personagens.erase(personagens.begin() + i);
                                    i--;
                                    // Checa tb se ainda ha personagens
                                    if(personagens.size() == 0){
                                        cout << "\n\nGAME OVER =(\n\n";
                                        return;
                                    }
                                }
                            }else{
                                // Calcular dano adicional dependendo da escolha da habilidade
                                double danoAdd;
                                danoAdd = opcHabilidade(i);

                                // Inimigo Atacando.
                                inimigoAtacar(i);
                                // Verifica se Personagem morreu.
                                if(!personagens[i]->estaVivo()){
                                    personagens.erase(personagens.begin() + i);
                                    i--;
                                    // Checa tb se ainda ha personagens
                                    if(personagens.size() == 0){
                                        cout << "\n\nGAME OVER =(\n\n";
                                        return;
                                    }
                                }else{
                                    // Personagem Atacando.
                                    personagens[i]->atacar(*inimigos[0], danoAdd);
                                    // Verifica se Inimigo morreu
                                    if(!inimigos[0]->estaVivo()){
                                        reiniciar();
                                        return;
                                    }
                                }
                            }
                            break;
                        }
                        else if(opcRodada == 2){
                            opcDefender(i);
                            inimigoAtacar(i);
                            if(!personagens[i]->estaVivo()){
                                personagens.erase(personagens.begin() + i);
                                i--;
                                if(personagens.size() == 0){
                                    cout << "\n\nGAME OVER =(\n\n";
                                    return;
                                }
                            }
                            break;
                        }
                        else if(opcRodada == 3){
                            opcFugir(i);
                            if(!personagens[i]->Fuga){
                                inimigoAtacar(i);
                                if(!personagens[i]->estaVivo()){
                                    personagens.erase(personagens.begin() + i);
                                    i--;
                                    if(personagens.size() == 0){
                                        cout << "\n\nGAME OVER =(\n\n";
                                        return;
                                    }
                                }
                            }
                            break;
                        }else{
                            cout << "Escolha uma opcao valida!" << endl;
                        }
                    }
                    cout << "\n["<< inimigos[0]->Nome << "] ainda esta vivo com: <" << inimigos[0]->PontosVida << "> de vida" << endl;         
                }
                else{
                    // Lógica para ver se todos jogadores fugiram
                    contador++;
                }
                if(contador == tam){
                    cout << "Todos jogadores fugiram da batalha.\nInimigo desapareceu!" << endl;
                    reiniciar();
                }
                batalhas++;
            }
        }
        
    }

    void mostrarInimigo(){
        cout << "<"<< inimigos[0]->Nome <<"> esta no campo de batalha. Vida: <" << inimigos[0]->PontosVida << ">" << " XP ao derrotar: <" << inimigos[0]->RecompensaXP << ">" << endl;
    }

    void reiniciar(){
        int XP = inimigos[0]->RecompensaXP;
        inimigos.pop_back();
        int tam = personagens.size();
        for(int i = 0; i<tam; i++){
            personagens[i]->upgrade(XP);
        }
    }

    void inimigoAtacar(int i){
        inimigos[0]->atacar(*personagens[i],0);
    }

    double opcHabilidade(int i){
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
            return danoAdicional;
        }else if(opcao == 1){
            int danoAdicional;
            Habilidade *a;
            a = personagens[i]->habilidades[opcao];
            danoAdicional = inimigos[0]->calcularDano(*a);
            return danoAdicional;

        }else if(opcao == 2){
            int danoAdicional;
            Habilidade *a;
            a = personagens[i]->habilidades[opcao];
            danoAdicional = inimigos[0]->calcularDano(*a);
            return danoAdicional;
        }
    }

    void opcDefender(int i){
        personagens[i]->defender();
    }

    void opcFugir(int i){
        personagens[i]->fugir();
    }

    void statusPersonagens(){
        int tam = personagens.size();
        if(tam == 0){
            cout << "Nao existem personagens!\nCrie um..." << endl;
            return;
        }
        for(int i = 0; i<tam ; i++){
            cout << i+1 << "- [" << personagens[i]->Nome << "] - [" << personagens[i]->Classe << "] - " << personagens[i]->PontosVida << " de vida - NIVEL: " << personagens[i]->nivel << " / XP: " << personagens[i]->xpAtual << endl;
        }
    }
};

int main(){
    Jogo jogo;

    while(true){
        int opc;
        cout << "\nSEJA BEM VINDO AO JOGO" << endl;
        cout << "[1] Para iniciar o jogo" << endl;
        cout << "[0] Para sair" << endl;
        cin >> opc;
        if(opc == 1){
            jogo.menu();
        }else if(opc == 0){
            break;
        }else{
            cout << "DIGITE UMA OPCAO VALIDA!" << endl;
        }
    }

    return 0;
}
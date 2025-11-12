/*
4. Classe DiarioSecreto (com senha)
Crie um diário que só pode ser acessado com senha:
Atributos: dono, senha, texto.

Métodos:

escrever(String senha, String texto)

ler(String senha)

Desafio extra: Se a senha estiver errada, mostre "Acesso negado".
*/

#include <string>
#include "DiarioSecreto.h"
#include "DiarioSecreto.cpp"
#include <iostream>
using namespace std;

int main(){
    DiarioSecreto diario;
    diario.senha = "123";
    diario.texto = "";
    int opcao = 0;
    while(true){
        cout << "[1] Escrever no Diario\n[2] Ler Diario\n[0]Sair" << endl;
        cin >> opcao;
        if(opcao == 0){
            break;
        }else if(opcao == 1){
            string texto;
            string senha;
            cout << "Digite o texto para guardar no seu diario: " << endl;
            cin >> texto;

            cout << "Digite a senha do seu diario: " << endl;
            cin >> senha;
            diario.escrever(senha,texto);
        }else if(opcao == 2){
            string senha;
            cout << "Digite a senha do seu diario para ler: " << endl;
            cin >> senha;

            diario.ler(senha);
        }
        else{
            cout << "Opção Inválida" << endl;
        }
    }
}
/*
6. Classe Robô com energia
Um robô que realiza tarefas, mas consome energia:
Atributos: nome, energia (0–100).

Métodos:

executarTarefa(String tarefa): consome 10 de energia.

recarregar(): enche a energia.

status(): imprime o nível de energia.

 Desafio extra: Não permitir executar tarefa com energia < 10.
*/

#include <string>
#include <iostream>
#include "RoboEnergia.h"
#include "RoboEnergia.cpp"
using namespace std;

int main(){
    int opcao;
    RoboEnergia robo;
    robo.nome = "Alfred";
    robo.energia = 100;
    while(true){
        cout << "[1] Executar Tarefa \n[2] Recarregar Energia\n[3] Status\n[0] Sair" << endl;
        cin >> opcao;
        if(opcao == 0){
            break;
        }else if(opcao == 1){
            string tarefa;
            cout << "Digite a tarefa: " << endl;
            cin >> tarefa;
            robo.executarTarefa(tarefa);
        }else if(opcao == 2){
            robo.recarregar();
        }else if(opcao == 3){
            robo.status();
        }
        else{
            cout << "Opção Inválida" << endl;
        }
    }
    return 0;
}
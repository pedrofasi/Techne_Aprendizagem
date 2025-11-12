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

#include "RoboEnergia.h"
#include <iostream>
using namespace std;

void RoboEnergia::executarTarefa(string tarefa){
    if(energia < 10){
        cout << "Tarefa nao realizada! Nivel de energia baixo: " << energia << endl;
    }
    else{
        energia -= 10;
        cout << nome << " realizou a Tarefa: '" << tarefa << "' realizada! Nivel de energia: " << energia << endl;
    }
}
void RoboEnergia::recarregar(){
    energia = 100;
    cout << "Energia recarregada de " << nome << "!" << endl;
}

void RoboEnergia::status(){
    cout << "Nivel de energia de " << nome << ": " << energia << endl;
}
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

#ifndef ROBOENERGIA_H
#define ROBOENERGIA_H

#include <iostream>
#include <string>
using namespace std;

class RoboEnergia{
    public:
        string nome;
        int energia;
    void executarTarefa(string tarefa);
    void recarregar();
    void status();
};

#endif
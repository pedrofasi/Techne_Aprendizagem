/*
4. Classe DiarioSecreto (com senha)
Crie um diário que só pode ser acessado com senha:
Atributos: dono, senha, texto.

Métodos:

escrever(String senha, String texto)

ler(String senha)

Desafio extra: Se a senha estiver errada, mostre "Acesso negado".
*/
#ifndef DIARIOSECRETO_H
#define DIARIOSECRETO_H

#include <iostream>
#include <string>
using namespace std;


class DiarioSecreto{
    public:
        string nome;
        string texto;
        string senha;
    void escrever(string senha_usuario, string texto_digitado);
    void ler(string senha_usuario);
};

#endif
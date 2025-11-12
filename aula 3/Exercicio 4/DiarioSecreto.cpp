/*
4. Classe DiarioSecreto (com senha)
Crie um diário que só pode ser acessado com senha:
Atributos: dono, senha, texto.

Métodos:

escrever(String senha, String texto)

ler(String senha)

Desafio extra: Se a senha estiver errada, mostre "Acesso negado".
*/

#include "DiarioSecreto.h"
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

void DiarioSecreto::escrever(string senha_usuario, string texto_digitado){
    if(senha_usuario == senha){
        texto = texto_digitado;
        cout << "Texto secreto registrado." << endl;
    }else{
        cout << "Senha incorreta! Acesso negado." << endl;
    }
}


void DiarioSecreto::ler(string senha_usuario){
    if(senha_usuario == senha){
        cout << "Texto: " << texto << endl;
    }else{
        cout << "Senha incorreta! Acesso negado." << endl;
    }
}
#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(){
    map<int, string> alunos;
 
    alunos[125] = "João";
    alunos[122] = "Maria";
    alunos[123] = "Pedro";
 
    cout << "Primeiro Aluno:" << endl;
   
    map<string, string> contatos;
 
    contatos["Joao"] = "47 99999-9999";
    contatos["Maria"] = "47 98888-8888";
    contatos["Pedro"] = "47 97777-7777";

    for(auto& item: contatos){
        cout << item.first << ": " << item.second << endl;
    }
 
 
    map<string, string> professor;
    
    professor["Nome"] = "Carlos";
    professor["Disciplina"] = "Programação";
    professor["Telefone"] = "47 96666-6666";
    for(auto& item: professor){
        cout << item.first << ": " << item.second << endl;
    }
 
}
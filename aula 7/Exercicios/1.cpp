/*
1) Contar e mostrar quantas linhas tem um arquivo
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int conta_linhas(ifstream& arquivo){
    int contador = 0;
    string linha;
    while(getline(arquivo,linha)){
        contador++;
    }
    arquivo.close();
    return contador;
}

int main(){
    ifstream arquivo("dados.txt");

    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
    }
    
    cout << conta_linhas(arquivo) << endl;
    return 0;
}
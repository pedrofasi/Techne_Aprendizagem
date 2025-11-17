#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int  main(){
    ofstream arquivo("dados.txt");
 
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
 
    arquivo << "Linha 1: Dados de exemplo" << endl;
    arquivo << "Linha 2: Mais dados de exemplo" << endl;
 
    arquivo.close();
    cout <<"Arquivo escrito com sucesso!" << endl;

    ifstream leitura("dados.txt");
    string linha;
    while(getline(leitura,linha)){
        cout << linha << endl;
    }
   return 0;
}
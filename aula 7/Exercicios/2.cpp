//2)Contar quantas palavras tem em um arquivo 

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int contarPalavras(fstream& arquivo){
    string palavra;
    string palavraBusca;
    cout << "Digite a palavra a ser pesquisada" << endl;
    cin >> palavraBusca;

    int contador = 0;
    while(arquivo >> palavra){
        if(palavraBusca == palavra){
            contador++;
        }
    }
    return contador;
    arquivo.close();
};

int main(){
    fstream arquivo("dados.txt");
    
    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
    }

    cout << contarPalavras(arquivo) << endl;

    return 0;
}
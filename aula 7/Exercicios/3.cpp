//3) Encontar uma palavra especifica (Pedir para o usuario uma palavra, e verificar se ela existe dentro do arquivo)

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void encontrarPalavra(fstream& arquivo){
    string palavra;
    string palavraBusca;
    cout << "Digite a palavra a ser pesquisada" << endl;
    cin >> palavraBusca;

    while(arquivo >> palavra){
        if(palavraBusca == palavra){
            cout << "Palavra: " << palavraBusca << " encontrada! Posicao: " << arquivo.tellg() << endl;
        }
    }
    arquivo.close();
};

int main(){
    fstream arquivo("dados.txt");
    
    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
    }

    encontrarPalavra(arquivo);

    return 0;
}
// 6)Mudar todas as ocorrencias da palavra "cachorro" para "mingau"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void MudaOcorrencias(fstream& leitura, ofstream& escrita){
    string palavraAtual, palavraBusca, palavraReposicao;
    cout << "Digite a palavra de ocorrencia a ser renomeada" << endl;
    cin >> palavraBusca;

    cout << "Digite a ser adicionada: " << endl;
    cin >> palavraReposicao;
    
    // fazendo assim fica sem espaço e sem \n ( >> ignora)
/*
    while(leitura >> palavraAtual){
        if(palavraAtual == palavraBusca){
            escrita << palavraReposicao;
            
        }else{
            escrita << palavraAtual;
        }
    }
*/
    // char by char

    char caracterAtual;
    bool flag = false;
    int contador = 0;
    vector <char> construindo;

    while(leitura.get(caracterAtual)){
        if(caracterAtual == palavraBusca[contador]){
            contador++;
            if(contador == palavraBusca.size()){
                // palavra encontrada
                escrita << palavraReposicao;
                construindo.clear();
            }
            construindo.push_back(caracterAtual);
            cout << caracterAtual << endl;
        }
        else{
            for(int i = 0; i< construindo.size(); i++){
                escrita << construindo[i];
            }
            contador = 0;
            construindo.clear();
            escrita << caracterAtual;
        }
    }

    leitura.close();
    escrita.close();

};

int main(){
    fstream leitura("dados.txt");
    ofstream escrita("dados2.txt");

    if(!leitura.is_open() || !escrita.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
    }

    MudaOcorrencias(leitura,escrita);

    return 0;
}
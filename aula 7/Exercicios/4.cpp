// 4)Mostrar o maior e menor numero

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void MostrarMM(fstream& arquivo){
    int numeroAtual,maior,menor;
    arquivo >> numeroAtual;
    maior = numeroAtual;
    menor = numeroAtual;
    while(arquivo >> numeroAtual){
        if(numeroAtual > maior){
            maior = numeroAtual;
        }
        if(numeroAtual < menor){
            menor = numeroAtual;
        }
    }

    cout << "Maior: " << maior << endl << "Menor: " << menor << endl;
    
    arquivo.close();
};

int main(){
    fstream arquivo("numeros.txt");
    
    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
    }

    MostrarMM(arquivo);

    return 0;
}
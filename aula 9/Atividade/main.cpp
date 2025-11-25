/*
Faça um programa (EXE) com menu simples:
1 - Converter texto para MAIÚSCULAS2 - Converter texto para minúsculas3 - Inverter texto4 - Mascarar e-mail5 - Mostrar info da DLL0 - Sair
Ele deve:
ler a opção do usuário
ler a string necessária
chamar a função DA DLL
exibir o resultado
*/

#include <iostream>
#include <string>
#include "systemtools.h"

using namespace std;

int main(){

    while(true){
        cout << "------ MENU -------" << endl;
        cout << "[1] Converter para maiusculas\n[2] Converter para minusculas\n[3] Inverter Texto\n[4] Mascarar email\n[5] Mostrar info da DLL\n[6] Contar Palavras\n[0] Sair" << endl;
        int opc;
        cin >> opc;
        cin.ignore();
        if(opc == 0){
            cout << "Saindo.." << endl;
            break;
        }else if(opc == 1){
            string texto;
            cout << "Informe o texto:" << endl;
            getline(cin,texto);
            texto = toUpper(texto);
            cout << "Resultado: " << texto << endl;
        }else if(opc == 2){
            string texto;
            cout << "Informe o texto:" << endl;
            getline(cin,texto);
            texto = toLower(texto);
            cout << "Resultado: " << texto << endl;
        }else if(opc == 3){
            string texto;
            cout << "Informe o texto:" << endl;
            getline(cin,texto);
            texto = reverseText(texto);
            cout << "Resultado: " << texto << endl;
        }else if(opc == 4){
            string texto;
            cout << "Informe o email:" << endl;
            getline(cin,texto);
            texto = maskEmail(texto);
            cout << "Resultado: " << texto << endl;
        }else if(opc == 5){
            getAppInfo();
        }else if(opc == 6){
            string texto;
            cout << "Informe o texto:" << endl;
            getline(cin,texto);
            int resultado = countWords(texto);
            cout << "O numero de palavras eh: " << resultado << endl;
        }
    }

    return 0;
}
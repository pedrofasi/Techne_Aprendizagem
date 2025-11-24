#include "systemtools.h"
#include <iostream>

string toLower(string a){
    int tam = a.size();
    for(int i = 0; i< tam; i++){
        // A-Z -> 65 ate 90 tabela ascii
        // a-z -> 97 ate 122 tabela ascii
        // diferenca de 32
        if(a[i] >= 'A' && a[i] <= 'Z'){
            a[i]+=32;
        }
    }
    return a;
}
string toUpper(string a){
    int tam = a.size();
    for(int i = 0; i< tam; i++){
        // A-Z -> 65 ate 90 tabela ascii
        // a-z -> 97 ate 122 tabela ascii
        // diferenca de -32
        if(a[i] >= 'a' && a[i] <= 'z'){
            a[i]-=32;
        }
    }
    return a;
}
string reverseText(string a){
    // 12345
    // tam = 5
    // a[0] = 1 e a[4] = 5
    // b[0] = 5 e b[4] = 1;
    int tam = a.size();
    int aux = tam-1;
    string b;
    for(int i = 0; i< tam; i++){
        b[i] = a[aux];
        aux--;
    }
    b[tam-1] = '\0';
    return b;
}
string getAppInfo(){
    cout << "Aplicativo desenvolvido por Pedro Henrique Reis Rodrigues" << endl;
}
string maskEmail(string a){
    int tam = a.size();
    for(int i = 0; i< tam; i++){
        if(a[i] == '@'){
            break;
        }else{
            a[i] = '*';
        }
    }
    cout << "[MASK] - " << a << endl;
    return a;
}
int countWords(string a){
    int tam = a.size();
    bool novaPalavra = false;
    int words = 0;
    for(int i = 0; i< tam; i++){
        if(a[i] == ' ' && novaPalavra){
            words++;
            novaPalavra = false;
        }else{
            novaPalavra = true;
        }
    }
    return words;
}
#pragma once
 
#ifdef BUILD_DLL
    #define DLL_API __declspec(dllexport)
#else
    #define DLL_API __declspec(dllimport)
#endif
 
#include <string>
using namespace std;
 
extern "C" {
    DLL_API string toLower(string a);
    DLL_API string toUpper(string a);
    DLL_API string reverseText(string a);
    DLL_API string getAppInfo();
    DLL_API string maskEmail(string a);
    DLL_API int countWords(string a);
}

/*

A DLL deve exportar funções com os seguintes comportamentos:
toUpper
Recebe uma string e devolve a mesma string em maiúsculas.
toLower
Recebe uma string e devolve em minúsculas.
reverseText
Recebe um texto e devolve o texto invertido.
getAppInfo
Retorna uma string curta com informações do programa:
maskEmail
Recebe um e-mail e retorna assim:
Extra (opcional): countWords
Conta quantas palavras existem na string.

*/
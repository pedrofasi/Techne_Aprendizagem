#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // para o exercicio 4

void exercicio1(){ /*
    1. Leitura e exibição simples
        Descrição:
        Peça para o usuário digitar seu nome e mostre uma mensagem de boas-vindas.
        Dica:
        Use fgets() ou scanf("%s", ...) e depois printf().*/
    char nome[50];
    printf("Informe seu nome:\n");
    scanf(" %[^\n]", nome);
    printf("\nSeja bem vindo, %s!", nome);
}

void exercicio2(){ /*
    2. Contar o comprimento de uma string
        Descrição:
        Peça uma palavra e mostre quantos caracteres ela tem.
        Dica:
        Use a função strlen() da <string.h>.*/
    char nome[50];
    printf("Informe uma palavra:\n");
    scanf(" %[^\n]", nome);
    printf("\nSua palavra possui %d caracteres!", strlen(nome));
}

void exercicio3(){ /*
    3. Contar vogais
        Descrição:
        Peça uma frase e mostre quantas vogais (a, e, i, o, u) existem nela.
        Dica:
        Percorra a string com um for e compare caractere por caractere.*/
    char nome[50];
    printf("Informe uma frase:\n");
    scanf(" %[^\n]", nome);
    int contador = 0;
    for(int i = 0; i< strlen(nome) ; i++){
        if(nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i' || nome[i] == 'o' || nome[i] == 'u'){
            contador++;
        }
    }
    printf("\nSua frase '%s' possui %d vogais!",nome,contador);
}

void exercicio4(){ /*
    Converter para maiúsculas
        Descrição:
        Peça uma palavra e transforme todos os caracteres em maiúsculos.
        Dica:
        Use toupper() da biblioteca <ctype.h>.*/
    char nome[50];
    printf("Informe uma palavra:\n", nome);
    scanf(" %[^\n]", nome);
    for(int i = 0; i< strlen(nome) ; i++){
        nome[i] = toupper(nome[i]);
    }
    printf("\nSua palavra toda em maiuscula: '%s'",nome);
}

void exercicio5(){ /*
    5. Inverter uma string
        Descrição:
        Peça uma palavra e mostre ela invertida.
        Dica:
        Use um for de trás pra frente e monte uma nova string.*/
    char nome[50];
    printf("Informe uma palavra:\n");
    scanf(" %[^\n]", nome);
    char aux[50];
    int cont = 0;
    printf("%d",strlen(nome));
    for(int i = strlen(nome)-1; i >= 0 ; i--){
        aux[cont] = nome[i];
        cont++;
    }
    aux[cont] = '\0';
    printf("\nSua palavra invertida: '%s'",aux);
}


void exercicio6(){ /*
    6. Concatenar duas palavras
        Descrição:
        Peça duas palavras e junte-as numa só string.
        Dica:
        Use strcat(destino, origem) da <string.h>.*/
    char nome[50];
    char nome2[50];
    printf("Informe a primeira palavra:\n");
    scanf(" %[^\n]", nome);
    printf("\nInforme a segunda palavra:\n");
    scanf(" %[^\n]", nome2);
    
    char aux[100] = "";
    strcat(aux, nome);
    strcat(aux,nome2);
    
    printf("\nSuas palavras concatenadas: '%s'",aux);
}

void exercicio7(){/*
    7. Comparar duas palavras
        Descrição:
        Peça duas palavras e diga se são iguais ou diferentes.
        Dica:
        Use strcmp(str1, str2) e verifique se o resultado é 0.*/
    char nome[50];
    char nome2[50];
    printf("Informe a primeira palavra:\n");
    scanf(" %[^\n]", nome);
    printf("\nInforme a segunda palavra:\n");
    scanf(" %[^\n]", nome2);

    if(strcmp(nome,nome2) == 0){
        printf("Suas palavras sao iguais!");
    }
    else{
        printf("Suas palavras sao diferentes!");
    }

}

void exercicio8(){/*
    8. Substituir caractere
        Descrição:
        Peça uma frase e um caractere.
        Depois, substitua todas as ocorrências desse caractere por outro informado.
        Dica:
        Percorra a string e, se encontrar o caractere antigo, troque pelo novo.*/
    char nome[50];
    char caracter1,caracter2;
    printf("Informe a frase:\n");
    scanf(" %[^\n]", nome);
    printf("\nInforme o caracter a ser substituido:\n");
    scanf(" %c", &caracter1);
    printf("\nInforme o caracter a ser atribuido:\n");
    scanf(" %c", &caracter2);

    for(int i = 0 ; i< strlen(nome) ; i++){
        if(nome[i] == caracter1){
            nome[i] = caracter2;
        }
    }

    printf("Sua frase ficou: '%s'",nome);
}

void exercicio9(){/*
    9. Contar palavras em uma frase
        Descrição:
        Conte quantas palavras existem em uma frase (separadas por espaço).
        Dica:
        Percorra a string e conte quantos espaços existem (mais um).*/
    char nome[50];
    int palavras = 0;
    bool novaPalavra = false;
    printf("Informe a frase:\n");
    scanf(" %[^\n]", nome);

    for(int i = 0; i<strlen(nome); i++){
        if(nome[i] == ' ' && novaPalavra){
            palavras++;
            novaPalavra = false;
        }else{
            novaPalavra = true;
        }
    }
    printf("Sua frase possui %d palavras!",palavras);
}

void exercicio10(){/*
    10. Verificar se é palíndromo
        Descrição:
        Peça uma palavra e diga se ela é um palíndromo (lida igual de trás pra frente).
        Exemplo:
        "ovo" → palíndromo
        "casa" → não é
        Dica:
        Compare a string original com sua versão invertida.*/
    char nome[50];
    printf("Informe a palavra:\n");
    scanf(" %[^\n]", nome);
    bool resultado = true;

    for(int i = 0, j = strlen(nome)-1 ; i < strlen(nome) ; i++,j--){
        if(nome[i] != nome[j]){
            resultado = false;
        }
    }
    if(resultado){
        printf("A palavra eh um palindromo!");
    }else{
        printf("A palavra nao eh um palindromo!");
    }
}

void exercicio11(){
    //11. Remover espaços extras
    // Peça uma frase e gere uma nova string sem espaços duplos ou no início/fim.

    char nome[50];
    printf("Informe uma frase:\n");
    scanf(" %[^\n]", nome);

    bool novaPalavra = false;
    int cont = 0;
    char novaString[50];

    for(int i = 0 ; i< strlen(nome); i++){
        if(nome[i] == ' '){
            if(novaPalavra){
                novaString[cont++] = ' ';
                novaPalavra = false;
            }
        }else{
            novaString[cont++] = nome[i];
            novaPalavra = true;
        }
    }
    novaString[cont] = '\0';

    printf("%s",novaString);

}

void exercicio12(){
    //12. Contar frequência de cada letra
    // Mostre quantas vezes cada letra do alfabeto aparece na frase.

    char nome[50];
    printf("Informe uma frase:\n");
    scanf(" %[^\n]", nome);

    int alfabeto[27];
    // inicializando
    for(int i = 0; i < 27 ; i++){
        alfabeto[i] = 0;
    }

    for(int i = 0 ; i< strlen(nome); i++){
        if(nome[i] == 'a' || nome[i] == 'A'){
            alfabeto[0]++;
        }else if(nome[i] == 'b' || nome[i] == 'B'){
            alfabeto[1]++;
        }
        else if(nome[i] == 'c' || nome[i] == 'C'){
            alfabeto[2]++;
        }
        else if(nome[i] == 'd' || nome[i] == 'D'){
            alfabeto[3]++;
        }
        else if(nome[i] == 'e' || nome[i] == 'E'){
            alfabeto[4]++;
        }
        else if(nome[i] == 'f'|| nome[i] == 'F'){
            alfabeto[5]++;
        }
        else if(nome[i] == 'g'|| nome[i] == 'G'){
            alfabeto[6]++;
        }
        else if(nome[i] == 'h'|| nome[i] == 'H'){
            alfabeto[7]++;
        }
        else if(nome[i] == 'i'|| nome[i] == 'I'){
            alfabeto[8]++;
        }
        else if(nome[i] == 'j'|| nome[i] == 'J'){
            alfabeto[9]++;
        }
        else if(nome[i] == 'k'|| nome[i] == 'K'){
            alfabeto[10]++;
        }
        else if(nome[i] == 'l'|| nome[i] == 'L'){
            alfabeto[11]++;
        }
        else if(nome[i] == 'm'|| nome[i] == 'M'){
            alfabeto[12]++;
        }
        else if(nome[i] == 'n'|| nome[i] == 'N'){
            alfabeto[13]++;
        }
        else if(nome[i] == 'o'|| nome[i] == 'O'){
            alfabeto[14]++;
        }
        else if(nome[i] == 'p' || nome[i] == 'P'){
            alfabeto[15]++;
        }
        else if(nome[i] == 'q'|| nome[i] == 'Q'){
            alfabeto[16]++;
        }
        else if(nome[i] == 'r'|| nome[i] == 'R'){
            alfabeto[17]++;
        }
        else if(nome[i] == 's'|| nome[i] == 'S'){
            alfabeto[18]++;
        }
        else if(nome[i] == 't'|| nome[i] == 'T'){
            alfabeto[19]++;
        }
        else if(nome[i] == 'u'|| nome[i] == 'U'){
            alfabeto[20]++;
        }
        else if(nome[i] == 'v'|| nome[i] == 'V'){
            alfabeto[21]++;
        }
        else if(nome[i] == 'w'|| nome[i] == 'W'){
            alfabeto[22]++;
        }
        else if(nome[i] == 'x'|| nome[i] == 'X'){
            alfabeto[23]++;
        }
        else if(nome[i] == 'y'|| nome[i] == 'Y'){
            alfabeto[24]++;
        }
        else if(nome[i] == 'z'|| nome[i] == 'Z'){
            alfabeto[25]++;
        }else{
            alfabeto[26]++;
        }
    }

    char aux = 65; // começa com A
    printf("As frequencias de letras que aparecem na frase sao:\n");
    for(int i = 0; i < 27 ; i++){
        if(alfabeto[i] > 0){
            if(i == 26){
                printf("%s - %d\n","Caracteres diversos",alfabeto[i]);
            }
            else{
                printf("%c - %d\n",aux++,alfabeto[i]);
            }
        }
        else{
            aux++;
        }
    }

}



int main(){
    // Exercicios
    // exercicio1();
    // exercicio1();
    // exercicio2();
    // exercicio3();
    // exercicio4();
    // exercicio5();
    // exercicio6();
    // exercicio7();
    // exercicio8();
    // exercicio9();
    // exercicio10();
    // exercicio11();
    exercicio12();
    return 0;
}
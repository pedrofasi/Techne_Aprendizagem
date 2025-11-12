/*

1. Sistema de Cadastro de Produtos
Descrição:
 
Crie um programa que gerencie o preço de produtos de uma loja.
 
Menu:
 
1 - Cadastrar preço (Desafio: Cadastre nome dos produtos junto)
2 - Listar preços
3 - (desafio) Buscar produto pelo nome 
4 - Mostrar preço mais caro e mais barato
5 - Média de preços
6 - Cadastrar Nome da loja
0 - Sair

ALUNO: Pedro Henrique Reis Rodrigues

*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;    

struct Produto {
    char nome[50];
    float preco;
};

Produto cadastrar_preco() {
    Produto p;
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco);
    printf("Produto cadastrado com sucesso!\n");
    printf("Pressione qualquer coisa para continuar...\n");
    fflush(stdin);
    getchar();
    return p;
}

void listar_precos(vector<Produto> produtos) {
    printf("Lista de Produtos:\n");
    for (int i = 0; i < produtos.size(); i++) {
        printf("Produto: %s, Preco: %.2f\n", produtos[i].nome, produtos[i].preco);
    }
    printf("Pressione qualquer coisa para continuar...\n");
    fflush(stdin);
    getchar();
}

void buscar_produto(vector<Produto> produtos) {
    if (produtos.empty()) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    char nome_busca[50];
    int contador = 0;
    bool caracterDiferente = true;
    bool encontrado = false;
    int tamanho_busca;
    int tamanho_produto;
    printf("Digite o nome do produto para buscar: ");
    scanf("%s", nome_busca);
    for(int i = 0; i< produtos.size(); i++){
        tamanho_busca = 0;
        tamanho_produto = 0;
        contador = 0;
        
        // Contando quantos numeros de caracter cada um tem
        for(; nome_busca[tamanho_busca] != '\0'; tamanho_busca++);
        for(; produtos[i].nome[tamanho_produto] != '\0'; tamanho_produto++);
        
        // Se os numeros de caracter são iguais, há a possibilidade que o produto pode ser encontrado
        // Caso não, ele nem entra.

        if(tamanho_produto == tamanho_busca){
            // Verificação caracter por caracter, caso haja um erro, flag vira falso, e ele não entra no proximo if.
            for(int j = 0; j < tamanho_produto; j++){
                if(produtos[i].nome[j] != nome_busca[j]){
                    caracterDiferente = false;
                    break;
                }
            }
            if(caracterDiferente){
                // Produto encontrado!!
                encontrado = true;
                printf("PRODUTO ENCONTRADO:\n");
                printf("Nome: %s\n", produtos[i].nome);
                printf("Preco: %.2f\n", produtos[i].preco);
            }
        }
    }
    if(encontrado){
        printf("Pressione qualquer coisa para continuar...\n");
        fflush(stdin);
        getchar();
    }
    else{
        printf("Nao encontramos o produto! =(\n");
        printf("Pressione qualquer coisa para continuar...\n");
        fflush(stdin);
        getchar();
    }
}

void mostrar_produto_mais_caro_e_barato(vector<Produto> produtos) {
    if (produtos.empty()) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    Produto mais_caro = produtos[0];
    Produto mais_barato = produtos[0];
    for (int i = 0; i < produtos.size(); i++) {
        if (produtos[i].preco > mais_caro.preco) {
            mais_caro = produtos[i];
        }
        if (produtos[i].preco < mais_barato.preco) {
            mais_barato = produtos[i];
        }
    }
    printf("Produto mais caro: %s, Preco: %.2f\n", mais_caro.nome, mais_caro.preco);
    printf("Produto mais barato: %s, Preco: %.2f\n", mais_barato.nome, mais_barato.preco);
    printf("Pressione qualquer coisa para continuar...\n");
    fflush(stdin);
    getchar();
}

void media_precos_produtos(vector<Produto> produtos) {
    if (produtos.empty()) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    float soma = 0;
    for (int i = 0; i < produtos.size(); i++) {
        soma += produtos[i].preco;
        printf("(%s) -> %.2f +\n",produtos[i].nome,produtos[i].preco);
    }
    printf("\t------------ / %d\n",produtos.size());
    float media = soma / produtos.size();
    printf("Media de precos dos produtos: %.2f\n", media);
    printf("Pressione qualquer coisa para continuar...\n");
    fflush(stdin);
    getchar();
}

int main() {
    vector <Produto> produtos;
    char nomeLoja[100];
    while(true){
        int opcao;
        system("cls");
        printf("Menu:\n1 - Cadastrar produto\n2 - Listar produtos\n3 - Buscar produto pelo nome\n4 - Mostrar produto com preco mais caro e mais barato\n5 - Media de precos\n6 - Cadastrar Nome da loja\n0 - Sair\n");
        scanf("%d", &opcao);
        system("cls");
        if(opcao == 0){
            break;
        }
        if(opcao == 1){
            produtos.push_back(cadastrar_preco());
        } else if(opcao == 2){
            // Código para listar preços
            listar_precos(produtos);
        } else if(opcao == 3){
            // Código para buscar produto pelo nome
            buscar_produto(produtos);
        } else if(opcao == 4){
            // Código para mostrar preço mais caro e mais barato
            mostrar_produto_mais_caro_e_barato(produtos);
        } else if(opcao == 5){
            // Código para calcular média de preços
            media_precos_produtos(produtos);
        } else if(opcao == 6){
            // Código para cadastrar nome da loja
            printf("Digite o nome da loja: ");
            scanf(" %[^\n]", nomeLoja);
            printf("Nome da loja cadastrado: %s\n", nomeLoja);
            printf("Pressione qualquer coisa para continuar...\n");
            fflush(stdin);
            getchar();
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
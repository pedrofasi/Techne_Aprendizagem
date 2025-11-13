/*
3. Animais Fantásticos – Criaturas e Sons
Classe base: CriaturaMagica, com emitirSom() virtual.
Filhos:
Grifo
Dragao
Fenix
Cada um emitir um som diferente.
No main, faça uma lista de criaturas e chame emitirSom().
Extra: Crie uma função void fazerBarulho(CriaturaMagica* c) que recebe um ponteiro genérico e chama o método virtual. Mostra que o tipo real é o da classe filha.
*/

#include <iostream>
#include <string>
#include <vector>

class CriaturaMagica{
    public:
    virtual void emitirSom(){
        std::cout << "Emitindo som generico" << std::endl;
    }
};

class Grifo:public CriaturaMagica{
    public:
    void emitirSom() override{
        std::cout << "Barulho do Grifo" << std::endl;
    }
};

class Dragao:public CriaturaMagica{
    public:
    void emitirSom() override{
        std::cout << "Barulho do Dragao" << std::endl;
    }
};

class Fenix:public CriaturaMagica{
    public:
    void emitirSom() override{
        std::cout << "Barulho do Fenix" << std::endl;
    }
};

void fazerBarulho(CriaturaMagica* m){
    m->emitirSom();
}

int main(){

    Grifo g;
    Dragao d;
    Fenix f;

    std::vector <CriaturaMagica*> cm;

    cm.push_back(&g);
    cm.push_back(&d);
    cm.push_back(&f);

    for(CriaturaMagica* criaturas : cm){
        criaturas->emitirSom();
    }
    while(true){
        std::cout << "Quer ouvir o barulho de quem?\n[1] Grifo\n[2] Dragao\n[3] Fenix\n[0] Sair" << std::endl;
        int opcao;
        std::cin >> opcao;
        if(opcao == 0){
            break;
        }else if(opcao == 1){
            // fazer barulho de um grifo
            fazerBarulho(&g);
        }else if(opcao == 2){
            // fazer barulho de um dragao
            fazerBarulho(&d);
        }else if(opcao == 3){
            // fazer barulho de um fenix
            fazerBarulho(&f);
        }else{
            std::cout << "Opcao invalida" << std::endl;
        }
    }

    return 0;
}
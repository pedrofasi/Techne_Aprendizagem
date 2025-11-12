#include <iostream>
#include <string>

class Pessoa{
    public:
        std::string nome;
        int idade;

        Pessoa(std::string n, int i){
            nome = n;
            idade = i;
           
        }   

        Pessoa(){

        }
    
};

class Bola{
    public:
        std::string nome;
        std::string material;
        float raio;
        std::string cor;

        Bola(){
            cor = "vermelho";
            material = "borracha";
        }
};

class Aluno{
    public:
        std::string nome;
        float nota1;
        float nota2;
        float nota3;
        float nota4;
        float media;

        Aluno(std::string n, float n1, float n2,float n3,float n4){
            nome = n;
            nota1 = n1;
            nota2 = n2;
            nota3 = n3;
            nota4 = n4;
            media = (n1+n2+n3+n4)/4;
        }
};

int main (){
    Pessoa p1("Marcelino",30);
    Pessoa p1("Marcelino",30);
    Pessoa p1("Marcelino",30);
    Pessoa p1("Marcelino",30);
    Pessoa p1("Marcelino",30);
  
    std::cout<<"Meu nome é: 0"<<p1.nome;

    Bola b1;
    std::cout<<"A cor da bola é "<<b1.cor;
    b1.cor = "azul";


    return 0;
}
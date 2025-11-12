
#include <iostream>
#include <string>

class Pessoa{
    public:
        std::string cpf;
        std::string nome;
        int idade;
        std::string dataNascimento;
        std::string endereco;


        Pessoa(){
            
        }
        Pessoa(std::string _cpf, std::string _nome, int _idade, std::string _dataNascimento, std::string _endereco){
            cpf = _cpf;
            nome = _nome;
            idade = _idade;
            dataNascimento = _dataNascimento;
            endereco = _endereco;
        }

        virtual void apresentar(){
            std::cout <<"Olá, eu sou "<< nome;
        }
};

class Aluno:public Pessoa{
    public:
        int matricula;
        float media;

         Aluno(int  _matricula, float _media,std::string _cpf, std::string _nome, int _idade, std::string _dataNascimento, std::string _endereco){
            matricula = _matricula;
            media = _media;
            cpf = _cpf;
            nome = _nome;
            idade = _idade;
            dataNascimento = _dataNascimento;
            endereco = _endereco;
         }

        Aluno(int  _matricula, float _media,std::string _cpf, std::string _nome, int _idade, std::string _dataNascimento, std::string _endereco)
            :Pessoa(_cpf, _nome, _idade, _dataNascimento, _endereco)
        {
            matricula = _matricula;
            media = _media;
        }

        Aluno(){

        }

        void estudar(){
            std::cout <<"Estou estudando pois minha média é: "<<media;
        }

        void apresentar() override{
            std::cout   <<"Oi, sou o aluno "<< nome
                        <<" e minha média é: "<< media; 
        }
};

class Professor:public Pessoa{
    public:
        std::string disciplina;
};

int main(){
    Aluno a1(1009, 10, "111.111.111-11","Carlos C++", 10, "10/10/2010","Rua aqui");

    a1.apresentar();
    a1.estudar();
    Pessoa p2 =  a1;

    Professor p1;
    p1.nome = "Paulo POO";
    p1.cpf = "222.222.222-22";
    p1.disciplina = "Matemática";
    p1.apresentar();
    


    return 0;
};
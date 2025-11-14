/*
SRP (Single Responsibility Principle)
Gerenciador de Usuários: Crie uma classe UsuarioService que seja responsável por cadastrar usuários, enviar e-mail de boas-vindas 
e gerar um relatório com todos os usuários cadastrados. Refatore essa classe para seguir o SRP, separando as responsabilidades em classes distintas 
(ex.: cadastro/gerenciamento, envio de e-mail, geração de relatório).
 
*/

#include <iostream>
#include <string>
#include <vector>

class Cadastro{
    public:
    std::string nome;
    int idade;
    std::string dataNasc;
    std::string email;
    Cadastro(std::string name, int age, std::string dataN, std::string em){
        nome = name;
        idade = age;
        dataNasc = dataN;
        email = em;
    }
};

class Emails{
    public:
    void DispararEmail(std::string email1, std::string email2){
        std::cout << "["<< email1 <<"]" << " Disparando email para -> " << email2 << std::endl;
    }
};

class Relatorio{
    public:
    void RelatorioGeral(std::vector <Cadastro*> users){
        int i = 0;
        for(Cadastro* usuario : users){
            std::cout << i << ". NOME: " << usuario->nome << "- EMAIL:" << usuario->nome << std::endl;
            i++;
        }
    }
};

class UsuarioService{
    public:
        std::vector<Cadastro*> usuarios;
};


int main(){
    Cadastro cadastro1("Pedro",24,"24/11/2000","pepedeus11@gmail.com");
    Cadastro cadastro2("Pedro1",25,"25/11/2000","pepedeus12@gmail.com");
    
    Relatorio relatar;
    Emails email;
    UsuarioService usuariosMain;

    usuariosMain.usuarios.push_back(&cadastro1);
    usuariosMain.usuarios.push_back(&cadastro2);

    email.DispararEmail(usuariosMain.usuarios[0]->email, usuariosMain.usuarios[1]->email);
    relatar.RelatorioGeral(usuariosMain.usuarios);

    
    return 0;
}
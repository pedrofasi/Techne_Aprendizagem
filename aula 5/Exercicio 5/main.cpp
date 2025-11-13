/*
5. RPG – Habilidades de Classes (Mago, Guerreiro, Arqueiro)
Classe base: Personagem, com método virtual atacar().
Derivados:
Mago → “Lançando bola de fogo!”
Guerreiro → “Golpeando com espada pesada!”
Arqueiro → “Disparando flecha precisa!”
Peça para os alunos criarem um vector<Personagem*> equipe com misto de personagens e chamarem atacar() num loop.
Extra:
Adicionar um método virtual especial() e fazer cada classe implementar algo totalmente diferente.
*/

#include <string>
#include <iostream>
#include <vector>


class Personagem{
    public:
    void virtual atacar(){
        std::cout << "Ataque generico" << std::endl;
    }
    void virtual especial(){
        std::cout << "Especial generico." << std::endl;
    }
};

class Mago:public Personagem{
    public:
    void atacar() override{
        std::cout << "Lancando bola de fogo!" << std::endl;
    }
    void especial() override{
        std::cout << "[MAGO ESPECIAL] BOLA FLAMEJANTE!" << std::endl;
    }
};

class Guerreiro:public Personagem{
    public:
    void atacar() override{
        std::cout << "Golpeando com espada pesada!" << std::endl;
    }
    void especial() override{
        std::cout << "[GUERREIRO ESPECIAL] ESPADA PERFURANTE!" << std::endl;
    }
};

class Arqueiro:public Personagem{
    public:
    void atacar() override{
        std::cout << "Disparando flecha precisa!" << std::endl;
    }
    void especial() override{
        std::cout << "[ARQUEIRO ESPECIAL] MIRA 100X ATIVADA!" << std::endl;
    }
};

int main(){
    Mago m;
    Guerreiro g;
    Arqueiro a;

    std::vector <Personagem*> p;

    p.push_back(&m);
    p.push_back(&g);
    p.push_back(&a);

    for(Personagem* personagens : p){
        personagens->atacar();
        personagens->especial();
    }
    
    return 0;

}
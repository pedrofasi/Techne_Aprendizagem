/*
2. X-Men – Sistema de Mutantes
Classe base: Mutante, com método virtual usarPoder().
Crie 3 mutantes:
Wolverine → “Ativando garras de adamantium!”
JeanGrey → “Telepatia e telecinese ativadas!”
Noturno → “BAMF! Teletransportando...”
Simule uma batalha chamando usarPoder() polimorficamente num array de Mutante*.
*/


#include <iostream>
#include <string>
#include <vector>

class Mutante{
    public:
    virtual void usarPoder();
};

class Wolverine:public Mutante{
    public:
    void usarPoder() override{
        std::cout << "Ativando garras de adamantium!" << std::endl;
    }
};

class JeanGrey:public Mutante{
    public:
    void usarPoder() override{
        std::cout << "Telepatia e telecinese ativadas!" << std::endl;
    }
};

class Noturno:public Mutante{
    public:
    void usarPoder() override{
        std::cout << "BAMF! Teletransportando..." << std::endl;
    }
};

int main(){

    Wolverine wolverine;
    JeanGrey jeangrey;
    Noturno noturno;

    std::vector <Mutante*> m;

    m.push_back(&wolverine);
    m.push_back(&jeangrey);
    m.push_back(&noturno);

    for(Mutante* mutantes : m){
        mutantes->usarPoder();
    }
    return 0;
}
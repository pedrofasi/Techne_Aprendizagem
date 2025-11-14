/*
OCP (Open/Closed Principle)
Cálculo de Frete: Implemente uma classe Pedido que calcula o valor do frete de acordo com o tipo de entrega (normal ou expressa), usando if ou switch. 
Em seguida, refatore o código para seguir o OCP, criando uma abstração para cálculo de frete e classes específicas para cada tipo (por exemplo, FreteNormal, FreteExpresso), 
de forma que novos tipos de frete possam ser adicionados sem modificar a classe Pedido.
*/

#include <iostream>
#include <string>
#include <vector>

// Classe sem refatoração

class FreteRepository{
    public:
    virtual void calcularFrete(int valor){
    };
};

class FreteRepositoryNormal:public FreteRepository{
    public:
    void calcularFrete(int valorPedido) override{
        valorPedido = valorPedido * 1.1;
        std::cout << valorPedido << " [NORMAL]" << std::endl;
    }
};

class FreteRepositoryExpresso:public FreteRepository{
    public:
    void calcularFrete(int valorPedido) override{
        valorPedido = valorPedido * 1.5;
        std::cout << valorPedido << " [EXPRESSO]" << std::endl;
    }
};

class FreteService {
    public:
    FreteRepository* freteRepository;

    FreteService() {}
    FreteService(FreteRepository* repo){
        freteRepository = repo;
    };

    void processarFrete(int valor) {
        std::cout << "Frete calculado: ";
        freteRepository->calcularFrete(valor);
    }
};

int main(){
    FreteRepository* fre = new FreteRepositoryExpresso();
    FreteRepository* frn = new FreteRepositoryNormal();
    std::vector<FreteService*> servico;
    servico.push_back(new FreteService(fre));
    servico.push_back(new FreteService(frn));

    for(FreteService* fretes : servico){
        fretes->processarFrete(20); // simulando valor de 20
    }

    return 0;
}


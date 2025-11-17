// OCP (Open/Closed Principle)
// Cálculo de Frete: Implemente uma classe Pedido que calcula o valor do frete de acordo 
// com o tipo de entrega (normal ou expressa), usando if ou switch. Em seguida, refatore o código para seguir o OCP, 
// criando uma abstração para cálculo de frete e classes específicas para cada tipo (por exemplo, FreteNormal, FreteExpresso), 
// de forma que novos tipos de frete possam ser adicionados sem modificar a classe Pedido.

#include <string>
#include <iostream>

class Frete{
    public:
    double valor;
    virtual void calcularFrete();

};

class IAplicarDesconto{
    public:
    virtual void aplicarDesconto();
};

class IMudarRota{
    public:
    virtual void mudarRota();
}

class FreteNormal : public Frete, public IAplicarDesconto{
    public:
    
    void calcularFrete() override {
        valor = valor * 0.1; // 10% do valor do pedido
        std::cout << "Frete Normal: R$ " << frete << std::endl;
    }
    
    void aplicarDesconto() override {
        valor = valor - (valor * 0.05); // 5% de desconto
        std::cout << "Desconto Aplicado: R$ " << desconto << std::endl;
    }
};

class FreteVip : public Frete, public IAplicarDesconto, public IMudarRota{
    public:
    
    void calcularFrete() override {
        valor = valor * 0.05; // 5% do valor do pedido
        std::cout << "Frete VIP: R$ " << frete << std::endl;
    }
    
    void aplicarDesconto() override {
        valor = valor - (valor * 0.1); // 10% de desconto
        std::cout << "Desconto Aplicado: R$ " << desconto << std::endl;
    }
    void mudarRota() override {
        std::cout << "Rota do Frete VIP alterada com sucesso!" << std::endl;
    }
}
class FreteExpresso : public IFrete{
    public:
    
    void calcularFrete(double valor) override {
        double frete = valor * 0.2; // 20% do valor do pedido
        std::cout << "Frete Expresso: R$ " << frete << std::endl;
    }
};
class FreteEconomico : public IFrete{
    public:
    
    void calcularFrete(double valor) override {
        double frete = valor * 0.08; // 8% do valor do pedido
        std::cout << "Frete Econômico: R$ " << frete << std::endl;
    }
};

MVC
Design Patterns
Arquitetura Hexagonal
Arquitetura Limpa


int main(){
    double valorPedido;
    std::cout << "Digite o valor do pedido: ";
    std::cin >> valorPedido;

    Frete frete = FreteExpresso();
    frete.calcularFrete(valorPedido);

}


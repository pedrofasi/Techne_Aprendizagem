/*
LSP (Liskov Substitution Principle)
Formas de Pagamento com Limite: Implemente uma classe base Cartao com métodos para autorizar pagamento e consultar limite disponível. 
Crie as subclasses CartaoCredito e CartaoDebito, garantindo que qualquer código que use Cartao funcione corretamente com as subclasses, 
sem quebrar expectativas de comportamento (limites, autorização, etc.).
 
*/

#include <iostream>
#include <string>
#include <vector>

class Cartao{
    public:
        int valorConta;
        int limite;
    virtual void processarPagamento(int valorCompra){

    }
};

class CartaoDebito:public Cartao{
    public:
    CartaoDebito(int vlrCnt){
        valorConta = vlrCnt;
    }
    virtual void processarPagamento(int valorCompra){
        if(valorCompra <= valorConta){
            std::cout << "Transacao concluida!" << std::endl;
            valorConta -= valorCompra;
        }
        else{
            std::cout << "Saldo indisponivel! SALDO ATUAL: " << valorConta << " VALOR DA COMPRA: " << valorCompra << std::endl;
        }
    }
};

class CartaoCredito:public Cartao{
    public:
    CartaoCredito(int limit){
        limite = limit;
    }
    virtual void processarPagamento(int valorCompra){
        if(valorCompra <= limite){
            std::cout << "Transacao concluida!" << std::endl;
            limite -= valorCompra;
        }else{
            std::cout << "Sem limite disponivel! LIMITE ATUAL:" << limite << " VALOR DA COMPRA:" << valorCompra << std::endl;
        }
        
    }
};

int main(){
    Cartao *cc = new CartaoCredito(100);
    Cartao *cd = new CartaoDebito(100);

    cc->processarPagamento(10);
    cc->processarPagamento(100);

    cd->processarPagamento(200);

}
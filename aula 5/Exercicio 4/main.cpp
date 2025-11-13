/*
4. Pagamentos – Sistema Financeiro
Classe base: Pagamento, com método virtual processar().
Filhos:
PagamentoPix
PagamentoCartaoCredito
PagamentoBoleto
Cada um descreve como é processado, por exemplo:
Pix → “Processando transferência instantânea.”
Cartão → “Autorizando transação via operadora.”
Boleto → “Registrando boleto em banco.”
Crie um vetor de pagamentos e processe todos.
*/

#include <iostream>
#include <string>
#include <vector>

class Pagamento{
    public:
    virtual void processar(){
        std::cout << "Processando generico" << std::endl;
    }  
};

class PagamentoPix:public Pagamento{
    public:
    void processar() override{
        std::cout << "Processando transferencia instantanea" << std::endl;
    }
};

class PagamentoCartaoCredito:public Pagamento{
    public:
    void processar() override{
        std::cout << "Autorizando transacao via operadora." << std::endl;
    }
};

class PagamentoBoleto:public Pagamento{
    public:
    void processar() override{
        std::cout << "Registrando boleto em banco." << std::endl;
    }
};

int main(){
    std::vector <Pagamento*> v;
    PagamentoBoleto b;
    PagamentoCartaoCredito cc;
    PagamentoPix p;

    v.push_back(&b);
    v.push_back(&cc);
    v.push_back(&p);

    for(Pagamento* pagamentos : v){
        pagamentos->processar();
    }
}


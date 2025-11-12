
#include "ContaBancaria.h"

class ContaInvestimento : public ContaBancaria {
    public:
        double rendimento;

    void calcularRendimento();
};

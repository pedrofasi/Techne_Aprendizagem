#include "Dano.h"
#include <unordered_map>
#include <string>
using namespace std;


double FogoRelacao::calcularMultiplicador(const string& tipoDefensor) const {
    if(tipoDefensor == "Gelo") {
        return 2.0;
    } else {
        return 0.5;
    }
}

double AguaRelacao::calcularMultiplicador(const string& tipoDefensor) const {
    if (tipoDefensor == "Fogo") {
        return 2.0;
    } else {
        return 0.5;
    }
}

double GeloRelacao::calcularMultiplicador(const string& tipoDefensor) const {
    if(tipoDefensor == "Agua") {
        return 2.0;
    } else {
        return 0.5;
    }
}

double VoadorRelacao::calcularMultiplicador(const string& tipoDefensor) const {
    if(tipoDefensor == "Voador") {
        return 2.0;
    } else {
        return 0.5;
    }
}

double TerrestreRelacao::calcularMultiplicador(const string& tipoDefensor) const {
    if(tipoDefensor == "Terrestre") {
        return 2.0;
    } else {
        return 0.5;
    }
}


IRelacaoElemento* TabelaElementos::getRelacao(const string& tipo) {

    static unordered_map<string, IRelacaoElemento*> mapa = {
        {"Fogo",      new FogoRelacao()},
        {"Agua",      new AguaRelacao()},
        {"Gelo",      new GeloRelacao()},
        {"Voador",    new VoadorRelacao()},
        {"Terrestre", new TerrestreRelacao()}
    };

    return mapa[tipo];
}
 
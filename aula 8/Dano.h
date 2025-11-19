#ifndef DANO_H
#define DANO_H

#include <string>

class IRelacaoElemento {
public:
    virtual double calcularMultiplicador(const std::string& tipoDefensor) const = 0;
    virtual ~IRelacaoElemento() = default;
};

class FogoRelacao : public IRelacaoElemento {
public:
    double calcularMultiplicador(const std::string& tipoDefensor) const override;
};

class AguaRelacao : public IRelacaoElemento {
public:
    double calcularMultiplicador(const std::string& tipoDefensor) const override;
};

class GeloRelacao : public IRelacaoElemento {
public:
    double calcularMultiplicador(const std::string& tipoDefensor) const override;
};

class VoadorRelacao : public IRelacaoElemento {
public:
    double calcularMultiplicador(const std::string& tipoDefensor) const override;
};

class TerrestreRelacao : public IRelacaoElemento {
public:
    double calcularMultiplicador(const std::string& tipoDefensor) const override;
};


class TabelaElementos {
public:
    static IRelacaoElemento* getRelacao(const std::string& tipo);
};

#endif
 
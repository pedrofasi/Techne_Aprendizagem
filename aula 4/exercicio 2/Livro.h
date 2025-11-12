#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>
#include "Produto.h"

class Livro:public Produto{
    public:
        std::string titulo;
        std::string autor;
        std::string dataLancamento;
};
#endif
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item{
    public:
        string Nome;
        string Raridade;
        int danoBase;
    void abrirBau();
};

#endif
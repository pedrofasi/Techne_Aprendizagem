#include <iostream>
using namespace std;  // Permite usar cout e endl sem o prefixo std::

int soma(int a, int b) {
    return a + b;
}

int main() {
    cout << "Hello, World!" << endl;
    int resultado = soma(3, 4);
    cout << "Soma: " << resultado << endl;
    return 0;
}
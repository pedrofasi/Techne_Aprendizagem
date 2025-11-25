#include <iostream>
#include <cmath>
using namespace std;

/*
Se o usuário informar o valor de A igual a zero, a equação não é do segundo grau e o programa não deve fazer pedir os demais valores 
Se o delta calculado for negativo, a equação não possui raizes reais. Informe ao usuário e encerre o programa; 
Se o delta calculado for igual a zero a equação possui apenas uma raiz real; informe-a ao usuário; 
Se o delta for positivo, a equação possui duas raiz reais; informe-as ao usuário;
*/
void bhaskara(double a,double b,double c){
    if(a == 0){
        throw invalid_argument("O valor de A nao pode ser igual a 0.");
    }

    double delta;
    delta = b*b - (4*a*c);
    if(delta < 0){
        throw invalid_argument("O valor de delta eh negativo. A equacao nao possui raizes reais.");
    }
    if(delta == 0){
        double raiz;
        raiz = -b/(2*a);
        cout << "Delta igual a zero. Unica raiz da equacao eh: " << raiz << endl;
        return;
    }

    double raizA,raizB;
    raizA = (-b + sqrt(delta))/(2*a);
    raizB = (-b - sqrt(delta))/(2*a);

    cout << "Raiz X = " << raizA << "\nRaiz X' = " << raizB << endl;
}

int main(){
    double a,b,c;
    int opc;
    bool saiu;
    while(true){
        try{
            cout << "Informe o A:" << endl;
            cin >> a;
            cout << "Informe o B:" << endl;
            cin >> b;
            cout << "Informe o C:" << endl;
            cin >> c;

            bhaskara(a,b,c);

        } catch(const exception& e){
            cout << "Erro: " << e.what() << endl;
        }
        while(true){
            cout << "Deseja continuar?\n[1] Continuar\n[0] Sair" << endl;
            cin >> opc;
            if(opc == 1){
                saiu = false;
            }else if(opc==0){
                saiu = true;
                break;
            }else{
                cout << "Selecione uma opcao valida." << endl;
            }
        }
        if(saiu){
            break;
        }
    }

    return 0;
}
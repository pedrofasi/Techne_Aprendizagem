/*
Exercício – Agenda Telefônica Simples
Objetivo: praticar operações básicas de CRUD no map.
Descrição:
Criar uma agenda que guarda nome → telefone usando std::map<std::string, std::string>.
O programa deve permitir:
adicionar um contato
buscar um contato pelo nome
listar todos os contatos
Sem menu complexo — pode ser tudo direto no main() para praticar.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

void adiciona_contato(map<string,string> &Contatos){
    string nome,telefone;
    cout << "Informe o nome do novo contato" << endl;
    getline(cin,nome);
    cout << "Informe o telefone do novo contato" << endl;
    getline(cin,telefone);
    
    Contatos[nome]=telefone;

    cout << "Contato adicionado com sucesso." << endl;
}

void busca_contato(map<string,string> &Contatos){
    cout << "Informe o nome do contato" << endl;
    string nome;
    getline(cin,nome);
    bool encontrado = false;
    for(auto &contato : Contatos){
        if(contato.first == nome){
            // Contato encontrado
            cout << "Contato encontrado: " << endl;
            cout << "Nome: " << contato.first << endl;
            cout << "Telefone: " << contato.second << endl;
            encontrado = true;
        }
    }

    if(!encontrado){
        cout << "Nenhum contato cadastrado com esse nome." << endl;
    }
}

void lista_contato(map<string,string> &Contatos){
    if(Contatos.size() == 0){
        cout << "Nnenhum Contato Registrado no Momento." << endl;
    }else{
        cout << "Lista de Contatos" << endl;
        for(auto &contato : Contatos){
            cout << "Nome: " << contato.first << " | Telefone: " << contato.second << endl;
        }
    }
}

void menu(map <string,string> &Contatos){
    while(true){
        int opc;
        cout << "[1] Adicionar contato\n[2] Buscar contato\n[3] Listar contatos\n[0] Sair" << endl;
        cin >> opc;
        cin.ignore();
        if(opc == 0){
            break;
        }else if(opc == 1){
            adiciona_contato(Contatos);
        }else if(opc == 2){
            busca_contato(Contatos);
        }else if(opc == 3){
            lista_contato(Contatos);
        }
    }
}

int main(){
    map <string,string> Contatos;
    menu(Contatos);
    return 0;
}
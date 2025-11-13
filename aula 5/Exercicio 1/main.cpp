/*
1. Sistema de Mensagens (WhatsApp/Telegram)
Crie um sistema onde exista uma classe base Mensagem com um método virtual enviar().
Crie subclasses:
    MensagemTexto
    MensagemVoz
    MensagemImagem

    Cada tipo deve sobrescrever enviar() com uma saída diferente, por exemplo:
Texto: “Enviando texto: olá mundo!”
Voz: “Enviando áudio de 17s...”
Imagem: “Enviando imagem (2048x1080)...”
No main, crie um vetor Mensagem* mensagens[5] com misto dos três tipos e chame enviar() num loop.
*/

#include <iostream>
#include <string>

class Mensagem{
    public:
        std::string mensagem;
    Mensagem(std::string msg){
        mensagem = msg;
    }
    virtual void enviar(){
        std::cout << "Enviando mensagem generica" << std::endl;
    }
};

class MensagemTexto:public Mensagem{
    public:
    MensagemTexto(std::string msg):Mensagem(msg){
        mensagem = msg;
    }
    void enviar() override{
        std::cout << "[Mensagem de TEXTO]: " << mensagem << std::endl;
    }
};

class MensagemVoz:public Mensagem{
    public:
    MensagemVoz(std::string msg):Mensagem(msg){
        mensagem = msg;
    }
    void enviar() override{
        std::cout << "[Mensagem de VOZ]: " << mensagem << std::endl;
    }
};

class MensagemImagem:public Mensagem{
    public:

    MensagemImagem(std::string msg):Mensagem(msg){
        mensagem = msg;
    }
    void enviar() override{
        std::cout << "[Mensagem de IMAGEM]: " << mensagem << std::endl;
    }
};

int main(){
    MensagemImagem imagem("Imagem de um gatinho fofo.");
    MensagemTexto texto("Ola mundo!");
    MensagemVoz voz("comprou pao??");
    MensagemImagem imagem2("Foto de um carro");
    MensagemVoz voz2("chegou bem em casa?");

    Mensagem* m[5] = {&imagem, &texto, &voz, &imagem2, &voz2};

    for(Mensagem* mensagens : m){
        mensagens->enviar();
    }  


    return 0;
}
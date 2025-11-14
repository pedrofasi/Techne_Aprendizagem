/*
DIP (Dependency Inversion Principle)
Sistema de Notificações: Implemente um sistema de notificação ao usuário que
possa enviar mensagens por e-mail e SMS. 
Comece com uma classe NotificacaoService que instancia diretamente 
EmailService e SmsService. 
Depois, refatore para seguir o DIP, criando uma abstração 
(por exemplo, INotificador) e fazendo com que 
NotificacaoService dependa dessa abstração, 
permitindo adicionar novos tipos de notificação (como push) 
sem modificar o código principal.
*/

#include <iostream>
#include <string>
#include <vector>


class INotificador{
    public:
    virtual void enviarMsg(std::string mensagem){}
};

class SMS:public INotificador{
    public:
    void enviarMsg(std::string mensagem) override{
        std::cout << "[SMS] - " << mensagem << std::endl;
    }
};

class EMAIL:public INotificador{
    public:
    void enviarMsg(std::string mensagem) override{
        std::cout << "[EMAIL] - " << mensagem << std::endl;
    }
};

class NotificacaoService{
    public:
        INotificador* notificacoes;
    NotificacaoService(){}
    NotificacaoService(INotificador* noti){
        notificacoes = noti;
    } 

    void dispararMensagens(std::string mensagem){
        std::cout << "Disparando mensagem:" << std::endl;
        notificacoes->enviarMsg(mensagem);
    }
};

int main(){
    std::vector <NotificacaoService*> notis;
    INotificador* sms = new SMS();
    INotificador* email = new EMAIL();
    notis.push_back(new NotificacaoService(sms));
    notis.push_back(new NotificacaoService(email));

    for(NotificacaoService* notificacoes : notis){
        notificacoes->dispararMensagens("Ola!"); // simulando valor de 20
    }
}
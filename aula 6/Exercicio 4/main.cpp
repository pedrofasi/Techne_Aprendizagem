/*
ISP (Interface Segregation Principle)
Mídia Player: Suponha uma interface única IMidiaPlayer com os métodos reproduzirMusica, reproduzirVideo e gravarAudio. 
Mostre o problema de forçar classes como PlayerMusicaSimples e GravadorDeAudio a implementarem métodos que não fazem sentido para elas. 
Em seguida, refatore criando interfaces menores e mais específicas (por exemplo, IReproduzMusica, IReproduzVideo, IGravaAudio) e 
ajuste as classes para implementar apenas o que realmente utilizam.
 
*/

#include <iostream>
#include <string>
#include <vector>

class IMidiaPlayer{
    public:
    virtual void ligarMidia() = 0;
    virtual void menu() = 0;
    virtual ~IMidiaPlayer() {}
};

class IReproduzMusica{
    public:
    virtual void reproduzirMusica() = 0;
    virtual ~IReproduzMusica() {}
};

class IReproduzVideo{
    public:
    virtual void reproduzirVideo() = 0;
    virtual ~IReproduzVideo() {}
};

class IGravaAudio{
    public:
    virtual void GravarAudio() = 0;
    virtual ~IGravaAudio() {}
};

class PlayerMusicaSimples:public IMidiaPlayer,public IReproduzVideo,public IReproduzMusica{
    public:
    void ligarMidia() override{
        std::cout << "Player Ligado." << std::endl;
    }
    void reproduzirMusica() override{
        std::cout << "[PLAYER] - Reproduzindo Musica" << std::endl;
    }
    void reproduzirVideo() override{
        std::cout << "[PLAYER] - Reproduzindo Video" << std::endl;
    }
    void menu() override{
        std::cout << "Iniciando video e musica" << std::endl;
        reproduzirVideo();
        reproduzirMusica();
    }
};

class GravadorAudio:public IMidiaPlayer, public IGravaAudio{
    public:
    void ligarMidia() override{
        std::cout << "Gravador Ligado." << std::endl;
    }
    void GravarAudio() override{
        std::cout << "Gravando audio..." << std::endl;
    }
    void menu() override{
        std::cout << "Iniciando gravador de voz" << std::endl;
        GravarAudio();
    }
};

int main(){
    PlayerMusicaSimples pms;
    GravadorAudio ga;

    std::vector<IMidiaPlayer*> midias = {&pms,&ga};

    for(IMidiaPlayer* midia : midias){
        midia->ligarMidia();
        midia->menu();

        std::cout << "----------------------" << std::endl;
    }

}
/*
3. Classe PlaylistMusical
Simule uma playlist:
Atributos: nome da playlist, música atual.

Métodos:

adicionarMusica(String musica)

tocarProxima()

mostrarMusicaAtual()

Desafio extra: Crie uma lista de 5 músicas e toque todas em sequência.
*/

#include "PlaylistMusical.h"
#include <string>
#include <iostream>
#include <vector>

void PlaylistMusical::adicionarMusica(string musica){
    if(musicas.size() == 0){
        musicaAtual = musica;
    }
    musicas.push_back(musica);
    cout << "Musica: " << musica << " adicionada na playlist na: " << nome << endl;
}


void PlaylistMusical::tocarProxima(){
    if(prox+1 == musicas.size()){
        prox = -1;
        // pra voltar a tocar a primeira
    }
    prox += 1;
    musicaAtual = musicas[prox];
    cout << "Tocando: '" << musicaAtual << "' agora! " << endl;
}


void PlaylistMusical::mostrarMusicaAtual(){
    if(musicas.size() == 0){
        cout << "Voce ainda nao adicionou nenhuma musica a playlist!"<< endl;
    }else{
        cout << "Voce esta ouvindo: " << musicaAtual << endl;
    }
}
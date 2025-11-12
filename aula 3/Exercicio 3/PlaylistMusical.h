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

#ifndef PLAYLISTMUSICAL_H
#define PLAYLISTMUSICAL_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PlaylistMusical{
    public:
        int prox = 0;
        string nome;
        vector <string> musicas;
        string musicaAtual;
    void adicionarMusica(string musica);
    void tocarProxima();
    void mostrarMusicaAtual();

};

#endif
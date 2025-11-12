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

#include <iostream>
#include "PlaylistMusical.h"
#include "PlaylistMusical.cpp"
#include <string>
using namespace std;

int main(){
    PlaylistMusical playlist;
    playlist.nome = "Minha nova Playlist";
    playlist.mostrarMusicaAtual();
    playlist.adicionarMusica("Eminem - Slim Shady");
    playlist.adicionarMusica("Paramore - Decode");
    playlist.adicionarMusica("Sum 41- Never There");
    playlist.adicionarMusica("Nickelback - Lullaby");
    playlist.adicionarMusica("Linkin Park - Castle of Glass");
    
    playlist.mostrarMusicaAtual();
    playlist.tocarProxima();

    playlist.mostrarMusicaAtual();
    playlist.tocarProxima();

    playlist.mostrarMusicaAtual();
    playlist.tocarProxima();

    playlist.mostrarMusicaAtual();
    playlist.tocarProxima();

    playlist.mostrarMusicaAtual();
    playlist.tocarProxima();

    playlist.mostrarMusicaAtual();
    playlist.tocarProxima();
    
    playlist.mostrarMusicaAtual();
    playlist.tocarProxima();

    return 0;
}
#include "Matchmaking.hpp"
#include <iostream>
#include <string>
using namespace "Matchmaking.hpp"

Matchmaking(int max_players){

}
~Matchmaking(){
}

bool insert(Player player){
    // deve inserir o jogador no final do array.
    // Caso exista espaço disponível, o jogador deve ser inserido e o método deve retornar true.
    // Caso não exista espaço disponível, o método deve retornar false.
    if (size < MAX_PLAYERS){
        players[size] = player;
        size++;
        return true;
    }
    return false;
}
bool removePlayer(int id){
// deve remover da fila o jogador com o identificador informado.
// O método deve retornar:
// true, caso o jogador seja encontrado e removido;
// false, caso nenhum jogador com o ID informado seja encontrado.

    int current = 0
    while (current < MAX_PLAYERS) {
        if (players[current].getId() == id){
            for(int i = current; i < MAX_PLAYERS; i++){
                
            }
        }
    }
}

void sortByScoreInsertion(){

}
void sortByScoreMerge(){

}

Player* formGroup(int groupSize, int delta, int* n){

}

Player* getWaitingPlayers(int* n){

}

void printWaitingPlayers(){

}

// Outros métodos auxiliares, se necessário
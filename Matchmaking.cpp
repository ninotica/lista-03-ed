#include "Matchmaking.hpp"
#include <iostream>
#include <string>

Matchmaking::Matchmaking() {

}
Matchmaking::~Matchmaking() {
}

bool Matchmaking::insert(Player player) {
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
bool Matchmaking::removePlayer(int id) {
// deve remover da fila o jogador com o identificador informado.
// O método deve retornar:
// true, caso o jogador seja encontrado e removido;
// false, caso nenhum jogador com o ID informado seja encontrado.

    int current = 0;
    while (current < MAX_PLAYERS) {
        if (players[current].getId() == id){
            for(int i = current; i < MAX_PLAYERS; i++){
                
            }
        }
    }
}

void Matchmaking::sortByScoreInsertion() {

}
void Matchmaking::sortByScoreMerge() {

}

Player* Matchmaking::formGroup(int groupSize, int delta, int* n) {

}

Player* Matchmaking::getWaitingPlayers(int* n) {

}

void Matchmaking::printWaitingPlayers() {

}

// Outros métodos auxiliares, se necessário
#include "Player.hpp"
#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

const int MAX_PLAYERS = 1000;

class Matchmaking {

private:

    Player players[MAX_PLAYERS];
    int size;

public:

    Matchmaking();
    ~Matchmaking();

    bool insert(Player player);
    bool removePlayer(int id);

    void sortByScoreInsertion();
    void sortByScoreMerge();

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

};

void mergeSort(Player arr[], int left, int right);
void merge(Player arr[], int left, int mid, int right);

#endif
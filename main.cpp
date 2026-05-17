#include "Matchmaking.hpp"

int main() {
    Matchmaking matchmaking = Matchmaking();

    Player Trajano(1, "Trajano", 1000, 2);
    Player Nina(2, "Nina", 1100, 3);
    Player Boldrini(3, "Boldrini", 900, 1);
    Player Yuri(4, "Yuri", 1150, 4);

    matchmaking.insert(Boldrini);
    matchmaking.insert(Trajano);
    matchmaking.insert(Nina);
    matchmaking.insert(Yuri);

    matchmaking.sortByScoreInsertion();
    matchmaking.sortByScoreMerge();

    int n;
    matchmaking.formGroup(3, 200, &n);

    matchmaking.removePlayer(1);
    matchmaking.removePlayer(2);

}
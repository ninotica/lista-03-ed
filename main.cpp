#include <chrono>
#include <cstdlib>
#include "Matchmaking.hpp"

int main() {
    Matchmaking* matchmaking = new Matchmaking();

    Player Trajano(1, "Trajano", 1000, 3);
    Player Nina(2, "Nina", 1100, 1);
    Player Boldrini(3, "Boldrini", 900, 2);
    Player Yuri(4, "Yuri", 1150, 4);
    Player Larissa(5, "Larissa", 1000, 6);
    Player Lisa(6, "Lisa", 1150, 5);

    std::cout << "===============================================" << std::endl;
    std::cout << "||           INSERCAO DE JOGADORES           ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    matchmaking->insert(Nina);
    matchmaking->insert(Boldrini);
    matchmaking->insert(Trajano);

    matchmaking->printWaitingPlayers();

    std::cout << "===============================================" << std::endl;
    std::cout << "||            INSERTION SORT                 ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    matchmaking->sortByScoreInsertion();
    matchmaking->printWaitingPlayers();

    std::cout << "===============================================" << std::endl;
    std::cout << "||       INSERCAO DE MAIS JOGADORES          ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    matchmaking->insert(Yuri);
    matchmaking->insert(Larissa);
    matchmaking->insert(Lisa);

    matchmaking->printWaitingPlayers();

    std::cout << "===============================================" << std::endl;
    std::cout << "||              MERGE SORT                   ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    matchmaking->sortByScoreMerge();
    matchmaking->printWaitingPlayers();

    std::cout << "===============================================" << std::endl;
    std::cout << "||           FORMACAO DE GRUPO               ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    int n;
    Player* group = matchmaking->formGroup(3, 200, &n);
    delete[] group;

    matchmaking->printWaitingPlayers();

    std::cout << "===============================================" << std::endl;
    std::cout << "||           REMOCAO DE JOGADOR              ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    matchmaking->removePlayer(4);
    matchmaking->printWaitingPlayers();

    std::cout << "===============================================" << std::endl;
    std::cout << "||      FALHA NA FORMACAO DE GRUPO           ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    matchmaking->formGroup(3, 100, &n);

    std::cout << "===============================================" << std::endl;
    std::cout << "||          GETWAITINGPLAYERS                ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    int m;
    Player* players = matchmaking->getWaitingPlayers(&m);
    std::cout << "Jogadores na fila: " << m << std::endl;
    delete[] players;

    std::cout << "===============================================" << std::endl;
    std::cout << "||             TESTES DE TEMPO               ||" << std::endl;
    std::cout << "===============================================" << std::endl;

    Matchmaking* matchA = new Matchmaking();
    Matchmaking* matchB = new Matchmaking();

    srand(42);

    for (int i = 1; i <= 10000; i++){
        int score = rand() % 100000;
        matchA->insert(Player(i, "irineu", score, i));
        matchB->insert(Player(i, "irineu", score, i));
    }

    auto start_i = std::chrono::high_resolution_clock::now();

    matchA->sortByScoreInsertion();

    auto end_i = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> insert_time = end_i - start_i;

    auto start_m = std::chrono::high_resolution_clock::now();

    matchB->sortByScoreMerge();

    auto end_m = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> merge_time = end_m - start_m;

    std::cout << "Tempo gasto no insertion sort: " << insert_time.count() << " ms" << std::endl;
    std::cout << "Tempo gasto no merge sort: " << merge_time.count() << " ms" << std::endl;
    
    return 0;
}
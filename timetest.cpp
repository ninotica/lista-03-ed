#include <chrono>
#include "Matchmaking.hpp"

int pseudorandom (int i) {
    return (373*i + 863)%2000;
}

int main() {
    Matchmaking matchmaking = Matchmaking();

    Player Trajano(1, "Trajano", 1000, 2);
    Player Nina(2, "Nina", 1100, 3);
    Player Boldrini(3, "Boldrini", 900, 1);
    Player Yuri(4, "Yuri", 1150, 4);
    Player Larissa(5, "Larissa", 1000, 6);
    Player Lisa(6, "Lisa", 1150, 5);

    matchmaking.insert(Boldrini);
    matchmaking.insert(Trajano);
    matchmaking.insert(Nina);
    
    matchmaking.printWaitingPlayers();
    
    matchmaking.sortByScoreInsertion();

    matchmaking.printWaitingPlayers();

    matchmaking.insert(Yuri);
    matchmaking.insert(Larissa);
    matchmaking.insert(Lisa);

    matchmaking.printWaitingPlayers();

    matchmaking.sortByScoreMerge();

    matchmaking.printWaitingPlayers();

    int n;
    matchmaking.formGroup(3, 200, &n);

    matchmaking.printWaitingPlayers();

    matchmaking.removePlayer(4);

    matchmaking.printWaitingPlayers();

    matchmaking.formGroup(3, 100, &n);


    // std::cout << "===============================================" << std::endl;
    // std::cout << "||             TESTES DE TEMPO               ||" << std::endl;
    // std::cout << "===============================================" << std::endl;

    // Matchmaking matchA;
    // Matchmaking matchB;



    // for (int i = 1; i <=300; i++){
    //     int score = pseudorandom(i);
    //     matchA.insert(Player(i, "irineu", score, i));
    //     matchB.insert(Player(i, "irineu", score, i));
    // };

    // auto start_i = std::chrono::high_resolution_clock::now();

    // matchA.sortByScoreInsertion();

    // auto end_i = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double, std::milli> insert_time = end_i - start_i;

    // auto start_m = std::chrono::high_resolution_clock::now();

    // matchB.sortByScoreMerge();

    // auto end_m = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double, std::milli> merge_time = end_m - start_m;

    // std::cout << "Tempo gasto no insertion sort: " << insert_time.count() << " ms" << std::endl;
    // std::cout << "Tempo gasto no merge sort: " << merge_time.count() << " ms" << std::endl;
    
    return 0;
}

// Criar um main.cpp contendo casos de teste que demonstrem:

// inserção de jogadores;
// remoção de jogadores;
// ordenação utilizando insertion sort;
// ordenação utilizando merge sort;
// ordenação com empate de score;
// formação bem-sucedida de grupo;
// tentativa de formação de grupo sem sucesso;
// recuperação dos dados por meio do método getWaitingPlayers;
// exibição do estado do sistema.

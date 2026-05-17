#include <iostream>
#include <chrono>
#include "Matchmaking.hpp"

int main() {
    Matchmaking matchA;
    Matchmaking matchB;

    int pseudorandom(int i){
        return (373*i + 863)%2000;
    };

    for (i = 1, i <=300, i++){
        int score = pseudorandom(i);
        matchA.insert(Player(i, "irineu", score, i));
        matchB.insert(Player(i, "irineu", score, i));
    }

    auto start_i = std::chrono::high_resolution_clock::now();

    matchA.sortByScoreInsertion()

    auto end_i = std::chrono::high_resolution_clock::now();

    auto start_m = std::chrono::high_resolution_clock::now();

    matchA.sortByScoreMerge()

    auto end_m = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> insert_time = end_i - start_i;
    std::chrono::duration<double, std::milli> merge_time = end_m - start_m;

    std::cout << "Tempo gasto no insertion sort: " << insert_time.count() << " ms" << std::endl;
    std::cout << "Tempo gasto no merge sort: " << merge_time.count() << " ms" << std::endl;
    
    return 0;
}
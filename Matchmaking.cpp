#include "Matchmaking.hpp"

Matchmaking::Matchmaking() {
    size = 0;
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
            for (int i = current; i < size; i++){
                players[i] = players[i+1];
            }
            size--;
            return true;
        }
    }
    return false;
}

void Matchmaking::sortByScoreInsertion() {
    for (int i = 1; i < size; i++){
        Player current = players[i];
        int j = i -1;
        while(j >=0 && players[j].getScore() < current.getScore()){
            players[j + 1] = players[j];
            j--;
        }
        j++;
        players[j] = current;
    }
}
void Matchmaking::sortByScoreMerge() {
    mergeSort(players, 0, size-1);
}


Player* Matchmaking::formGroup(int groupSize, int delta, int* n) {
    int m;
    Player* waiting = getWaitingPlayers(&m);
    if (m <= groupSize) {
        delete[] waiting;
        std::cout << "Group:" << std::endl;
        std::cout << "(empty)" << std::endl;
        *n = 0;
        return nullptr;
    }

    for (int i = 0; i <= m - groupSize; i++) {
        if (waiting[i + groupSize - 1].getScore() - waiting[i].getScore() > delta) continue;
        else {
            Player* group = new Player[groupSize];
            std::cout << "Group:" << std::endl;
            for (int j = 0; j < groupSize; j++) {
                group[j] = waiting[i + j];
                removePlayer(waiting[i + j].getId());
                std::cout << "[" << group[j].getId() << " | " << group[j].getName() << " | " << group[j].getScore() << " | " << group[j].getTimestamp() << "]" << std::endl;
            }

            delete[] waiting;
            *n = groupSize;
            return group;
        }
    }

    delete[] waiting;
    std::cout << "Group:" << std::endl;
    std::cout << "(empty)" << std::endl;
    *n = 0;
    return nullptr;
}

Player* Matchmaking::getWaitingPlayers(int* n) {
    *n = size;
    Player* waiting = new Player[*n];
    for (int i = 0; i < *n; i++) {
        waiting[i] = players[i];
    }
    return waiting;
}

void Matchmaking::printWaitingPlayers() {
    int n;
    Player* waiting = getWaitingPlayers(&n);
    
    std::cout << "Waiting Players:" << std::endl;
    if (n == 0){
        std::cout << "(empty)" << std::endl;
    }
    for (int i = 0; i<n; i++){

        std::cout << "[" << waiting[i].getId() << " | " << waiting[i].getName() << " | " << waiting[i].getScore() << " | " << waiting[i].getTimestamp() << "]" << std::endl;
    }

    delete[] waiting;
    return;
}

// Player* merge(Player arr1[], int n, Player arr2[], int m){
//     Player* arr_new = new Player[m+n];
//     int idx1 = 0;
//     int idx2 = 0;
//     for (int i = 0; i < m+n; i++){
//         if (idx1 >= n){
//             arr_new[i] = arr2[idx2];
//             idx2++;
//         } else if (idx2 >= m){
//             arr_new[i] = arr1[idx1];
//             idx1++;
//         } else {
//             if (arr1[idx1].getScore() <= arr2[idx2].getScore()){
//                 arr_new[i] = arr1[idx1];
//                 idx1++;
//             } else {
//                 arr_new[i] = arr2[idx2];
//                 idx2++;
//             }
//         }
//     }
//     return arr_new;
// }


// Player* mergeSort(Player arr[], int n) {
//     if (n == 1){
//         Player unit[1];
//         unit[0] = arr[0];
//         return unit;
//     }

//     int mid = n/2;

//     Player* left = mergeSort(arr, mid);
//     Player* right = mergeSort(arr + mid, n-mid);

//     Player* sorted = merge(left, mid, right, n-mid);

//     delete[] left;
//     delete[] right;

//     return sorted;
// }

void merge(Player arr[], int left, int mid, int right){
    Player* arr_new = new Player[right-left+1];
    for (int i = left; i <= right; i++){
        arr_new[i-left] = arr[i];
    }
    int idx1 = left;
    int idx2 = mid + 1;
    for (int i = left; i <= right; i++){
        if (idx1 > mid){
            arr[i] = arr_new[idx2 - left];
            idx2++;
        } else if (idx2 > right){
            arr[i] = arr_new[idx1 - left];
            idx1++;
        } else {
            if (arr_new[idx1 - left].getScore() <= arr_new[idx2 - left].getScore()){
                arr[i] = arr_new[idx1 - left];
                idx1++;
            } else {
                arr[i] = arr_new[idx2 - left];
                idx2++;
            }
        }
    }
    delete[] arr_new;
    return;
}


void mergeSort(Player arr[], int left, int right) {
    if (left>=right){
        return;
    }

    int mid = (left+right)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);

    return;
}
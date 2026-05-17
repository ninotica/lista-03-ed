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

}

Player* Matchmaking::getWaitingPlayers(int* n) {

}

void Matchmaking::printWaitingPlayers() {

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
// Outros métodos auxiliares, se necessário

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
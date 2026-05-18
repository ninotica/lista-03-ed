#include "Matchmaking.hpp"

Matchmaking::Matchmaking() {
    size = 0;
}
Matchmaking::~Matchmaking() {
}

bool Matchmaking::insert(Player player) {
    // Insere no final do array e incrementa size.
    // Retorna false se a fila já estiver cheia.
    if (size < MAX_PLAYERS){
        players[size] = player;
        size++;
        return true;
    }
    return false;
}
bool Matchmaking::removePlayer(int id) {
    // Busca linear pelo ID. Ao encontrar, desloca todos os elementos
    // seguintes uma posição à esquerda para preencher o espaço,
    // mantendo a ordem atual do array.
    int current = 0;
    while (current < size) {
        if (players[current].getId() == id){
            for (int i = current; i < size - 1; i++){
                players[i] = players[i + 1];
            }
            size--;
            return true;
        }
        current++;
    }
    return false;
}

void Matchmaking::sortByScoreInsertion() {
    // Para cada elemento a partir do índice 1, desloca para a direita
    // todos os anteriores com score maior, inserindo o atual na posição correta.
    // Por só deslocar elementos maiores, a ordem relativa entre scores iguais
    // é preservada — o algoritmo é estável, garantindo desempate por timestamp.

    for (int i = 1; i < size; i++) {
        Player current = players[i];
        int j = i -1;
        while (j >= 0 && players[j].getScore() > current.getScore()) {
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
    // Sem jogadores suficientes para formar um grupo.
    if (m < groupSize) {
        delete[] waiting;
        std::cout << "Group:" << std::endl;
        std::cout << "(empty)" << std::endl;
        *n = 0;
        return nullptr;
    }

    // Com o array ordenado por score, a diferença máxima de qualquer janela
    // de groupSize posições consecutivas é sempre waiting[i+groupSize-1] - waiting[i].
    // Basta uma varredura linear para encontrar a primeira janela válida.
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

    // Nenhuma janela válida encontrada; fila permanece inalterada.
    delete[] waiting;
    std::cout << "Group:" << std::endl;
    std::cout << "(empty)" << std::endl;
    *n = 0;
    return nullptr;
}

Player* Matchmaking::getWaitingPlayers(int* n) {
    // Retorna cópia dinâmica do array interno. Chamador é responsável por delete[].
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
    for (int i = 0; i < n; i++) {

        std::cout << "[" << waiting[i].getId() << " | " << waiting[i].getName() << " | " << waiting[i].getScore() << " | " << waiting[i].getTimestamp() << "]" << std::endl;
    }

    delete[] waiting;
    return;
}

void merge(Player arr[], int left, int mid, int right){
    // Copia o intervalo arr[left..right] para um buffer auxiliar,
    // depois intercala as duas metades de volta ao array original em ordem crescente.
    Player* arr_new = new Player[right - left + 1];
    for (int i = left; i <= right; i++){
        arr_new[i - left] = arr[i];
    }
    int idx1 = left;
    int idx2 = mid + 1;
    for (int i = left; i <= right; i++){
        if (idx1 > mid) {                       // Metade esquerda esgotada.
            arr[i] = arr_new[idx2 - left];
            idx2++;
        } else if (idx2 > right) {              // Metade direita esgotada.
            arr[i] = arr_new[idx1 - left];
            idx1++;
        } else if (arr_new[idx1 - left].getScore() < arr_new[idx2 - left].getScore() ||
            (arr_new[idx1 - left].getScore() == arr_new[idx2 - left].getScore() &&
            arr_new[idx1 - left].getTimestamp() <= arr_new[idx2 - left].getTimestamp())) {
            arr[i] = arr_new[idx1 - left];      // Elemento da esquerda é menor ou igual.
            idx1++;
        } else {
                arr[i] = arr_new[idx2 - left];  // Elemento da direita é menor.
                idx2++;
        }
    }
    delete[] arr_new;
    return;
}

void mergeSort(Player arr[], int left, int right) {
    // Caso base: subarray de 0 ou 1 elemento já está ordenado.
    if (left >= right){
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);                  // Ordena metade esquerda.
    mergeSort(arr, mid + 1, right);             // Ordena metade direita.
    merge(arr, left, mid, right);               // Combina as duas metades.

    return;
}
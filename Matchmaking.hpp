#include "Player.hpp"
#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

const int MAX_PLAYERS = 100000;

class Matchmaking {

private:

    Player players[MAX_PLAYERS];
    int size;

public:

    /**
     * @brief Inicializa o sistema de matchmaking com a fila vazia.
     */
    Matchmaking();
    /**
     * @brief Destrói o sistema de matchmaking.
     */
    ~Matchmaking();

    /**
     * @brief Insere um jogador no final da fila de espera.
     * 
     * @param player Jogador a ser inserido.
     * @return true se a inserção foi bem-sucedida; false se a fila estiver cheia.
     */
    bool insert(Player player);
    /**
     * @brief Remove o jogador com o ID informado da fila de espera.
     * 
     * @param id Identificador do jogador a ser removido.
     * @return true se o jogador foi encontrado e removido; false caso contrário.
     */
    bool removePlayer(int id);

    /**
     * @brief Ordena os jogadores por score crescente usando insertion sort.
     *        Em caso de empate no score, jogadores com menor timestamp vêm primeiro.
     */
    void sortByScoreInsertion();
    /**
     * @brief Ordena os jogadores por score crescente usando merge sort recursivo.
     *        Em caso de empate no score, jogadores com menor timestamp vêm primeiro.
     */
    void sortByScoreMerge();

    /**
     * @brief Tenta formar um grupo de jogadores com scores próximos.
     *        Assume que os jogadores já estão ordenados por score.
     * 
     * @param groupSize Número de jogadores no grupo.
     * @param delta     Diferença máxima permitida entre o maior e o menor score do grupo.
     * @param n         Recebe groupSize se um grupo foi formado, ou 0 caso contrário.
     * @return Ponteiro para array alocado dinamicamente com os jogadores do grupo,
     *         ou nullptr se nenhum grupo válido foi encontrado.
     *         O chamador é responsável por liberar a memória com delete[].
     */
    Player* formGroup(int groupSize, int delta, int* n);

    /**
     * @brief Retorna cópias dos jogadores atualmente na fila de espera.
     * 
     * @param n Recebe a quantidade de jogadores retornados.
     * @return Ponteiro para array alocado dinamicamente com os jogadores,
     *         ou nullptr se a fila estiver vazia.
     *         O chamador é responsável por liberar a memória com delete[].
     */
    Player* getWaitingPlayers(int* n);

    /**
     * @brief Exibe o estado atual da fila de espera no formato padronizado.
     */
    void printWaitingPlayers();

};

void mergeSort(Player arr[], int left, int right);
void merge(Player arr[], int left, int mid, int right);

#endif
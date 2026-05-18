#include <iostream>
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {

private:
    int id;
    std::string name;
    int score;
    int timestamp;

public:

    /**
     * @brief Inicializa um player com valores padrão.
     */
    Player();
    /**
     * @brief Inicializa um player com os dados fornecidos.
     * 
     * @param id        Identificador único do jogador.
     * @param name      Nome do jogador.
     * @param score     Nível de habilidade do jogador.
     * @param timestamp Ordem de chegada na fila de espera.
     */
    Player(int id, std::string name, int score, int timestamp);
    /**
     * @brief Destrói o player e libera os recursos associados.
     */
    ~Player();

    /**
     * @brief Retorna o identificador do jogador.
     * 
     * @return Inteiro único que identifica o jogador no sistema.
     */
    int getId();
    /**
     * @brief Retorna o nome do jogador.
     * 
     * @return String com o nome do jogador.
     */
    std::string getName();
    /**
     * @brief Retorna o score do jogador.
     * 
     * @return Inteiro representando a pontuação do jogador.
     */
    int getScore();
    /**
     * @brief Retorna o timestamp do jogador.
     * 
     * @return Inteiro representando a ordem de chegada na fila de espera.
     */
    int getTimestamp();
};

#endif
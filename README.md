# Sistema de Matchmaking para Jogos Online

Sistema de matchmaking implementado em C++ que gerencia uma fila de espera de jogadores e forma grupos com níveis de habilidade semelhantes, utilizando algoritmos de ordenação implementados manualmente.

---

## Descrição do projeto

O sistema armazena jogadores em uma fila de espera e, a partir de dois algoritmos de ordenação (insertion sort e merge sort), organiza os jogadores por score para facilitar a formação de grupos equilibrados.

Cada jogador possui:

- **id**: identificador único;
- **name**: nome do jogador;
- **score**: nível de habilidade;
- **timestamp**: ordem de chegada na fila.

A ordenação segue dois critérios: primeiro por score crescente e, em caso de empate, por timestamp crescente (quem chegou antes fica à frente). Com os jogadores ordenados, o método `formGroup` percorre o array em busca do primeiro grupo de `groupSize` jogadores consecutivos cuja diferença entre maior e menor score seja menor ou igual a `delta`.

---

## Organização dos arquivos

```
matchmaking/
├── main.cpp          # Casos de teste para todas as funcionalidades
├── Matchmaking.hpp   # Declaração da classe Matchmaking
├── Matchmaking.cpp   # Implementação da classe Matchmaking (insert, remove, sort, formGroup, etc.)
├── Player.hpp        # Declaração da classe Player
├── Player.cpp        # Implementação da classe Player
└── README.md         # Este arquivo
```

- **`Player.hpp` / `Player.cpp`**: define a estrutura de um jogador e seus métodos de acesso (`getId`, `getName`, `getScore`, `getTimestamp`).
- **`Matchmaking.hpp` / `Matchmaking.cpp`**: contém a lógica central do sistema — armazenamento em array estático de tamanho `MAX_PLAYERS` (1000), inserção, remoção, dois algoritmos de ordenação e formação de grupos. As funções auxiliares `mergeSort` e `merge` são declaradas no `.hpp` e implementadas no `.cpp`.
- **`main.cpp`**: arquivo principal com todos os casos de teste.

---

## Compilação

Todos os arquivos devem estar no mesmo diretório. Para compilar, execute:

```bash
g++ main.cpp Matchmaking.cpp Player.cpp -o matchmaking
```

Não são necessárias flags adicionais. O compilador padrão do ambiente (g++) é suficiente.

---

## Execução

Após compilar, execute o programa com:

```bash
./matchmaking
```

No Windows:

```bash
matchmaking.exe
```

---

## Testes implementados no `main.cpp`

O `main.cpp` cobre os seguintes cenários, executados em sequência ao rodar o programa:

1. **Inserção de jogadores** — insere Boldrini, Trajano e Nina e exibe a fila antes e depois da ordenação por insertion sort.

2. **Ordenação com insertion sort** — ordena os três jogadores por score e exibe o resultado.

3. **Novas inserções** — insere mais três jogadores (Yuri, Larissa, Lisa) na fila já parcialmente ordenada, demonstrando que a inserção é sempre feita ao final do array.

4. **Ordenação com merge sort** — ordena todos os seis jogadores e exibe o resultado.

5. **Formação bem-sucedida de grupo** — chama `formGroup(3, 200, &n)`, encontrando o primeiro grupo de 3 jogadores com diferença de score ≤ 200, exibe o grupo formado e mostra a fila restante.

6. **Remoção de jogador** — remove o jogador de id 4 (Yuri) e exibe a fila atualizada.

7. **Tentativa de formação de grupo sem sucesso** — chama `formGroup(3, 100, &n)` com um delta mais restrito, esperando que nenhum grupo seja encontrado (saída `(empty)`).

8. **Testes de desempenho** — insere 300 jogadores com scores pseudoaleatórios em dois objetos `Matchmaking` separados e mede o tempo de execução do insertion sort e do merge sort usando `<chrono>`, exibindo os resultados em milissegundos.

A saída completa do programa permite verificar cada etapa visualmente, com o estado da fila exibido antes e depois de cada operação.

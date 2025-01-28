#ifndef LIG4_HPP
#define LIG4_HPP

#include "jogos_tabuleiro.hpp"

/**
 * @class Lig4
 * @brief Classe que implementa o jogo Lig4 (Conecta 4).
 *
 * A classe representa a lógica e o estado do jogo Lig4, herda da classe abstrata `JogoDeTabuleiro`.
 * O objetivo do jogo é conectar quatro peças consecutivas em linha, coluna ou diagonal.
 */
class Lig4 : public JogoDeTabuleiro
{
public:
    /**
     * @brief Construtor da classe Lig4.
     *
     * Inicializa o tabuleiro com 6 linhas e 7 colunas, preenchido com espaços em branco,
     * e define o jogador inicial como 'X'.
     */
    Lig4();

    /**
     * @brief Inicializa o tabuleiro do jogo.
     *
     * Configura o tabuleiro com células vazias antes do início da partida.
     */
    void iniciarJogo() override;

    /**
     * @brief Realiza uma jogada no tabuleiro.
     *
     * Coloca a peça do jogador atual na coluna especificada, na linha disponível mais baixa.
     * Alterna para o próximo jogador ao final de uma jogada válida.
     *
     * @param linha Índice da linha (não utilizado diretamente neste jogo).
     * @param coluna Índice da coluna onde a peça será colocada.
     * @return true Se a jogada foi realizada com sucesso.
     * @return false Se a jogada foi inválida (coluna cheia ou índice fora do intervalo).
     */
    bool realizarJogada(int linha, int coluna) override;

    /**
     * @brief Verifica se houve vitória no jogo.
     *
     * Examina todas as posições do tabuleiro em busca de quatro peças consecutivas do mesmo jogador
     * em linha, coluna ou diagonal.
     *
     * @return true Se um jogador conseguiu conectar quatro peças consecutivas.
     * @return false Caso contrário.
     */
    bool verificarVitoria() const override;

    /**
     * @brief Imprime o tabuleiro no console.
     *
     * Exibe o estado atual do tabuleiro, substituindo células vazias por pontos para maior clareza.
     */
    void imprimirTabuleiro() const override;

    /**
     * @brief Verifica se uma jogada é válida.
     *
     * Uma jogada é válida se a coluna especificada está dentro do intervalo permitido
     * e se ainda há espaço disponível na coluna.
     *
     * @param linha Índice da linha (não utilizado diretamente neste jogo).
     * @param coluna Índice da coluna a ser verificada.
     * @return true Se a jogada é válida.
     * @return false Caso contrário.
     */
    bool jogadaValida(int linha, int coluna) const override;

    /**
     * @brief Verifica se o tabuleiro está cheio.
     *
     * O tabuleiro é considerado cheio se a linha superior (primeira linha) estiver completamente ocupada.
     *
     * @return true Se o tabuleiro está cheio.
     * @return false Caso contrário.
     */
    bool tabuleiroCheio() const override;

private:
    /**
     * @brief Representa o jogador atual ('X' ou 'O').
     */
    char jogadorAtual;

    /**
     * @brief Alterna o jogador atual.
     *
     * Alterna entre os jogadores 'X' e 'O' após uma jogada válida.
     */
    void alternarJogador();

    /**
     * @brief Verifica uma sequência de peças consecutivas no tabuleiro.
     *
     * A sequência é verificada a partir de uma posição inicial `(linha, coluna)` seguindo uma direção
     * específica determinada por `(deltaLinha, deltaColuna)`.
     *
     * @param linha Linha inicial da verificação.
     * @param coluna Coluna inicial da verificação.
     * @param deltaLinha Variação na linha a cada passo.
     * @param deltaColuna Variação na coluna a cada passo.
     * @return true Se uma sequência de quatro peças consecutivas foi encontrada.
     * @return false Caso contrário.
     */
    bool verificarSequencia(int linha, int coluna, int deltaLinha, int deltaColuna) const;
};

#endif

#ifndef JOGO_DA_VELHA_HPP
#define JOGO_DA_VELHA_HPP

#include "jogos_tabuleiro.hpp"

/**
 * @class JogoDaVelha
 * @brief Classe que implementa o jogo da velha como um jogo de tabuleiro.
 *
 * A classe gerencia as regras, o estado do tabuleiro e o fluxo do jogo.
 * É derivada da classe base JogoDeTabuleiro.
 */
class JogoDaVelha : public JogoDeTabuleiro
{
public:
    /**
     * @brief Construtor da classe JogoDaVelha.
     *
     * Inicializa o tabuleiro com dimensões de 3x3 e define o jogador inicial como 'X'.
     */
    JogoDaVelha();

    /**
     * @brief Inicia o jogo, limpando o tabuleiro.
     *
     * Preenche todas as posições do tabuleiro com o caractere de espaço (' ').
     */
    void iniciarJogo() override;

    /**
     * @brief Realiza uma jogada no tabuleiro.
     *
     * Marca a posição especificada no tabuleiro com o símbolo do jogador atual,
     * se a jogada for válida, e alterna o jogador.
     *
     * @param linha Índice da linha onde a jogada será realizada (0 a 2).
     * @param coluna Índice da coluna onde a jogada será realizada (0 a 2).
     * @return true Se a jogada foi realizada com sucesso.
     * @return false Se a jogada for inválida.
     */
    bool realizarJogada(int linha, int coluna) override;

    /**
     * @brief Verifica se algum jogador venceu o jogo.
     *
     * Verifica linhas, colunas e diagonais em busca de três símbolos iguais consecutivos.
     *
     * @return true Se um jogador venceu o jogo.
     * @return false Caso contrário.
     */
    bool verificarVitoria() const override;

    /**
     * @brief Imprime o estado atual do tabuleiro no console.
     *
     * Exibe o tabuleiro, substituindo células vazias (' ') por pontos ('.') para maior clareza.
     */
    void imprimirTabuleiro() const override;

    /**
     * @brief Verifica se uma jogada é válida.
     *
     * Uma jogada é válida se os índices de linha e coluna estão dentro dos limites
     * do tabuleiro e a célula correspondente está vazia.
     *
     * @param linha Índice da linha da jogada.
     * @param coluna Índice da coluna da jogada.
     * @return true Se a jogada é válida.
     * @return false Caso contrário.
     */
    bool jogadaValida(int linha, int coluna) const override;

    /**
     * @brief Verifica se o tabuleiro está cheio.
     *
     * O tabuleiro é considerado cheio se todas as células estão ocupadas por símbolos de jogadores.
     *
     * @return true Se o tabuleiro está cheio.
     * @return false Caso contrário.
     */
    bool tabuleiroCheio() const override;

private:
    /**
     * @brief Indica o jogador atual.
     *
     * O jogador atual é representado por 'X' ou 'O'.
     */
    char jogadorAtual;

    /**
     * @brief Alterna o jogador atual.
     *
     * Se o jogador atual for 'X', passa para 'O', e vice-versa.
     */
    void alternarJogador();
};

#endif

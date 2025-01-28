#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogos_tabuleiro.hpp"

/**
 * @brief Classe que representa o jogo Reversi (também conhecido como Othello).
 *
 * Esta classe é uma implementação do jogo de tabuleiro Reversi, que é jogado em um
 * tabuleiro 8x8. O objetivo do jogo é capturar as peças do adversário ao cercá-las
 * com suas próprias peças. A classe gerencia as jogadas, verificações de vitória, e
 * captura de peças durante o jogo.
 *
 * @note Esta classe herda de `JogoDeTabuleiro`, que define métodos genéricos para
 * jogos de tabuleiro.
 */
class Reversi : public JogoDeTabuleiro
{
public:
    /**
     * @brief Construtor da classe Reversi.
     *
     * Inicializa um tabuleiro 8x8 e define o jogador atual como 'X'.
     * As peças iniciais são posicionadas nas posições (3, 3), (3, 4), (4, 3) e (4, 4).
     */
    Reversi();

    /**
     * @brief Inicia o jogo configurando as peças iniciais no tabuleiro.
     *
     * Este método coloca as 4 peças iniciais no centro do tabuleiro.
     */
    void iniciarJogo() override;

    /**
     * @brief Realiza uma jogada no tabuleiro.
     *
     * Este método verifica se a jogada é válida e, se for, coloca a peça do jogador
     * na posição especificada e captura as peças do adversário. Após a jogada, o
     * jogador atual é alternado.
     *
     * @param linha A linha onde a jogada será feita.
     * @param coluna A coluna onde a jogada será feita.
     *
     * @return `true` se a jogada for realizada com sucesso, `false` caso contrário.
     */
    bool realizarJogada(int linha, int coluna) override;

    /**
     * @brief Verifica se há um vencedor no jogo.
     *
     * Este método verifica se o tabuleiro está cheio ou se um dos jogadores não tem
     * mais peças no tabuleiro, indicando que o jogo terminou.
     *
     * @return `true` se houver um vencedor, `false` caso contrário.
     */
    bool verificarVitoria() const override;

    /**
     * @brief Imprime o tabuleiro na tela.
     *
     * Este método exibe o estado atual do tabuleiro, substituindo espaços vazios
     * por pontos ('.') para facilitar a visualização.
     */
    void imprimirTabuleiro() const override;

    /**
     * @brief Verifica se uma jogada é válida.
     *
     * Este método verifica se a posição informada é válida para a realização de uma
     * jogada. Para que a jogada seja válida, a célula precisa estar vazia e deve
     * ser possível capturar pelo menos uma peça adversária.
     *
     * @param linha A linha onde a jogada será realizada.
     * @param coluna A coluna onde a jogada será realizada.
     *
     * @return `true` se a jogada for válida, `false` caso contrário.
     */
    bool jogadaValida(int linha, int coluna) const override;

    /**
     * @brief Verifica se o tabuleiro está cheio.
     *
     * Este método verifica se o tabuleiro está completamente preenchido com peças.
     *
     * @return `true` se o tabuleiro estiver cheio, `false` caso contrário.
     */
    bool tabuleiroCheio() const override;

    /**
     * @brief Conta o número de peças de um jogador no tabuleiro.
     *
     * Este método percorre o tabuleiro e conta quantas peças do jogador especificado
     * estão presentes.
     *
     * @param jogador O caractere que representa o jogador ('X' ou 'O').
     *
     * @return O número de peças do jogador no tabuleiro.
     */
    int contarPecas(char jogador) const;

private:
    /**
     * @brief Representa o jogador atual no jogo.
     *
     * O jogador atual é armazenado como um caractere, sendo 'X' para o jogador X e
     * 'O' para o jogador O.
     */
    char jogadorAtual;

    /**
     * @brief Alterna o jogador atual.
     *
     * Este método altera o valor de `jogadorAtual`, trocando entre 'X' e 'O'.
     */
    void alternarJogador();

    /**
     * @brief Realiza a captura de peças após uma jogada.
     *
     * Este método verifica em todas as direções possíveis se há peças adversárias
     * que podem ser capturadas após a jogada. Se capturar alguma peça, ela será
     * substituída pela peça do jogador atual.
     *
     * @param linha A linha onde a jogada foi feita.
     * @param coluna A coluna onde a jogada foi feita.
     *
     * @return `true` se alguma peça foi capturada, `false` caso contrário.
     */
    bool capturaPecas(int linha, int coluna);

    /**
     * @brief Verifica se há peças adversárias em uma direção específica.
     *
     * Este método verifica se, a partir da posição informada, existem peças adversárias
     * em uma direção específica que podem ser capturadas, ou seja, se houver uma sequência
     * de peças do adversário seguidas por uma peça do jogador atual.
     *
     * @param linha A linha onde a jogada foi feita.
     * @param coluna A coluna onde a jogada foi feita.
     * @param deltaLinha A variação de linha para a direção a ser verificada.
     * @param deltaColuna A variação de coluna para a direção a ser verificada.
     *
     * @return `true` se uma captura é possível nessa direção, `false` caso contrário.
     */
    bool capturaDirecao(int linha, int coluna, int deltaLinha, int deltaColuna) const;
};

#endif

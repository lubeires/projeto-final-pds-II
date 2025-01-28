#ifndef JOGOS_TABULEIRO_HPP
#define JOGOS_TABULEIRO_HPP

#include <iostream>
#include <vector>
#include <string>

/**
 * @class JogoDeTabuleiro
 * @brief Classe abstrata que define a interface para jogos de tabuleiro.
 *
 * Esta classe fornece a estrutura base para implementar diferentes jogos de tabuleiro.
 * Contém métodos virtuais puros que devem ser implementados pelas classes derivadas.
 */
class JogoDeTabuleiro
{
public:
    /**
     * @brief Destrutor virtual.
     *
     * Garante que as subclasses possam realizar limpeza de recursos adequadamente.
     */
    virtual ~JogoDeTabuleiro() {}

    /**
     * @brief Inicializa o estado do jogo.
     *
     * Deve ser implementado para configurar o tabuleiro e quaisquer variáveis necessárias
     * antes do início do jogo.
     */
    virtual void iniciarJogo() = 0;

    /**
     * @brief Realiza uma jogada no tabuleiro.
     *
     * O método deve ser implementado para marcar o tabuleiro com base nos índices fornecidos
     * de linha e coluna, se a jogada for válida.
     *
     * @param linha Índice da linha onde a jogada será realizada.
     * @param coluna Índice da coluna onde a jogada será realizada.
     * @return true Se a jogada foi realizada com sucesso.
     * @return false Se a jogada for inválida.
     */
    virtual bool realizarJogada(int linha, int coluna) = 0;

    /**
     * @brief Verifica se houve uma vitória no jogo.
     *
     * Este método deve verificar as condições de vitória específicas para o jogo.
     *
     * @return true Se um jogador venceu o jogo.
     * @return false Caso contrário.
     */
    virtual bool verificarVitoria() const = 0;

    /**
     * @brief Imprime o tabuleiro no console.
     *
     * Deve ser implementado para exibir o estado atual do tabuleiro de maneira visualmente clara.
     */
    virtual void imprimirTabuleiro() const = 0;

    /**
     * @brief Verifica se uma jogada é válida.
     *
     * Este método deve validar se a posição especificada está dentro dos limites do tabuleiro
     * e se a célula correspondente está disponível.
     *
     * @param linha Índice da linha a ser verificada.
     * @param coluna Índice da coluna a ser verificada.
     * @return true Se a jogada é válida.
     * @return false Caso contrário.
     */
    virtual bool jogadaValida(int linha, int coluna) const = 0;

    /**
     * @brief Verifica se o tabuleiro está cheio.
     *
     * Deve ser implementado para determinar se todas as células do tabuleiro estão ocupadas.
     *
     * @return true Se o tabuleiro está completamente preenchido.
     * @return false Caso contrário.
     */
    virtual bool tabuleiroCheio() const = 0;

protected:
    /**
     * @brief Número de linhas do tabuleiro.
     */
    int linhas;

    /**
     * @brief Número de colunas do tabuleiro.
     */
    int colunas;

    /**
     * @brief Representação do tabuleiro como uma matriz 2D de caracteres.
     *
     * Cada célula do tabuleiro é representada por um caractere.
     */
    std::vector<std::vector<char>> tabuleiro;
};

#endif

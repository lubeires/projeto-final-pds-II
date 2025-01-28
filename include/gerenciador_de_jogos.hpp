#ifndef GERENCIADOR_DE_JOGOS_HPP
#define GERENCIADOR_DE_JOGOS_HPP

#include <memory>
#include "jogo_da_velha.hpp"
#include "lig4.hpp"
#include "reversi.hpp"
#include "jogador.hpp"

/**
 * @class GerenciadorDeJogos
 * @brief Classe responsável por gerenciar e executar partidas de jogos de tabuleiro.
 *
 * Suporta os seguintes jogos:
 * - 'R': Reversi.
 * - 'L': Lig4.
 * - 'V': Jogo da Velha.
 */
class GerenciadorDeJogos
{
public:
    /**
     * @brief Executa uma partida de um jogo de tabuleiro especificado.
     *
     * Este método gerencia o fluxo de uma partida entre dois jogadores,
     * alternando turnos, verificando condições de vitória ou empate e
     * registrando os resultados.
     *
     * @param tipoJogo Caractere que identifica o tipo de jogo a ser jogado.
     *                 - 'R': Reversi.
     *                 - 'L': Lig4.
     *                 - 'V': Jogo da Velha.
     * @param jogador1 Referência ao primeiro jogador.
     * @param jogador2 Referência ao segundo jogador.
     *
     * @throws std::invalid_argument Se o tipo de jogo for inválido.
     * @throws std::runtime_error Se ocorrerem erros na entrada do usuário.
     */
    static void executarPartida(char tipoJogo, Jogador &jogador1, Jogador &jogador2);
};

#endif

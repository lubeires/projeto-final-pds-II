#ifndef GERENCIADOR_DE_JOGOS_HPP
#define GERENCIADOR_DE_JOGOS_HPP

#include <memory>
#include "jogo_da_velha.hpp"
#include "lig4.hpp"
#include "reversi.hpp"
#include "jogador.hpp"

class GerenciadorDeJogos
{
public:
    static void executarPartida(char tipoJogo, Jogador &jogador1, Jogador &jogador2);
};

#endif

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogo_da_velha.hpp"

TEST_CASE("Teste da classe JogoDaVelha")
{
    JogoDaVelha jogo;

    SUBCASE("Teste de inicialização do jogo")
    {
        jogo.iniciarJogo();

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                CHECK(jogo.jogadaValida(i, j));
            }
        }
    }

    SUBCASE("Teste de jogada válida")
    {
        jogo.iniciarJogo();
        CHECK(jogo.realizarJogada(0, 0));     // Jogador X
        CHECK_FALSE(jogo.jogadaValida(0, 0)); // Já ocupada
    }

    SUBCASE("Teste de jogada inválida")
    {
        jogo.iniciarJogo();
        CHECK_FALSE(jogo.realizarJogada(3, 3));  // Fora dos limites
        CHECK_FALSE(jogo.realizarJogada(-1, 0)); // Fora dos limites
    }

    SUBCASE("Teste de alternância de jogadores")
    {
        jogo.iniciarJogo();
        CHECK(jogo.realizarJogada(0, 0)); // X joga
        CHECK(jogo.realizarJogada(1, 1)); // O joga
        CHECK(jogo.realizarJogada(0, 1)); // X joga
    }

    SUBCASE("Teste de vitória por linha")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(0, 0); // X
        jogo.realizarJogada(1, 0); // O
        jogo.realizarJogada(0, 1); // X
        jogo.realizarJogada(1, 1); // O
        jogo.realizarJogada(0, 2); // X - Vitória
        CHECK(jogo.verificarVitoria());
    }

    SUBCASE("Teste de vitória por coluna")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(0, 0); // X
        jogo.realizarJogada(0, 1); // O
        jogo.realizarJogada(1, 0); // X
        jogo.realizarJogada(1, 1); // O
        jogo.realizarJogada(2, 0); // X - Vitória
        CHECK(jogo.verificarVitoria());
    }

    SUBCASE("Teste de vitória na diagonal principal")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(0, 0); // X
        jogo.realizarJogada(0, 1); // O
        jogo.realizarJogada(1, 1); // X
        jogo.realizarJogada(0, 2); // O
        jogo.realizarJogada(2, 2); // X - Vitória
        CHECK(jogo.verificarVitoria());
    }

    SUBCASE("Teste de vitória na diagonal secundária")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(0, 2); // X
        jogo.realizarJogada(0, 1); // O
        jogo.realizarJogada(1, 1); // X
        jogo.realizarJogada(1, 0); // O
        jogo.realizarJogada(2, 0); // X - Vitória
        CHECK(jogo.verificarVitoria());
    }

    SUBCASE("Teste de empate")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(0, 0); // X
        jogo.realizarJogada(0, 1); // O
        jogo.realizarJogada(0, 2); // X
        jogo.realizarJogada(1, 1); // O
        jogo.realizarJogada(1, 0); // X
        jogo.realizarJogada(1, 2); // O
        jogo.realizarJogada(2, 1); // X
        jogo.realizarJogada(2, 0); // O
        jogo.realizarJogada(2, 2); // X
        CHECK(jogo.tabuleiroCheio());
        CHECK_FALSE(jogo.verificarVitoria());
    }

    SUBCASE("Teste de tabuleiro cheio sem empate")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(0, 0); // X
        jogo.realizarJogada(0, 1); // O
        jogo.realizarJogada(0, 2); // X
        jogo.realizarJogada(1, 0); // O
        jogo.realizarJogada(1, 1); // X
        jogo.realizarJogada(1, 2); // O
        jogo.realizarJogada(2, 0); // X
        jogo.realizarJogada(2, 1); // O
        CHECK_FALSE(jogo.tabuleiroCheio());
    }
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lig4.hpp"

TEST_CASE("Teste da classe Lig4")
{
    Lig4 jogo;

    SUBCASE("Teste de inicialização do jogo")
    {
        jogo.iniciarJogo();

        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                CHECK(jogo.jogadaValida(0, j));
            }
        }
    }

    SUBCASE("Teste de jogada válida")
    {
        jogo.iniciarJogo();
        CHECK(jogo.realizarJogada(0, 0));     // Jogador X realiza jogada
        CHECK_FALSE(jogo.jogadaValida(0, 0)); // Verifica que a célula mais baixa na coluna está ocupada
    }

    SUBCASE("Teste de jogada inválida")
    {
        jogo.iniciarJogo();
        CHECK_FALSE(jogo.realizarJogada(0, -1)); // Fora dos limites
        CHECK_FALSE(jogo.realizarJogada(0, 7));  // Fora dos limites
    }

    SUBCASE("Teste de alternância de jogadores")
    {
        jogo.iniciarJogo();
        CHECK(jogo.realizarJogada(0, 0)); // Jogador X
        CHECK(jogo.realizarJogada(0, 1)); // Jogador O
        CHECK(jogo.realizarJogada(0, 2)); // Jogador X
    }

    SUBCASE("Teste de vitória horizontal")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(5, 0); // X
        jogo.realizarJogada(5, 4); // O
        jogo.realizarJogada(5, 1); // X
        jogo.realizarJogada(5, 5); // O
        jogo.realizarJogada(5, 2); // X
        jogo.realizarJogada(5, 6); // O
        jogo.realizarJogada(5, 3); // X - Vitória
        CHECK(jogo.verificarVitoria());
    }

    SUBCASE("Teste de vitória vertical")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(5, 0); // X
        jogo.realizarJogada(5, 1); // O
        jogo.realizarJogada(4, 0); // X
        jogo.realizarJogada(5, 2); // O
        jogo.realizarJogada(3, 0); // X
        jogo.realizarJogada(5, 3); // O
        jogo.realizarJogada(2, 0); // X - Vitória
        CHECK(jogo.verificarVitoria());
    }

    SUBCASE("Teste de vitória diagonal (principal)")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(5, 0); // X
        jogo.realizarJogada(5, 1); // O
        jogo.realizarJogada(4, 1); // X
        jogo.realizarJogada(5, 2); // O
        jogo.realizarJogada(3, 2); // X
        jogo.realizarJogada(5, 3); // O
        jogo.realizarJogada(2, 2); // X
        jogo.realizarJogada(4, 3); // O
        jogo.realizarJogada(3, 3); // X
        jogo.realizarJogada(2, 3); // O
        jogo.realizarJogada(1, 3); // X - Vitória
        CHECK(jogo.verificarVitoria());
    }

    SUBCASE("Teste de vitória diagonal (secundária)")
    {
        jogo.iniciarJogo();
        jogo.realizarJogada(5, 3); // X
        jogo.realizarJogada(5, 2); // O
        jogo.realizarJogada(4, 2); // X
        jogo.realizarJogada(5, 1); // O
        jogo.realizarJogada(3, 1); // X
        jogo.realizarJogada(5, 0); // O
        jogo.realizarJogada(2, 1); // X
        jogo.realizarJogada(4, 0); // O
        jogo.realizarJogada(3, 0); // X
        jogo.realizarJogada(2, 0); // O
        jogo.realizarJogada(1, 0); // X - Vitória
        CHECK(jogo.verificarVitoria());
    }

    SUBCASE("Teste de empate")
    {
        jogo.iniciarJogo();
        for (int i = 5; i >= 0; --i)
        {
            for (int j = 0; j < 7; ++j)
            {
                jogo.realizarJogada(i, j);
            }
        }
        CHECK(jogo.tabuleiroCheio());
        CHECK_FALSE(jogo.verificarVitoria());
    }
}

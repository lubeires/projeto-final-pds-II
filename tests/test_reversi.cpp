#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/reversi.hpp"

TEST_CASE("Teste do construtor de Reversi")
{
    Reversi jogo;
    CHECK(jogo.contarPecas('X') == 0);
    CHECK(jogo.contarPecas('O') == 0);
}

TEST_CASE("Teste de iniciar jogo")
{
    Reversi jogo;
    jogo.iniciarJogo();
    CHECK(jogo.contarPecas('X') == 2);
    CHECK(jogo.contarPecas('O') == 2);
}

TEST_CASE("Teste de realizar jogada válida")
{
    Reversi jogo;
    jogo.iniciarJogo();
    CHECK(jogo.realizarJogada(2, 3) == true);
    CHECK(jogo.contarPecas('X') > 2);
}

TEST_CASE("Teste de realizar jogada inválida")
{
    Reversi jogo;
    jogo.iniciarJogo();
    CHECK(jogo.realizarJogada(3, 3) == false);  // Jogada em posição já ocupada
    CHECK(jogo.realizarJogada(-1, 0) == false); // Fora do tabuleiro
}

TEST_CASE("Teste de alternar jogador")
{
    Reversi jogo;
    jogo.iniciarJogo();
    jogo.realizarJogada(2, 3);
    CHECK(jogo.realizarJogada(2, 2) == true);
}

TEST_CASE("Teste de verificação de vitória")
{
    Reversi jogo;
    jogo.iniciarJogo();
    CHECK(jogo.verificarVitoria() == false);

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (jogo.jogadaValida(i, j))
            {
                jogo.realizarJogada(i, j);
            }
        }
    }
    CHECK(jogo.tabuleiroCheio() == true);
}

TEST_CASE("Teste de contagem de peças")
{
    Reversi jogo;
    jogo.iniciarJogo();
    CHECK(jogo.contarPecas('X') == 2);
    CHECK(jogo.contarPecas('O') == 2);
}

TEST_CASE("Teste de captura de peças")
{
    Reversi jogo;
    jogo.iniciarJogo();
    jogo.realizarJogada(2, 3);
    CHECK(jogo.contarPecas('X') > 2);
    CHECK(jogo.contarPecas('O') < 2);
}

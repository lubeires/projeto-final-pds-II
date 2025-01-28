#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "reversi.hpp"

TEST_CASE("Teste inicializacao do jogo")
{
    Reversi jogo;
    jogo.iniciarJogo();

    CHECK(jogo.tabuleiroCheio() == false);

    CHECK(jogo.jogadaValida(3, 3) == false);
    CHECK(jogo.jogadaValida(3, 4) == false);
    CHECK(jogo.jogadaValida(4, 3) == false);
    CHECK(jogo.jogadaValida(4, 4) == false);
}

TEST_CASE("Teste de jogadas válidas e inválidas")
{
    Reversi jogo;
    jogo.iniciarJogo();

    CHECK(jogo.jogadaValida(-1, 0) == false);
    CHECK(jogo.jogadaValida(0, -1) == false);
    CHECK(jogo.jogadaValida(8, 8) == false);
    CHECK(jogo.jogadaValida(3, 3) == false);

    CHECK(jogo.jogadaValida(2, 3) == true);
    CHECK(jogo.jogadaValida(5, 4) == true);
}

TEST_CASE("Teste de realizar jogadas")
{
    Reversi jogo;

    CHECK(jogo.realizarJogada(2, 3) == true);
    CHECK(jogo.realizarJogada(5, 4) == true);

    CHECK(jogo.realizarJogada(2, 2) == true); // Próximo jogador joga

    CHECK(jogo.realizarJogada(3, 3) == false);
}

TEST_CASE("Teste de alternância de jogadores")
{
    Reversi jogo;
    jogo.iniciarJogo();

    CHECK(jogo.realizarJogada(2, 3) == true); // Jogador 'X'
    CHECK(jogo.realizarJogada(5, 4) == true); // Jogador 'O'
    CHECK(jogo.realizarJogada(2, 4) == true); // Jogador 'X'
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
            jogo.realizarJogada(i, j);
        }
    }

    CHECK(jogo.tabuleiroCheio() == true);
    CHECK(jogo.verificarVitoria() == true);
}

TEST_CASE("Teste de contagem de peças")
{
    Reversi jogo;
    jogo.iniciarJogo();

    CHECK(jogo.contarPecas('X') == 2);
    CHECK(jogo.contarPecas('O') == 2);

    jogo.realizarJogada(2, 3); // Jogador 'X'
    CHECK(jogo.contarPecas('X') > 2);
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "gerenciador_de_jogos.hpp"
#include "reversi.hpp"
#include "lig4.hpp"
#include "jogo_da_velha.hpp"
#include "jogador.hpp"

class MockJogo : public JogoDeTabuleiro
{
public:
    bool tabuleiroCheio() const override { return false; }
    bool verificarVitoria() const override { return false; }
    bool realizarJogada(int, int) override { return true; }
    void imprimirTabuleiro() const override {}
    void iniciarJogo() override {}
};

TEST_CASE("Teste GerenciadorDeJogos - Inicialização e execução")
{
    GerenciadorDeJogos gerenciador;
    Jogador jogador1("Alice");
    Jogador jogador2("Bob");

    SUBCASE("Teste de jogo Reversi")
    {
        MockJogo reversi;
        CHECK_NOTHROW(gerenciador.executarPartida('R', jogador1, jogador2));
    }

    SUBCASE("Teste de jogo Lig4")
    {
        MockJogo lig4;
        CHECK_NOTHROW(gerenciador.executarPartida('L', jogador1, jogador2));
    }

    SUBCASE("Teste de jogo Jogo da Velha")
    {
        MockJogo jogoDaVelha;
        CHECK_NOTHROW(gerenciador.executarPartida('V', jogador1, jogador2));
    }

    SUBCASE("Teste com tipo de jogo inválido")
    {
        CHECK_THROWS_AS(gerenciador.executarPartida('X', jogador1, jogador2), std::invalid_argument);
    }
}

TEST_CASE("Teste de troca de turno")
{
    GerenciadorDeJogos gerenciador;
    Jogador jogador1("Alice");
    Jogador jogador2("Bob");

    class MockTrocaTurno : public MockJogo
    {
        mutable int jogadas = 0;

    public:
        bool tabuleiroCheio() const override { return jogadas >= 4; }
        bool verificarVitoria() const override { return jogadas == 3; }
        bool realizarJogada(int, int) override
        {
            jogadas++;
            return true;
        }
    };

    MockTrocaTurno mock;
    CHECK_NOTHROW(gerenciador.executarPartida('R', jogador1, jogador2));
    CHECK(jogador1.getVitorias('R') == 1 || jogador2.getVitorias('R') == 1);
    CHECK(jogador1.getDerrotas('R') == 1 || jogador2.getDerrotas('R') == 1);
}

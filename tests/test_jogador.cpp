#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/jogador.hpp"

TEST_CASE("Teste da classe Jogador")
{
    SUBCASE("Teste de criação e getters")
    {
        Jogador jogador("apelido123", "Nome Completo");
        CHECK(jogador.getApelido() == "apelido123");
        CHECK(jogador.getNome() == "Nome Completo");
    }

    SUBCASE("Teste de incrementar vitórias e derrotas")
    {
        Jogador jogador("Player1", "Nome Exemplo");

        jogador.incrementarVitoria('R');
        jogador.incrementarVitoria('L');
        jogador.incrementarDerrota('V');
        jogador.incrementarDerrota('V');

        // Estatísticas devem refletir os incrementos
        CHECK(jogador.serializar().find("R,1,0;") != std::string::npos); // 1 vitória em 'R'
        CHECK(jogador.serializar().find("L,1,0;") != std::string::npos); // 1 vitória em 'L'
        CHECK(jogador.serializar().find("V,0,2;") != std::string::npos); // 2 derrotas em 'V'
    }

    SUBCASE("Teste de serialização")
    {
        Jogador jogador("nickname", "Full Name");
        jogador.incrementarVitoria('R');
        jogador.incrementarDerrota('L');

        std::string serializado = jogador.serializar();
        CHECK(serializado.find("nickname|Full Name|") == 0);

        CHECK(serializado.find("R,1,0;") != std::string::npos);
        CHECK(serializado.find("L,0,1;") != std::string::npos);
    }

    SUBCASE("Teste de desserialização")
    {
        std::string dados = "gamer123|John Doe|R,3,1;L,0,2;V,5,0;";
        Jogador jogador = Jogador::desserializar(dados);

        CHECK(jogador.getApelido() == "gamer123");
        CHECK(jogador.getNome() == "John Doe");

        CHECK(jogador.serializar().find("R,3,1;") != std::string::npos);
        CHECK(jogador.serializar().find("L,0,2;") != std::string::npos);
        CHECK(jogador.serializar().find("V,5,0;") != std::string::npos);
    }

    SUBCASE("Teste de impressão de estatísticas")
    {
        Jogador jogador("Player", "Example Name");
        jogador.incrementarVitoria('R');
        jogador.incrementarDerrota('L');

        CHECK_NOTHROW(jogador.imprimirEstatisticas());
    }
}

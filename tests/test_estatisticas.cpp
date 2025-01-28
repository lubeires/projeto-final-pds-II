#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/estatisticas.hpp"
#include <sstream>

TEST_SUITE("Estatisticas")
{

    TEST_CASE("Testando o construtor e valores iniciais")
    {
        Estatisticas est;

        CHECK(est.getVitorias('R') == 0);
        CHECK(est.getVitorias('L') == 0);
        CHECK(est.getVitorias('V') == 0);

        CHECK(est.getDerrotas('R') == 0);
        CHECK(est.getDerrotas('L') == 0);
        CHECK(est.getDerrotas('V') == 0);
    }

    TEST_CASE("Testando incrementarVitoria e getVitorias")
    {
        Estatisticas est;

        est.incrementarVitoria('R');
        est.incrementarVitoria('R');
        est.incrementarVitoria('L');

        CHECK(est.getVitorias('R') == 2);
        CHECK(est.getVitorias('L') == 1);
        CHECK(est.getVitorias('V') == 0);
    }

    TEST_CASE("Testando incrementarDerrota e getDerrotas")
    {
        Estatisticas est;

        est.incrementarDerrota('V');
        est.incrementarDerrota('V');
        est.incrementarDerrota('V');
        est.incrementarDerrota('R');

        CHECK(est.getDerrotas('R') == 1);
        CHECK(est.getDerrotas('L') == 0);
        CHECK(est.getDerrotas('V') == 3);
    }

    TEST_CASE("Testando imprimirEstatisticas")
    {
        Estatisticas est;
        est.incrementarVitoria('R');
        est.incrementarVitoria('L');
        est.incrementarDerrota('R');
        est.incrementarDerrota('L');

        std::ostringstream oss;
        std::streambuf *coutBuf = std::cout.rdbuf(); // Salva o buffer original de cout
        std::cout.rdbuf(oss.rdbuf());                // Redireciona cout para o buffer de string

        est.imprimirEstatisticas();

        std::cout.rdbuf(coutBuf); // Restaura o buffer original de cout

        std::string resultadoEsperado = "R - V: 1 D: 1\nL - V: 1 D: 1\nV - V: 0 D: 0\n";
        CHECK(oss.str() == resultadoEsperado);
    }

    TEST_CASE("Testando serializar e desserializar")
    {
        Estatisticas est;
        est.incrementarVitoria('R');
        est.incrementarVitoria('L');
        est.incrementarDerrota('R');
        est.incrementarDerrota('L');

        std::string serializado = est.serializar();
        CHECK(serializado == "R,1,1;L,1,1;V,0,0;");

        Estatisticas est2;
        est2.desserializar(serializado);

        CHECK(est2.getVitorias('R') == 1);
        CHECK(est2.getVitorias('L') == 1);
        CHECK(est2.getVitorias('V') == 0);

        CHECK(est2.getDerrotas('R') == 1);
        CHECK(est2.getDerrotas('L') == 1);
        CHECK(est2.getDerrotas('V') == 0);
    }

    TEST_CASE("Testando casos com entradas inexistentes")
    {
        Estatisticas est;

        CHECK(est.getVitorias('X') == 0);
        CHECK(est.getDerrotas('Y') == 0);

        est.incrementarVitoria('X');
        est.incrementarDerrota('Y');

        CHECK(est.getVitorias('X') == 0);
        CHECK(est.getDerrotas('Y') == 0);
    }
}

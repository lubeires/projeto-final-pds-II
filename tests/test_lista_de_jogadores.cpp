#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/lista_de_jogadores.hpp"
#include "../include/jogador.hpp"
#include <filesystem>

TEST_CASE("Teste do construtor de ListaDeJogadores")
{
    std::filesystem::remove("../data/jogadores.txt");
    ListaDeJogadores lista;

    CHECK(std::filesystem::exists("../data/jogadores.txt"));
}

TEST_CASE("Teste de adicionar e buscar jogador")
{
    ListaDeJogadores lista;
    Jogador jogador1("jogador1", "João", 10, 5, 20);

    SUBCASE("Adicionar novo jogador com sucesso")
    {
        lista.adicionarJogador(jogador1);
        Jogador *encontrado = lista.buscarJogador("jogador1");
        REQUIRE(encontrado != nullptr);
        CHECK(encontrado->getApelido() == "jogador1");
        CHECK(encontrado->getNome() == "João");
    }

    SUBCASE("Adicionar jogador duplicado")
    {
        lista.adicionarJogador(jogador1);
        std::ostringstream oss;
        std::streambuf *coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
        lista.adicionarJogador(jogador1);
        std::cout.rdbuf(coutBuf);
        CHECK(oss.str().find("ERRO: existe um jogador com o apelido") != std::string::npos);
    }
}

TEST_CASE("Teste de remoção de jogador")
{
    ListaDeJogadores lista;
    Jogador jogador1("jogador1", "João", 10, 5, 20);
    lista.adicionarJogador(jogador1);

    SUBCASE("Remover jogador existente")
    {
        lista.removerJogador("jogador1");
        CHECK(lista.buscarJogador("jogador1") == nullptr);
    }

    SUBCASE("Remover jogador inexistente")
    {
        std::ostringstream oss;
        std::streambuf *coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
        lista.removerJogador("jogador_inexistente");
        std::cout.rdbuf(coutBuf);
        CHECK(oss.str().find("ERRO: jogador jogador_inexistente não encontrado.") != std::string::npos);
    }
}

TEST_CASE("Teste de salvar e carregar lista de jogadores")
{
    ListaDeJogadores lista;
    Jogador jogador1("jogador1", "João", 10, 5, 20);
    Jogador jogador2("jogador2", "Maria", 15, 2, 25);

    lista.adicionarJogador(jogador1);
    lista.adicionarJogador(jogador2);

    ListaDeJogadores novaLista;
    CHECK(novaLista.buscarJogador("jogador1") != nullptr);
    CHECK(novaLista.buscarJogador("jogador2") != nullptr);
}

TEST_CASE("Teste de listar jogadores")
{
    ListaDeJogadores lista;
    lista.removerJogador("jogador1"); // Certificar que o arquivo comece limpo

    Jogador jogador1("jogador1", "João", 10, 5, 20);
    Jogador jogador2("jogador2", "Ana", 15, 2, 25);

    lista.adicionarJogador(jogador1);
    lista.adicionarJogador(jogador2);

    SUBCASE("Listar jogadores por apelido")
    {
        std::ostringstream oss;
        std::streambuf *coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
        lista.listarJogadores('A');
        std::cout.rdbuf(coutBuf);
        CHECK(oss.str().find("jogador1") < oss.str().find("jogador2"));
    }

    SUBCASE("Listar jogadores por nome")
    {
        std::ostringstream oss;
        std::streambuf *coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
        lista.listarJogadores('N');
        std::cout.rdbuf(coutBuf);
        CHECK(oss.str().find("Ana") < oss.str().find("João"));
    }
}
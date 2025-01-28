#include "../include/jogador.hpp"
#include <sstream>

Jogador::Jogador(const std::string &apelido, const std::string &nome)
    : apelido(apelido), nome(nome) {}

const std::string &Jogador::getApelido() const
{
    return apelido;
}

const std::string &Jogador::getNome() const
{
    return nome;
}

void Jogador::incrementarVitoria(char jogo)
{
    estatisticas.incrementarVitoria(jogo);
}

void Jogador::incrementarDerrota(char jogo)
{
    estatisticas.incrementarDerrota(jogo);
}

void Jogador::imprimirEstatisticas() const
{
    std::cout << std::endl
              << apelido << " (" << nome << ")" << std::endl;
    estatisticas.imprimirEstatisticas();
}

std::string Jogador::serializar() const
{
    return apelido + "|" + nome + "|" + estatisticas.serializar();
}

Jogador Jogador::desserializar(const std::string &linha)
{
    std::istringstream iss(linha);
    std::string apelido, nome, stats;
    std::getline(iss, apelido, '|');
    std::getline(iss, nome, '|');
    std::getline(iss, stats);

    Jogador jogador(apelido, nome);
    jogador.estatisticas.desserializar(stats);
    return jogador;
}
#include "../include/estatisticas.hpp"

Estatisticas::Estatisticas()
{
    vitorias = {{'R', 0}, {'L', 0}, {'V', 0}};
    derrotas = {{'R', 0}, {'L', 0}, {'V', 0}};
}

void Estatisticas::incrementarVitoria(char jogo)
{
    if (vitorias.count(jogo))
    {
        vitorias[jogo]++;
    }
}

void Estatisticas::incrementarDerrota(char jogo)
{
    if (derrotas.count(jogo))
    {
        derrotas[jogo]++;
    }
}

int Estatisticas::getVitorias(char jogo) const
{
    return vitorias.count(jogo) ? vitorias.at(jogo) : 0;
}

int Estatisticas::getDerrotas(char jogo) const
{
    return derrotas.count(jogo) ? derrotas.at(jogo) : 0;
}

void Estatisticas::imprimirEstatisticas() const
{
    for (const auto &[jogo, vitoria] : vitorias)
    {
        std::cout << jogo << " - V: " << vitoria
                  << " D: " << derrotas.at(jogo) << std::endl;
    }
}

std::string Estatisticas::serializar() const
{
    std::ostringstream oss;
    for (const auto &[jogo, vitoria] : vitorias)
    {
        oss << jogo << "," << vitoria << "," << derrotas.at(jogo) << ";";
    }
    return oss.str();
}

void Estatisticas::desserializar(const std::string &dados)
{
    vitorias.clear();
    derrotas.clear();

    std::istringstream iss(dados);
    std::string entrada;
    while (std::getline(iss, entrada, ';'))
    {
        if (entrada.empty())
            continue;

        std::istringstream jogoStream(entrada);
        char jogo;
        int vitoria, derrota;

        if (jogoStream >> jogo && jogoStream.get() == ',' &&
            jogoStream >> vitoria && jogoStream.get() == ',' &&
            jogoStream >> derrota)
        {
            vitorias[jogo] = vitoria;
            derrotas[jogo] = derrota;
        }
    }
}

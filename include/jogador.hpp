#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include "estatisticas.hpp"

class Jogador
{
private:
    std::string apelido;
    std::string nome;
    Estatisticas estatisticas;

public:
    Jogador(const std::string &apelido, const std::string &nome);

    const std::string &getApelido() const;
    const std::string &getNome() const;

    void incrementarVitoria(char jogo);
    void incrementarDerrota(char jogo);

    void imprimirEstatisticas() const;

    std::string serializar() const;
    static Jogador desserializar(const std::string &linha);
};

#endif
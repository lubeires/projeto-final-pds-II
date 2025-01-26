#ifndef ESTATISTICAS_HPP
#define ESTATISTICAS_HPP

#include <map>
#include <string>
#include <iostream>
#include <sstream>

class Estatisticas
{
private:
    std::map<char, int> vitorias;
    std::map<char, int> derrotas;

public:
    Estatisticas();

    void incrementarVitoria(char jogo);
    void incrementarDerrota(char jogo);

    int getVitorias(char jogo) const;
    int getDerrotas(char jogo) const;

    void imprimirEstatisticas() const;

    std::string serializar() const;
    void desserializar(const std::string &dados);
};

#endif
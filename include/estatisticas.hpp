#ifndef ESTATISTICAS_HPP
#define ESTATISTICAS_HPP

#include <map>
#include <string>
#include <iostream>
#include <sstream>

/**
 * @class Estatisticas
 * @brief Classe para gerenciar estatísticas de vitórias e derrotas de diferentes jogos.
 */
class Estatisticas
{
private:
    /**
     * @brief Mapa que armazena o número de vitórias para cada jogo.
     *
     * A chave é um caractere que identifica o jogo (ex.: 'R', 'L', 'V').
     * O valor é um inteiro representando o número de vitórias.
     */
    std::map<char, int> vitorias;

    /**
     * @brief Mapa que armazena o número de derrotas para cada jogo.
     *
     * A chave é um caractere que identifica o jogo (ex.: 'R', 'L', 'V').
     * O valor é um inteiro representando o número de derrotas.
     */
    std::map<char, int> derrotas;

public:
    /**
     * @brief Construtor padrão.
     *
     * Inicializa os mapas de vitórias e derrotas com valores zerados para os jogos padrão ('R', 'L', 'V').
     */
    Estatisticas();

    /**
     * @brief Incrementa o número de vitórias para o jogo especificado.
     *
     * @param jogo Caractere que identifica o jogo.
     */
    void incrementarVitoria(char jogo);

    /**
     * @brief Incrementa o número de derrotas para o jogo especificado.
     *
     * @param jogo Caractere que identifica o jogo.
     */
    void incrementarDerrota(char jogo);

    /**
     * @brief Retorna o número de vitórias para o jogo especificado.
     *
     * @param jogo Caractere que identifica o jogo.
     * @return Número de vitórias para o jogo ou 0 se o jogo não existir no mapa.
     */
    int getVitorias(char jogo) const;

    /**
     * @brief Retorna o número de derrotas para o jogo especificado.
     *
     * @param jogo Caractere que identifica o jogo.
     * @return Número de derrotas para o jogo ou 0 se o jogo não existir no mapa.
     */
    int getDerrotas(char jogo) const;

    /**
     * @brief Imprime as estatísticas de vitórias e derrotas para todos os jogos.
     *
     * O formato de saída é: "<jogo> - V: <vitórias> D: <derrotas>".
     */
    void imprimirEstatisticas() const;

    /**
     * @brief Serializa os dados de vitórias e derrotas em uma string.
     *
     * O formato da string é: "<jogo>,<vitórias>,<derrotas>;" para cada jogo.
     *
     * @return String serializada contendo os dados.
     */
    std::string serializar() const;

    /**
     * @brief Desserializa uma string e preenche os mapas de vitórias e derrotas.
     *
     * @param dados String no formato "<jogo>,<vitórias>,<derrotas>;".
     */
    void desserializar(const std::string &dados);
};

#endif

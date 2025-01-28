#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include "estatisticas.hpp"

/**
 * @class Jogador
 * @brief Classe que representa um jogador com informações pessoais e estatísticas de desempenho.
 */
class Jogador
{
private:
    /**
     * @brief Apelido do jogador.
     *
     * Um identificador curto que pode ser usado para exibição e diferenciação entre jogadores.
     */
    std::string apelido;

    /**
     * @brief Nome completo do jogador.
     *
     * Nome real do jogador, utilizado para identificações mais formais.
     */
    std::string nome;

    /**
     * @brief Estatísticas de desempenho do jogador.
     *
     * Inclui o número de vitórias e derrotas para cada tipo de jogo.
     */
    Estatisticas estatisticas;

public:
    /**
     * @brief Construtor da classe Jogador.
     *
     * Inicializa o jogador com apelido e nome.
     *
     * @param apelido Apelido do jogador.
     * @param nome Nome completo do jogador.
     */
    Jogador(const std::string &apelido, const std::string &nome);

    /**
     * @brief Obtém o apelido do jogador.
     *
     * @return Referência constante para a string do apelido.
     */
    const std::string &getApelido() const;

    /**
     * @brief Obtém o nome completo do jogador.
     *
     * @return Referência constante para a string do nome.
     */
    const std::string &getNome() const;

    /**
     * @brief Incrementa o número de vitórias do jogador para um tipo específico de jogo.
     *
     * @param jogo Caractere que identifica o tipo de jogo (ex.: 'R', 'L', 'V').
     */
    void incrementarVitoria(char jogo);

    /**
     * @brief Incrementa o número de derrotas do jogador para um tipo específico de jogo.
     *
     * @param jogo Caractere que identifica o tipo de jogo (ex.: 'R', 'L', 'V').
     */
    void incrementarDerrota(char jogo);

    /**
     * @brief Imprime as estatísticas de desempenho do jogador.
     *
     * Exibe o apelido, nome e estatísticas de vitórias e derrotas em um formato legível.
     */
    void imprimirEstatisticas() const;

    /**
     * @brief Serializa os dados do jogador em uma string.
     *
     * O formato da string é: "<apelido>|<nome>|<estatísticas>".
     *
     * @return Uma string contendo os dados serializados do jogador.
     */
    std::string serializar() const;

    /**
     * @brief Desserializa uma string para criar um objeto Jogador.
     *
     * A string deve estar no formato: "<apelido>|<nome>|<estatísticas>".
     *
     * @param linha String contendo os dados serializados.
     * @return Objeto Jogador inicializado com os dados desserializados.
     */
    static Jogador desserializar(const std::string &linha);
};

#endif

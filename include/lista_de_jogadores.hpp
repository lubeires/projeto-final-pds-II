#ifndef LISTADEJOGADORES_HPP
#define LISTADEJOGADORES_HPP

#include <vector>
#include <string>
#include "jogador.hpp"

/**
 * @brief Classe que representa uma lista de jogadores.
 *
 * Esta classe gerencia uma lista de objetos do tipo `Jogador`. Ela permite a adição,
 * remoção, busca, e listagem de jogadores. Além disso, também realiza a persistência
 * dos jogadores em arquivos de texto para garantir que os dados sejam mantidos entre
 * diferentes execuções do programa.
 */
class ListaDeJogadores
{
private:
    /**
     * @brief Estrutura de dados utilizada para armazenar os jogadores.
     *
     * A lista de jogadores é armazenada em um vetor (`std::vector`) de objetos do tipo
     * `Jogador`. O vetor é dinâmico, ou seja, seu tamanho pode aumentar conforme
     * jogadores são adicionados ou removidos.
     */
    std::vector<Jogador> jogadores;

public:
    /**
     * @brief Construtor da classe ListaDeJogadores.
     *
     * O construtor verifica a existência de um diretório para armazenar o arquivo de
     * jogadores e cria o arquivo `jogadores.txt` caso ele não exista. Caso o arquivo
     * exista, os dados são carregados dele.
     */
    ListaDeJogadores();

    /**
     * @brief Destruidor da classe ListaDeJogadores.
     *
     * O destruidor verifica se o arquivo `jogadores.txt` está vazio. Caso esteja, o
     * arquivo é removido. Caso contrário, os dados da lista de jogadores são salvos
     * no arquivo.
     */
    ~ListaDeJogadores();

    /**
     * @brief Adiciona um jogador à lista de jogadores.
     *
     * Este método verifica se já existe um jogador com o mesmo apelido antes de
     * adicionar o novo jogador. Caso o apelido já exista, um erro é exibido.
     *
     * @param jogador O objeto do tipo `Jogador` a ser adicionado à lista.
     */
    void adicionarJogador(const Jogador &jogador);

    /**
     * @brief Remove um jogador da lista de jogadores pelo apelido.
     *
     * Este método busca o jogador pelo seu apelido. Caso o jogador seja encontrado,
     * ele é removido da lista. Caso contrário, um erro é exibido.
     *
     * @param apelido O apelido do jogador a ser removido.
     */
    void removerJogador(const std::string &apelido);

    /**
     * @brief Busca um jogador na lista pelo apelido.
     *
     * Este método busca um jogador pelo seu apelido. Caso o jogador seja encontrado,
     * um ponteiro para o objeto `Jogador` correspondente é retornado. Caso contrário,
     * o método retorna um ponteiro nulo.
     *
     * @param apelido O apelido do jogador a ser buscado.
     *
     * @return Ponteiro para o jogador encontrado, ou `nullptr` se não encontrado.
     */
    Jogador *buscarJogador(const std::string &apelido);

    /**
     * @brief Salva a lista de jogadores em um arquivo.
     *
     * Este método grava todos os jogadores da lista no arquivo especificado. Cada
     * jogador é serializado como uma linha no arquivo.
     *
     * @param nomeArquivo O nome do arquivo onde os jogadores serão salvos.
     */
    void salvarEmArquivo(const std::string &nomeArquivo) const;

    /**
     * @brief Carrega os jogadores de um arquivo.
     *
     * Este método lê os dados de um arquivo e desserializa os jogadores, populando a
     * lista de jogadores com os dados lidos do arquivo.
     *
     * @param nomeArquivo O nome do arquivo de onde os jogadores serão carregados.
     */
    void carregarDeArquivo(const std::string &nomeArquivo);

    /**
     * @brief Lista todos os jogadores, ordenados por um critério.
     *
     * Este método permite listar os jogadores da lista, ordenados por um critério
     * especificado. O critério pode ser o nome ou apelido do jogador.
     *
     * @param criterio O critério de ordenação: 'A' para apelido e 'N' para nome.
     */
    void listarJogadores(char criterio) const;
};

#endif

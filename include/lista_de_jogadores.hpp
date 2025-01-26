#ifndef LISTADEJOGADORES_HPP
#define LISTADEJOGADORES_HPP

#include <vector>
#include <string>
#include "jogador.hpp"

class ListaDeJogadores
{
private:
    std::vector<Jogador> jogadores;

public:
    ListaDeJogadores();
    ~ListaDeJogadores();
    void adicionarJogador(const Jogador &jogador);
    void removerJogador(const std::string &apelido);
    Jogador *buscarJogador(const std::string &apelido);
    void salvarEmArquivo(const std::string &nomeArquivo) const;
    void carregarDeArquivo(const std::string &nomeArquivo);
    void listarJogadores(char criterio) const;
};

#endif

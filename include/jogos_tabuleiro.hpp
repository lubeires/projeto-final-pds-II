#ifndef JOGOS_TABULEIRO_HPP
#define JOGOS_TABULEIRO_HPP

#include <iostream>
#include <vector>
#include <string>

class JogoDeTabuleiro
{
public:
    virtual ~JogoDeTabuleiro() {}

    virtual void iniciarJogo() = 0;
    virtual bool realizarJogada(int linha, int coluna) = 0;
    virtual bool verificarVitoria() const = 0;
    virtual void imprimirTabuleiro() const = 0;
    virtual bool jogadaValida(int linha, int coluna) const = 0;
    virtual bool tabuleiroCheio() const = 0;

protected:
    int linhas;
    int colunas;
    std::vector<std::vector<char>> tabuleiro;
};

#endif
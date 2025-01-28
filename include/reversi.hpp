#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogos_tabuleiro.hpp"

class Reversi : public JogoDeTabuleiro
{
public:
    Reversi();

    void iniciarJogo() override;
    bool realizarJogada(int linha, int coluna) override;
    bool verificarVitoria() const override;
    void imprimirTabuleiro() const override;
    bool jogadaValida(int linha, int coluna) const override;
    bool tabuleiroCheio() const override;
    int contarPecas(char jogador) const;

private:
    char jogadorAtual;

    void alternarJogador();
    bool capturaPecas(int linha, int coluna);
    bool capturaDirecao(int linha, int coluna, int deltaLinha, int deltaColuna) const;
};

#endif

#ifndef LIG4_HPP
#define LIG4_HPP

#include "jogos_tabuleiro.hpp"

class Lig4 : public JogoDeTabuleiro
{
public:
    Lig4();
    void iniciarJogo() override;
    bool realizarJogada(int linha, int coluna) override;
    bool verificarVitoria() const override;
    void imprimirTabuleiro() const override;
    bool jogadaValida(int linha, int coluna) const override;
    bool tabuleiroCheio() const override;

private:
    char jogadorAtual;
    void alternarJogador();
    bool verificarSequencia(int linha, int coluna, int deltaLinha, int deltaColuna) const;
};

#endif

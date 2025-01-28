#ifndef JOGO_DA_VELHA_HPP
#define JOGO_DA_VELHA_HPP

#include "jogos_tabuleiro.hpp"

class JogoDaVelha : public JogoDeTabuleiro
{
public:
    JogoDaVelha();
    void iniciarJogo() override;
    bool realizarJogada(int linha, int coluna) override;
    bool verificarVitoria() const override;
    void imprimirTabuleiro() const override;
    bool jogadaValida(int linha, int coluna) const override;
    bool tabuleiroCheio() const override;

private:
    char jogadorAtual;
    void alternarJogador();
};

#endif

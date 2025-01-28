#include "jogo_da_velha.hpp"

JogoDaVelha::JogoDaVelha()
{
    linhas = 3;
    colunas = 3;
    tabuleiro = std::vector<std::vector<char>>(linhas, std::vector<char>(colunas, ' '));
    jogadorAtual = 'X';
}

void JogoDaVelha::iniciarJogo()
{
    for (auto &linha : tabuleiro)
    {
        std::fill(linha.begin(), linha.end(), ' ');
    }
}

bool JogoDaVelha::realizarJogada(int linha, int coluna)
{
    if (!jogadaValida(linha, coluna))
        return false;
    tabuleiro[linha][coluna] = jogadorAtual;
    alternarJogador();
    return true;
}

bool JogoDaVelha::verificarVitoria() const
{
    for (int i = 0; i < 3; ++i)
    {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return true;
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return true;
    }
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return true;
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return true;
    return false;
}

void JogoDaVelha::imprimirTabuleiro() const
{
    std::cout << '\n';
    for (const auto &linha : tabuleiro)
    {
        for (const auto &celula : linha)
        {
            std::cout << (celula == ' ' ? '.' : celula) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool JogoDaVelha::jogadaValida(int linha, int coluna) const
{
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && tabuleiro[linha][coluna] == ' ';
}

bool JogoDaVelha::tabuleiroCheio() const
{
    for (const auto &linha : tabuleiro)
    {
        for (const auto &celula : linha)
        {
            if (celula == ' ')
                return false;
        }
    }
    return true;
}

void JogoDaVelha::alternarJogador()
{
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

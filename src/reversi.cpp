#include "reversi.hpp"

Reversi::Reversi()
{
    linhas = 8;
    colunas = 8;
    tabuleiro = std::vector<std::vector<char>>(linhas, std::vector<char>(colunas, ' '));
    jogadorAtual = 'X';
}

void Reversi::iniciarJogo()
{
    tabuleiro[3][3] = 'O';
    tabuleiro[3][4] = 'X';
    tabuleiro[4][3] = 'X';
    tabuleiro[4][4] = 'O';
}

bool Reversi::realizarJogada(int linha, int coluna)
{
    if (!jogadaValida(linha, coluna))
        return false;
    tabuleiro[linha][coluna] = jogadorAtual;
    capturaPecas(linha, coluna);
    alternarJogador();
    return true;
}

bool Reversi::verificarVitoria() const
{
    int pecasX = contarPecas('X');
    int pecasO = contarPecas('O');
    return tabuleiroCheio() || pecasX == 0 || pecasO == 0;
}

void Reversi::imprimirTabuleiro() const
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

bool Reversi::jogadaValida(int linha, int coluna) const
{
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || tabuleiro[linha][coluna] != ' ')
        return false;

    for (int deltaLinha = -1; deltaLinha <= 1; ++deltaLinha)
    {
        for (int deltaColuna = -1; deltaColuna <= 1; ++deltaColuna)
        {
            if (deltaLinha == 0 && deltaColuna == 0)
                continue;
            if (capturaDirecao(linha, coluna, deltaLinha, deltaColuna))
                return true;
        }
    }
    return false;
}

bool Reversi::tabuleiroCheio() const
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

void Reversi::alternarJogador()
{
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

int Reversi::contarPecas(char jogador) const
{
    int count = 0;
    for (const auto &linha : tabuleiro)
    {
        for (const auto &celula : linha)
        {
            if (celula == jogador)
                ++count;
        }
    }
    return count;
}

bool Reversi::capturaPecas(int linha, int coluna)
{
    bool capturou = false;

    for (int deltaLinha = -1; deltaLinha <= 1; ++deltaLinha)
    {
        for (int deltaColuna = -1; deltaColuna <= 1; ++deltaColuna)
        {
            if (deltaLinha == 0 && deltaColuna == 0)
                continue;

            if (capturaDirecao(linha, coluna, deltaLinha, deltaColuna))
            {
                int i = linha + deltaLinha;
                int j = coluna + deltaColuna;
                char adversario = (jogadorAtual == 'X') ? 'O' : 'X';

                while (tabuleiro[i][j] == adversario)
                {
                    tabuleiro[i][j] = jogadorAtual;
                    i += deltaLinha;
                    j += deltaColuna;
                }

                capturou = true;
            }
        }
    }

    return capturou;
}

bool Reversi::capturaDirecao(int linha, int coluna, int deltaLinha, int deltaColuna) const
{
    int i = linha + deltaLinha;
    int j = coluna + deltaColuna;
    bool encontrouAdversario = false;

    char adversario = (jogadorAtual == 'X') ? 'O' : 'X';

    while (i >= 0 && i < linhas && j >= 0 && j < colunas && tabuleiro[i][j] == adversario)
    {
        i += deltaLinha;
        j += deltaColuna;
        encontrouAdversario = true;
    }

    if (encontrouAdversario && i >= 0 && i < linhas && j >= 0 && j < colunas && tabuleiro[i][j] == jogadorAtual)
    {
        return true;
    }

    return false;
}

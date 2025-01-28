#include "lig4.hpp"

Lig4::Lig4()
{
    linhas = 6;
    colunas = 7;
    tabuleiro = std::vector<std::vector<char>>(linhas, std::vector<char>(colunas, ' '));
    jogadorAtual = 'X';
}

void Lig4::iniciarJogo()
{
    for (auto &linha : tabuleiro)
    {
        std::fill(linha.begin(), linha.end(), ' ');
    }
}

bool Lig4::realizarJogada(int linha, int coluna)
{
    if (!jogadaValida(linha, coluna))
        return false;
    for (int i = linhas - 1; i >= 0; --i)
    {
        if (tabuleiro[i][coluna] == ' ')
        {
            tabuleiro[i][coluna] = jogadorAtual;
            alternarJogador();
            return true;
        }
    }
    return false;
}

bool Lig4::verificarVitoria() const
{
    for (int i = 0; i < linhas; ++i)
    {
        for (int j = 0; j < colunas; ++j)
        {
            if (tabuleiro[i][j] != ' ' && (verificarSequencia(i, j, 0, 1) ||
                                           verificarSequencia(i, j, 1, 0) ||
                                           verificarSequencia(i, j, 1, 1) ||
                                           verificarSequencia(i, j, 1, -1)))
                return true;
        }
    }
    return false;
}

void Lig4::imprimirTabuleiro() const
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

bool Lig4::jogadaValida(int linha, int coluna) const
{
    return coluna >= 0 && coluna < colunas && tabuleiro[0][coluna] == ' ';
}

bool Lig4::tabuleiroCheio() const
{
    for (const auto &celula : tabuleiro[0])
    {
        if (celula == ' ')
            return false;
    }
    return true;
}

void Lig4::alternarJogador()
{
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

bool Lig4::verificarSequencia(int linha, int coluna, int deltaLinha, int deltaColuna) const
{
    char inicial = tabuleiro[linha][coluna];
    for (int i = 1; i < 4; ++i)
    {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;
        if (novaLinha < 0 || novaLinha >= linhas || novaColuna < 0 || novaColuna >= colunas || tabuleiro[novaLinha][novaColuna] != inicial)
        {
            return false;
        }
    }
    return true;
}

#include "gerenciador_de_jogos.hpp"
#include <iostream>
#include <stdexcept>

void GerenciadorDeJogos::executarPartida(char tipoJogo, Jogador &jogador1, Jogador &jogador2)
{
    std::unique_ptr<JogoDeTabuleiro> jogo;

    try
    {
        switch (tipoJogo)
        {
        case 'R':
            jogo = std::make_unique<Reversi>();
            std::cout << "Reversi iniciado!\n";
            break;
        case 'L':
            jogo = std::make_unique<Lig4>();
            std::cout << "Lig 4 iniciado!\n";
            break;
        case 'V':
            jogo = std::make_unique<JogoDaVelha>();
            std::cout << "Jogo da velha iniciado!\n";
            break;
        default:
            throw std::invalid_argument("Tipo de jogo inválido! Use 'R', 'L' ou 'V'.");
        }

        jogo->iniciarJogo();
        jogo->imprimirTabuleiro();

        Jogador *jogadorAtual = &jogador1;
        Jogador *jogadorAdversario = &jogador2;

        while (!jogo->tabuleiroCheio() && !jogo->verificarVitoria())
        {
            std::cout << "Turno de jogador(a) " << jogadorAtual->getApelido() << ":\n";

            int linha, coluna;
            std::cout << "Digite sua jogada (linha coluna): ";
            std::cin >> linha >> coluna;

            if (!std::cin)
            {
                throw std::runtime_error("Entrada inválida! Certifique-se de inserir números.");
            }

            if (!jogo->realizarJogada(linha, coluna))
            {
                std::cerr << "Jogada inválida! Tente novamente.\n";
                continue;
            }

            jogo->imprimirTabuleiro();

            if (jogo->verificarVitoria())
            {
                std::cout << "Parabéns! Jogador(a) " << jogadorAtual->getApelido() << " venceu o jogo!\n";
                jogadorAtual->incrementarVitoria(tipoJogo);
                jogadorAdversario->incrementarDerrota(tipoJogo);
                return;
            }

            std::swap(jogadorAtual, jogadorAdversario);
        }

        std::cout << "O jogo terminou em empate.\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
    }
}

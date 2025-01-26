#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "../include/jogador.hpp"
#include "../include/lista_de_jogadores.hpp"

void exibirMenu()
{
    const int larguraLinha = 50;

    std::cout << std::setfill(' ') << std::left;
    std::cout << std::endl
              << std::endl
              << std::setw(25) << "MENU" << std::right << std::setw(25) << "" << std::endl;
    std::cout << std::setw(larguraLinha) << std::setfill('=') << "" << std::endl;

    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(25) << "JOGADORES" << std::right << std::setw(25) << "" << std::endl;
    std::cout << std::setw(larguraLinha) << std::setfill('-') << "" << std::endl;

    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(30) << "1. (CADASTRAR JOGADOR)" << "CJ <Apelido> <Nome>" << std::endl;
    std::cout << std::setw(30) << "2. (REMOVER JOGADOR)" << "RJ <Apelido>" << std::endl;
    std::cout << std::setw(30) << "3. (LISTAR POR APELIDO)" << "LJ A" << std::endl;
    std::cout << std::setw(30) << "4. (LISTAR POR NOME)" << "LJ N" << std::endl;

    std::cout << std::setw(larguraLinha) << std::setfill('-') << "" << std::endl;

    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(25) << "JOGOS DE TABULEIRO" << std::right << std::setw(25) << "" << std::endl;
    std::cout << std::setw(larguraLinha) << std::setfill('-') << "" << std::endl;

    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(30) << "1. (REVERSI)" << "EP R <Jog1> <Jog2>" << std::endl;
    std::cout << std::setw(30) << "2. (LIG4)" << "EP L <Jog1> <Jog2>" << std::endl;
    std::cout << std::setw(30) << "3. (JOGO DA VELHA)" << "EP V <Jog1> <Jog2>" << std::endl;

    std::cout << std::setw(larguraLinha) << std::setfill('-') << "" << std::endl;

    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(30) << "(FINALIZAR SISTEMA)" << "FS" << std::endl;

    std::cout << std::setw(larguraLinha) << std::setfill('=') << "" << std::endl
              << std::endl;
}

int main()
{
    ListaDeJogadores jogadores;
    bool finalizado = false;
    std::string input;
    while (!finalizado)
    {
        exibirMenu();
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::string operacao;
        iss >> operacao;

        if (operacao == "CJ")
        {
            std::string apelido, nome;
            iss >> apelido;
            std::getline(iss, nome);
            if (!apelido.empty() && !nome.empty())
            {
                nome.erase(0, nome.find_first_not_of(" "));
                jogadores.adicionarJogador(Jogador(apelido, nome));
            }
            else
                std::cout << "ERRO: dados incorretos." << std::endl;
        }
        else if (operacao == "RJ")
        {
            std::string apelido;
            iss >> apelido;
            if (!apelido.empty())
                jogadores.removerJogador(apelido);
            else
                std::cout << "ERRO: dados incorretos." << std::endl;
        }
        else if (operacao == "LJ")
        {
            char criterio;
            iss >> criterio;

            if (criterio != 'A' && criterio != 'N')
            {
                std::cout << "ERRO: criterio de listagem invalido" << std::endl;
                continue;
            }
            jogadores.listarJogadores(criterio);
        }
        else if (operacao == "EP")
        {
            char jogo;
            iss >> jogo;
            std::string jogador1, jogador2;
            if (jogo == 'R')
            {
                // INICIAR PARTIDA DE REVERSI
            }
            else if (jogo == 'L')
            {
                // INICIAR PARTIDA DE LIG4
            }
            else if (jogo == 'V')
            {
                // INICIAR PARTIDA DE JOGO DA VELHA
            }
            else
            {
                std::cout << "ERRO: dados incorretos" << std::endl;
            }
        }
        else if (operacao == "FS")
            finalizado = true;
        else
            std::cout << "ERRO: comando invalido" << std::endl;
    }
    return 0;
}

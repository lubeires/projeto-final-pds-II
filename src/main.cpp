#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "../include/jogador.hpp"
#include "../include/lista_de_jogadores.hpp"
#include "../include/gerenciador_de_jogos.hpp"

void exibirMenu()
{
    const int larguraLinha = 50;

    std::cout << std::setfill(' ') << std::left;
    std::cout << std::endl
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
    std::cout << std::setw(30) << "(FINALIZAR SISTEMA/SALVAR ESTATÍSTICAS)" << " FS" << std::endl;

    std::cout << std::setw(larguraLinha) << std::setfill('=') << "" << std::endl
              << std::endl;
}

void tornarMinusculo(std::string &texto)
{
    std::transform(texto.begin(), texto.end(), texto.begin(), [](unsigned char c)
                   { return std::tolower(c); });
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
            tornarMinusculo(apelido);

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
            tornarMinusculo(apelido);

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
            std::string j1, j2;
            iss >> j1 >> j2;

            tornarMinusculo(j1);
            tornarMinusculo(j2);

            Jogador *jogador1 = jogadores.buscarJogador(j1);
            Jogador *jogador2 = jogadores.buscarJogador(j2);

            if (jogador1 == nullptr || jogador2 == nullptr)
                std::cout << "ERRO: jogador inexistente" << std::endl;
            else if (jogo == 'R' || jogo == 'L' || jogo == 'V')
                GerenciadorDeJogos().executarPartida(jogo, *jogador1, *jogador2);
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

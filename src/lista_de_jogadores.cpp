#include "../include/lista_de_jogadores.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>

ListaDeJogadores::ListaDeJogadores()
{
    std::filesystem::path diretorio("../data/");
    if (!std::filesystem::exists(diretorio))
    {
        std::filesystem::create_directories(diretorio);
    }

    std::ifstream arquivo("../data/jogadores.txt");

    if (!arquivo.is_open())
    {
        std::ofstream novoArquivo("../data/jogadores.txt");
        if (!novoArquivo.is_open())
        {
            std::cerr << "Erro ao criar o arquivo jogadores.txt." << std::endl;
            return;
        }
        novoArquivo.close();
    }
    else

        carregarDeArquivo("../data/jogadores.txt");

    arquivo.close();
}

ListaDeJogadores::~ListaDeJogadores()
{
    std::ifstream arquivo("../data/jogadores.txt", std::ios::ate);
    if (arquivo.is_open() && arquivo.tellg() == 0)
    {
        arquivo.close();
        std::filesystem::remove("../data/jogadores.txt");
        std::cout << "Arquivo jogadores.txt foi excluído, pois está vazio." << std::endl;
    }
    else
    {
        salvarEmArquivo("../data/jogadores.txt");
        arquivo.close();
    }
}

void ListaDeJogadores::adicionarJogador(const Jogador &jogador)
{
    if (buscarJogador(jogador.getApelido()) != nullptr)
    {
        std::cout << "ERRO: existe um jogador com o apelido " << jogador.getApelido() << "." << std::endl;
        return;
    }
    jogadores.push_back(jogador);
    std::cout << "Jogador " << jogador.getApelido() << " cadastrado com sucesso!" << std::endl;

    salvarEmArquivo("../data/jogadores.txt");
}

void ListaDeJogadores::removerJogador(const std::string &apelido)
{
    auto it = std::find_if(jogadores.begin(), jogadores.end(),
                           [&](const Jogador &jogador)
                           { return jogador.getApelido() == apelido; });
    if (it == jogadores.end())
    {
        std::cout << "ERRO: jogador " << apelido << " não encontrado." << std::endl;
        return;
    }
    jogadores.erase(it);
    std::cout << "Jogador " << apelido << " removido com sucesso!" << std::endl;

    salvarEmArquivo("../data/jogadores.txt");
}

Jogador *ListaDeJogadores::buscarJogador(const std::string &apelido)
{
    for (auto &jogador : jogadores)
    {
        if (jogador.getApelido() == apelido)
        {
            return &jogador;
        }
    }
    return nullptr;
}

void ListaDeJogadores::salvarEmArquivo(const std::string &nomeArquivo) const
{
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return;
    }
    for (const auto &jogador : jogadores)
    {
        arquivo << jogador.serializar() << std::endl;
    }
    arquivo.close();
}

void ListaDeJogadores::carregarDeArquivo(const std::string &nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    jogadores.clear();
    std::string linha;
    while (std::getline(arquivo, linha))
    {
        if (!linha.empty())
        {
            try
            {
                jogadores.push_back(Jogador::desserializar(linha));
            }
            catch (const std::exception &e)
            {
                std::cerr << "Erro ao desserializar jogador: " << e.what() << std::endl;
            }
        }
    }

    arquivo.close();
}

void ListaDeJogadores::listarJogadores(char criterio) const
{
    std::vector<Jogador> copia = jogadores;

    if (copia.empty())
    {
        std::cout << "Não há jogadores cadastrados!" << std::endl;
        return;
    }

    if (criterio == 'A')
    {
        std::sort(copia.begin(), copia.end(), [](const Jogador &a, const Jogador &b)
                  { return a.getApelido() < b.getApelido(); });
    }
    else if (criterio == 'N')
    {
        std::sort(copia.begin(), copia.end(), [](const Jogador &a, const Jogador &b)
                  { return a.getNome() < b.getNome(); });
    }

    for (const auto &jogador : copia)
    {
        jogador.imprimirEstatisticas();
    }
}

# Projeto Final - Jogos de Tabuleiro (PDS II)

## Introdução

Este projeto foi desenvolvido como parte da disciplina **Projeto e Desenvolvimento de Software II** (PDS II) no 2º semestre de 2024. O objetivo do trabalho foi desenvolver um sistema orientado a objetos para implementar e gerenciar jogos de tabuleiro. Além da funcionalidade básica, o sistema foi projetado para ser modular, extensível e confiável, aplicando os conceitos de orientação a objetos (POO) aprendidos em sala de aula.

Os jogos implementados são:

- **Reversi (Othello)**: Jogo estratégico em um tabuleiro 8x8, onde os jogadores capturam peças adversárias ao cercá-las.
- **Lig 4 (Connect Four)**: Jogo clássico onde o objetivo é conectar quatro peças consecutivas em qualquer direção.
- **Jogo da Velha**: Um jogo simples em um tabuleiro 3x3, onde dois jogadores tentam formar uma linha de três peças consecutivas.

O sistema também gerencia jogadores, registrando estatísticas de vitórias e derrotas para cada jogo.

---

## Visão Geral do Sistema

O sistema foi desenvolvido com uma arquitetura orientada a objetos e segue uma estrutura organizada para facilitar a manutenção e extensão. Abaixo estão os principais componentes do sistema:

### Hierarquia de Classes para Jogos

- **JogoDeTabuleiro (Classe Abstrata)**:

  - Representa a base para jogos de tabuleiro.
  - Métodos principais:
    - `iniciarJogo()`: Inicializa o estado do jogo.
    - `realizarJogada()`: Realiza uma jogada no tabuleiro.
    - `verificarVitoria()`: Verifica se houve uma vitória.
    - `imprimirTabuleiro()`: Exibe o estado do tabuleiro.
    - `jogadaValida()`: Verifica se uma jogada é válida.
    - `tabuleiroCheio()`: Verifica se o tabuleiro está cheio.

- **Classes Derivadas**:
  - **JogoDaVelha**: Implementa as regras do jogo da velha.
  - **Lig4**: Gerencia o jogo Lig 4 com suporte a dimensões específicas do tabuleiro.
  - **Reversi**: Implementa as regras do jogo Reversi, incluindo captura de peças adversárias.

### Gerenciamento de Jogadores

- **Jogador**:

  - Representa um jogador com:
    - Nome.
    - Apelido único.
    - Estatísticas de desempenho (número de vitórias e derrotas para cada jogo).
  - Métodos:
    - Incrementar vitórias/derrotas.
    - Serializar e desserializar dados para persistência.

- **ListaDeJogadores**:
  - Gerencia o cadastro de jogadores com as seguintes funcionalidades:
    - Adicionar, remover e listar jogadores.
    - Buscar jogadores pelo apelido.
    - Persistir e carregar dados de jogadores a partir de arquivos.

### Execução de Partidas

- **GerenciadorDeJogos**:
  - Controla as partidas, incluindo:
    - Alternância de turnos.
    - Validação de jogadas.
    - Atualização de estatísticas.
    - Exibição do tabuleiro após cada jogada.
  - Suporta a execução de partidas para os três jogos implementados.

---

## Estrutura de Arquivos do Projeto

O projeto segue a seguinte organização:

```
/docs/               # Documentação gerada pelo Doxygen
/include/            # Arquivos de cabeçalho (.hpp)
/src/                # Código-fonte (.cpp)
/tests/              # Arquivos de teste
Doxyfile             # Configuração para geração de documentação com Doxygen
README.md            # Documentação do projeto
Makefile             # Automação da compilação do projeto
```

---

## Principais Dificuldades

Durante o desenvolvimento, as seguintes dificuldades foram enfrentadas:

1. **Validação de Condições de Vitória**:

   - No Reversi, foi desafiador implementar corretamente a lógica de captura de peças adversárias.
   - Em Lig 4, garantir a validação para diferentes dimensões do tabuleiro exigiu ajustes específicos.

2. **Testes Unitários**:

   - Alguns módulos não passaram em todos os testes devido a cenários extremos não previstos.
   - Escrever casos de teste abrangentes para as condições de vitória e empate exigiu refinamento iterativo.

3. **Persistência de Dados**:
   - Garantir que os dados de jogadores fossem corretamente salvos e carregados entre execuções demandou tratamento cuidadoso de arquivos.

---

## Ferramentas Utilizadas

- **Linguagem**: C++.
- **Controle de Versão**: Git e GitHub.
- **Testes Unitários**: Biblioteca `doctest`.
- **Documentação**: Gerada com `Doxygen`.
- **Compilação**: Gerenciada por `Makefile`.

---

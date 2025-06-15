# 🎮 Jogo da Forca em C

Um jogo da forca completo, feito na linguagem C, com suporte a temas, níveis de dificuldade, pontuação, modo multiplayer, reinício e pausa durante o jogo.

## 📌 Sobre o Projeto

Este é um jogo de terminal inspirado no clássico **Jogo da Forca**, desenvolvido como prática de programação em linguagem C. O jogador pode escolher entre três níveis de dificuldade e jogar sozinho ou em modo multiplayer.

## ✨ Funcionalidades

- 🎯 **Modo Singleplayer** com 3 níveis de dificuldade:
  - Fácil, Médio e Difícil.
- 🤝 **Modo Multiplayer**, onde um jogador insere a palavra e o tema.
- 🧠 **Temas aleatórios** como Países, Tecnologia e Cinema.
- 🎮 **Pontuação dinâmica** baseada em acertos e erros:
  - +10 pontos por letra correta.
  - -5 pontos por letra incorreta.
  - +50 pontos por acertar a palavra inteira.
- ⏸️ **Pausa e Reinício** durante a jogada.
- 🔡 Validação de letras já utilizadas.
- 💀 Desenho da forca com base no número de tentativas.
- ✨ Interface colorida no terminal com sequências ANSI.

## 🧠 Conceitos Aplicados

- Manipulação de strings (`<string.h>`)
- Entrada e saída com `scanf`, `printf`
- Controle de fluxo com `switch`, `if`, `while`
- Vetores e matrizes
- Uso de `toupper()` e `strlen()`
- Manipulação de caracteres (`<ctype.h>`)
- Funções auxiliares para modularidade
- Alocação dinâmica de memória (`malloc`, `free`)
- Uso de `srand()` e `rand()` para sortear temas/palavras
- Compatibilidade com Windows e Unix via `#ifdef _WIN32`

## 🧱 Estrutura do Código

- `main()` – inicia o menu principal
- `MenuExibicao()` – interface de navegação do jogador
- `jogarSingle()` – modo solo com escolha de dificuldade
- `JogarMulti()` – modo multiplayer com entrada de palavra
- `jogar()` – lógica principal do jogo
- `DesenharForca()` – imprime a forca com base nas tentativas
- `LimparTela()` – limpa a tela conforme o sistema operacional

## 🖥️ Como Executar

### Pré-requisitos

- Compilador C instalado (ex: GCC)
- Terminal de comando

### Compilando no Windows com GCC (MinGW)

```bash
gcc -o forca main.c
./forca

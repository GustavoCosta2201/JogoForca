#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void MenuExibicao(); 
void LimparTela();
void DesenharForca(int tentativas);
void jogar(const char* palavra, const char* tema);
void JogarMulti();
void jogarSingle();


void MenuExibicao() {           //Menu Principal com as escolhas;
    int opcao;

    do {
        LimparTela();
        printf("\033[1;36m===== MENU PRINCIPAL =====\033[0m\n");
        printf("1 - Jogar\n");
        printf("2 - Reiniciar\n");
        printf("3 - Pausar\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1: {
            printf("Voce escolheu Jogar.\n");
            int op;
            printf("1 - SinglePlayer\n");       //escolhe de single ou MultiPlayer
            printf("2 - MultiPlayer\n");
            scanf("%i", &op);
            if (op == 1) {
                jogarSingle();
            } else if (op == 2) {
                JogarMulti();
            } else {
                printf("Opcao Invalida\n");
                getchar();
                getchar();
            }
            break;
        }
        case 2:
            printf("Voce escolheu Reiniciar.\n");
            getchar();
            getchar();
            break;
        case 3:
            printf("Voce escolheu Pausar.\n");
            getchar();
            getchar();
            break;
        case 4:
            printf("Voce escolheu Sair. Saindo...\n");
            return;
        default:
            printf("Opcao Invalida\n");
            getchar();
            getchar();
            break;
        }
    } while (opcao != 4);
}

void jogarSingle() {
    LimparTela();               //Limpa tela
    srand(time(NULL));

    printf("Escolha o nivel que deseja jogar: \n");     //escolha de niveis
    printf("1 - Nivel Facil\n");
    printf("2 - Nivel Medio\n");
    printf("3 - Nivel Dificil\n");

    int nivel;
    scanf("%i", &nivel);

    const char* nomesTemas[] = {"Paises", "Tecnologia", "Cinema"};      //3 temas diferentes
    const char* palavra = "";
    const char* tema = "";

    int temaIndex = rand() % 3;         // faz um random pelos temas
    tema = nomesTemas[temaIndex];       //escolhe o tema

    switch (nivel) {
    case 1: {
        const char* palavras[3][4] = {              //matriz para 3 temas para 4 palavras
            {"BRASIL", "CHILE", "MEXICO", "ARGENTINA"},
            {"MOUSE", "TECLADO", "TELA", "CABO"},
            {"BATMAN", "TITANIC", "AVATAR", "JOKER"}
        };
        palavra = palavras[temaIndex][rand() % 4];
        break;
    }
    case 2: {
        const char* palavras[3][4] = {
            {"NORUEGA", "DINAMARCA", "UCRANIA", "FINLANDIA"},
            {"ROTEADOR", "PROCESSADOR", "SISTEMA", "FIRMWARE"},
            {"GLADIADOR", "INCEPTION", "CORINGA", "MATRIX"}
        };
        palavra = palavras[temaIndex][rand() % 4];
        break;
    }
    case 3: {
        const char* palavras[3][4] = {
            {"QUAZAR", "AFEGANISTAO", "BANGLADESH", "UZBEQUISTAO"},
            {"MICROPROCESSADOR", "INTELIGENCIA", "ALGORITMO", "CRIPTOSSISTEMA"},
            {"INTERESTELAR", "EXTERMINADOR", "TRANSFORMERS", "APOCALYPTO"}
        };
        palavra = palavras[temaIndex][rand() % 4];
        break;
    }
    default:
        printf("Opcao invalida.\n");
        getchar();
        getchar();
        return;
    }

    jogar(palavra, tema);
}

void JogarMulti() {
    char* palavra = malloc(100);            //alocamento de memoria dinamicamente
    char* tema = malloc(100);

    printf("Jogador 1 - Digite uma palavra: ");
    scanf("%s", palavra);
    getchar();
    printf("Tema: ");
    scanf("%s", tema);

    for (int i = 0; palavra[i]; i++)
        palavra[i] = toupper(palavra[i]);

    jogar(palavra, tema);

    free(palavra);
    free(tema);
}

void jogar(const char* palavra, const char* tema) {
    int tamanho = strlen(palavra);
    int MaxTentativas = 6;
    int tentativas = 0;
    int pontos = 0;
    char letra;
    char exibicao[tamanho + 1];
    int letrasFaltando = tamanho;
    char entrada[100];
    char letrasUsadas[26] = {0};
    int letrasUsadasCount = 0;

    for (int i = 0; i < tamanho; i++)
        exibicao[i] = '_';
    exibicao[tamanho] = '\0';

    while (tentativas < MaxTentativas && letrasFaltando > 0) {
        LimparTela();
        DesenharForca(tentativas);

        printf("Tema: %s\n", tema);
        printf("Tentativas restantes: %d\n", MaxTentativas - tentativas);
        printf("Pontuacao atual: %d\n", pontos);

        printf("Palavra: ");
        for (int i = 0; i < tamanho; i++)
            printf("%c ", exibicao[i]);
        printf("\n");

        printf("Letras usadas: ");
        for (int i = 0; i < letrasUsadasCount; i++)
            printf("%c ", letrasUsadas[i]);
        printf("\n");

        printf("Digite uma letra ou a palavra inteira:\n ");
        printf("2 - \033[1;33mPausar\033[0m | 3 - \033[1;31mReiniciar\033[0m\n");
        scanf("%s", entrada);

        if (strlen(entrada) == 1 && entrada[0] == '2') {
            printf("\033[1;33mJogo pausado. Pressione Enter para continuar...\033[0m\n");   //Opcao para pausar;
            getchar();
            getchar();
            continue;
        }

        if (strlen(entrada) == 1 && entrada[0] == '3') {
            printf("\033[1;31mReiniciando...\033[0m\n");   //Opcao para reiniciar durante a partida;
            getchar();
            getchar();
            jogarSingle();
            return;
        }

        // Verifica se o jogador tentou a palavra inteira
        if (strlen(entrada) > 1) {
            for (int i = 0; entrada[i]; i++) {      //Converte para maiuscula
                entrada[i] = toupper(entrada[i]);
            }

            if (strcmp(entrada, palavra) == 0) {
                // Acertou a palavra inteira
                for (int i = 0; i < tamanho; i++)
                    exibicao[i] = palavra[i];
                letrasFaltando = 0;
                pontos += 50; // bonus de vitoria
                printf("\033[1;32mParabens! Voce acertou a palavra inteira!\033[0m\n");
                getchar();
                getchar();
                break;
            } else {
                tentativas++;
                pontos -= 10; // penalidade maior para chute errado da palavra inteira
                printf("\033[1;31mPalavra incorreta! -10 pontos\033[0m\n");
                getchar();
                getchar();
                continue;
            }
        }

        letra = toupper(entrada[0]);

        int jaUsada = 0;
        for (int i = 0; i < letrasUsadasCount; i++) {
            if (letrasUsadas[i] == letra) {
                jaUsada = 1;
                break;
            }
        }

        if (jaUsada) {
            printf("\033[1;33mLetra ja usada!\033[0m\n");
            getchar();
            getchar();
            continue;
        } else {
            letrasUsadas[letrasUsadasCount++] = letra;
        }

        int letraEncontrada = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra && exibicao[i] == '_') {
                exibicao[i] = letra;
                letraEncontrada = 1;
                letrasFaltando--;
                pontos += 10;
            }
        }

        if (!letraEncontrada) {
            tentativas++;
            pontos -= 5;
            printf("\033[1;31mLetra incorreta! -5 pontos\033[0m\n");
        } else {
            printf("\033[1;32mBoa! +10 pontos\033[0m\n");
        }

        printf("Pontuacao atual: %d\n", pontos);
        getchar();
        getchar();
    }

    LimparTela();
    DesenharForca(tentativas);

    if (letrasFaltando == 0) {
        pontos += 50;
        printf("\033[1;32mParabens! Voce acertou a palavra: %s\033[0m\n", palavra);
        printf("\033[1;34mBonus de vitoria: +50 pontos!\033[0m\n");
    } else {
        printf("\033[1;31mGame Over! A palavra era: %s\033[0m\n", palavra);
    }

    printf("\033[1;35mPontuacao final: %d pontos\033[0m\n", pontos);
    printf("Pressione Enter para voltar ao menu...\n");
    getchar();
    getchar();
}

void DesenharForca(int tentativas) {
    printf("\033[1;36m===== FORCA =====\033[0m\n");
    printf(" _______\n");
    printf("|       |\n");

    if (tentativas >= 1) printf("|       O\n");
    else printf("|        \n");
    if (tentativas == 2) printf("|       |\n");
    else if (tentativas == 3) printf("|      /|\n");
    else if (tentativas >= 4) printf("|      /|\\\n");
    else printf("|        \n");

    if (tentativas == 5) printf("|      / \n");
    else if (tentativas >= 6) printf("|      / \\\n");
    else printf("|        \n");

    printf("|\n");
    printf("=========\n\n");
}

void LimparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    MenuExibicao();
    return 0;
}

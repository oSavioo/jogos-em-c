#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcao;
    do {
        printf("\n==== Bem-vindo ao Jogo da Adivinhacao ====\n");
        printf("(1) Jogar\n");
        printf("(2) Instrucoes\n");
        printf("(3) Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        if (opcao == 1) {
            int nivel, chute, tentativas = 0, ganhou = 0;
            int numerodetentativas, numeroSecreto;
            double pontos = 1000.0;

            printf("Escolha o nivel de dificuldade\n");
            printf("(1) Facil  (2) Medio  (3) Dificil  (4) Impossivel\n");
            printf("Digite sua escolha: ");
            if (scanf("%d", &nivel) != 1) {
                printf("Entrada invalida! Por favor, digite um numero.\n");
                while (getchar() != '\n'); // Limpa o buffer
                continue;
            }

            if (nivel == 1) {
                numerodetentativas = 20;
            } else if (nivel == 2) {
                numerodetentativas = 10;
            } else if (nivel == 3) {
                numerodetentativas = 7;
            } else if (nivel == 4) {
                numerodetentativas = 5;
            } else {
                printf("Nivel invalido! Escolha entre 1 e 4.\n");
                continue;
            }

            // Gerar o número secreto
            srand(time(0));
            numeroSecreto = rand() % 100;

            printf("Voce tera %d tentativas. Boa sorte!\n", numerodetentativas);

            for (int i = 1; i <= numerodetentativas; i++) {
                printf("\nTentativa %d\n", i);
                printf("Qual o seu chute? ");
                if (scanf("%d", &chute) != 1) {
                    printf("Entrada invalida! Digite um numero.\n");
                    while (getchar() != '\n'); // Limpa o buffer
                    continue;
                }

                if (chute < 0) {
                    printf("Voce nao pode chutar numeros negativos. Tente novamente.\n");
                    continue;
                }

                tentativas++;

                if (chute == numeroSecreto) {
                    printf("Parabens! Voce acertou o numero secreto!\n");
                    printf("Tentativas usadas: %d\n", tentativas);
                    printf("Pontos: %.2lf\n", pontos);
                    ganhou = 1;
                    break;
                } else if (chute > numeroSecreto) {
                    printf("Seu chute foi maior que o numero secreto.\n");
                } else {
                    printf("Seu chute foi menor que o numero secreto.\n");
                }

                double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
                pontos -= pontosPerdidos;
            }

            if (!ganhou) {
                printf("\nFim de jogo! Voce nao conseguiu acertar.\n");
                printf("O numero secreto era %d. Tente novamente!\n", numeroSecreto);
            }
        } else if (opcao == 2) {
            printf("\n==== Instrucoes ====\n");
            printf("1. Este eh um jogo de adivinhacao.\n");
            printf("2. Um numero secreto sera gerado automaticamente entre 0 e 99.\n");
            printf("3. Escolha o nivel de dificuldade:\n");
            printf("   - Facil: 20 tentativas.\n");
            printf("   - Medio: 10 tentativas.\n");
            printf("   - Dificil: 7 tentativas.\n");
            printf("   - Impossivel: 5 tentativas.\n");
            printf("4. Em cada tentativa, voce deve digitar um numero.\n");
            printf("5. O programa dira se seu chute foi maior ou menor que o numero secreto.\n");
            printf("6. O objetivo eh adivinhar o numero secreto com o menor numero de tentativas.\n");
            printf("7. Pontos sao calculados com base na diferenca entre seu chute e o numero secreto.\n");
            printf("Divirta-se e boa sorte!\n");
        } else if (opcao == 3) {
            printf("Obrigado por jogar! Ate a proxima.\n");
        } else {
            printf("Opcao invalida! Escolha entre 1, 2 e 3.\n");
        }
    } while (opcao != 3);

    return 0;
}

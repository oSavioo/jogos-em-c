#include <stdio.h>
#include <stdlib.h>

int main() {
    char tabuleiro[3][3], jogador, jogar_novamente;
    int linha, coluna, rodada, ganhou, opcao;
    int placar_x = 0, placar_o = 0; // Placar 

    do {
        // Menu 
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printf("==== Bem-vindo ao Jogo da Velha ====\n");
        printf("1. Jogar\n");
        printf("2. Instrucoes\n");
        printf("3. Sair do Jogo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 2) {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            printf("==== Instrucoes ====\n");
            printf("1. Este e um jogo de dois jogadores.\n");
            printf("2. O tabuleiro possui 3 linhas e 3 colunas.\n");
            printf("3. Cada jogador alterna sua jogada (X e O).\n");
            printf("4. Ganha quem formar uma linha, coluna ou diagonal com o mesmo simbolo.\n");
            printf("5. Caso todas as casas sejam preenchidas e ninguem ganhe, o jogo termina em empate (deu velha).\n");
            printf("6. Durante o jogo, voce deve digitar as coordenadas da linha e coluna onde deseja jogar.\n");
            printf("7. Para se jogar basta digitar '1 3' primeira linha e terceira coluna");
            printf("\nPressione qualquer tecla para voltar ao menu...\n");
            while (getchar() != '\n'); 
            getchar(); 
        } else if (opcao == 3) {
            printf("\nObrigado por jogar! Ate a proxima.\n");
            break;
        } else if (opcao == 1) {
            do {
                //Tabuleiro vazio
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tabuleiro[i][j] = ' ';
                    }
                }

                ganhou = 0; // Ninguém ganhou no início da partida

                // Imprime o tabuleiro inicial
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                printf(" %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
                printf("---+---+---\n");
                printf(" %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
                printf("---+---+---\n");
                printf(" %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);

                // Rodadas
                for (rodada = 1; rodada <= 9 && ganhou == 0; rodada++) {
                    // Define o jogador da rodada
                    jogador = (rodada % 2 == 1) ? 'X' : 'O';

                    
                    do {
                        printf("\nJogador '%c', digite as coordenadas (linha e coluna, de 1 a 3): ", jogador);
                        scanf("%d %d", &linha, &coluna);
                        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ') {
                            printf("Coordenada invalida! Tente novamente.\n");
                        }
                    } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ');

                    
                    tabuleiro[linha - 1][coluna - 1] = jogador;

                    // Imprime o tabuleiro atualizado
#ifdef _WIN32
                    system("cls");
#else
                    system("clear");
#endif
                    printf(" %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
                    printf("---+---+---\n");
                    printf(" %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
                    printf("---+---+---\n");
                    printf(" %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);

                    // Verifica se o jogador venceu
                    if ((tabuleiro[linha - 1][0] == jogador && tabuleiro[linha - 1][1] == jogador && tabuleiro[linha - 1][2] == jogador) || // Linha
                        (tabuleiro[0][coluna - 1] == jogador && tabuleiro[1][coluna - 1] == jogador && tabuleiro[2][coluna - 1] == jogador) || // Coluna
                        (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) || 
                        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) { 
                        ganhou = 1;
                    }
                }

                // Imprime o resultado da partida
                if (ganhou) {
                    printf("\nO jogador '%c' ganhou!\n", jogador);
                    if (jogador == 'X') {
                        placar_x++;
                    } else {
                        placar_o++;
                    }
                } else {
                    printf("\nDeu velha! Ninguem ganhou.\n");
                }

                // Mostra o placar
                printf("\nPlacar atual:\n");
                printf("Jogador 'X': %d\n", placar_x);
                printf("Jogador 'O': %d\n", placar_o);

                // Pergunta se o jogador deseja jogar novamente
                printf("\nDeseja jogar novamente? (s/n): ");
                scanf(" %c", &jogar_novamente);

            } while (jogar_novamente == 's' || jogar_novamente == 'S');
        } else {
            printf("Opcao invalida! Escolha entre 1, 2 e 3.\n");
        }
    } while (opcao != 3);

    printf("\nObrigado por jogar! Ate a proxima!\n");

    return 0;
}

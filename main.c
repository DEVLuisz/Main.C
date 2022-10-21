#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("                                                \n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("                                                  \n");
    printf("*           Created By: ®Luís - Void           *  \n");
    printf("                                                \n\n");

    int seconds = time(0);
    srand(seconds);
    int randomNumber = rand();
    int numberSecret = randomNumber % 100;
    int chute;
    int attempts = 1;
    int numberOfAttempts;
    int acertou = 0;

    double points = 1000;

    int nivel;
    printf("Qual o nível de dificuldade? \n");
    printf("(1) GG Easy (2) Deveras Interessante (3) TryHard \n\n");
    printf("Escolha: \n");
    scanf("%d", &nivel);

    switch (nivel) {
        case 1:
            numberOfAttempts = 20;
            break;
        case 2:
            numberOfAttempts = 16;
            break;
        default:
            numberOfAttempts = 6;
            break;
    }

    for(int i = 1; i <= numberOfAttempts; i ++) {

        printf("Tentiva %d\n", attempts);
        printf("Qual é o seu chute?: ");
        scanf("%d", &chute );
        printf("Seu chute foi: %d \n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");

            continue;
        }

        acertou = (chute == numberSecret);
        int larger = chute > numberSecret;

        if(acertou) {
            break;
        }

        else if(larger) {
                printf("Seu chute foi maior que o número secreto \n");
            }
            else {
                printf("Seu chute foi menor que o número secreto \n");
            }
        attempts += 1;

        double lostPoints = abs(chute - numberSecret) / 2.0;
        points = points - lostPoints;
    }

    printf("Fim de Jogo! \n");

    if(acertou){
        printf("                                     \n");
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("                                     \n");
        printf("\nParabéns! Você acertou!\n");
        printf("Você fez %.1f pontos. Até a próxima!\n\n", points);
        printf("Powered By: ®Luís - Void\n");
    } else {
        printf("                         \n\n");
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        printf("                         \n\n");
        printf("Você perdeu! Try Again\n");
        printf("Powered By: ®Luís -  Void\n");
    }

}

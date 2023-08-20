#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
// tudo o que come�a com # s�o diretivas, #incluce e #define

int main(){
    setlocale (LC_ALL, "Portuguese_Brazil");
    printf ("          P  /_\\  P                              ");
    printf ("\n         /_\\_|_|_/_\\                             ");
    printf ("\n     n_n | ||. .|| | n_n         Bem vindo ao    ");
    printf ("\n    |_|_|nnnn nnnn|_|_|     Jogo de Adivinha��o!");
    printf ("\n    |" "  |  |_|  |"  " |                        ");
    printf ("\n    |_____| ' _ ' |_____|                        ");
    printf ("\n          \\__|_|__/                              ");
    printf ("\n\n");

    // CRIA��O DE UM N�MERO ALEATORIAMENTE
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    ///////////////////

    int chute;
    int tentativas = 1;
    int qttentativas;
    int acertou = 0; // no bool, 0 = falso // 1 = verdadeiro
    int ganhou = 0;
    double pontos = 1000;

    int nivel;
    printf ("\nQual o n�vel de dificuldade?");
    printf ("\n \t1- F�cil \n\t2- M�dio \n\t3- Dif�cil");
    printf ("\nDigite o n�mero referente � dificuldade desejada:\n");
    scanf ("%d", &nivel);

    switch (nivel){
        case 1:
            qttentativas = 20;
            break;
        case 2:
            qttentativas = 15;
            break;
        default:
            qttentativas = 6;
            break;
    }

    for (tentativas = 1; tentativas <= qttentativas; tentativas++){
        printf ("\nTentativa: %d de %d \n", tentativas, qttentativas);
        printf ("Qual � o seu chute? \n");
        scanf ("%d", &chute);
        printf ("Seu chute foi: %d", chute);

        if (chute < 0){
            printf ("\nVoc� n�o pode chutar um n�mero negativo!\n");
            continue; // Para a execu��o do bloco, e continua o loop
        }

        int acertou = (chute == numerosecreto);
        // Os par�nteses n�o s�o obrigat�rios na compara��o
        int maior = chute > numerosecreto;

        if (acertou){
            break;
        }
        else if (maior){ // else if interrompe o restante dos ifs caso o primeiro seja verdadeiro
            printf ("\nSeu chute foi maior que o n�mero secreto. \n");
        }
        else{
            printf ("\nSeu chute foi menor que o n�mero secreto. \n");
        }
    // tentativas = tentativas + 1; // soma mais uma tentativa � vari�vel
    double pontosperdidos = abs(chute - numerosecreto) / 2.0; // fun��o abs extrai o m�dulo de um n�mero
    pontos = pontos - pontosperdidos;
    }

    if (chute == numerosecreto){
        printf("\n             OOOOOOOOOOO               \n");
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
        printf("\n\n");
        printf ("Parab�ns!!!! Voc� acertou em %d tentativas!\n", tentativas);
        printf ("Total de pontos: %.2f", pontos);
    }
    else{
        printf ("\nFim do jogo! \n");
        printf ("Voc� n�o ganhou desta vez, tente de novo! \n");
        printf("\n       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");

    }
}
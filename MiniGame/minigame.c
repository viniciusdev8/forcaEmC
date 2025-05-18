#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>

int jogar();
void jogo();

int main() {
    setlocale(LC_CTYPE, "Portuguese");
    jogar();
    return 0;
}

void jogo() {
    char palavra[32], escondida[32], carac;
    int i, tentativas=10, tamanho=0;

    printf("[PALAVRA ESCOLHIDA]: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    system("cls");
    for(i=0; palavra[i] != '\0'; i++) {
        escondida[i] = '#';
        tamanho++;
    }
    int total=tamanho, j=0;
    char informados[26];

    while(tentativas>0) {
        int acerto=0, encontrado=0;

        printf("[CARACTERES UTILIZADOS]:"); 
        for(i=0; i < j; i++) {
            printf(" %c", informados[i]);
        }
        printf("\n\n");

        printf("[TENTATIVAS RESTANTES]: %d\n\n", tentativas); 
        for(i=0; i<tamanho; i++) {
            palavra[i] = toupper(palavra[i]);
            printf(" %c", escondida[i]);
        }
        printf("\n");
        if(total==0) {
            break;
        }
        printf("\n[DIGITE UM CARACTERE]: ");
        carac = getch();
        carac = toupper(carac);

        for(i=0; i<tamanho; i++) {
            if(informados[i] == carac) {
                encontrado = 1;
            }
            if(palavra[i] == carac) {
                if (palavra[i] != escondida[i]) {
                    escondida[i] = carac;
                    acerto = 1;
                    total--;
                }
            }
        }
        if (!encontrado) {
            informados[j] = carac;
            j++;
        }
        if(!acerto) {
            tentativas--;
        }
        system("cls");
    }

    if (tentativas>0) {
        printf("\nParabéns! Você venceu com %d/10 tentativas!\n\n", tentativas);
    } else {
        printf("Que pena, você perdeu!\n");
        printf("A palavra era:");
        for(i=0; i<tamanho; i++) {
            printf(" %c", palavra[i]);
        }
        printf("\n\n");
    }
    printf("Pressione qualquer tecla para voltar ao menu...\n");
    getch();
}
int jogar() {
    int opcao;
    while(1) {
        system("cls");
        system("title Jogo da Forca - por viniciusdev8");
        printf("Desenvolvido por viniciusdev8 :]\n\n");
        printf("\t[JOGO DA FORCA]\n\n");
        printf("_________________________________\n\n");
        printf("[1] JOGAR\n");
        printf("[2] COMO JOGAR\n");
        printf("[3] SAIR\n\n");
        printf("_________________________________\n\n");
        printf("> ");
        opcao = getch();

        system("cls");
        switch(opcao) {
            case '1':
                jogo();
                break;
            case '2':
                printf("Um jogador deve digitar uma palavra secreta, e o outro terá até 10 tentativas para adivinhá-la!\n\n");
                printf("Pressione qualquer tecla para continuar...\n");
                getch();
                break;
            case '3':
                return 1;
        }
    }
}
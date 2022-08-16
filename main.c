#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "separador.h"
#include <time.h>

char resposta[999];
char vetor[999];
int contador = 0, aux = 1;
struct no *topo = NULL;

void empilhaAleatorios(){
    int i;
    for(i=0; i<1; i++){
        vetor[i]= 97 + (char)(rand()%26);
        push(vetor[i], &topo);
        contador = contador + 1;
    }
}

int main(){

    char atual;
    int errar = 1, ver = 0, sair = 0, pontos = 0;
    printf("===================================\n");
    printf("Bem-vindo ao Jogo da memoria!!\n===================================\n\n 1) JOGAR \n\n 0) SAIR  \n\n===================================\n\nRESPOSTA: ");
    scanf("%d", &sair);


    switch (sair)
    {
        case 0:
            system("cls");
            printf("Saindo!");
            exit(0);
            break;
        case 1:
            system("cls");
            do
            {
                printf("Digite a proxima letra de A-Z: ");
                scanf("%s", &atual);
                push(atual,&topo);
                empilhaAleatorios();
                contador = contador -1;
                vetor[contador+1] = atual;
                aux++;
                printf("Proxima letra: %c. Voce tem 3 segundos para memorizar\n", vetor[contador]);

                sleep(3);
                system("cls");
                printf("Digite a sequencia: ");
                scanf("%s", resposta);
                for (int i = 0; i <= ver; i++)
                {
                    if(vetor[i] != resposta[i]){
                        printf("\nVoce perdeu!!\nSua pontuacao: %d", pontos);
                        printf("\nSequencia correta: %s", vetor);
                        exit(0);
                    }
                    else{
                        system("cls");
                        printf("\nParabens!! +10 pontos!\n");
                        pontos +=10;
                    }
                }
                
            } while (contador <= 9);
            break;
        default:
            system("cls");
            printf("Valor invalido, tente novamente.\n");
            system("pause");
            system("cls");
            main();
            break;
    }
    getch();
    return main();
}

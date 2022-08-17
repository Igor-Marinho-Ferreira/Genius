#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "push.h"
#include "design.h"

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
void SelecionarMenuPrincipal(){
    int Opcao;
    char atual;
    int errar = 1, ver = 0, sair = 0, pontos = 0;
    do{
        desenhaJanela();
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR");
        desenha(24,5,100,20);
        gotoxy(26,5);
        printf(" MENU ");
        gotoxy(26,7);
        printf("1 - Jogar");
        gotoxy(26,8);
        printf("2 - Ranking");
        gotoxy(26,9);
        printf("0 - Sair");
        gotoxy(26,19);
        printf("Selecione qual o tipo de operacao deseja realizar: ");
        scanf("%d",&Opcao);
        switch (Opcao){
            case 0:
                system("cls");
                gotoxy(0,0);
                printf("ENCERRADO!");
                
                break;
            case 1:
            	system("cls");
			do{
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
                        printf("Parabens! +10 pontos!\n");
                        sleep(3);
                        system("cls");
                        pontos +=10;
                    }
                }
                
            } while (contador <= 9);
                break;
            case 2:
                system("cls");
                printf("Em breve");
		sleep(3);
                system("cls");
                break;
        }        
    }while (Opcao != 0);
}

#endif

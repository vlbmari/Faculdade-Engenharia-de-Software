#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int escolhaJogador, escolhaComputador; 
    srand(time(0));
    //FASE 1: Inicio opcoes do jogo
    printf ("***JOGO DE JOKENPÔ***\n");
    printf("Escolha uma opção:\n 1. Pedra\n2. Papel\n3. Tesoura\n");
    printf("Escolha: ");
    scanf("%d", &escolhaJogador);

    escolhaComputador = rand() % 3 + 1;
    //Mostrar escolhas do jogador
    switch (escolhaJogador){
    case 1:
        printf("Jogador: Pedra - ");
        break; 
    case 2:
        printf("Jogador: Papel - ");
        break;   
    case 3:
        printf("Jogador: Tesoura - ");
        break;
    default:
        printf("Opção inválida\n");
        break;
    }
    //Mostrar escolhas do computador
    switch (escolhaComputador){
    case 1:
        printf("Computador: Pedra\n");
        break;
    
    case 2:
        printf("Computador: Papel\n");
        break;
    
    case 3:
        printf("Computador: Tesoura\n");
        break;
    }

    //FASE 2: Decisão do jogo
    if(escolhaComputador == escolhaJogador){
        printf("Jogo empatou");
    }else if ((escolhaJogador == 1) && (escolhaComputador == 3) || 
                (escolhaJogador == 2) && (escolhaComputador == 1) || 
                (escolhaJogador == 3) && (escolhaComputador == 2)){
        printf("Paraéns, você ganhou!");
    }else{
        printf("Você perdeu...");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numeroJogador, numeroComputador, resultado;
    char tipoComparacao;

    //Gerar número aleatório
    srand(time(0));
    numeroComputador = rand() % 100 + 1; //Numero entre 1 e 100

    //Inicio do jogo
    printf("Bem-vindo ao jogo Maior, Menor ou Igual!\n");
    printf("Você deve escolher um número e o tipo de comparação. \n");
    printf("M. Maior\nN. Menor\nI. Igual\n");

    printf("Escolha a comparação: ");
    scanf("%c", &tipoComparacao);
    printf("Escolha seu número (entre 1 e 100): ");
    scanf("%d", &numeroJogador);

    switch (tipoComparacao)
    {
    case 'M':
    case 'm':
        printf("Você escolheu a opção 'Maior'\n");
        resultado = numeroJogador > numeroComputador ? 1 : 0;
        break;
    
    case 'N':
    case 'n':
        printf("Você escolheu a opção 'Menor'\n");
        resultado = numeroJogador < numeroComputador ? 1 : 0;
        break;
    
    case 'I':
    case 'i':
        printf("Você escolheu a opção 'Igual'\n");
        resultado = numeroJogador == numeroComputador ? 1 : 0;
        break;
    
    default:
    printf("Opção do jogo inválida");
        break;
    }

    printf("Seu número é: %d \nO numero do computador é: %d", numeroJogador, numeroComputador);
    if(resultado == 1){
        printf("\nParabéns você venceu!");
    }else{
        printf("\nInfelizmente você perdeu...");
    }
}
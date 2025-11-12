#include <stdio.h>

int main(){
    int idade, matricula;
    float altura;
    char nome[50];
    //Recolher dados do aluno
    printf("Digite seu nome: \n");
    scanf("%s", &nome);
    printf("Digite sua altura: \n");
    scanf("%f", &altura);
    printf("Digite sua idade: \n");
    scanf("%d", &idade);
    printf("Digite sua matricula: \n");
    scanf("%d", &matricula);

    printf("Nome: %d - Altura: %f\n", nome, altura);
    printf("Idade: %d - Matricula %d", idade, matricula);

    
}
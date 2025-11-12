#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para a função exit (opcional, para saídas controladas)

// Define a estrutura para representar uma Carta de País
typedef struct {
    char nome_pais[50];
    int populacao;               
    float area;               
    float pib;                  
    int pontos_turisticos;       
    float densidade_demografica; 
} Carta;

// Função para calcular os atributos derivados (Densidade)
void calcular_atributos(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_demografica = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_demografica = 0.0;
    }
}

// Função para exibir o menu de opções
void exibir_menu(int atributo_ignorado) {
    printf("\nOpcoes de Atributos:\n");
    if (atributo_ignorado != 1) printf("1. Populacao\n");
    if (atributo_ignorado != 2) printf("2. Area\n");
    if (atributo_ignorado != 3) printf("3. PIB\n");
    if (atributo_ignorado != 4) printf("4. Pontos Turisticos\n");
    if (atributo_ignorado != 5) printf("5. Densidade Demografica (MENOR vence)\n");
    printf("--------------------------------------\n");
    printf("Escolha o numero do atributo: ");
}

// Função para processar a comparação de um atributo
// Retorna 1 se a Carta 1 vencer, 2 se a Carta 2 vencer, 0 se for empate
int comparar_atributo(int opcao, const Carta *c1, const Carta *c2, const char **nome_attr, float *val1_out, float *val2_out) {
    float val1 = 0, val2 = 0;
    int c1_vence = 0; // 0: Empate, 1: C1 Vence, 2: C2 Vence
    
    switch (opcao) {
        case 1: // População (MAIOR vence)
            *nome_attr = "Populacao"; val1 = (float)c1->populacao; val2 = (float)c2->populacao;
            if (val1 > val2) c1_vence = 1; else if (val2 > val1) c1_vence = 2;
            break;
        case 2: // Área (MAIOR vence)
            *nome_attr = "Area"; val1 = c1->area; val2 = c2->area;
            if (val1 > val2) c1_vence = 1; else if (val2 > val1) c1_vence = 2;
            break;
        case 3: // PIB (MAIOR vence)
            *nome_attr = "PIB"; val1 = c1->pib; val2 = c2->pib;
            if (val1 > val2) c1_vence = 1; else if (val2 > val1) c1_vence = 2;
            break;
        case 4: // Pontos Turísticos (MAIOR vence)
            *nome_attr = "Pontos Turisticos"; val1 = (float)c1->pontos_turisticos; val2 = (float)c2->pontos_turisticos;
            if (val1 > val2) c1_vence = 1; else if (val2 > val1) c1_vence = 2;
            break;
        case 5: // Densidade Demográfica (MENOR vence)
            *nome_attr = "Densidade Demografica"; val1 = c1->densidade_demografica; val2 = c2->densidade_demografica;
            if (val1 < val2) c1_vence = 1; else if (val2 < val1) c1_vence = 2;
            break;
        default:
            *nome_attr = "ERRO";
            break;
    }

    *val1_out = val1;
    *val2_out = val2;
    return c1_vence;
}

// Função para determinar o resultado final (usa o operador ternário)
void determinar_vencedor_final(int pontos1, int pontos2, const char *nome1, const char *nome2) {
    const char *resultado;

    if (pontos1 == pontos2) {
        resultado = "EMPATE!";
    } else {
        // Usa o operador ternário para determinar o vencedor
        resultado = (pontos1 > pontos2) ? nome1 : nome2;
    }


    printf("   ##  RESULTADO FINAL DA RODADA   ##  \n");
    printf("%s - Pontuacao Total: %d\n", nome1, pontos1);
    printf("%s - Pontuacao Total: %d\n", nome2, pontos2);
    printf("-----------------------------------\n");

    if (pontos1 == pontos2) {
        printf("Resultado: %s\n", resultado);
    } else {
        printf("VENCEDOR GERAL: %s\n", resultado);
    }

}

int main() {
    // 1. Dados Fixos das Cartas
    Carta carta1, carta2;
    int attr_escolhido1 = 0, attr_escolhido2 = 0;
    
    // --- Carta 1: Brasil ---
    strcpy(carta1.nome_pais, "Brasil");
    carta1.populacao = 217000000;
    carta1.area = 8516000.0;
    carta1.pib = 2.08;
    carta1.pontos_turisticos = 35;

    // --- Carta 2: Russia ---
    strcpy(carta2.nome_pais, "Russia");
    carta2.populacao = 144000000;
    carta2.area = 17100000.0;
    carta2.pib = 2.24;
    carta2.pontos_turisticos = 15;

    // Calcular atributo derivado
    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    printf("  SUPER TRUNFO - COMPARACAO DUPLA\n");
    printf("   %s vs %s\n", carta1.nome_pais, carta2.nome_pais);


    // 2. Escolha do Primeiro Atributo (Menu Dinâmico)
    while (attr_escolhido1 < 1 || attr_escolhido1 > 5) {
        exibir_menu(0); // 0 indica que nenhum atributo deve ser ignorado
        if (scanf("%d", &attr_escolhido1) != 1) {
            printf("\nEntrada invalida. Tente novamente.\n");
            while(getchar() != '\n'); // Limpa buffer de entrada
        } else if (attr_escolhido1 < 1 || attr_escolhido1 > 5) {
             printf("\nOpcao fora do intervalo (1 a 5). Tente novamente.\n");
        }
    }


    // 3. Escolha do Segundo Atributo (Menu Dinâmico e Validação de Repetição)
    while (attr_escolhido2 < 1 || attr_escolhido2 > 5 || attr_escolhido2 == attr_escolhido1) {
        exibir_menu(attr_escolhido1); // Ignora o atributo já escolhido
        printf("(Atributo 1 ja escolhido: %d)\n", attr_escolhido1);
        if (scanf("%d", &attr_escolhido2) != 1) {
            printf("\nEntrada invalida. Tente novamente.\n");
            while(getchar() != '\n');
            attr_escolhido2 = 0; // Reseta para forçar nova entrada
        } else if (attr_escolhido2 < 1 || attr_escolhido2 > 5) {
             printf("\nOpcao fora do intervalo (1 a 5). Tente novamente.\n");
        } else if (attr_escolhido2 == attr_escolhido1) {
            printf("\nEste atributo ja foi escolhido! Selecione outro.\n");
        }
    }


    // 4. Comparação e Soma dos Atributos (Pontuação)
    int pontos_c1 = 0;
    int pontos_c2 = 0;
    
    const char *nome_attr1, *nome_attr2;
    float val1_attr1, val2_attr1;
    float val1_attr2, val2_attr2;

    // --- Comparação do Primeiro Atributo ---
    int vencedor1 = comparar_atributo(attr_escolhido1, &carta1, &carta2, &nome_attr1, &val1_attr1, &val2_attr1);
    if (vencedor1 == 1) {
        pontos_c1++;
    } else if (vencedor1 == 2) {
        pontos_c2++;
    }

    // --- Comparação do Segundo Atributo ---
    int vencedor2 = comparar_atributo(attr_escolhido2, &carta1, &carta2, &nome_attr2, &val1_attr2, &val2_attr2);
    if (vencedor2 == 1) {
        pontos_c1++;
    } else if (vencedor2 == 2) {
        pontos_c2++;
    }


    // 5. Exibição Detalhada do Resultado
    printf("     DETALHES DA COMPARACAO     \n");
    // Atributo 1
    printf("\n--> Atributo 1: %s\n", nome_attr1);
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_pais, val1_attr1, carta2.nome_pais, val2_attr1);
    if (vencedor1 == 1) printf("Vencedor da Rodada: %s (1 Ponto)\n", carta1.nome_pais);
    else if (vencedor1 == 2) printf("Vencedor da Rodada: %s (1 Ponto)\n", carta2.nome_pais);
    else printf("Rodada 1: Empate!\n");

    // Atributo 2
    printf("\n--> Atributo 2: %s\n", nome_attr2);
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_pais, val1_attr2, carta2.nome_pais, val2_attr2);
    if (vencedor2 == 1) printf("Vencedor da Rodada: %s (1 Ponto)\n", carta1.nome_pais);
    else if (vencedor2 == 2) printf("Vencedor da Rodada: %s (1 Ponto)\n", carta2.nome_pais);
    else printf("Rodada 2: Empate!\n");

    // 6. Resultado Final
    determinar_vencedor_final(pontos_c1, pontos_c2, carta1.nome_pais, carta2.nome_pais);

    return 0;
}
#include <stdio.h>

// CONSTANTES GLOBAIS (para definir as distâncias de movimento)
const int CASAS_TORRE = 5;
const int CASAS_RAINHA = 8;
const int CASAS_BISPO = 5;

// Constantes para o novo movimento do CAVALO: 2x Cima, 1x Direita
const int CAVALO_PASSOS_VERTICAIS = 2; 
const int CAVALO_PASSOS_HORIZONTAIS = 1;



// FUNÇÕES RECURSIVAS (Torre e Rainha)
void moverTorreRecursivamente(int casas_restantes) {
    // Caso base: A recursão para quando não há mais casas para mover.
    if (casas_restantes <= 0) {
        return;
    }

    // Ação: Imprime a direção do movimento para esta casa.
    printf("Direita\n");

    // Passo recursivo: Chama a função novamente, diminuindo o contador de casas.
    moverTorreRecursivamente(casas_restantes - 1);
}


void moverRainhaRecursivamente(int casas_restantes) {
    // Caso base
    if (casas_restantes == 0) {
        return;
    }

    // Ação
    printf("Esquerda\n");

    // Passo recursivo
    moverRainhaRecursivamente(casas_restantes - 1);
}



// FUNÇÃO RECURSIVA E LOOPS ANINHADOS (Bispo)

void moverBispoRecursivamenteComLoops(int casas_restantes) {
    // Caso base
    if (casas_restantes <= 0) {
        return;
    }

    
    int vertical = 0; // Loop externo: Movimento vertical (Cima)
    // O loop for é usado como o loop externo.
    for (vertical = 0; vertical < 1; vertical++) { 
        
        int horizontal = 0; // Loop interno: Movimento horizontal (Direita)
        // O loop do-while é usado como o loop interno.
        do {
            // Imprime a combinação de direções para a diagonal (Cima Direita)
            printf("Cima Direita\n"); 
            horizontal++;
        } while (horizontal < 1);
    }
    
    // Passo recursivo: Chama a função novamente, diminuindo o contador de passos diagonais.
    moverBispoRecursivamenteComLoops(casas_restantes - 1);
}


// FUNÇÃO PRINCIPAL

int main() {

    // 1. SIMULAÇÃO DO MOVIMENTO DA TORRE (usando Recursividade)
    printf("Simulacao da TORRE (Recursividade):\n");

    
    moverTorreRecursivamente(CASAS_TORRE);
    
    printf("\n");


    // 2. SIMULAÇÃO DO MOVIMENTO DA RAINHA (usando Recursividade)
    printf("Simulacao da RAINHA (Recursividade):\n");

    moverRainhaRecursivamente(CASAS_RAINHA);

    printf("\n");


    // 3. SIMULAÇÃO DO MOVIMENTO DO BISPO (Recursividade + Loops Aninhados)
    printf("Simulacao do BISPO (Recursividade + Loops Aninhados):\n");
    printf("======================================\n");

    moverBispoRecursivamenteComLoops(CASAS_BISPO);
    
    printf("\n");

    // 4. SIMULAÇÃO DO MOVIMENTO DO CAVALO (Loops Aninhados Complexos com break/continue)
    // Movimento: 2x Cima e 1x Direita
    printf("Simulacao do CAVALO (Loops Aninhados Complexos):\n");

    
    int passo_l = 0; // Controla o ciclo "L" (deve ser 3 passos no total)
    int condicao_quebra = 0; // Variável para controlar o 'break'

    // Loop Externo: Controla os 3 passos do movimento "L"
    for (passo_l = 1; passo_l <= 3; passo_l++) {
        
        // Loop Interno: Controla a execução da impressão
        // O loop 'while' usa uma condição composta e múltiplas variáveis
        while (condicao_quebra < 1 && passo_l <= 3) {
            
            // Condição 1: Movimento Vertical (2 casas para CIMA)
            if (passo_l <= CAVALO_PASSOS_VERTICAIS) {
                printf("Cima\n");
                
                // O 'continue' força o loop 'for' a próxima iteração
                // sem executar o código subsequente neste loop 'while'.
                condicao_quebra = 1; 
                continue; 
            }
            
            // Condição 2: Movimento Horizontal (1 casa para DIREITA)
            if (passo_l == CAVALO_PASSOS_VERTICAIS + CAVALO_PASSOS_HORIZONTAIS) {
                printf("Direita\n");
                
                // O 'break' encerra o loop 'for' (o mais externo), pois o movimento 'L' está completo.
                // É necessário um 'break' condicional dentro do 'while' aninhado para afetar o 'for'.
                condicao_quebra = 1; 
                break; 
            }
            
            // Incremento do 'condicao_quebra' para sair do loop 'while' após a ação (se não houver continue/break)
            condicao_quebra++;
        }
        
        // Reseta a variável de controle do loop 'while' para a próxima iteração do 'for'
        condicao_quebra = 0; 

        // Adiciona uma condição de quebra explícita após o loop 'while' para o 'for'
        if (passo_l == CAVALO_PASSOS_VERTICAIS + CAVALO_PASSOS_HORIZONTAIS) {
             break; // Encerra o 'for' para garantir que não haja iterações desnecessárias.
        }
    }
    
    printf("\nFim da simulacao.\n");
    
    return 0;
}
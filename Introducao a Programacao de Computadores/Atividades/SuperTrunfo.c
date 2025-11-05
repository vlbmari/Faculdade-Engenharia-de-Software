#include <stdio.h>

int main() {
// --- CARTA 1 ---
    char estado1;
    char codCarta1[10]; 
    char nomeCidade1[50]; 
    unsigned long int populacao1; 
    float area1;                 
    float pib1;                   
    int numPontosTuristicos1;
    float densidadePopulacional1; 
    float pibPerCapita1;
    float superPoder1;

    // --- CARTA 2 ---
    char estado2;
    char codCarta2[10]; 
    char nomeCidade2[50]; 
    unsigned long int populacao2; 
    float area2; 
    float pib2;
    int numPontosTuristicos2;
    float densidadePopulacional2; 
    float pibPerCapita2;
    float superPoder2;
    
    // VARIÁVEIS DE COMPARAÇÃO (Para armazenar o resultado 1 ou 0)
    int vitoriaPop, vitoriaArea, vitoriaPib, vitoriaPontos, vitoriaDensidade, vitoriaPibPC, vitoriaSP;


    // FASE 1: LEITURA DOS DADOS (CARTA 1)
    printf("******CADASTRO DE 2 CARTAS - SUPER TRUNFO******\n");
    printf("\n--- CARTA 1 ---\n");

    printf("1. Estado (OBS: Letra de 'A' a 'H'): ");
    scanf(" %c", &estado1); 
    printf("2. Código da Carta (ex: A01, B03): ");
    scanf("%s", codCarta1); 
    printf("3. Nome da Cidade:\n");
    scanf("%s", nomeCidade1);
    printf("4. População: ");
    scanf("%lu", &populacao1);
    printf("5. Área da cidade (em km²):\n");
    scanf("%f", &area1);     
    printf("6. Produto Interno Bruto (PIB):\n");
    scanf("%f", &pib1);     
    printf("7. Número de Pontos Turísticos:\n");
    scanf("%d", &numPontosTuristicos1); 


    // FASE 1: LEITURA DOS DADOS (CARTA 2)
    printf("\n--- Inserir dados da CARTA 2 ---\n");

    printf("1. Estado (OBS: Letra de 'A' a 'H'): ");
    scanf(" %c", &estado2); 
    printf("2. Código da Carta (ex: A01, B03): ");
    scanf("%s", codCarta2); 
    printf("3. Nome da Cidade: ");
    scanf("%s", nomeCidade2);
    printf("4. População (unsigned long int): ");
    scanf("%lu", &populacao2);
    printf("5. Área da cidade (em km² - float): ");
    scanf("%f", &area2);     
    printf("6. Produto Interno Bruto (PIB - float): ");
    scanf("%f", &pib2);     
    printf("7. Número de Pontos Turísticos: ");
    scanf("%d", &numPontosTuristicos2); 

    // FASE 2: CÁLCULOS (CARTA 1)
    densidadePopulacional1 = (float)populacao1 / area1; 
    pibPerCapita1 = pib1 / (float)populacao1; 
    
    // Super Poder: Soma dos atributos, com atenção à conversão de tipos
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)numPontosTuristicos1 + pibPerCapita1 + (1.0f / densidadePopulacional1);

    // FASE 2: CÁLCULOS (CARTA 2)
    densidadePopulacional2 = (float)populacao2 / area2; 
    pibPerCapita2 = pib2 / (float)populacao2; 
    
    // Super Poder: Soma dos atributos
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)numPontosTuristicos2 + pibPerCapita2 + (1.0f / densidadePopulacional2);

    // FASE 3: EXIBIÇÃO DETALHADA
    printf("\n\n===== DADOS CADASTRADOS E CALCULADOS =====");

    // EXIBIÇÃO CARTA 1
    printf("\n--- CARTA 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codCarta1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1); // Uso de %lu
    printf("Área: %.2f km²\n", area1); 
    printf("PIB: %.2f bilhões de reais\n", pib1); 
    printf("Número de Pontos Turísticos: %d\n", numPontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1); 
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);                  
    printf("Super Poder: %.2f\n", superPoder1);

    // EXIBIÇÃO CARTA 2
    printf("\n--- CARTA 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codCarta2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2); 
    printf("PIB: %.2f bilhões de reais\n", pib2); 
    printf("Número de Pontos Turísticos: %d\n", numPontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2); 
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);                    
    printf("Super Poder: %.2f\n", superPoder2);



    // FASE 4: BATALHA E COMPARAÇÃO
    printf("\n\n===== COMPARAÇÃO DE CARTAS (BATALHA) ======");
    
    // Regra: MAIOR valor vence (exceto Densidade)
    // 1. População (Maior vence)
    vitoriaPop = populacao1 > populacao2;
    printf("\nPopulação: Carta %d venceu (%d)\n", vitoriaPop ? 1 : 2, vitoriaPop);

    // 2. Área (Maior vence)
    vitoriaArea = area1 > area2;
    printf("Área: Carta %d venceu (%d)\n", vitoriaArea ? 1 : 2, vitoriaArea);

    // 3. PIB (Maior vence)
    vitoriaPib = pib1 > pib2;
    printf("PIB: Carta %d venceu (%d)\n", vitoriaPib ? 1 : 2, vitoriaPib);
    
    // 4. Pontos Turísticos (Maior vence)
    vitoriaPontos = numPontosTuristicos1 > numPontosTuristicos2;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", vitoriaPontos ? 1 : 2, vitoriaPontos);

    // 5. Densidade Populacional (MENOR valor vence)
    vitoriaDensidade = densidadePopulacional1 < densidadePopulacional2;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", vitoriaDensidade ? 1 : 2, vitoriaDensidade);
    
    // 6. PIB per Capita (Maior vence)
    vitoriaPibPC = pibPerCapita1 > pibPerCapita2;
    printf("PIB per Capita: Carta %d venceu (%d)\n", vitoriaPibPC ? 1 : 2, vitoriaPibPC);

    // 7. Super Poder (Maior vence)
    vitoriaSP = superPoder1 > superPoder2;
    printf("Super Poder: Carta %d venceu (%d)\n", vitoriaSP ? 1 : 2, vitoriaSP);
    
    return 0;
}
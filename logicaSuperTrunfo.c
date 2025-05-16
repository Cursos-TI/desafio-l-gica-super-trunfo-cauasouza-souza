#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1 (pré-definidos)
    char estado1[] = "SP";
    char codigo1[] = "SP01";
    char cidade1[] = "São Paulo";
    unsigned long populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 699.28; // em bilhões
    int pontos_turisticos1 = 50;
    
    // Dados da Carta 2 (pré-definidos)
    char estado2[] = "RJ";
    char codigo2[] = "RJ02";
    char cidade2[] = "Rio de Janeiro";
    unsigned long populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50; // em bilhões
    int pontos_turisticos2 = 30;
    
    // Cálculos para ambas as cartas
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pib_per_capita1 = (pib1 * 1e9) / populacao1; // Convertendo para reais por habitante
    float pib_per_capita2 = (pib2 * 1e9) / populacao2;
    
    // Escolha do atributo para comparação (definido no código)
    // Opções: 1-População, 2-Área, 3-PIB, 4-Densidade, 5-PIB per capita
    int atributo_escolhido = 1; // Vamos comparar por População
    
    // Variáveis para armazenar o resultado
    int carta_vencedora;
    char atributo_nome[20];
    float valor1, valor2;
    
    // Determina qual atributo será comparado
    switch(atributo_escolhido) {
        case 1: // População
            strcpy(atributo_nome, "População");
            valor1 = populacao1;
            valor2 = populacao2;
            carta_vencedora = (populacao1 > populacao2) ? 1 : 2;
            break;
            
        case 2: // Área
            strcpy(atributo_nome, "Área");
            valor1 = area1;
            valor2 = area2;
            carta_vencedora = (area1 > area2) ? 1 : 2;
            break;
            
        case 3: // PIB
            strcpy(atributo_nome, "PIB");
            valor1 = pib1;
            valor2 = pib2;
            carta_vencedora = (pib1 > pib2) ? 1 : 2;
            break;
            
        case 4: // Densidade Populacional (menor valor vence)
            strcpy(atributo_nome, "Densidade Populacional");
            valor1 = densidade1;
            valor2 = densidade2;
            carta_vencedora = (densidade1 < densidade2) ? 1 : 2;
            break;
            
        case 5: // PIB per capita
            strcpy(atributo_nome, "PIB per capita");
            valor1 = pib_per_capita1;
            valor2 = pib_per_capita2;
            carta_vencedora = (pib_per_capita1 > pib_per_capita2) ? 1 : 2;
            break;
            
        default:
            printf("Atributo inválido para comparação!\n");
            return 1;
    }
    
    // Exibição dos resultados
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    printf("Atributo comparado: %s\n\n", atributo_nome);
    
    printf("Carta 1 - %s (%s):\n", cidade1, estado1);
    if(atributo_escolhido == 1) {
        printf("População: %.0f habitantes\n", valor1);
    } else if(atributo_escolhido == 4) {
        printf("Densidade: %.2f hab/km²\n", valor1);
    } else if(atributo_escolhido == 5) {
        printf("PIB per capita: R$ %.2f\n", valor1);
    } else {
        printf("%s: %.2f\n", atributo_nome, valor1);
    }
    
    printf("\nCarta 2 - %s (%s):\n", cidade2, estado2);
    if(atributo_escolhido == 1) {
        printf("População: %.0f habitantes\n", valor2);
    } else if(atributo_escolhido == 4) {
        printf("Densidade: %.2f hab/km²\n", valor2);
    } else if(atributo_escolhido == 5) {
        printf("PIB per capita: R$ %.2f\n", valor2);
    } else {
        printf("%s: %.2f\n", atributo_nome, valor2);
    }
    
    printf("\nResultado: Carta %d (%s) venceu!\n", 
           carta_vencedora, 
           (carta_vencedora == 1) ? cidade1 : cidade2);
    
    return 0;
}
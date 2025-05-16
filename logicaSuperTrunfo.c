#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Dados das cartas (pré-cadastrados)
    char estado1[] = "SP";
    char codigo1[] = "SP01";
    char cidade1[] = "São Paulo";
    unsigned long populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 699.28; // em bilhões
    int pontos_turisticos1 = 50;
    float densidade1 = populacao1 / area1;
    float pib_per_capita1 = (pib1 * 1e9) / populacao1;
    
    char estado2[] = "RJ";
    char codigo2[] = "RJ02";
    char cidade2[] = "Rio de Janeiro";
    unsigned long populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50; // em bilhões
    int pontos_turisticos2 = 30;
    float densidade2 = populacao2 / area2;
    float pib_per_capita2 = (pib2 * 1e9) / populacao2;
    
    int opcao;
    int continuar = 1;
    
    while(continuar) {
        // Exibe o menu de opções
        printf("\n=== SUPER TRUNFO - MENU DE COMPARAÇÃO ===\n");
        printf("Cartas disponíveis:\n");
        printf("1. %s (%s)\n", cidade1, estado1);
        printf("2. %s (%s)\n", cidade2, estado2);
        printf("\nEscolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("6 - PIB per Capita\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        // Limpa o buffer do teclado
        while(getchar() != '\n');
        
        // Variáveis para armazenar os valores comparados
        float valor1, valor2;
        char atributo[30];
        int resultado;
        
        switch(opcao) {
            case 0:
                continuar = 0;
                printf("Saindo do jogo...\n");
                break;
                
            case 1: // População
                strcpy(atributo, "População");
                valor1 = populacao1;
                valor2 = populacao2;
                resultado = (populacao1 > populacao2) ? 1 : (populacao2 > populacao1) ? 2 : 0;
                break;
                
            case 2: // Área
                strcpy(atributo, "Área");
                valor1 = area1;
                valor2 = area2;
                resultado = (area1 > area2) ? 1 : (area2 > area1) ? 2 : 0;
                break;
                
            case 3: // PIB
                strcpy(atributo, "PIB");
                valor1 = pib1;
                valor2 = pib2;
                resultado = (pib1 > pib2) ? 1 : (pib2 > pib1) ? 2 : 0;
                break;
                
            case 4: // Pontos Turísticos
                strcpy(atributo, "Pontos Turísticos");
                valor1 = pontos_turisticos1;
                valor2 = pontos_turisticos2;
                resultado = (pontos_turisticos1 > pontos_turisticos2) ? 1 : (pontos_turisticos2 > pontos_turisticos1) ? 2 : 0;
                break;
                
            case 5: // Densidade Demográfica (menor valor vence)
                strcpy(atributo, "Densidade Demográfica");
                valor1 = densidade1;
                valor2 = densidade2;
                resultado = (densidade1 < densidade2) ? 1 : (densidade2 < densidade1) ? 2 : 0;
                break;
                
            case 6: // PIB per Capita
                strcpy(atributo, "PIB per Capita");
                valor1 = pib_per_capita1;
                valor2 = pib_per_capita2;
                resultado = (pib_per_capita1 > pib_per_capita2) ? 1 : (pib_per_capita2 > pib_per_capita1) ? 2 : 0;
                break;
                
            default:
                printf("\nOpção inválida! Por favor, escolha uma opção entre 0 e 6.\n");
                continue;
        }
        
        // Exibe o resultado da comparação (exceto para opção 0 - Sair)
        if(opcao >= 1 && opcao <= 6) {
            printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
            printf("Atributo: %s\n\n", atributo);
            
            printf("%s (%s): ", cidade1, estado1);
            if(opcao == 1) printf("%.0f habitantes\n", valor1);
            else if(opcao == 5) printf("%.2f hab/km²\n", valor1);
            else if(opcao == 6) printf("R$ %.2f\n", valor1);
            else printf("%.2f\n", valor1);
            
            printf("%s (%s): ", cidade2, estado2);
            if(opcao == 1) printf("%.0f habitantes\n", valor2);
            else if(opcao == 5) printf("%.2f hab/km²\n", valor2);
            else if(opcao == 6) printf("R$ %.2f\n", valor2);
            else printf("%.2f\n", valor2);
            
            printf("\nResultado: ");
            if(resultado == 1) {
                printf("%s venceu!\n", cidade1);
            } else if(resultado == 2) {
                printf("%s venceu!\n", cidade2);
            } else {
                printf("Empate!\n");
            }
        }
    }
    
    return 0;
}

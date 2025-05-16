#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para exibir o menu de atributos disponíveis
void exibir_menu(int atributo_excluido) {
    printf("\nEscolha um atributo:\n");
    if(atributo_excluido != 1) printf("1 - População\n");
    if(atributo_excluido != 2) printf("2 - Área\n");
    if(atributo_excluido != 3) printf("3 - PIB\n");
    if(atributo_excluido != 4) printf("4 - Pontos Turísticos\n");
    if(atributo_excluido != 5) printf("5 - Densidade Demográfica\n");
    if(atributo_excluido != 6) printf("6 - PIB per Capita\n");
    printf("0 - Cancelar\n");
    printf("Opção: ");
}

// Função para obter a escolha do usuário
int obter_escolha(int atributo_excluido) {
    int opcao;
    while(1) {
        scanf("%d", &opcao);
        while(getchar() != '\n'); // Limpa o buffer
        
        if(opcao == 0) return 0; // Cancelar
        if(opcao < 1 || opcao > 6) {
            printf("Opção inválida! Escolha entre 1-6 ou 0 para cancelar: ");
            continue;
        }
        if(opcao == atributo_excluido) {
            printf("Atributo já selecionado! Escolha outro: ");
            continue;
        }
        return opcao;
    }
}

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
    
    int continuar = 1;
    
    while(continuar) {
        printf("\n=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
        printf("Cartas disponíveis:\n");
        printf("1. %s (%s)\n", cidade1, estado1);
        printf("2. %s (%s)\n", cidade2, estado2);
        
        // Escolha do primeiro atributo
        printf("\nPRIMEIRO ATRIBUTO:\n");
        exibir_menu(0);
        int atributo1 = obter_escolha(0);
        if(atributo1 == 0) {
            continuar = 0;
            continue;
        }
        
        // Escolha do segundo atributo
        printf("\nSEGUNDO ATRIBUTO (diferente do primeiro):\n");
        exibir_menu(atributo1);
        int atributo2 = obter_escolha(atributo1);
        if(atributo2 == 0) {
            continuar = 0;
            continue;
        }
        
        // Variáveis para armazenar os valores comparados
        float valor1_1, valor1_2; // Valores para carta 1 (atributo1 e atributo2)
        float valor2_1, valor2_2; // Valores para carta 2
        char nome_atributo1[30], nome_atributo2[30];
        int resultado1, resultado2; // Resultados das comparações individuais
        float soma1, soma2; // Somas dos atributos
        
        // Obter valores do primeiro atributo para ambas as cartas
        switch(atributo1) {
            case 1:
                strcpy(nome_atributo1, "População");
                valor1_1 = populacao1;
                valor2_1 = populacao2;
                resultado1 = (valor1_1 > valor2_1) ? 1 : (valor2_1 > valor1_1) ? 2 : 0;
                break;
            case 2:
                strcpy(nome_atributo1, "Área");
                valor1_1 = area1;
                valor2_1 = area2;
                resultado1 = (valor1_1 > valor2_1) ? 1 : (valor2_1 > valor1_1) ? 2 : 0;
                break;
            case 3:
                strcpy(nome_atributo1, "PIB");
                valor1_1 = pib1;
                valor2_1 = pib2;
                resultado1 = (valor1_1 > valor2_1) ? 1 : (valor2_1 > valor1_1) ? 2 : 0;
                break;
            case 4:
                strcpy(nome_atributo1, "Pontos Turísticos");
                valor1_1 = pontos_turisticos1;
                valor2_1 = pontos_turisticos2;
                resultado1 = (valor1_1 > valor2_1) ? 1 : (valor2_1 > valor1_1) ? 2 : 0;
                break;
            case 5:
                strcpy(nome_atributo1, "Densidade Demográfica");
                valor1_1 = densidade1;
                valor2_1 = densidade2;
                resultado1 = (valor1_1 < valor2_1) ? 1 : (valor2_1 < valor1_1) ? 2 : 0;
                break;
            case 6:
                strcpy(nome_atributo1, "PIB per Capita");
                valor1_1 = pib_per_capita1;
                valor2_1 = pib_per_capita2;
                resultado1 = (valor1_1 > valor2_1) ? 1 : (valor2_1 > valor1_1) ? 2 : 0;
                break;
        }
        
        // Obter valores do segundo atributo para ambas as cartas
        switch(atributo2) {
            case 1:
                strcpy(nome_atributo2, "População");
                valor1_2 = populacao1;
                valor2_2 = populacao2;
                resultado2 = (valor1_2 > valor2_2) ? 1 : (valor2_2 > valor1_2) ? 2 : 0;
                break;
            case 2:
                strcpy(nome_atributo2, "Área");
                valor1_2 = area1;
                valor2_2 = area2;
                resultado2 = (valor1_2 > valor2_2) ? 1 : (valor2_2 > valor1_2) ? 2 : 0;
                break;
            case 3:
                strcpy(nome_atributo2, "PIB");
                valor1_2 = pib1;
                valor2_2 = pib2;
                resultado2 = (valor1_2 > valor2_2) ? 1 : (valor2_2 > valor1_2) ? 2 : 0;
                break;
            case 4:
                strcpy(nome_atributo2, "Pontos Turísticos");
                valor1_2 = pontos_turisticos1;
                valor2_2 = pontos_turisticos2;
                resultado2 = (valor1_2 > valor2_2) ? 1 : (valor2_2 > valor1_2) ? 2 : 0;
                break;
            case 5:
                strcpy(nome_atributo2, "Densidade Demográfica");
                valor1_2 = densidade1;
                valor2_2 = densidade2;
                resultado2 = (valor1_2 < valor2_2) ? 1 : (valor2_2 < valor1_2) ? 2 : 0;
                break;
            case 6:
                strcpy(nome_atributo2, "PIB per Capita");
                valor1_2 = pib_per_capita1;
                valor2_2 = pib_per_capita2;
                resultado2 = (valor1_2 > valor2_2) ? 1 : (valor2_2 > valor1_2) ? 2 : 0;
                break;
        }
        
        // Calcular a soma dos atributos para cada carta
        soma1 = valor1_1 + valor1_2;
        soma2 = valor2_1 + valor2_2;
        
        // Determinar o vencedor final
        int vencedor_final = (soma1 > soma2) ? 1 : (soma2 > soma1) ? 2 : 0;
        
        // Exibir resultados
        printf("\n=== RESULTADOS DA COMPARAÇÃO ===\n");
        printf("Atributos selecionados: %s e %s\n\n", nome_atributo1, nome_atributo2);
        
        // Carta 1
        printf("%s (%s):\n", cidade1, estado1);
        printf("- %s: ", nome_atributo1);
        if(atributo1 == 1) printf("%.0f\n", valor1_1);
        else if(atributo1 == 5) printf("%.2f hab/km²\n", valor1_1);
        else if(atributo1 == 6) printf("R$ %.2f\n", valor1_1);
        else printf("%.2f\n", valor1_1);
        
        printf("- %s: ", nome_atributo2);
        if(atributo2 == 1) printf("%.0f\n", valor1_2);
        else if(atributo2 == 5) printf("%.2f hab/km²\n", valor1_2);
        else if(atributo2 == 6) printf("R$ %.2f\n", valor1_2);
        else printf("%.2f\n", valor1_2);
        printf("Soma: %.2f\n\n", soma1);
        
        // Carta 2
        printf("%s (%s):\n", cidade2, estado2);
        printf("- %s: ", nome_atributo1);
        if(atributo1 == 1) printf("%.0f\n", valor2_1);
        else if(atributo1 == 5) printf("%.2f hab/km²\n", valor2_1);
        else if(atributo1 == 6) printf("R$ %.2f\n", valor2_1);
        else printf("%.2f\n", valor2_1);
        
        printf("- %s: ", nome_atributo2);
        if(atributo2 == 1) printf("%.0f\n", valor2_2);
        else if(atributo2 == 5) printf("%.2f hab/km²\n", valor2_2);
        else if(atributo2 == 6) printf("R$ %.2f\n", valor2_2);
        else printf("%.2f\n", valor2_2);
        printf("Soma: %.2f\n\n", soma2);
        
        // Resultado final
        printf("RESULTADO FINAL:\n");
        if(vencedor_final == 1) {
            printf("%s venceu com maior soma de atributos!\n", cidade1);
        } else if(vencedor_final == 2) {
            printf("%s venceu com maior soma de atributos!\n", cidade2);
        } else {
            printf("Empate! As cartas têm a mesma soma de atributos.\n");
        }
        
        // Perguntar se deseja continuar
        printf("\nDeseja fazer outra comparação? (S/N): ");
        char resposta;
        scanf(" %c", &resposta);
        while(getchar() != '\n');
        continuar = (toupper(resposta) == 'S');
    }
    
    printf("\nObrigado por jogar Super Trunfo!\n");
    return 0;
}

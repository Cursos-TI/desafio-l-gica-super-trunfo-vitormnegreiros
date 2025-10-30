#include <stdio.h>
#include <string.h>


struct Carta {
    char nome[30];
    float populacao;            
    float area;                
    float pib;                  
    float densidadeDemografica; 
    float expectativaVida;      
};

int main() {
    struct Carta carta1 = {"Brasil", 213.3, 8515.8, 2.05, 25.0, 75.9};
    struct Carta carta2 = {"Japão", 125.8, 377.9, 5.15, 333.0, 84.5};

    int opcao1, opcao2;
    float valor1A, valor2A, valor1B, valor2B;
    float soma1, soma2;

    printf("=== SUPER TRUNFO: NÍVEL MESTRE ===\n\n");

    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Escolha o PRIMEIRO atributo para comparação:\n");
    printf("1 - População (maior vence)\n");
    printf("2 - Área (maior vence)\n");
    printf("3 - PIB (maior vence)\n");
    printf("4 - Densidade Demográfica (menor vence)\n");
    printf("5 - Expectativa de Vida (maior vence)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao1);

    
    printf("\nAgora escolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == opcao1) continue; 
        switch (i) {
            case 1: printf("1 - População (maior vence)\n"); break;
            case 2: printf("2 - Área (maior vence)\n"); break;
            case 3: printf("3 - PIB (maior vence)\n"); break;
            case 4: printf("4 - Densidade Demográfica (menor vence)\n"); break;
            case 5: printf("5 - Expectativa de Vida (maior vence)\n"); break;
        }
    }

    printf("Digite sua escolha: ");
    scanf("%d", &opcao2);

   
    if (opcao1 == opcao2 || opcao1 < 1 || opcao1 > 5 || opcao2 < 1 || opcao2 > 5) {
        printf("\nOpções inválidas! Você deve escolher dois atributos diferentes entre 1 e 5.\n");
        return 1;
    }

  
    switch (opcao1) {
        case 1: valor1A = carta1.populacao; valor2A = carta2.populacao; break;
        case 2: valor1A = carta1.area; valor2A = carta2.area; break;
        case 3: valor1A = carta1.pib; valor2A = carta2.pib; break;
        case 4: valor1A = carta1.densidadeDemografica; valor2A = carta2.densidadeDemografica; break;
        case 5: valor1A = carta1.expectativaVida; valor2A = carta2.expectativaVida; break;
        default: valor1A = valor2A = 0;
    }

    switch (opcao2) {
        case 1: valor1B = carta1.populacao; valor2B = carta2.populacao; break;
        case 2: valor1B = carta1.area; valor2B = carta2.area; break;
        case 3: valor1B = carta1.pib; valor2B = carta2.pib; break;
        case 4: valor1B = carta1.densidadeDemografica; valor2B = carta2.densidadeDemografica; break;
        case 5: valor1B = carta1.expectativaVida; valor2B = carta2.expectativaVida; break;
        default: valor1B = valor2B = 0;
    }


    soma1 = valor1A + valor1B;
    soma2 = valor2A + valor2B;


    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Atributo 1: ");
    switch (opcao1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Densidade Demográfica\n"); break;
        case 5: printf("Expectativa de Vida\n"); break;
    }
    printf(" - %s: %.2f\n - %s: %.2f\n\n", carta1.nome, valor1A, carta2.nome, valor2A);

    printf("Atributo 2: ");
    switch (opcao2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Densidade Demográfica\n"); break;
        case 5: printf("Expectativa de Vida\n"); break;
    }
    printf(" - %s: %.2f\n - %s: %.2f\n\n", carta1.nome, valor1B, carta2.nome, valor2B);

    printf("Soma dos atributos:\n");
    printf(" - %s: %.2f\n - %s: %.2f\n\n", carta1.nome, soma1, carta2.nome, soma2);


    int vitoriaA1 = (opcao1 == 4) ? (valor1A < valor2A) : (valor1A > valor2A);
    int vitoriaA2 = (opcao2 == 4) ? (valor1B < valor2B) : (valor1B > valor2B);

    int totalVitorias1 = vitoriaA1 + vitoriaA2;
    int totalVitorias2 = 2 - totalVitorias1;

    printf("Resultado final: ");
    if (soma1 > soma2) {
        printf("%s venceu!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    printf("\n=====\n");
    return 0;
}

/*
NOME: Arthur Vinícius Vieira Ventura
PERÍODO/CURSO: 3° período de Ciência da computação
DATA: 27/08/2024
HORÁRIO: 21:42
*/

#include <stdio.h>
#include <stdlib.h>

void exibirBinario(unsigned short int num) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void decimalParaComplemento2(int num) {
    unsigned short int resultado;

    printf("Convertendo %d para complemento a 2 com 16 bits:\n", num);

    if (num < 0) {
        num = abs(num);

        printf("Convertendo para binário com 16 bits:\n");
        resultado = num;
        exibirBinario(resultado);

        printf("Invertendo todos os bits:\n");
        resultado = ~resultado;
        exibirBinario(resultado);

        printf("Somando 1 ao complemento de 1 para ter o complemento a 2:\n");
        resultado += 1;
        exibirBinario(resultado);

    } else {
        printf("Convertendo para binário com 16 bits:\n");
        resultado = num;
        exibirBinario(resultado);
    }

    printf("Resultado final em complemento a 2: ");
    exibirBinario(resultado);
}

int main() {
    int num;

    printf("Digite um número decimal: ");
    scanf("%d", &num);

    decimalParaComplemento2(num);

    return 0;
}

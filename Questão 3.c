/*
NOME: Arthur Vinícius Vieira Ventura
PERÍODO/CURSO: 3° período de Ciência da computação
DATA: 29/08/2024
HORÁRIO: 08:30
*/

#include <stdio.h>
#include <stdint.h>

void printBitsFloat(uint32_t n);
void printBitsDouble(uint64_t n);
void showFloatDetails(float f);
void showDoubleDetails(double d);

int main() {
    float f;
    scanf("%f",&f);
    double d = f;

    showFloatDetails(f);
    showDoubleDetails(d);

    return 0;
}

void printBitsFloat(uint32_t n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

void printBitsDouble(uint64_t n) {
    for (int i = 63; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

void showFloatDetails(float f) {
    uint32_t bits;
    memcpy(&bits, &f, sizeof(bits));

    uint32_t sign = (bits >> 31) & 1;
    uint32_t exponent = (bits >> 23) & 0xFF;
    uint32_t mantissa = bits & 0x7FFFFF;

    printf("Float: %f\n", f);
    printf("Bits: ");
    printBitsFloat(bits);
    printf("Sinal: %u\n", sign);
    printf("Expoente em binário: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\nExpoente com viés: %u\n", exponent);
    printf("Fração: ");
    printBitsFloat(mantissa);
}

void showDoubleDetails(double d) {
    uint64_t bits;
    memcpy(&bits, &d, sizeof(bits));

    uint64_t sign = (bits >> 63) & 1;
    uint64_t exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;

    printf("\nDouble: %lf\n", d);
    printf("Bits: ");
    printBitsDouble(bits);
    printf("Sinal: %llu\n", sign);
    printf("Expoente em binário: ");
    for (int i = 10; i >= 0; i--) {
        printf("%llu", (exponent >> i) & 1);
    }
    printf("\nExpoente com viés: %llu\n", exponent);
    printf("Fração: ");
    printBitsDouble(mantissa);
}
